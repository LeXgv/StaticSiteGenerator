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
protected:
	/**
	enum type objects markdown format
	*/
	enum type_el {NONE, TEXT,
		/*FORM*/H1, H2, H3, H4, H5, H6, STRIKE, BOLD, ITALIC, TABLE, QUOTE, LIST, NUMLIST, HRULES,
		/*CODE*/ INLINE, LISTING, COMMENTS, 
		/*LINK*/ URL, YOUTUBE, IMG};
	//enum group_t {NONE, FORM, CODE, LINK, };
	struct elSyntax { bool is; char s; };
	struct node
	{
		type_el type;
		node *near;
		node *inner; //pointer type depende from value "type"
		/**
		if type == TEXT || type == LISTING that
		inner -> std::string
		else
		inner -> node
		*/
	};
	node *head;
	node *last;
public:
	/**
	 Creating empty list
	*/
	mdObjectsList();
	/**
	Crating object, and start parse "marcdown" format to objects list
	*/
	mdObjectsList(std::string str);


protected:
	/**
	Function define: whether the symbol is the starting symbol of the key word
	*/
	//group_t isStartingTerm(char s);
	elSyntax isSyntaxStruc(std::string::iterator i, std::string::iterator end);
	/**
	function perform building syntax tree for markup language 'Markdown'
	prametrs:
		node *&p - pointer which must will pointing to root, In this pointer will be recordered addres to memory
		std::string::iterator start - iterator the beginning of the string
		std::string::iterator end - iterator the ending of the string
	return:
		std::string::iterator - iterator the ending of the string which finished work
	*/
	std::string::iterator creator(node *&p, std::string::iterator start, std::string::iterator end);
	/**
	This type is designed in order to the function can will returning several value:
	type_el t - object type that is contained in the string
	std::string::iterator inStart - 
	std::string::iterator inEnd - start description a object (inside elements, without syntax of this object)
	*/
	struct tvalue { type_el t;  std::string::iterator inStart; std::string::iterator inEnd; };
	tvalue getTypeMdStr(std::string::iterator i);
	/**
	Function recognizing headers
	*/
	tvalue header(std::string::iterator start, std::string::iterator end);
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
