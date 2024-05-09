/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:31:45 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 14:41:12 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

# include <unistd.h>
# include <iostream>
# include <fstream>

class FileHandler
{
	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;
		std::string		_from;
		std::string		_to;

	public:
		FileHandler(const std::string& to, const std::string& from);
		~FileHandler();
		bool	openFiles(const std::string& infile_name);
		void	replaceLines(void);

};

#endif

