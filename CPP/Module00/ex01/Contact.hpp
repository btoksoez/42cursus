#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <string>
# include <iostream>
# include "utils.hpp"

class Contact
{
	private:
		int			_index;
		std::string	_first;
		std::string	_last;
		std::string _nick;
		std::string _num;
		std::string _secret;

		std::string	_printLen(std::string str);


	public:
		void		create_new(void);
		void		show(void);
		void		setIndex(int i);

};

#endif
