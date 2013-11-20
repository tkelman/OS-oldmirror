/* $Id$ */
# ifndef CPPAD_COSH_OP_INCLUDED
# define CPPAD_COSH_OP_INCLUDED

/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-10 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */


CPPAD_BEGIN_NAMESPACE
/*!
\file cosh_op.hpp
Forward and reverse mode calculations for z = cosh(x).
*/


/*!
Compute forward mode Taylor coefficient for result of op = CoshOp.

The C++ source code corresponding to this operation is
\verbatim
	z = cosh(x)
\endverbatim
The auxillary result is
\verbatim
	y = sinh(x)
\endverbatim
The value of y, and its derivatives, are computed along with the value
and derivatives of z.

\copydetails forward_unary2_op
*/
template <class Base>
inline void forward_cosh_op(
	size_t j           ,
	size_t i_z         ,
	size_t i_x         ,
	size_t nc_taylor   , 
	Base*  taylor      )
{	
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(CoshOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( NumRes(CoshOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( i_x + 1 < i_z );
	CPPAD_ASSERT_UNKNOWN( j < nc_taylor );

	// Taylor coefficients corresponding to argument and result
	Base* x = taylor + i_x * nc_taylor;
	Base* c = taylor + i_z * nc_taylor;
	Base* s = c      -       nc_taylor;

	// rest of this routine is identical for the following cases:
	// forward_sin_op, forward_cos_op, forward_sinh_op, forward_cosh_op.
	size_t k;
	if( j == 0 )
	{	s[j] = sinh( x[0] );
		c[j] = cosh( x[0] );
	}
	else
	{
		s[j] = Base(0);
		c[j] = Base(0);
		for(k = 1; k <= j; k++)
		{	s[j] += Base(k) * x[k] * c[j-k];
			c[j] += Base(k) * x[k] * s[j-k];
		}
		s[j] /= Base(j);
		c[j] /= Base(j);
	}
}

/*!
Compute zero order forward mode Taylor coefficient for result of op = CoshOp.

The C++ source code corresponding to this operation is
\verbatim
	z = cosh(x)
\endverbatim
The auxillary result is
\verbatim
	y = sinh(x)
\endverbatim
The value of y is computed along with the value of z.

\copydetails forward_unary2_op_0
*/
template <class Base>
inline void forward_cosh_op_0(
	size_t i_z         ,
	size_t i_x         ,
	size_t nc_taylor   , 
	Base*  taylor      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(CoshOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( NumRes(CoshOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( i_x + 1 < i_z );
	CPPAD_ASSERT_UNKNOWN( 0 < nc_taylor );

	// Taylor coefficients corresponding to argument and result
	Base* x = taylor + i_x * nc_taylor;
	Base* c = taylor + i_z * nc_taylor;  // called z in documentation
	Base* s = c      -       nc_taylor;  // called y in documentation

	c[0] = cosh( x[0] );
	s[0] = sinh( x[0] );
}
/*!
Compute reverse mode partial derivatives for result of op = CoshOp.

The C++ source code corresponding to this operation is
\verbatim
	z = cosh(x)
\endverbatim
The auxillary result is
\verbatim
	y = sinh(x)
\endverbatim
The value of y is computed along with the value of z.

\copydetails reverse_unary2_op
*/

template <class Base>
inline void reverse_cosh_op(
	size_t      d            ,
	size_t      i_z          ,
	size_t      i_x          ,
	size_t      nc_taylor    , 
	const Base* taylor       ,
	size_t      nc_partial   ,
	Base*       partial      )
{
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(CoshOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( NumRes(CoshOp) == 2 );
	CPPAD_ASSERT_UNKNOWN( i_x + 1 < i_z );
	CPPAD_ASSERT_UNKNOWN( d < nc_taylor );
	CPPAD_ASSERT_UNKNOWN( d < nc_partial );

	// Taylor coefficients and partials corresponding to argument
	const Base* x  = taylor  + i_x * nc_taylor;
	Base* px       = partial + i_x * nc_partial;

	// Taylor coefficients and partials corresponding to first result
	const Base* c  = taylor  + i_z * nc_taylor; // called z in doc
	Base* pc       = partial + i_z * nc_partial;

	// Taylor coefficients and partials corresponding to auxillary result
	const Base* s  = c  - nc_taylor; // called y in documentation
	Base* ps       = pc - nc_partial;

	// rest of this routine is identical for the following cases:
	// reverse_sin_op, reverse_cos_op, reverse_sinh_op, reverse_cosh_op.
	size_t j = d;
	size_t k;
	while(j)
	{
		ps[j]   /= Base(j);
		pc[j]   /= Base(j);
		for(k = 1; k <= j; k++)
		{
			px[k]   += ps[j] * Base(k) * c[j-k];
			px[k]   += pc[j] * Base(k) * s[j-k];
	
			ps[j-k] += pc[j] * Base(k) * x[k];
			pc[j-k] += ps[j] * Base(k) * x[k];

		}
		--j;
	}
	px[0] += ps[0] * c[0];
	px[0] += pc[0] * s[0];
}

CPPAD_END_NAMESPACE
# endif
