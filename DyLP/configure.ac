# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

## $Id: configure.ac,v 1.1.2.1 2006/04/19 23:25:12 andreasw Exp $

# Author:  Andreas Waechter            IBM    2006-04-13
# 	   Lou Hafer		       SFU    many mods since then

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_PREREQ(2.59)

AC_INIT([DyLP],[1.9],[coin-dylp@list.coin-or.org])


AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Eclipse Public License.])

AC_REVISION(0.10)

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(src/Dylp/dylp.h)

# Where should everything be installed by default?  Here, we want it
# to be installed directly in 'bin', 'lib', 'include' subdirectories
# of the directory where configure is run.  The default would be
# /usr/local.
AC_PREFIX_DEFAULT([`pwd`])

#############################################################################
#                         Standard build tool stuff                         #
#############################################################################

# Get the system type
AC_CANONICAL_BUILD

# Do a bit of basic setup for configuration
AC_COIN_PROJECTDIR_INIT(DyLP)

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE(DyLP)

# Get the name of the C compiler and appropriate compiler options
AC_COIN_PROG_CC

# Get the name of the C++ compiler and appropriate compiler options
AC_COIN_PROG_CXX

# Initialize automake and libtool
AC_COIN_INIT_AUTO_TOOLS

#############################################################################
#                              COIN components                              #
#############################################################################

# None of these are required to build and test libDylp. All are needed to
# properly test libOsiDylp and to fully link the doxygen documentation.
# (So we should actually not need to search for CoinUtils separately.)

AC_COIN_CHECK_PACKAGE([CoinUtils],[coinutils],[OsiDyLPLib])
AC_COIN_CHECK_PACKAGE([Osi],[osi],[OsiDyLPLib])
AC_COIN_CHECK_PACKAGE([OsiTests],[osi-unittests])

# Just Sample will be enough to run basic tests. If Netlib is present, the
# OsiDylp test will run the Netlib problem set.

AC_COIN_CHECK_PACKAGE([Sample],[coindatasample])
AC_COIN_CHECK_PACKAGE([Netlib],[coindatanetlib])

#############################################################################
#                       Doing project specific tests                        #
#############################################################################

# Tweak compilation flags.
AC_DYLP_FIX_CPPFLAGS

# Determine the C type that corresponds to the C++ bool type in size

AC_DYLP_EQUIV_FOR_CPP_BOOL

########################################################################

AC_SUBST(DYLPLIB_LIBS)
AC_SUBST(DYLPLIB_PCLIBS)
AC_SUBST(DYLPLIB_LIBS_INSTALLED)

# The floating point functions we'll be looking for seem to live in one of
# the following headers: math.h, ieeefp.h, float.h, and sunmath.h. Check
# for presence. We'll use the results to limit the work below.

# check for presence/absence of -lm (for libmath) and store in DYLP_(PC)LIBS flags
AC_COIN_CHECK_LIBM(DyLPLib)

AC_CHECK_HEADER([math.h],
    [AC_DEFINE([HAVE_MATH_H],[1],[Define to 1 if math.h exists.])
     fp_header_list="math.h" 
     AC_C_ADD_TO_INCLUDES([math.h])],
    [AC_MSG_WARN([It appears that math.h is missing.])
     AC_MSG_WARN([There is no hope of building dylp on this system.])])
AC_CHECK_HEADER([ieeefp.h],
    [AC_DEFINE([HAVE_IEEEFP_H],[1],[Define to 1 if ieeefp.h exists.])
     fp_header_list="ieeefp.h $fp_header_list"
     AC_C_ADD_TO_INCLUDES([ieeefp.h])],
    [])
AC_CHECK_HEADER([float.h],
    [AC_DEFINE([HAVE_FLOAT_H],[1],[Define to 1 if float.h exists.])
     fp_header_list="float.h $fp_header_list"
     AC_C_ADD_TO_INCLUDES([float.h])],
    [])
AC_CHECK_HEADER([sunmath.h],
    [AC_DEFINE([HAVE_SUNMATH_H],[1],[Define to 1 if sunmath.h exists.])
     fp_header_list="sunmath.h $fp_header_list"
     AC_C_ADD_TO_INCLUDES([sunmath.h])
     AC_DYLP_GET_SUNSTUDIO_LIBDIRS
     DYLPLIB_LIBS="-lsunmath $DYLPLIB_LIBS"
     DYLPLIB_LIBS_INSTALLED="-lsunmath $DYLPLIB_LIBS_INSTALLED"
     DYLPLIB_PCLIBS="-lsunmath $DYLPLIB_PCLIBS"],
    [])

AC_MSG_NOTICE([Found floating point header files $fp_header_list.])
# AC_MSG_NOTICE([includes are now:])
# AC_MSG_NOTICE([$ac_includes_default])

# Now determine the names in this environment for isfinite() and isnan(). The
# most common variants are finite() and isnan(). We check for others. After
# these macros finish, DYLP_ISFINITE has the name for isfinite(), and
# DYLP_ISNAN has the name for isnan().

AC_DYLP_FIND_ISFINITE
AC_DYLP_FIND_ISNAN

# Check for the presence of a quiet_nan function. To my knowledge, this will
# exist only if sunmath is present, but hey, who knows what lurks out there.

