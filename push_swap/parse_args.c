/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 09:40:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *str)
{
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (1);
	if (str[0] == '-')
		str++;
	if (ft_strlen(str) > ft_strlen("2147483647"))
		return (0);
	if (ft_strlen(str) == ft_strlen("2147483647")
		&& ft_strncmp(str, "2147483647", ft_strlen(str)) > 0)
		return (0);
	return (1);
}

int	no_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], 9) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(int argc, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (!ft_isdigit(res[i][0]) && !(res[i][0] == '-'
			&& ft_isdigit(res[i][1])))
			return (0);
		j = 1;
		while (res[i][j] != '\0')
		{
			if (!ft_isdigit(res[i][j]))
				return (0);
			j++;
		}
		if (!is_valid_int(res[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**parse_args(int argc, char *argv[])
{
	char	**res;
	int		i;

	i = 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
		res = argsdup(argc, argv);
	if (!is_valid(ft_arrlen(res), res) || !no_duplicates(ft_arrlen(res), res))
	{
		free_arr(res);
		write_stderror();
		return (NULL);
	}
	return (res);
}
