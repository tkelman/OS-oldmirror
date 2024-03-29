# $Id$
# -----------------------------------------------------------------------------
# CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell
#
# CppAD is distributed under multiple licenses. This distribution is under
# the terms of the 
#                     Eclipse Public License Version 1.0.
#
# A copy of this license is included in the COPYING file of this distribution.
# Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
# -----------------------------------------------------------------------------
# Build the multi_thread/openmp directory tests 
# Inherit environment from ../CMakeList.txt

# Specifies build type for this directory. Possible values are 
# empty, Debug, Release, RelWithDebInfo and MinSizeRel
SET(CMAKE_BUILD_TYPE RELEASE)

# Local include directories to search (not in package_prefix/include)
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/.. )

# Cannot find specifications for CMAKE_CXX_FLAGS in version 2.6 documentation
# so using ADD_DEFINITIONS instead.
ADD_DEFINITIONS( ${OpenMP_CXX_FLAGS} )
 
# add_executable(<name> [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL]
#                 source1 source2 ... sourceN
# )
ADD_EXECUTABLE(openmp_test EXCLUDE_FROM_ALL ../thread_test.cpp 
	../multi_newton_time.cpp
	../multi_newton.cpp
	../multi_newton_work.cpp
	../team_example.cpp
	../harmonic_time.cpp
	../harmonic.cpp
	../harmonic_work.cpp
	a11c_openmp.cpp
	simple_ad_openmp.cpp
	team_openmp.cpp
)

# Compiler flags for cppad source
add_cppad_cxx_flags( openmp_test )

# Extra flags used by linker for openmp support
SET(CMAKE_EXE_LINKER_FLAGS ${OpenMP_CXX_FLAGS} )

# Add the check_openmp target
ADD_CUSTOM_TARGET(check_openmp 
	openmp_test simple_ad
	DEPENDS openmp_test
)
