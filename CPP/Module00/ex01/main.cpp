/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:21:22 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/07 12:04:43 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	printHeader()
{
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
}

void	printPrompt()
{
    std::cout << "/* *************************************** */" << std::endl;

    // Prompt the user to choose an option
    std::cout << "/* Choose an option:                       */" << std::endl;
    std::cout << "/* 1. [ADD]                                */" << std::endl;
    std::cout << "/* 2. [SEARCH]                             */" << std::endl;
    std::cout << "/* 3. [EXIT]                               */" << std::endl;

    // Print the bottom frame
    std::cout << "/* *************************************** */\n";
}

int main()
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string str;

	printHeader();
	while (true)
	{
		printPrompt();
		str = getInput("Your choice: ");
		// std::cin >> str;
		if (str == "ADD" || str == "1")
		{
			contact.create_new();
			phonebook.add(contact);
		}
		else if (str == "SEARCH" || str == "2")
		{
			phonebook.show_all();
			phonebook.show_entry();
			//prompt for index of entry
				//check input
			//phonebook.showEntry(index)
		}
		else if (str == "EXIT" || str == "3")
			break ;
		//else
			//do nothing
	}

}
