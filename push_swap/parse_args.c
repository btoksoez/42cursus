/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/23 11:50:12 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_int(const char *str)
{
    if (str[0] == '-')
        str++;
    if (ft_strlen(str) > ft_strlen("2147483647"))
        return (0);
    if (ft_strlen(str) == ft_strlen("2147483647") && ft_strncmp(str, "2147483647", ft_strlen(str)) > 0)
        return (0);
    return (1);
}

int	no_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
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

int	is_valid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!ft_isdigit(argv[i][0]) && !(argv[i][0] == '-' && ft_isdigit(argv[i][1])))
			return (0);
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (!is_valid_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**parse_args(int argc, char *argv[])
{
	char **res;
	int	i;

	i = 1;
	if (!(is_valid(argc, argv)))
		return (NULL);
	if (!no_duplicates(argc, argv))
		return (NULL);
	res = (char **)malloc(sizeof(char *) * argc);
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i - 1] = argv[i];
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}
// int main(int argc, char *argv[])
// {
// 	char **parsedArgs = parse_args(argc, argv);
//     if (!parsedArgs)
//     {
//         printf("Failed to parse arguments.\n");
//         return 0;
//     }

//     // Print the parsed arguments
//     printf("Parsed Arguments:\n");
//     for (int i = 0; parsedArgs[i] != NULL; i++)
//     {
//         printf("%s %d\n", parsedArgs[i], i);
//     }

//     // Free the allocated memory
//     free(parsedArgs);

//     return 0;
// }
