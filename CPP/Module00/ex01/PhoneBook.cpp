/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:37:21 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/04 15:55:52 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::show(void)
{
	std::cout << "First Name: " << this->first << std::endl;
	std::cout << "Last Name: " << this->last << std::endl;
	std::cout << "Nickname: " << this->nick << std::endl;
	std::cout << "Phone Number: " << this->num << std::endl;
	std::cout << "Darkest Secret: " << this->secret << std::endl;
}

std::string getAndTrim(const std::string& prompt)
{
	std::string	input;

	std::cout << prompt;
	std::getline(std::cin, input);
	input.erase(0, input.find_first_not_of(" \t\n\r"));
	input.erase(input.find_last_not_of(" \t\n\r") + 1);
	return (input);

}

void Contact::create_new(void)
{

	this->first = getAndTrim("First Name: ");
	std::cout << "Last Name:" << std::endl;
	std::cin >> this->last;
	std::cout << "Nickname:" << std::endl;
	std::cin >> this->nick;
	std::cout << "Phone number:" << std::endl;
	std::cin >> this->num;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> this->secret;
}

// Contact::is_valid(void)
// {
// 	//if none of the fields empty
// 		//return 1
// 	//return 0
// }

// PhoneBook::add(Contact)
// {
// 	//check if space available
// 		//if not add to beginning
// 		//else add in the end
// }

void print_prompt() {
    std::cout << "/* ************************************************************************** */" << std::endl;

    // Print the ASCII art for "PhoneBook"
	std::cout << ":::::::::  :::    :::  ::::::::  ::::    ::: :::::::::: :::::::::   ::::::::   ::::::::  :::    :::\n"
			  << ":+:    :+: :+:    :+: :+:    :+: :+:+:   :+: :+:        :+:    :+: :+:    :+: :+:    :+: :+:   :+:\n"
			  << "+:+    +:+ +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+        +:+    +:+ +:+    +:+ +:+    +:+ +:+  +:+\n"
			  << "#++:++#+   +#++:++#++ +#+    +:+ +#+ +:+ +#+ +#++:++#   +#++:++#+  +#+    +:+ +#+    +:+ +#++:++\n"
			  << "+#+        +#+    +#+ +#+    +#+ +#+  +#+#+# +#+        +#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+\n"
			  << "#+#+       #+#    #+# #+#    #+# #+#   #+#+# #+#        #+#    #+# #+#    #+# #+#    #+# #+#   #+#\n"
			  << "###        ###    ###  ########  ###    #### ########## #########   ########   ########  ###    ### " << std::endl;

    // Print the bottom frame
    std::cout << "/* ************************************************************************** */" << std::endl;

    // Prompt the user to choose an option
    std::cout << "/* Choose an option:                                                        */" << std::endl;
    std::cout << "/* 1. [ADD]                                                                 */" << std::endl;
    std::cout << "/* 2. [SEARCH]                                                              */" << std::endl;
    std::cout << "/* 3. [EXIT]                                                                */" << std::endl;

    // Print the bottom frame
    std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "Your choice: ";
}


int main()
{
	// PhoneBook	phonebook;
	Contact		contact;
	std::string str;

	while (true)
	{
		print_prompt();
		std::cin >> str;
		if (str == "ADD" || str == "1")
		{
			contact.create_new();
			contact.show();
			// if (contact.is_valid())
			// 	phonebook.add(contact);
		}
		//if search
			//phonebook.show(contacs)
			//prompt for index of entry
				//check input
			//phonebook.showEntry(index)
		if (str == "EXIT" || str == "3")
			break ;
		//else
			//do nothing
	}

}
