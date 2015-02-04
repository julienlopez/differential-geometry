/*
 * main_tests.cpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
