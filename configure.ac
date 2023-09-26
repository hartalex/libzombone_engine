#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libzombone_engine], [1.1.0], [alex@hartcode.com])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([subdir-objects])
LT_INIT([])

AC_DEFINE([LOG_LEVEL], [1], [Sets the logging level, 0:debug 1:info 2:warn: 3:error ])
AC_DEFINE_UNQUOTED([ZOMBONE_ENGINE_VERSION], ["$VERSION"])
AC_DEFINE_UNQUOTED([ZOMBONE_ENGINE_PACKAGE_STRING], ["$PACKAGE_STRING"])

AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([src/config.hpp
                   zombone_engine.hpp])

AC_CONFIG_TESTDIR([tests])
AC_CONFIG_FILES([makefile
     src/makefile
		 tests/makefile
     tests/engine/makefile
     tests/sceneManager/makefile
     tests/objectFileFactory/makefile
		 tests/atlocal])
AC_LANG([C++])
# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL


# Checks for libraries.
AC_CHECK_LIB([m],[sqrt],,AC_MSG_ERROR(Couldn't find library libm))

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h syslog.h math.h],,AC_MSG_ERROR(Missing header))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Check for applications
AC_CHECK_PROG([GCOVR], gcovr, yes)

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN"; then
   AC_MSG_WARN([Doxygen not found - continue without Doxygen support])
fi
AC_CHECK_PROGS([DOT], [dot])
if test -z "$DOT"; then
   AC_MSG_ERROR([Doxygen needs dot, please install dot first])
fi

AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])

AC_SUBST([async_exec])

AC_CANONICAL_HOST

build_linux=no
build_windows=no
build_mac=no

# Detect the target system
case "${host_os}" in
    linux*)
        build_linux=yes
        ;;
    cygwin*|mingw*)
        build_windows=yes
        ;;
    darwin*)
        build_mac=yes
        ;;
    *)
        AC_MSG_ERROR(["OS $host_os is not supported"])
        ;;
esac

# Pass the conditionals to automake
AM_CONDITIONAL([LINUX], [test "$build_linux" = "yes"])
AM_CONDITIONAL([WINDOWS], [test "$build_windows" = "yes"])
AM_CONDITIONAL([OSX], [test "$build_mac" = "yes"])


AC_OUTPUT
