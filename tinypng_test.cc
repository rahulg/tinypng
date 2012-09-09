/*!
 * @file tinypng_test.cc
 * Test file for TinyPNG.
 *
 * @author Rahul A. G.
 */

#include "tinypng.h"

#include <iostream>
#include <stdio.h>

using namespace tinypng;

int main(int argc, char const *argv[])
{
	PNG input("test_in.png");

	input.writeToFile("test_out.png");

	PNG test("test_out.png");
	
	std::cout << "TinyPNG test: ";
	if (input == test)
	{
		std::cout << "SUCCESS" << endl;
	}
	else
	{
		std::cout << "FAILURE" << endl;
	}

	remove("test_out.png");

	return 0;
}