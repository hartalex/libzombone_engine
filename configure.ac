#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libzombone_engine], [1.0], [alex@hartcode.com])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([subdir-objects])
LT_INIT([])

AC_DEFINE([LOG_LEVEL], [1], [Sets the logging level, 0:debug 1:info 2:warn: 3:error ])

AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([headers/config.hpp])

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
AC_CHECK_LIB([ncursesw],[initscr],,AC_CHECK_LIB([ncurses],[initscr],,AC_MSG_ERROR(Couldn't find library libncurses-dev)))
AC_CHECK_LIB([SDL2],[main],,AC_MSG_ERROR(Couldn't find library libsdl2-dev))
AC_CHECK_LIB([SDL2main],[main],,AC_MSG_ERROR(Couldn't find library libsdl2-dev))
AC_CHECK_LIB([SDL2_mixer],[main],,AC_MSG_ERROR(Couldn't find library libsdl2-mixer-dev))

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h syslog.h ncurses.h math.h],,AC_MSG_ERROR(Missing header))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Check for applications
AC_CHECK_PROG([GCOVR], gcovr, yes)

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
