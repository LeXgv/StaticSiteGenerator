#include "mdObjectsList.h"
#include <iostream>
#include <string>
class test_mdObjectsList : protected mdObjectsList
{
public:
	test_mdObjectsList()
	{
		std::cout << "testing mdObjectsList started" << std::endl;
	}

	void header_t1()
	{
		std::string str1 = "# Hello World!";
		tvalue r1 = header(str1.begin(), str1.end());
		std::cout << r1.t;
	}
};

