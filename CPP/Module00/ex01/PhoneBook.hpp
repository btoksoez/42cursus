#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <array>
#include <iomanip>
#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		_numContacts;
		Contact	_contacts[8];
		void	_printHeader(void);

	public:
		PhoneBook();
		void	add(Contact& new_contact);
		void	show_all(void);
		void	show_entry(void);
};



#endif

