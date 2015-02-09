#!/bin/bash
DIR_OPTIONS="--base-directory src --directory build_tests/CMakeFiles/tests.dir"

function error_exit
{
	echo "$1" 1>&2
	exit 1
}

bin/tests
[ $? -ne 0 ] && exit 1

echo "analyzing coverage data...: lcov $DIR_OPTIONS --capture --output-file app.info"
lcov $DIR_OPTIONS --capture --output-file app.info

echo "removing useless data"
lcov --remove app.info "/usr*" --output-file app.info
lcov --remove app.info "tests/*" --output-file app.info

echo "generation html doc"
genhtml -o cov-html app.info #>> lcov.log 2>> lcov.err

echo "done!"

