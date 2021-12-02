#!/bin/sh
autoreconf -if
automake --add-missing --copy >/dev/null 2>&1
