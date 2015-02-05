#!/bin/bash

#builds a target with $1 being the source directory and $2 being the build directory
function buildTarget
{
	SRC_DIR=$1
	BUILD_DIR=$2

	[ -d $BUILD_DIR ] || mkdir $BUILD_DIR
	cd $BUILD_DIR

	cmake ../$SRC_DIR && make

	cd ..
}

buildTarget src build
buildTarget tests build_tests
