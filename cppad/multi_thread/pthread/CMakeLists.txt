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
# Build the multi_thread/pthread directory tests 
# Inherit environment from ../CMakeList.txt

# Specifies build type for this directory. Possible values are 
# empty, Debug, Release, RelWithDebInfo and MinSizeRel
SET(CMAKE_BUILD_TYPE RELEASE)

# Local include directories to search (not in package_prefix/include)
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/.. )

# add_executable(<name> [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL]
#                 source1 source2 ... sourceN
# )
ADD_EXECUTABLE(pthread_test EXCLUDE_FROM_ALL ../thread_test.cpp 
	../multi_newton_time.cpp
	../multi_newton.cpp
	../multi_newton_work.cpp
	../team_example.cpp
	../harmonic_time.cpp
	../harmonic.cpp
	../harmonic_work.cpp
	a11c_pthread.cpp
	simple_ad_pthread.cpp
	team_pthread.cpp
)

# Compiler flags for cppad source
add_cppad_cxx_flags( pthread_test )

# Paths in which the linker will search for libraries,
# only applies to targets created after it is called
LINK_DIRECTORIES( ${pthread_lib_path} )

# List of libraries to be linked into the specified target
TARGET_LINK_LIBRARIES(pthread_test ${pthread_lib})

# Add the check_pthread target
ADD_CUSTOM_TARGET(check_pthread 
	pthread_test simple_ad 
	DEPENDS pthread_test
)
