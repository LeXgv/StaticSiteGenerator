#ifndef _MD_OBJECTS_LIST_
#define _MD_OBJECTS_LIST_
#include <iostream>
#include <string>

/**
mdObjectsList - this c++ class taking apart string in Markdown format.
Creating linked list of object 
*/
class mdObjectsList
{
private:
	std::string md_str;
public:


	mdObjectsList();
	mdObjectsList(std::string str);
	int error();


};



#endif
