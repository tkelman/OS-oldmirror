// $Id$
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

/*
$begin reciprocal.cpp$$
$spell
	Tanh
$$

$section Reciprocal as a User Atomic Operation: Example and Test$$

$index reciprocal, user_atomic$$
$index user, atomic reciprocal$$
$index atomic, reciprocal$$
$index test, user_atomic$$
$index user_atomic, example$$
$index example, user_atomic$$

$head Theory$$
The example below defines the user atomic function 
$latex f : \B{R}^n \rightarrow \B{R}^m$$ where
$latex n = 1$$, $latex m = 1$$, and $latex f(x) = 1 / x$$.

$code
$verbatim%example/reciprocal.cpp%0%// BEGIN C++%// END C++%1%$$
$$

$end
*/
// BEGIN C++
# include <cppad/cppad.hpp>

namespace { // Begin empty namespace 
	using CppAD::vector;
	// ----------------------------------------------------------------------
	// a utility to compute the union of two sets.
	void my_union(
		std::set<size_t>&         result  ,
		const std::set<size_t>&   left    ,
		const std::set<size_t>&   right   )
	{	std::set<size_t> temp;
		std::set_union(
			left.begin()              ,
			left.end()                ,
			right.begin()             ,
			right.end()               ,
			std::inserter(temp, temp.begin())
		);
		result.swap(temp);
	}

