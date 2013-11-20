// Copyright 2009 Hans Pirnay
// All Rights Reserved.
// This code is published under the Common Public License.
//
// Date   : 2009-07-10

#include "AsMetadataMeasurement.hpp"
#include "AsNmpcUtils.hpp"

#include <vector>

namespace Ipopt
{
#if COIN_IPOPT_VERBOSITY > 0
  static const Index dbg_verbosity = 1;
#endif

  MetadataMeasurement::MetadataMeasurement()
    :
    n_idx_(0),
    x_owner_space_(NULL),
    s_owner_space_(NULL),
    y_c_owner_space_(NULL),
    y_d_owner_space_(NULL),
    z_L_owner_space_(NULL),
    z_U_owner_space_(NULL)
  {
    DBG_START_METH("MetadataMeasurement::MetadataMeasurement", dbg_verbosity);
  }

  MetadataMeasurement::~MetadataMeasurement()
  {
    DBG_START_METH("MetadataMeasurement::~MetadataMeasurement", dbg_verbosity);
  }

  bool MetadataMeasurement::InitializeImpl(const OptionsList& options,
					   const std::string& prefix)
  {
    DBG_START_METH("MetadataMeasurement::InitializeImpl", dbg_verbosity);

    x_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->x()->OwnerSpace()));
    s_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->s()->OwnerSpace()));
    y_c_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->y_c()->OwnerSpace()));
    y_d_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->y_d()->OwnerSpace()));
    z_L_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->z_L()->OwnerSpace()));
    z_U_owner_space_ = dynamic_cast<const DenseVectorSpace*>(GetRawPtr(IpData().curr()->z_U()->OwnerSpace()));
    DBG_ASSERT(IsValid(x_owner_space_) && IsValid(s_owner_space_) && 
	       IsValid(y_c_owner_space_) && IsValid(y_d_owner_space_) &&
	       IsValid(z_L_owner_space_) && IsValid(z_U_owner_space_));



    bool run_nmpc;
    options.GetBoolValue("run_nmpc", run_nmpc, "");
    if (run_nmpc) {
      std::string nmpc_state_0 = "nmpc_state_1"; // nmpc_state_0 doesn't exist anymore...
      std::vector<Index> tmp_idx = x_owner_space_->GetIntegerMetaData(nmpc_state_0);
      
      n_idx_ = AsIndexMax(tmp_idx.size(), &tmp_idx[0], 1);

      options.GetStringValue("select_step", select_step_, "");

    }

    return true;
  }

  std::vector<Index> MetadataMeasurement::GetInitialEqConstraints()
  {
    DBG_START_METH("MetadataMeasurement::GetInitialEqConstraints", dbg_verbosity);

    SmartPtr<const IteratesVector> it = IpData().curr();
    Index n_base = it->x()->Dim() + it->s()->Dim();

    const std::vector<Index> constr_metadata = y_c_owner_space_->GetIntegerMetaData("nmpc_init_constr");
    
    std::vector<Index> retval;
    for (Index i = 0; i<constr_metadata.size(); ++i) {
      if (constr_metadata[i]>0) {
	retval.push_back(n_base+i);
      }
    }
    return retval;
  }

  std::vector<Index> MetadataMeasurement::GetNmpcState(Index state_number)
  {
    DBG_START_METH("MetadataMeasurement::GetNmpcState", dbg_verbosity);
    
    std::string state      = "nmpc_state_";
    append_Index(state, state_number);

    const std::vector<Index> idx_ipopt = x_owner_space_->GetIntegerMetaData(state.c_str());

    std::vector<Index> retval = idx_ipopt;
    /*
      for (Index i=0; i<idx_ipopt.size(); ++i) {
      if (idx_ipopt[i]>0) {
      retval.push_back(i);
      }
      }
    */
    return retval;
  }

  SmartPtr<DenseVector> MetadataMeasurement::GetMeasurement(Index measurement_number)
  {
    DBG_START_METH("MetadataMeasurement::GetMeasurement", dbg_verbosity);

    DBG_ASSERT(measurement_number>0 && measurement_number<7);

    std::string state;
    std::string statevalue;
      
    state      = "nmpc_state_";
    statevalue = "nmpc_state_value_";
    append_Index(state,measurement_number);
    append_Index(statevalue,measurement_number);

    const std::vector<Index> idx_ipopt = x_owner_space_->GetIntegerMetaData(state.c_str());
    const std::vector<Number> val_ipopt = x_owner_space_->GetNumericMetaData(statevalue.c_str());

    SmartPtr<DenseVectorSpace> delta_u_space;
    if (select_step_=="advanced" || select_step_=="ift") {
      delta_u_space = new DenseVectorSpace(2*n_idx_);
    }
    else if (select_step_=="sensitivity" || select_step_=="iftsensitivity") {
      delta_u_space = new DenseVectorSpace(n_idx_);
    }

    SmartPtr<DenseVector> delta_u = new DenseVector(GetRawPtr(ConstPtr(delta_u_space)));
    Number* du_val = delta_u->Values();

    const Number* u_0_val = dynamic_cast<const DenseVector*>(GetRawPtr(IpData().trial()->x()))->Values();

    // Fill up values of delta_u vector
    for (Index i=0; i<val_ipopt.size(); ++i) {
      if (idx_ipopt[i]>0) {
	du_val[idx_ipopt[i]-1] = val_ipopt[i]-u_0_val[i]; //initial_val[idx_ipopt[i]-1];
	//du_val[idx_ipopt[i]-1] = val_ipopt[i];
      }
    }

    if (select_step_=="advanced" || select_step_=="ift") {
      std::vector<Index> constr_ipopt = GetInitialEqConstraints();
      SmartPtr<const IteratesVector> it = IpData().curr();
      Index n_base = it->x()->Dim() + it->s()->Dim();

      const Number* u_0_lambda = dynamic_cast<const DenseVector*>(GetRawPtr(IpData().trial()->y_c()))->Values();
    
      Index ind_it = constr_ipopt.size();
      for (std::vector<Index>::iterator it=constr_ipopt.begin(); it!=constr_ipopt.end(); ++it) {
	DBG_PRINT((dbg_verbosity,"constr-nr. %d : %f\n", *it-n_base,-u_0_lambda[*it-n_base]));
	du_val[ind_it++] = -u_0_lambda[*it-n_base];
      }
    }
    
    delta_u->SetValues(du_val);
    
    return delta_u;
  }

  void MetadataMeasurement::SetSolution(Index measurement_number, SmartPtr<IteratesVector> sol)
  {
    DBG_START_METH("MetadataMeasurement::SetSolution", dbg_verbosity);

    std::string nmpc_sol = "nmpc_sol_state_";
    append_Index(nmpc_sol, measurement_number);

    const Number* sol_x_val = dynamic_cast<const DenseVector*>(GetRawPtr(sol->x()))->Values();
    std::vector<Number> x_sol = std::vector<Number>(sol_x_val, sol_x_val+sol->x()->Dim());
    SmartPtr<DenseVectorSpace> x_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(x_owner_space_));
    x_owner_space_nonconst->SetNumericMetaData(nmpc_sol, x_sol);
    
    SmartPtr<const DenseVector> s_dv = dynamic_cast<const DenseVector*>(GetRawPtr(sol->s()));
    if (IsValid(s_dv)) {
      const Number* sol_s_val = s_dv->Values();
      std::vector<Number> s_sol = std::vector<Number>(sol_s_val, sol_s_val+sol->s()->Dim());
      SmartPtr<DenseVectorSpace> s_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(s_owner_space_));
      s_owner_space_nonconst->SetNumericMetaData(nmpc_sol, s_sol);
    }
    
    const Number* sol_y_c_val = dynamic_cast<const DenseVector*>(GetRawPtr(sol->y_c()))->Values();
    std::vector<Number> y_c_sol = std::vector<Number>(sol_y_c_val, sol_y_c_val+sol->y_c()->Dim());
    SmartPtr<DenseVectorSpace> y_c_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(y_c_owner_space_));
    y_c_owner_space_nonconst->SetNumericMetaData(nmpc_sol, y_c_sol);

    const Number* sol_y_d_val = dynamic_cast<const DenseVector*>(GetRawPtr(sol->y_d()))->Values();
    std::vector<Number> y_d_sol = std::vector<Number>(sol_y_d_val, sol_y_d_val+sol->y_d()->Dim());
    SmartPtr<DenseVectorSpace> y_d_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(y_d_owner_space_));
    y_d_owner_space_nonconst->SetNumericMetaData(nmpc_sol, y_d_sol);
    
    const Number* sol_z_L_val = dynamic_cast<const DenseVector*>(GetRawPtr(sol->z_L()))->Values();
    std::vector<Number> z_L_sol = std::vector<Number>(sol_z_L_val, sol_z_L_val+sol->z_L()->Dim());
    SmartPtr<DenseVectorSpace> z_L_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(z_L_owner_space_));
    z_L_owner_space_nonconst->SetNumericMetaData(nmpc_sol, z_L_sol);

    const Number* sol_z_U_val = dynamic_cast<const DenseVector*>(GetRawPtr(sol->z_U()))->Values();
    std::vector<Number> z_U_sol = std::vector<Number>(sol_z_U_val, sol_z_U_val+sol->z_U()->Dim());
    SmartPtr<DenseVectorSpace> z_U_owner_space_nonconst = const_cast<DenseVectorSpace*>(GetRawPtr(z_U_owner_space_));
    z_U_owner_space_nonconst->SetNumericMetaData(nmpc_sol, z_U_sol);
  }

  std::vector<Index> MetadataMeasurement::GetIntegerSuffix(std::string suffix_string)
  {
    DBG_START_METH("MetadataMeasurement::GetIntegerSuffix", dbg_verbosity);

    const std::vector<Index> idx_ipopt = x_owner_space_->GetIntegerMetaData(suffix_string.c_str());

    std::vector<Index> retval = idx_ipopt;
    
    return retval;    
  }
}
