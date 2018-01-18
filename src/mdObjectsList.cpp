#include "mdObjectsList.h"


mdObjectsList::mdObjectsList()
{
	head = nullptr;
}

/*
mdObjectsList::mdObjectsList(std::string str)
{
	head = new node;
	node *tmp = head;
	//recognize tag marcdown
	std::string::iterator i = str.begin();	
	for (; i < str.end(); i++)
	{
		if (isFormatText(i))
		{
			//
		}
		if (*i == '\n')
		{
			i++;
			if (i < str.end();)
			{
				if (*i == '#') header(i);
				else if (*i == '|') table(i);
				else if (*i == '>') quote(i);
				else if (*i >= '0' && <= '9') numlist(i);
				else if (*i == '-' || *i == '+') list(i);
			}
		}
	}
	tmp = text(i, tmp);
}
*/
mdObjectsList::elSyntax mdObjectsList::isSyntaxStruc(std::string::iterator i, std::string::iterator end)
{
	if (i == end) return { false, -1 };

	
	if ((*i == '\n') && ((++i) < end))
	{
		//this syntax constructions can will meet in string after symbol \n
		if(*i == '\t') return { true, '\t' };
		int counting_space = 0;
		while (*i == ' ' && counting_space <= 3)
		{
			i++;
			counting_space++;
			if(i == end) return {false, 0};// returned with 0 because forward argument does not eaqual end iterator
		}
		i++;
		if (i != end && *i == ' ')  return { true, '\t' };//this code block
		if (*i >= '0' && *i <= '9')
		{
			//if we is meet number that we must check next symbol
			//if next symbol is dot and after dote go space that
			//before us syntax construction for object numeric list

			if (i < end && *(++i) == '.')
			{
				//if(i < end )
			}
		}
		char syntax2[] = { '#', '*', '~', '>', '_', '-', '`', '|' };
		for (int j = 0; j < 9; j++)
		{
			if (syntax2[j] == *i) return { true, syntax2[j] };
		}
	}
	//this syntax constructions can will meet in any place string
	char syntax[] = { '*', '~',  '_',  '`' };
	for (int j = 0; j < 4; j++)
	{
		if (syntax[j] == *i) return { true, syntax[j] };
	}
	return { false, 0 };
}

std::string::iterator mdObjectsList::creator(node *&p, std::string::iterator start, std::string::iterator end)
{
	if (!(start < end)) return start;
	std::string::iterator st = start;
	elSyntax sy = isSyntaxStruc(st, end);
	if (!(sy.is))
	{
		if (p == nullptr)
		{
			p = new node;
			p->type = TEXT;
			p->inner = reinterpret_cast<node*>(new std::string);
		}
		reinterpret_cast<std::string*>(p->inner)->push_back(*st);
	}
	else
	{
		std::string::iterator endSyntexStruct;
		tvalue type;
		if (sy.s == '#') type = header(st, end);
		/* this functions not were created 
		else if (sy.s == '*') type = bold(p, st, end, type);
		else if (sy.s == '~') type = striket(p, st, end, type);
		else if (sy.s == '_') type = italic(p, st, end, type);
		*/
		p = new node;
		p->type = type.t;
		p->near = nullptr;
		p->inner = nullptr;
		st = creator(p->inner, type.inStart, type.inEnd);
	}
	st++;
	while (!(isSyntaxStruc(st, end).is) && st < end)
	{
		reinterpret_cast<std::string*>(p->inner)->push_back(*st);
		st++;
	}
	creator(p->near, st, end);

}

mdObjectsList::tvalue mdObjectsList::header(std::string::iterator start, std::string::iterator end)
{
	std::string::iterator i = start;
	//std::string::iterator end;
	
		// define type header
		type_el  header_type = NONE;
		int count_hash = 0;
		while (i < end && *i == '#' && count_hash <= 7)
		{
			count_hash++;
			i++;
		}
		if (i == end) return { TEXT, start, i };
		//if after hash do not folow space bar that this is TEXT.
		//or number hash more then 6 
		if (*i != ' ' || count_hash == 7)
		{
			//before us string containing object of type text
			//we add symbols in object until we will meet syntax symbol
			elSyntax t = isSyntaxStruc(i, end);
			while (!(t.is) && t.s != -1)
			{
				//if t.is == false that t.s == 0 if iterator != end
				//if iterator == end that t.s == -1
				i++;
				t = isSyntaxStruc(i, end);
			}
			return {TEXT, start, i};
		}
		else
		{
			i++;
			std::string::iterator s = i;
			//after hash going space. this is HEADER
			tvalue res;
			res.t = static_cast<type_el>(count_hash + 1);//TODO check conformity with type
			res.inStart = i;
			while (i < end && *i != '\n') i++;
			res.inEnd = i;
			return res;
		}

}
/*
mdObjectsList::group_t mdObjectsList::isStartingTerm(char s)
{
	char form[] = { '\n', '*', '~', '>', '_', '-' };
	char code[] = {'<', '`'};
	char link[] = { '[' };
	switch (s)
	{
	case '#': return FORM;
	case '<': COMMENTS;
		break;
	case '*': bold(i);
		break;
	case '~': striket(i);
		break;
	case '_': italic(i);
		break;
		case '>'quote(i);
	default:
		return NONE
	}
	return false;
}

mdObjectsList::node mdObjectsList::getTypeMdStr(std::string::iterator i)
{
	switch (*i)
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
*/