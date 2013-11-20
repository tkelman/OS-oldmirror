# ! /bin/bash
# -----------------------------------------------------------------------------
# CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-08 Bradley M. Bell
#
# CppAD is distributed under multiple licenses. This distribution is under
# the terms of the 
#                     Common Public License Version 1.0.
#
# A copy of this license is included in the COPYING file of this distribution.
# Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
# -----------------------------------------------------------------------------
#
svn status | \
sed                                                           \
	-e '/^[?].*\.[0-9]*$/d'                               \
	-e '/^[?].*\.tmp$/d'                                  \
	-e '/^[?].*\.out$/d'                                  \
	-e '/^[?].*\.gz$/d'                                   \
	-e '/^[?].*\.tgz$/d'                                  \
	-e '/^[?].*\.zip$/d'                                  \
	-e '/^[?].*\.swp$/d'                                  \
	-e '/^[?].*\.cache$/d'                                \
	-e '/^[?].*\.exe$/d'                                  \
	-e '/^[?].*\.ncb$/d'                                  \
	-e '/^[?].*\.suo$/d'                                  \
	-e '/^[?].*\.deps$/d'                                 \
	-e '/^[?].*\.a$/d'                                    \
	-e '/^[?].*\.log$/d'                                  \
	-e '/^[?].*\.stackdump$/d'                            \
	-e '/^[?].*\/test_one.cpp$/d'                         \
	-e '/^[?].*\/Debug$/d'                                \
	-e '/^[?].*\/Release$/d'                              \
	-e '/^[?].*\/stamp-h1$/d'                             \
	-e '/^[?].*\/makefile$/d'                             \
	-e '/^[?].*\/_adolc-*/d'                              \
	-e '/^[?] *makefile$/d'                               \
	-e '/^[?].*\/junk$/d'                                 \
	-e '/^[?] *junk$/d'                                   \
	-e '/^[?].*\/junk\.[0-9a-zA-Z]*$/d'                   \
	-e '/^[?] *junk\.[0-9a-zA-Z]*$/d'                     \
	-e '/^[?] *dev$/d'                                    \
	-e '/^[?] *config.status$/d'                          \
	-e '/^[?] *doc$/d'                                    \
	-e '/^[?] *dev$/d'                                    \
	-e '/^[?] *aclocal.m4$/d'                             \
	-e '/^[?] *cppad-[0-9]\{8\}.*$/d'                     \
	-e '/^[?] *omh\/install_unix.omh$/d'                  \
	-e '/^[?] *omh\/install_windows.omh$/d'               \
	-e '/cygwin_package$/d'
#
