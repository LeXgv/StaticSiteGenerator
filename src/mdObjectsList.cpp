#include "mdObjectsList.h"


mdObjectsList::mdObjectsList()
{
	head = nullptr;
}

mdObjectsList::mdObjectsList(std::string str)
{
	head = new node;
	//recognize tag marcdown
	for (std::string::iterator i = str.begin(); i < str.end(); i++)
	{
		switch (*i)
		{
		case '#': header(i);
			break;
		case '<': comments(i);
			break;
		case '*': bold(i);
			break;
		case '~': striket(i);
			break;
		case '_': italic(i);
			break;
			case '>'quote(i);
				break;
		default:
			break;
		}
	}
}

