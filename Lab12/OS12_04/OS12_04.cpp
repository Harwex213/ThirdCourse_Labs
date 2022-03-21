﻿#include <iostream>
#pragma comment(lib, "../x64/Debug/OS12_LIB.lib")
#include "OS12_LIB.h"

int main()
{

	try
	{
		LPVOID h1 = OS12::Init();
		LPVOID h2 = OS12::Init();

		std::cout << "OS12::Adder::Add(h1, 2, 3) = " << OS12::Adder::Add(h1, 2, 3) << "\n";
		std::cout << "OS12::Adder::Add(h2, 2, 3) = " << OS12::Adder::Add(h2, 2, 3) << "\n";

		std::cout << "OS12::Adder::Sub(h1, 2, 3) = " << OS12::Adder::Sub(h1, 2, 3) << "\n";
		std::cout << "OS12::Adder::Sub(h2, 2, 3) = " << OS12::Adder::Sub(h2, 2, 3) << "\n";

		std::cout << "OS12::Multiplier::Mul(h1, 2, 3) = " << OS12::Multiplier::Mul(h1, 2, 3) << "\n";
		std::cout << "OS12::Multiplier::Mul(h2, 2, 3) = " << OS12::Multiplier::Mul(h2, 2, 3) << "\n";

		std::cout << "OS12::Multiplier::Div(h1, 2, 3) = " << OS12::Multiplier::Div(h1, 2, 3) << "\n";
		std::cout << "OS12::Multiplier::Div(h2, 2, 3) = " << OS12::Multiplier::Div(h2, 2, 3) << "\n";

		OS12::Dispose(h1);
		OS12::Dispose(h2);

	}
	catch (int e) { std::cout << "OS12: error = " << e << "\n"; }

}



