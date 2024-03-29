/* $Id$ */
# ifndef CPPAD_DIV_OP_INCLUDED
# define CPPAD_DIV_OP_INCLUDED

/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

CPPAD_BEGIN_NAMESPACE
/*!
\defgroup div_op_hpp div_op.hpp
\{
\file div_op.hpp
Forward and reverse mode calculations for z = x / y.
*/

// --------------------------- Divvv -----------------------------------------
/*!
Compute forward mode Taylor coefficients for result of op = DivvvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where both x and y are variables
and the argument \a parameter is not used.

\copydetails forward_binary_op
*/

template <class Base>
inline void forward_divvv_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );

	// Taylor coefficients corresponding to arguments and result
	Base* x = taylor + arg[0] * nc_taylor;
	Base* y = taylor + arg[1] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;


        // Using CondExp, it can make sense to divide by zero,
        // so do not make it an error.
	size_t k;
	z[d] = x[d];
	for(k = 1; k <= d; k++)
		z[d] -= z[d-k] * y[k];
	z[d] /= y[0];
}


/*!
Compute zero order forward mode Taylor coefficients for result of op = DivvvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where both x and y are variables
and the argument \a parameter is not used.

\copydetails forward_binary_op_0
*/

template <class Base>
inline void forward_divvv_op_0(
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );

	// Taylor coefficients corresponding to arguments and result
	Base* x = taylor + arg[0] * nc_taylor;
	Base* y = taylor + arg[1] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;

	z[0] = x[0] / y[0];
}

/*!
Compute reverse mode partial derivatives for result of op = DivvvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where both x and y are variables
and the argument \a parameter is not used.

\copydetails reverse_binary_op
*/

template <class Base>
inline void reverse_divvv_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	const Base*   taylor      ,
	size_t        nc_partial  ,
	Base*         partial     )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );
	CPPAD_ASSERT_UNKNOWN( d < nc_partial );

	// Arguments
	const Base* y  = taylor + arg[1] * nc_taylor;
	const Base* z  = taylor + i_z    * nc_taylor;

	// Partial derivatives corresponding to arguments and result
	Base* px = partial + arg[0] * nc_partial;
	Base* py = partial + arg[1] * nc_partial;
	Base* pz = partial + i_z    * nc_partial;

	// Using CondExp, it can make sense to divide by zero
	// so do not make it an error.

	size_t k;
	// number of indices to access
	size_t j = d + 1;
	while(j)
	{	--j;
		// scale partial w.r.t. z[j]
		pz[j] /= y[0];

		px[j] += pz[j];
		for(k = 1; k <= j; k++)
		{	pz[j-k] -= pz[j] * y[k];
			py[k]   -= pz[j] * z[j-k];
		}	
		py[0] -= pz[j] * z[j];
	}
}

// --------------------------- Divpv -----------------------------------------
/*!
Compute forward mode Taylor coefficients for result of op = DivpvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a parameter and y is a variable.

\copydetails forward_binary_op
*/

template <class Base>
inline void forward_divpv_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivpvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivpvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );

	// Taylor coefficients corresponding to arguments and result
	Base* y = taylor + arg[1] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;

	// Paraemter value
	Base x = parameter[ arg[0] ];

        // Using CondExp, it can make sense to divide by zero,
        // so do not make it an error.
        size_t k;
# if USE_CPPAD_FORWARD0SWEEP
	z[d] = Base(0);
# else
	if( d == 0 )
		z[d] = x;
	else	z[d] = Base(0);
# endif
	for(k = 1; k <= d; k++)
		z[d] -= z[d-k] * y[k];
	z[d] /= y[0];

}

/*!
Compute zero order forward mode Taylor coefficient for result of op = DivpvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a parameter and y is a variable.

\copydetails forward_binary_op_0
*/

template <class Base>
inline void forward_divpv_op_0(
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivpvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivpvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );

	// Paraemter value
	Base x = parameter[ arg[0] ];

	// Taylor coefficients corresponding to arguments and result
	Base* y = taylor + arg[1] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;

	z[0] = x / y[0];
}

/*!
Compute reverse mode partial derivative for result of op = DivpvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a parameter and y is a variable.

\copydetails reverse_binary_op
*/

template <class Base>
inline void reverse_divpv_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	const Base*   taylor      ,
	size_t        nc_partial  ,
	Base*         partial     )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvvOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvvOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[1]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );
	CPPAD_ASSERT_UNKNOWN( d < nc_partial );

	// Arguments
	const Base* y = taylor + arg[1] * nc_taylor;
	const Base* z = taylor + i_z    * nc_taylor;

	// Partial derivatives corresponding to arguments and result
	Base* py = partial + arg[1] * nc_partial;
	Base* pz = partial + i_z    * nc_partial;

	// Using CondExp, it can make sense to divide by zero so do not
	// make it an error.

	size_t k;
	// number of indices to access
	size_t j = d + 1;
	while(j)
	{	--j;
		// scale partial w.r.t z[j]
		pz[j] /= y[0];

		for(k = 1; k <= j; k++)
		{	pz[j-k] -= pz[j] * y[k];
			py[k]   -= pz[j] * z[j-k];
		}	
		py[0] -= pz[j] * z[j];
	}
}


// --------------------------- Divvp -----------------------------------------
/*!
Compute forward mode Taylor coefficients for result of op = DivvvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a variable and y is a parameter.

\copydetails forward_binary_op
*/

template <class Base>
inline void forward_divvp_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvpOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvpOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );

	// Taylor coefficients corresponding to arguments and result
	Base* x = taylor + arg[0] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;

	// Parameter value
	Base y = parameter[ arg[1] ];

	// Using CondExp and multiple levels of AD, it can make sense 
	// to divide by zero so do not make it an error.
	z[d] = x[d] / y;
}


/*!
Compute zero order forward mode Taylor coefficients for result of op = DivvvOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a variable and y is a parameter.

\copydetails forward_binary_op_0
*/

template <class Base>
inline void forward_divvp_op_0(
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	Base*         taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvpOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvpOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );

	// Parameter value
	Base y = parameter[ arg[1] ];

	// Taylor coefficients corresponding to arguments and result
	Base* x = taylor + arg[0] * nc_taylor;
	Base* z = taylor + i_z    * nc_taylor;

	z[0] = x[0] / y;
}

/*!
Compute reverse mode partial derivative for result of op = DivvpOp.

The C++ source code corresponding to this operation is
\verbatim
	z = x / y
\endverbatim
In the documentation below,
this operations is for the case where x is a variable and y is a parameter.

\copydetails reverse_binary_op
*/

template <class Base>
inline void reverse_divvp_op(
	size_t        d           , 
	size_t        i_z         ,
	const addr_t* arg         ,
	const Base*   parameter   ,
	size_t        nc_taylor   ,
	const Base*   taylor      ,
	size_t        nc_partial  ,
	Base*         partial     )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(DivvpOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( NumRes(DivvpOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );
	CPPAD_ASSERT_UNKNOWN( d < nc_partial );

	// Argument values
	Base  y = parameter[ arg[1] ];

	// Partial derivatives corresponding to arguments and result
	Base* px = partial + arg[0] * nc_partial;
	Base* pz = partial + i_z    * nc_partial;

	// Using CondExp, it can make sense to divide by zero
	// so do not make it an error.

	// number of indices to access
	size_t j = d + 1;
	while(j)
	{	--j;
		px[j] += pz[j] / y;
	}
}

/*! \} */
CPPAD_END_NAMESPACE
# endif
