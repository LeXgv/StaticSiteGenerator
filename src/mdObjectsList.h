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
	/**
	enum type objects markdown format
	*/
	enum type_el {TEXT, H1, H2, H3, H4, H5, STRIKE, BOLD, ITALIC, LISTING, TABLE, URL, YOUTUBE, QUOTE};
	struct node
	{
		type_el type;
		node *near;
		void *inner; //pointer type depende from value "type"
		/**
		if type == TEXT || type == LISTING that
		inner -> std::string
		else
		inner -> node
		*/
	};
	node *head;
public:
	/**
	 Creating empty list
	*/
	mdObjectsList();
	/**
	Crating object, and start parse "marcdown" format to objects list
	*/
	mdObjectsList(std::string str);


private:
	/**
	This function returning type the passed string in the format 'Markdown'
	*/
	getTypeMdStr(int i)
	/**
	Function recognizing headers
	*/
	void header(int indx);
	/**
	Function recognizing comments
	*/
	void comments(int indx);
	/**
	Function recognizing striketrought text
	*/
	void striket(int indx);
	/**
	Function recognizing bold text
	*/
	void bold(int indx);
	/**
	Function recognizing italic text
	*/
	void italic(int indx);
	/**
	Function recognizing code listing
	*/
	void listing(int indx);
	/**
	Function recognizing table
	*/
	void table(int indx);
	/**
	Function recognizing URL
	*/
	void url(int indx);
	/**
	Function recognizing video Youtube
	*/
	void youtube(int indx);
	/**
	Function recognizing qutes
	*/
	void quote(int indx);

};

#endif
