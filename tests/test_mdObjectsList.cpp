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
		std::cout << "___testing method mdObjectsList::header___\n";
		std::string str1 = "# Hello World!";
		tvalue r1 = header(str1.begin(), str1.end());
		if (r1.t == H1 && r1.inStart == (str1.begin() + 2) && r1.inEnd == str1.end())
		{
			std::cout << "test 1: Done\n";
		}
		else
		{
			std::cout << "test 2 Failed\n";
		}
		//test 2
		 str1 = "## Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == H2 && r1.inStart == (str1.begin() + 3) && r1.inEnd == str1.end())
		{
			std::cout << "test 2: Done\n";
		}
		else
		{
			std::cout << "test 2: Failed\n";
		}

		//test 3
		str1 = "### Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == H3 && r1.inStart == (str1.begin() + 4) && r1.inEnd == str1.end())
		{
			std::cout << "test 3: Done\n";
		}
		else
		{
			std::cout << "test 3: Failed\n";
		}

		//test 4
		str1 = "#### Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == H4 && r1.inStart == (str1.begin() + 5) && r1.inEnd == str1.end())
		{
			std::cout << "test 4: Done\n";
		}
		else
		{
			std::cout << "test 4: Failed\n";
		}

		//test 5
		str1 = "##### Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == H5 && r1.inStart == (str1.begin() + 6) && r1.inEnd == str1.end())
		{
			std::cout << "test 5: Done\n";
		}
		else
		{
			std::cout << "test 5: Failed\n";
		}

		//test 6
		str1 = "###### Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == H6 && r1.inStart == (str1.begin() + 7) && r1.inEnd == str1.end())
		{
			std::cout << "test 6: Done\n";
		}
		else
		{
			std::cout << "test 6: Failed\n";
		}

		//test 7
		str1 = "#####Hello World!";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == TEXT && r1.inStart == str1.begin() && r1.inEnd == str1.end())
		{
			std::cout << "test 7: Done\n";
		}
		else
		{
			std::cout << "test 7: Failed\n";
		}

		//test 8
		str1 = "####Hello World!\n meating ";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == TEXT && r1.inStart == str1.begin() && r1.inEnd == str1.end())
		{
			std::cout << "test 8: Done\n";
		}
		else
		{
			std::cout << "test 8: Failed\n";
		}


		//test *
		str1 = "####Hello World!\n1. meating ";
		r1 = header(str1.begin(), str1.end());
		if (r1.t == TEXT && r1.inStart == str1.begin() && r1.inEnd == (str1.begin() + 15))
		{
			std::cout << "test 9: Done\n";
		}
		else
		{
			std::cout << "test 9: Failed\n";
		}
	}

	void isSyntaxStruc_t1()
	{
		std::string str1 = "\n1. text";
		elSyntax r1 = isSyntaxStruc(str1.begin(), str1.end());
		if (r1.is == true && r1.s == '1')
		{
			std::cout << "test 9: Done\n";
		}
		else
		{
			std::cout << "test 9: Failed\n";
		}
	}
};

