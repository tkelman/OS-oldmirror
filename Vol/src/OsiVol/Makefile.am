# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 1152 2007-12-28 03:59:07Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOsiVol                                #
########################################################################

# Name of the library compiled in this directory.
coinlibdir = ${libdir}/coin
coinlib_LTLIBRARIES = libOsiVol.la

# List all source files for this library, including headers
libOsiVol_la_SOURCES = \
	OsiVolSolverInterface.cpp OsiVolSolverInterface.hpp \
	OsiVolSolverInterfaceIO.cpp

# This is for libtool (on Windows)
libOsiVol_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows.
# "top_srcdir" refers to the basic directory for the main package that is
# being compiled.
AM_CPPFLAGS = ${COINUTILS_CFLAGS} ${OSI_CFLAGS} \
	-I`$(CYGPATH_W) $(srcdir)/..`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'includedir/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = OsiVolSolverInterface.hpp