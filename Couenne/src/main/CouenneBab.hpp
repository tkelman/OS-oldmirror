/* $Id$
 *
 * Name:    CouenneBab.hpp
 * Author:  Pietro Belotti
 * Purpose: B&B object  
 * Created: 2012-01-25
 *
 * This file is licensed under the Eclipse Public License (EPL)
 */

#ifndef COUENNEBAB_H
#define COUENNEBAB_H

#include "BonCbc.hpp"

#include "BonBabSetupBase.hpp"
//#include "CbcModel.hpp"

namespace Couenne {

  //class BabSetupBase;

  class CouenneProblem;

  class CouenneBab: public Bonmin::Bab {

  public:

    // /** Integer optimization return codes.*/
    // enum MipStatuses {FeasibleOptimal /** Optimum solution has been found and its optimality proved.*/,
    // 		      ProvenInfeasible /** Problem has been proven to be infeasible.*/,
    // 		      Feasible /** An integer solution to the problem has been found.*/,
    // 		      UnboundedOrInfeasible /*Coninuous relaxation is unbounded.*/,
    // 		      NoSolutionKnown/** No feasible solution to the problem is known*/,
    // 		      NumMipStats};

    CouenneBab (); ///< Constructor

    virtual ~CouenneBab(); ///< Destructor

    void setProblem (CouenneProblem *p);

    virtual void branchAndBound (Bonmin::BabSetupBase &s); ///< Carry out branch and bound

    // /**operator() performs the branchAndBound*/
    // virtual void operator()(BabSetupBase & s);

    // /**operator() performs the branchAndBound*/
    // virtual void operator()(BabSetupBase * s){
    //   operator()(*s);}

    /** get the best solution known to the problem (is optimal if MipStatus is FeasibleOptimal).
	if no solution is known returns NULL.*/
    const double * bestSolution() const;

    /** return objective value of the bestSolution */
    double bestObj() const;

    // /** return Mip Status */
    // MipStatuses mipStatus() const
    // {
    //   return mipStatus_;
    // }

    /** return the best known lower bound on the objective value*/
    double bestBound() { return CoinMin(Bonmin::Bab::bestBound(), bestObj()); }

    // /** return the total number of nodes explored.*/
    // int numNodes() const
    // {
    //   return numNodes_;
    // }

    // /** return the total number of iterations in the last mip solved.*/
    // int iterationCount()
    // {
    //   return mipIterationCount_;
    // }

    // /** returns the value of the continuous relaxation. */
    // double continuousRelaxation()
    // {
    //   return continuousRelaxation_;
    // }

    // /** virtual callback function to eventually modify objects for integer variable
    // 	(replace with user set). This is called after CbcModel::findIntegers */
    // virtual void replaceIntegers(OsiObject ** objects, int numberObjects)
    // {}

    // /** Get cbc model used to solve. */
    // const CbcModel&  model() const
    // {
    //   return model_;
    // }

    // /** Get cbc model used to solve as non-const, in case we want to
    //     change options before things happen */
    // CbcModel&  model()
    // {
    //   return model_;
    // }

    // /** Say that algorithm is using Couenne.*/
    // void setUsingCouenne(bool v)
    // {
    //   usingCouenne_ = v;
    // }

    // /** Get value of usingCouenne variable.*/
    // bool getUsingCouenne()
    // {
    //   return usingCouenne_;
    // }

  protected:

    CouenneProblem *problem_;

    // /** Stores the solution of MIP. */
    // double * bestSolution_;

    // /** Status of the mip solved*/
    // MipStatuses mipStatus_;

    // /** objValue of MIP */
    // double bestObj_;

    // /** best known (lower) bound.*/
    // double bestBound_;

    // /** Continuous relaxation of the problem */
    // double continuousRelaxation_;

    // /** Number of nodes enumerated.*/
    // int numNodes_;

    // /** get total number of iterations in last mip solved.*/
    // int mipIterationCount_;

    // /** CbcModel used to solve problem.*/
    // CbcModel model_;

    // /** Message handler for CbcModel. */
    // CoinMessageHandler * modelHandler_;

    // /** \brief OsiObjects of the model.
    //  * this is not null if and only if there are some non-simple-integer branching objects such as SOS constraints.
    //  * It is up to CouenneBab to pass them over to appropriate components of the algorithm. */
    // OsiObject** objects_;

    // /** number of objects.*/
    // int nObjects_;

    // /** Say if current algorithm is Couenne.*/
    // bool usingCouenne_;
  };
}

#endif
