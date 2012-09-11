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

	test(0,0).red() -= 7;
	test(0,0).green() -= 7;
	test(0,0).blue() -= 7;
	test(0,0).alpha() -= 7;

	std::cout << "TinyPNG byte-wise access test: ";
	uint32_t v_test, v_input;
	v_input =  input(0,0).red() + input(0,0).green() + input(0,0).blue() + input(0,0).alpha();
	v_test =  test(0,0).red() + test(0,0).green() + test(0,0).blue() + test(0,0).alpha();
	if (v_test == v_input - 28)
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