// Test_Markdown.cpp: определяет точку входа для консольного приложения.
//

#include "test_mdObjectsList.cpp"
#pragma comment(lib,"MarcdownHandler")
int main()
{

	test_mdObjectsList r;
	r.header_t1();
	r.isSyntaxStruc_t1();

    return 0;
}

