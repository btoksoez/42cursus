/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:24:13 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/07 12:21:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <string>
# include <iostream>
# include <sstream>
# include "Contact.hpp"
# include "utils.hpp"

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

