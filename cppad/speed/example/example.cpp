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
$begin speed_example.cpp$$
$spell
$$

$index speed, example program$$
$index program, speed example$$
$index example, speed program$$


$section Run the Speed Examples$$

$head Running Tests$$
To build this program and run its correctness tests see $cref cppad_test$$.


$code
$verbatim%speed/example/example.cpp%0%// BEGIN C++%// END C++%1%$$
$$

$end
*/
// BEGIN C++

# include <cppad/cppad.hpp>

// various example routines
extern bool det_of_minor(void);
extern bool det_by_lu(void);
extern bool det_by_minor(void);
extern bool elapsed_seconds(void);
extern bool mat_sum_sq(void);
extern bool ode_evaluate(void);
extern bool sparse_hes_fun(void);
extern bool sparse_jac_fun(void);
extern bool speed_test(void);
extern bool time_test(void);

namespace {
	// function that runs one test
	size_t Run_ok_count    = 0;
	size_t Run_error_count = 0;
	const char* exception_list[] = {
		"elapsed_seconds",
		"speed_test",
		"time_test"
	};
	size_t n_exception = sizeof(exception_list) / sizeof(exception_list[0]);
	bool Run(bool TestOk(void), std::string name)
	{	bool ok               = true;
		std::streamsize width =  20;         
		std::cout.width( width );
		std::cout.setf( std::ios_base::left );
		std::cout << name;
		bool exception = false;
		for(size_t i = 0; i < n_exception; i++)
			exception |= exception_list[i] == name;
		//
		ok &= name.size() < size_t(width);
		ok &= TestOk();
		if( ok )
		{	std::cout << "OK" << std::endl;
			Run_ok_count++;
		}
		else if ( exception )
		{	std::cout << "Error: perhaps too many other programs running";
			std::cout << std::endl;
			// no change to Run_ok_count
			ok = true;
		}
		else
		{	std::cout << "Error" << std::endl;
			Run_error_count++;
		}
		return ok;
	}
}

// main program that runs all the tests
int main(void)
{	bool ok = true;
	using std::cout;
	using std::endl;

	ok &= Run(det_of_minor,          "det_of_minor"   );
	ok &= Run(det_by_minor,         "det_by_minor"    );
	ok &= Run(det_by_lu,               "det_by_lu"    );
	ok &= Run(elapsed_seconds,   "elapsed_seconds"    );
	ok &= Run(mat_sum_sq,             "mat_sum_sq"    );
	ok &= Run(ode_evaluate,         "ode_evaluate"    );
	ok &= Run(sparse_hes_fun,    "sparse_hes_fun"     );
	ok &= Run(sparse_jac_fun,    "sparse_jac_fun"     );
	ok &= Run(speed_test,             "speed_test"    );
	ok &= Run(time_test,               "time_test"    );
	assert( ok || (Run_error_count > 0) );

	// check for memory leak in previous calculations
	if( ! CppAD::thread_alloc::free_all() )
	{	ok = false;
		cout << "Error: memroy leak detected" << endl;
	}

	if( ok )
	{	cout << "All " << int(Run_ok_count) << " tests passed ";
		cout << "(possibly excepting elapsed_seconds).";
	}
	else	cout << int(Run_error_count) << " tests failed.";
	cout << endl;


	return static_cast<int>( ! ok );
}

// END C++
