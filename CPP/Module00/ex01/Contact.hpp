#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <array>
#include <iomanip>
#include <string>
#include <iostream>

class Contact
{
	private:
		int			_index;
		std::string	_first;
		std::string	_last;
		std::string _nick;
		std::string _num;
		std::string _secret;

		std::string	_getInput(std::string str);
		std::string	_getInputNum(std::string str);
		bool		_isDigitStr(std::string str);
		bool		_isWhitespace(const std::string& str);
		std::string	_trim(std::string& str);
		std::string	_printLen(std::string str);


	public:
		void		create_new(void);
		void		show(void);
		void		setIndex(int i);

};

#endif
