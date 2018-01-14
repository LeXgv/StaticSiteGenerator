#ifndef _MARCDOWN_HANDLER_
#define _MARCDOWN_HANDLER_
#include <string>

class mdHandler
{
private:
	std::string md;
public:
	/**
	Create empty object of handler
	*/
	mdHandler();
	/**
	Create handler with passing string in Markdown format
	*/
	mdHandler(std::string &md_str);
	/**
	(Move semantic)
	Create handler with passing string in Markdown format
	*/
	mdHandler(std::string &&md_str);
	/**
	Converting Marcdown format to HTML format
	*/
	std::string toHTML();
	/**
	Pass string in Marcdown format to Handler
	*/
	void mdString(std::string &md_str)
};



#endif
