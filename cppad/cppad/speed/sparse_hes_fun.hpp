/* $Id$ */
# ifndef CPPAD_SPARSE_HES_FUN_INCLUDED
# define CPPAD_SPARSE_HES_FUN_INCLUDED

/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
/*
$begin sparse_hes_fun$$
$spell
	hes
	cppad
	hpp
	fp
	CppAD
	namespace
	const
	bool
	exp
	arg
$$

$section Evaluate a Function That Has a Sparse Hessian$$ 

$index sparse_hes_fun, function$$
$index function, sparse_hes_fun$$

$head Syntax$$
$codei%# include <cppad/speed/sparse_hes_fun.hpp>
%$$
$codei%sparse_hes_fun(%n%, %x%, %row%, %col%, %p%, %fp%)%$$

$head Purpose$$
This routine evaluates
$latex f(x)$$, $latex f^{(1)} (x)$$, or $latex f^{(2)} (x)$$
where the Hessian $latex f^{(2)} (x)$$ is sparse.
The function $latex f : \B{R}^n \rightarrow \B{R}$$ only depends on the 
size and contents of the index vectors $icode row$$ and $icode col$$. 
The non-zero entries in the Hessian of this function have 
one of the following forms:
$latex \[
	\DD{f}{x[row[k]]}{x[row[k]]}
	\; , \;
	\DD{f}{x[row[k]]}{x[col[k]]}
	\; , \;
	\DD{f}{x[col[k]]}{x[row[k]]}
	\; , \;
	\DD{f}{x[col[k]]}{x[col[k]]}
\] $$
for some $latex k $$ between zero and $latex K-1 $$.
All the other terms of the Hessian are zero.

$head Inclusion$$
The template function $code sparse_hes_fun$$ 
is defined in the $code CppAD$$ namespace by including 
the file $code cppad/speed/sparse_hes_fun.hpp$$ 
(relative to the CppAD distribution directory).
It is only intended for example and testing purposes, 
so it is not automatically included by
$cref/cppad.hpp/cppad/$$.

$head Float$$
The type $icode Float$$ must be a $cref NumericType$$.
In addition, if $icode y$$ and $icode z$$ are $icode Float$$ objects,
$codei%
	%y% = exp(%z%)
%$$ 
must set the $icode y$$ equal the exponential of $icode z$$, i.e.,
the derivative of $icode y$$ with respect to $icode z$$ is equal to $icode y$$.

$head FloatVector$$
The type $icode FloatVector$$ is any
$cref SimpleVector$$, or it can be a raw pointer, 
with elements of type $icode Float$$.

$head n$$
The argument $icode n$$ has prototype
$icode%
	size_t %n%
%$$
It specifies the dimension for the domain space for $latex f(x)$$.

$head x$$
The argument $icode x$$ has prototype
$codei%
	const %FloatVector%& %x%
%$$
It contains the argument value for which the function,
or its derivative, is being evaluated.
We use $latex n$$ to denote the size of the vector $icode x$$.

$head row$$
The argument $icode row$$ has prototype
$codei%
	 const CppAD::vector<size_t>& %row%
%$$
It specifies one of the first 
index of $latex x$$ for each non-zero Hessian term
(see $cref/purpose/sparse_hes_fun/Purpose/$$ above).
All the elements of $icode row$$ must be between zero and $icode%n%-1%$$.
The value $latex K$$ is defined by $icode%K% = %row%.size()%$$.

$head col$$
The argument $icode col$$ has prototype
$codei%
	 const CppAD::vector<size_t>& %col%
%$$
and its size must be $latex K$$; i.e., the same as for $icode col$$.
It specifies the second 
index of $latex x$$ for the non-zero Hessian terms.
All the elements of $icode col$$ must be between zero and $icode%n%-1%$$.

$head p$$
The argument $icode p$$ has prototype
$icode%
	size_t %p%
%$$
It is between zero and two and
specifies the order of the derivative of $latex f$$
that is being evaluated, i.e., $latex f^{(p)} (x)$$ is evaluated.

$head fp$$
The argument $icode fp$$ has prototype
$icode%
	%FloatVector%& %fp%
%$$
The input value of the elements of $icode fp$$ does not matter.

$subhead Function$$
If $icode p$$ is zero, $icode fp$$ has size one and
$icode%fp%[0]%$$ is the value of $latex f(x)$$.

$subhead Gradient$$
If $icode p$$ is one, $icode fp$$ has size $icode n$$ and 
for $latex j = 0 , \ldots , n-1$$
$latex \[
	\D{f}{x[j]} = fp [ j ]
\] $$

$subhead Hessian$$
If $icode p$$ is two, $icode fp$$ has size $icode%n% * %n%$$ and
for $latex i = 0 , \ldots , n-1$$,
$latex j = 0 , \ldots , n-1$$
$latex \[
	\DD{f}{x[i]}{x[j]} = fp [ i * n + j ]
\] $$

$children%
	speed/example/sparse_hes_fun.cpp%
	omh/sparse_hes_fun.omh
%$$

$head Example$$
The file
$cref sparse_hes_fun.cpp$$
contains an example and test  of $code sparse_hes_fun.hpp$$.
It returns true if it succeeds and false otherwise.

$head Source Code$$
The file 
$cref sparse_hes_fun.hpp$$
contains the source code for this template function.

$end
------------------------------------------------------------------------------
*/
// BEGIN C++
# include <cppad/local/cppad_assert.hpp>
# include <cppad/check_numeric_type.hpp>
# include <cppad/vector.hpp>

// following needed by gcc under fedora 17 so that exp(double) is defined
# include <cppad/base_require.hpp> 

namespace CppAD {
	template <class Float, class FloatVector>
	void sparse_hes_fun(
		size_t                       n    ,
		const FloatVector&           x    ,
		const CppAD::vector<size_t>& row  , 
		const CppAD::vector<size_t>& col  , 
		size_t                       p    ,
		FloatVector&                fp    )
	{
		// check numeric type specifications
		CheckNumericType<Float>();

		// check value of p
		CPPAD_ASSERT_KNOWN(
			p < 3,
			"sparse_hes_fun: p > 2"
		);

		size_t i, j, k;
		size_t size = 1;
		for(k = 0; k < p; k++)
			size *= n;
		for(k = 0; k < size; k++)
			fp[k] = Float(0);

		size_t K = row.size();
		Float t;
		Float dt_i;
		Float dt_j;
		for(k = 0; k < K; k++)
		{	i    = row[k];
			j    = col[k];
			t    = exp( x[i] * x[j] );	
			dt_i = t * x[j];
			dt_j = t * x[i];
			switch(p)
			{
				case 0:
				fp[0] += t;
				break;

				case 1:
				fp[i] += dt_i;
				fp[j] += dt_j;
				break;

				case 2:
				fp[i * n + i] += dt_i * x[j];
				fp[i * n + j] += t + dt_j * x[j];
				//
				fp[j * n + i] += t + dt_i * x[i];
				fp[j * n + j] += dt_j * x[i];
				break;
			}
		}
			
	}
}
// END C++
# endif
