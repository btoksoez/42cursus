#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <array>
#include <iomanip>
#include <string>
#include <iostream>

class Contact
{
	private:
		std::string first;
		std::string last;
		std::string nick;
		std::string num;
		std::string secret;

	public:
		void	create_new(void);
		bool	is_valid(void);
		void	show(void);


};

class PhoneBook
{
	private:
		std::array<Contact, 8> contacts;
	public:
		void	add(Contact);
		void	show_all(void);
		void	show_entry(int index);
};



#endif

