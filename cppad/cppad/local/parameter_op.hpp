/* $Id$ */
# ifndef CPPAD_PARAMETER_OP_INCLUDED
# define CPPAD_PARAMETER_OP_INCLUDED

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
\defgroup parameter_op_hpp parameter_op.hpp
\{
\file parameter_op.hpp
Zero order forward mode for ParOp
*/


/*!
Compute zero order forward mode Taylor coefficient for result of op = ParOp.

The C++ source code corresponding to this operation is one of the following
\verbatim
	ADFun<Base> f(x, y)
	f.Dependent(x, y)
\endverbatim
where some of the components of the vector y are parameters.

\tparam Base
base type for the operator; i.e., this operation was recorded
using AD< \a Base > and computations by this routine are done using type 
\a Base .

\param i_z
variable index corresponding to the result for this operation; 
i.e. the row index in \a taylor corresponding to the component of y
that is a parameter. 

\param arg
\a arg[0]
\n
index corresponding to the parameter value for this operator.

\param num_par
is the number of parameters in \a parameter.

\param parameter
\b Input: \a parameter[ \a arg[0] ] is the value of a component
of y that is a parameter. 

\param nc_taylor
number of colums in the matrix containing all the Taylor coefficients.

\param taylor
\b Output: \a taylor [ \a i_z * \a nc_taylor + 0 ] 
is the zero order Taylor coefficient corresponding to z. 

\par Checked Assertions where op is the unary operator with one result:
\li NumArg(op) == 1
\li NumRes(op) == 1
\li \a size_t(arg[0]) < num_par 
\li \a 0 < \a nc_taylor
*/
template <class Base>
inline void forward_par_op_0(
	size_t        i_z         ,
	const addr_t* arg         ,
	size_t        num_par     ,
	const Base*   parameter   ,
	size_t        nc_taylor   , 
	Base*         taylor      )
{	
	// check assumptions
	CPPAD_ASSERT_UNKNOWN( NumArg(ParOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( NumRes(ParOp) == 1 );
	CPPAD_ASSERT_UNKNOWN( size_t(arg[0]) < num_par );
	CPPAD_ASSERT_UNKNOWN( 0 < nc_taylor );

	Base* z = taylor + i_z * nc_taylor;

	z[0]  = parameter[ arg[0] ];
}

/*! \} */
CPPAD_END_NAMESPACE
# endif