AC_CHECK_FUNC([quiet_nan],
    [AC_DEFINE([DYLP_HAS_QUIET_NAN],[1],
	[Define this symbol if the quiet_nan function exists. This function
	 should return the bit pattern for IEEE quiet NaN.])])

# And determine whether we're big-endian or little-endian. This is necessary to
# define the correct patterns for IEEE infinity and quiet_nan, in the event
# that we can't get them any other way. This will define WORDS_BIGENDIAN if
# we're on a big-endian machine, and do nothing otherwise.

AC_C_BIGENDIAN

# Finally, dylp needs to know where its error message text file is located.
# This is made horribly complicated by Windows, which uses drive letters and
# backslash in the native path format, and by the variation between faked unix
# environments on Windows. Cygwin isn't too bad --- it provides cygpath to
# translate a unix path into native Windows format. Mingw/Msys can't be
# bothered, so we need to work harder.

# Keep in mind the sed expressions are interpreted by the shell and then by
# sed; the backslashes are halved each time. In the end we're left with
# s,/,\\,g or s,\,\\,g as the actual substitutions. This gets us a double
# backslash in DYLP_ERRMSGDIR, which the various compilers can strip down to
# one. Sheesh.

AC_ARG_VAR(DYLP_ERRMSGDIR,
    [Directory containing the DyLP error message text file (dy_errmsgs.txt).
     Should be set to /absolute/path/to/srcdir/DyLP/src/Dylp, using native
     path syntax (i.e., drive letters and backslashes on Windows).])
if test x"$DYLP_ERRMSGDIR" = x; then
  case $build in
    *-mingw*|*-msys*)
      DYLP_ERRMSGDIR="`(cd "$abs_source_dir";pwd -W)`/src/Dylp/"
      DYLP_ERRMSGDIR=`echo $DYLP_ERRMSGDIR | sed -e 's,/,\\\\\\\\,g'`
      ;;
    *-cygwin*)
      DYLP_ERRMSGDIR="`$CYGPATH_W $abs_source_dir/src/Dylp/`"
      DYLP_ERRMSGDIR=`echo $DYLP_ERRMSGDIR | sed -e 's,\\\\,\\\\\\\\,g'`
      ;;
    *)
      DYLP_ERRMSGDIR="$abs_source_dir/src/Dylp/"
      ;;
  esac
fi
AC_DEFINE_UNQUOTED([DYLP_ERRMSGDIR],
    ["$DYLP_ERRMSGDIR"],
    [Directory containing the DyLP error message text file (dy_errmsgs.txt).
     Should be set to /absolute/path/to/srcdir/DyLP/src/Dylp, using native
     path syntax (i.e., drive letters and backslashes on Windows).])

##############################################################################
#		Dylp configuration options				     #
##############################################################################

AC_DYLP_PARANOIA([no])
AC_DYLP_STATISTICS([no])
AC_DYLP_INFO([yes])

##############################################################################
#		OsiDylp configuration options				     #
##############################################################################

AC_ODSI_INFO(yes)
AC_ODSI_STATISTICS(no)
AC_ODSI_PARANOIA(1)

##############################################################################
#		         Documentation                                       #
##############################################################################

# Doxygen documentation. Dylp is independent of Coin code, but OsiDylp can
# benefit from links to doxygen doc'n for CoinUtils and Osi.

AC_COIN_DOXYGEN([CoinUtils Osi])

##############################################################################
#                   VPATH links for example input files                      #
##############################################################################

# In case this is a VPATH configuration we need to make sure that the
# input files for the examples are available in the VPATH directory.

AC_COIN_VPATH_LINK([examples/plain
		    examples/generic.spc examples/greenbeb.spc])

##############################################################################
#                   Finishing up by writing all the output                   #
##############################################################################

# Here list all the files that configure should create (except for the
# configuration header file). First the usual stuff: DyLP's top-level Makefile,
# the code Makefiles (src/*/Makefile), and the test Makefile.

AC_CONFIG_FILES([Makefile
                 examples/Makefile
                 src/DylpStdLib/Makefile
                 src/Dylp/Makefile
                 src/OsiDylp/Makefile
                 test/Makefile])

# Files for doxygen documentation

AC_CONFIG_FILES([doxydoc/doxygen.conf])

# The pkg-config data files

AC_CONFIG_FILES([dylp.pc dylp-uninstalled.pc])
if test $coin_has_osi = yes ; then
  AC_CONFIG_FILES([osi-dylp.pc:src/OsiDylp/osi-dylp.pc.in
                   osi-dylp-uninstalled.pc:src/OsiDylp/osi-dylp-uninstalled.pc.in])
fi

# And all the stuff that goes into building the documentation. See the note in
# Makefile.am with respect to CONFIG_CLEAN_FILES and the distclean and
# distclean-local targets.

AC_CONFIG_FILES([doc/Makefile
		 doc/dylpabsdir.tex
		 doc/makefile.dylpdoc
		 doc/Figures/Makefile
		 doc/TexMF/Makefile])
AC_CONFIG_FILES([doc/build_dylpdoc],[chmod +x doc/build_dylpdoc])

# Here put the location and name of the configuration header files

AC_CONFIG_HEADERS([src/DylpStdLib/config.h src/DylpStdLib/config_dylp.h])

# Finally, we let configure write all the output...

AC_COIN_FINALIZE
