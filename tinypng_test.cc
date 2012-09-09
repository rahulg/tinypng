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
	
	std::cout << "TinyPNG IO + codec test: ";
	if (input == test)
	{
		std::cout << "SUCCESS" << endl;
	}
	else
	{
		std::cout << "FAILURE" << endl;
	}

	uint8_t *bytes = test.bytes();
	int max = test.getWidth() * test.getHeight() * 4;
	for (int i = 0; i < max; ++i)
	{
		bytes[i] += 7;
	}
	
	std::cout << "TinyPNG byte-wise access test: ";
	if (test(0,0)->red == input(0,0)->red + 7)
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