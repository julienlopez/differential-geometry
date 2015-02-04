#!/bin/bash
DIR_OPTIONS="--base-directory tests --directory tests/expression"

function error_exit
{
	echo "$1" 1>&2
	exit 1
}

echo "resetting coverage values"
lcov --zerocounters $DIR_OPTIONS #> lcov.log 2> lcov.err

echo "running baseline"
lcov --capture --initial $DIR_OPTIONS --output-file app.baseline #>> lcov.log 2>> lcov.err

tests/geom-diff

echo "analyzing coverage data...: lcov --no-checksum $DIR_OPTIONS --no-external --capture --output-file app"
lcov --no-checksum $DIR_OPTIONS --capture --output-file app #>> lcov.log 2>> lcov.err
#lcov --no-checksum $DIR_OPTIONS --no-external --capture --output-file app.info

echo "merging datas"
lcov --add-tracefile app.baseline --add-tracefile app --output-file app.info

echo "removing useless data"
lcov --remove app.info "/usr*" --output-file app.info

echo "generation html doc"
genhtml -o cov-html app.info #>> lcov.log 2>> lcov.err

echo "done!"