	// ----------------------------------------------------------------------
	// forward mode routine called by CppAD
	bool reciprocal_forward(
		size_t                   id ,
		size_t                    k ,
		size_t                    n ,
		size_t                    m ,
		const vector<bool>&      vx ,
		vector<bool>&            vy ,
		const vector<double>&    tx ,
		vector<double>&          ty
	)
	{	assert( id == 0 );
		assert( n == 1 );
		assert( m == 1 );
		assert( k == 0 || vx.size() == 0 );
		bool ok = false;	
		double f, fp, fpp;

		// Must always define the case k = 0.
		// Do not need case k if not using f.Forward(p, xp) for p >= k.
		switch(k)
		{	case 0:
			// this case must  be implemented
			if( vx.size() > 0 )
				vy[0] = vx[0];
			// y^0 = f( x^0 ) = 1 / x^0
			ty[0] = 1. / tx[0];
			ok    = true;
			break;

			case 1:
			// needed if first order forward mode is used
			assert( vx.size() == 0 );
			// y^1 = f'( x^0 ) x^1
			f     = ty[0];
			fp    = - f / tx[0];
			ty[1] = fp * tx[1]; 
			ok    = true;
			break;

			case 2:
			// needed if second order forward mode is used
			assert( vx.size() == 0 );
			// Y''(t) = X'(t)^\R{T} f''[X(t)] X'(t) + f'[X(t)] X''(t)
			// 2 y^2  = x^1 * f''( x^0 ) x^1 + 2 f'( x^0 ) x^2
			f     = ty[0];
			fp    = - f / tx[0];
			fpp   = - 2.0 * fp / tx[0];
			ty[2] = tx[1] * fpp * tx[1] / 2.0 + fp * tx[2];
			ok    = true;
			break;
		}
		return ok;
	}
	// ----------------------------------------------------------------------
	// reverse mode routine called by CppAD
	bool reciprocal_reverse(
		size_t                   id ,
		size_t                    k ,
		size_t                    n ,
		size_t                    m ,
		const vector<double>&    tx ,
		const vector<double>&    ty ,
		vector<double>&          px ,
		const vector<double>&    py
	)
	{	// Do not need case k if not using f.Reverse(k+1, w).
		assert( id == 0 );
		assert( n == 1 );
		assert( m == 1 );
		bool ok = false;	

		double f, fp, fpp, fppp;
		switch(k)
		{	case 0:
			// needed if first order reverse mode is used
			// reverse: F^0 ( tx ) = y^0 = f( x^0 )
			f     = ty[0];
			fp    = - f / tx[0];
			px[0] = py[0] * fp;;
			ok    = true;
			break;

			case 1:
			// needed if second order reverse mode is used
			// reverse: F^1 ( tx ) = y^1 = f'( x^0 ) x^1
			f      = ty[0];
			fp     = - f / tx[0];
			fpp    = - 2.0 * fp / tx[0];
			px[1]  = py[1] * fp;
			px[0]  = py[1] * fpp * tx[1];
			// reverse: F^0 ( tx ) = y^0 = f( x^0 );
			px[0] += py[0] * fp;

			ok     = true;
			break;

			case 2:
			// needed if third order reverse mode is used
			// reverse: F^2 ( tx ) = y^2 =
			//            = x^1 * f''( x^0 ) x^1 / 2 + f'( x^0 ) x^2
			f      = ty[0];
			fp     = - f / tx[0];
			fpp    = - 2.0 * fp / tx[0];
			fppp   = - 3.0 * fpp / tx[0];
			px[2]  = py[2] * fp;
			px[1]  = py[2] * fpp * tx[1];
			px[0]  = py[2] * tx[1] * fppp * tx[1] / 2.0 + fpp * tx[2]; 
			// reverse: F^1 ( tx ) = y^1 = f'( x^0 ) x^1
			px[1] += py[1] * fp;
			px[0] += py[1] * fpp * tx[1];
			// reverse: F^0 ( tx ) = y^0 = f( x^0 );
			px[0] += py[0] * fp;

			ok = true;
			break;
		}
		return ok;
	}
	// ----------------------------------------------------------------------
	// forward Jacobian sparsity routine called by CppAD
	bool reciprocal_for_jac_sparse(
		size_t                               id ,             
		size_t                                n ,
		size_t                                m ,
		size_t                                q ,
		const vector< std::set<size_t> >&     r ,
		vector< std::set<size_t> >&           s )
	{	// Can just return false if not using f.ForSparseJac
		assert( id == 0 );
		assert( n == 1 );
		assert( m == 1 );

		// sparsity for S(x) = f'(x) * R is same as sparsity for R
		s[0] = r[0];

		return true; 
	}
	// ----------------------------------------------------------------------
	// reverse Jacobian sparsity routine called by CppAD
	bool reciprocal_rev_jac_sparse(
		size_t                               id ,             
		size_t                                n ,
		size_t                                m ,
		size_t                                q ,
		vector< std::set<size_t> >&           r ,
		const vector< std::set<size_t> >&     s )
	{	// Can just return false if not using RevSparseJac.
		assert( id == 0 );
		assert( n == 1 );
		assert( m == 1 );

		// sparsity for R(x) = S * f'(x) is same as sparsity for S
		r[0] = s[0];

		return true; 
	}
	// ----------------------------------------------------------------------
	// reverse Hessian sparsity routine called by CppAD
	bool reciprocal_rev_hes_sparse(
		size_t                               id ,             
		size_t                                n ,
		size_t                                m ,
		size_t                                q ,
		const vector< std::set<size_t> >&     r ,
		const vector<bool>&                   s ,
		vector<bool>&                         t ,
		const vector< std::set<size_t> >&     u ,
		vector< std::set<size_t> >&           v )
	{	// Can just return false if not use RevSparseHes.
		assert( id == 0 );
		assert( n == 1 );
		assert( m == 1 );

		// sparsity for T(x) = S(x) * f'(x) is same as sparsity for S
		t[0] = s[0];
	
		// V(x) = [ f'(x)^T * g''(y) * f'(x) + g'(y) * f''(x) ] * R 
		// U(x) = g''(y) * f'(x) * R
		// S(x) = g'(y)
		
		// back propagate the sparsity for U because derivative of
		// reciprocal may be non-zero
		v[0] = u[0]; 

		// convert forward Jacobian sparsity to Hessian sparsity
		// because second derivative of reciprocal may be non-zero
		if( s[0] )
			my_union(v[0], v[0], r[0] );


		return false;
	}
	// ---------------------------------------------------------------------
	// Declare the AD<double> routine reciprocal(id, ax, ay)
	CPPAD_USER_ATOMIC(
		reciprocal                 , 
		CppAD::vector              ,
		double                     , 
		reciprocal_forward         , 
		reciprocal_reverse         ,
		reciprocal_for_jac_sparse  ,
		reciprocal_rev_jac_sparse  ,
		reciprocal_rev_hes_sparse  
	)
} // End empty namespace

