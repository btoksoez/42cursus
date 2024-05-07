/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:23:57 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/07 12:22:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iomanip>
# include <string>
# include <iostream>

bool		isWhitespace(const std::string& str);
std::string	trim(std::string& str);
std::string getInput(std::string str);
std::string	getInputNum(std::string str);
bool		isDigitStr(std::string str);
int			ft_atoi(const char *str);

#endif
