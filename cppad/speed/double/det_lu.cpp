/* $Id$ */
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
/*
$begin double_det_lu.cpp$$
$spell
	bool
	cppad
	hpp
	Lu
	det
	CppAD
$$

$section Double Speed: Determinant Using Lu Factorization$$

$index link_det_lu, double$$
$index double, link_det_lu$$
$index speed, double$$
$index double, speed$$
$index lu, speed double$$
$index matrix, factor speed double$$
$index factor, matrix speed double$$

$head Specifications$$
See $cref link_det_lu$$.

$head Implementation$$
$codep */
# include <cppad/vector.hpp>
# include <cppad/speed/det_by_lu.hpp>
# include <cppad/speed/uniform_01.hpp>

bool link_det_lu(
	size_t                           size     , 
	size_t                           repeat   , 
	CppAD::vector<double>           &matrix   ,
	CppAD::vector<double>           &det      )
{
	// -----------------------------------------------------
	// setup
	CppAD::det_by_lu<double>  Det(size);
	size_t n = size * size; // number of independent variables
	
	// ------------------------------------------------------

	while(repeat--)
	{	// get the next matrix
		CppAD::uniform_01(n, matrix);

		// computation of the determinant
		det[0] = Det(matrix);
	}
	return true;
}
/* $$
$end
*/