bool reciprocal(void)
{	bool ok = true;
	using CppAD::AD;
	using CppAD::NearEqual;
	double eps = 10. * CppAD::numeric_limits<double>::epsilon();

	// --------------------------------------------------------------------
	// Create the function f(x)
	//
	// domain space vector
	size_t n  = 1;
	double  x0 = 0.5;
	vector< AD<double> > ax(n);
	ax[0]     = x0;

	// declare independent variables and start tape recording
	CppAD::Independent(ax);

	// range space vector 
	size_t m = 1;
	vector< AD<double> > ay(m);

	// call user function and store reciprocal(x) in au[0] 
	vector< AD<double> > au(m);
	size_t id = 0;           // not used
	reciprocal(id, ax, au);	// u = 1 / x

	// call user function and store reciprocal(u) in ay[0] 
	reciprocal(id, au, ay);	// y = 1 / u = x

	// create f: x -> y and stop tape recording
	CppAD::ADFun<double> f(ax, ay);  // f(x) = x

	// --------------------------------------------------------------------
	// Check forward mode results
	//
	// check function value 
	double check = x0;
	ok &= NearEqual( Value(ay[0]) , check,  eps, eps);

	// check first order forward mode
	size_t p;
	vector<double> x_p(n), y_p(m);
	p      = 1;
	x_p[0] = 1;
	y_p    = f.Forward(p, x_p);
	check  = 1.;
	ok &= NearEqual(y_p[0] , check,  eps, eps);

	// check second order forward mode
	p      = 2;
	x_p[0] = 0;
	y_p    = f.Forward(p, x_p);
	check  = 0.;
	ok &= NearEqual(y_p[0] , check,  eps, eps);

	// --------------------------------------------------------------------
	// Check reverse mode results
	//
	// third order reverse mode 
	p     = 3;
	vector<double> w(m), dw(n * p);
	w[0]  = 1.;
	dw    = f.Reverse(p, w);
	check = 1.;
	ok &= NearEqual(dw[0] , check,  eps, eps);
	check = 0.;
	ok &= NearEqual(dw[1] , check,  eps, eps);
	ok &= NearEqual(dw[2] , check,  eps, eps);

	// --------------------------------------------------------------------
	// forward mode sparstiy pattern
	size_t q = n;
	CppAD::vectorBool r1(n * q), s1(m * q);
	r1[0] = true;          // compute sparsity pattern for x[0]
	s1    = f.ForSparseJac(q, r1);
	ok  &= s1[0] == true;  // f[0] depends on x[0]  

	// --------------------------------------------------------------------
	// reverse mode sparstiy pattern
	p = m;
	CppAD::vectorBool s2(p * m), r2(p * n);
	s2[0] = true;          // compute sparsity pattern for f[0]
	r2    = f.RevSparseJac(p, s2);
	ok  &= r2[0] == true;  // f[0] depends on x[0]  

	// --------------------------------------------------------------------
	// Hessian sparsity (using previous ForSparseJac call) 
	CppAD::vectorBool s3(m), h(q * n);
	s3[0] = true;        // compute sparsity pattern for f[0]
	h     = f.RevSparseJac(q, s3);
	ok  &= h[0] == true; // second partial of f[0] w.r.t. x[0] may be non-zero

	// -----------------------------------------------------------------
	// Free all temporary work space associated with user_atomic objects. 
	// (If there are future calls to user atomic functions, they will 
	// create new temporary work space.)
	CppAD::user_atomic<double>::clear();

	return ok;
}
// END C++
