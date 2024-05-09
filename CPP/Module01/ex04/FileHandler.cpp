/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:00:03 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 14:33:14 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

FileHandler::FileHandler(const std::string& to, const std::string& from)
{
	_from = from;
	_to = to;
}

FileHandler::~FileHandler(void)
{
	if (_infile.is_open())
		_infile.close();
	if (_outfile.is_open())
		_outfile.close();
}

bool	FileHandler::openFiles(const std::string& infile_name)
{
	_infile.open(infile_name);
	if (!_infile)
		return (std::cout << "failed to open infile" << std::endl, false);
	_outfile.open(infile_name + ".replace");
	if (!_outfile)
		return (std::cout << "failed to open outfile" << std::endl, false);
	return (true);
}

void	FileHandler::replaceLines(void)
{
	std::string	line;
	while (std::getline(_infile, line))
		{
			std::string	newLine;
			size_t	pos = 0;
			if (!_from.empty())
			{
				while ((pos = line.find(_from, pos)) != std::string::npos)
				{
					newLine += line.substr(0, pos);
					newLine += _to;
					line = line.substr(pos + _from.length());
					pos = 0;
				}
			}
			newLine += line;
			_outfile << newLine << '\n';
		}
}
