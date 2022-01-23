/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:17:24 by pnimwata          #+#    #+#             */
/*   Updated: 2022/01/23 19:03:09 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	putnbr(char *c)
{
	int		index;
	char	*proto_num;

	proto_num = "0123456789";
	index = 0;
	while (*(proto_num + index) != '\0')
	{
		if (*c == *(proto_num + index))
			return (index);
		index++;
	}
	return (-1);
}

int	is_nbr(char *num)
{
	if (*num >= '0' && *num <= '9')
		return (1);
	return (0);
}

int	count_char_num(char *num)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (*(num + index) != '\0')
	{
		if (is_nbr(num))
			count++;
		index++;
	}
	return (count);
}

int	*convert_to_arr(char *str, int *max_num)
{
	int		*new_arr;
	int		new_arr_i;
	int		index;
	char	*c;

	index = 0;
	new_arr = malloc(*max_num * 4);
	new_arr_i = 0;
	while (str[index] != '\0')
	{
		c = str + index;
		if (is_nbr(c) == 1)
		{
			*(new_arr + new_arr_i) = putnbr(c);
			new_arr_i++;
		}
		else if (!(is_nbr(c) == 1) && *c != ' ')
		{
			write(1, "error format\n", 12);
			return (0);
		}
		index++;
	}
	return (new_arr);
}

int	main(int counter, char **vector)
{
	int	*arr_num;
	int	max_vector;
	int	max_table;

	max_table = count_char_num(*(vector + 1)) / 4;
	max_vector = sizeof (*(vector + 1));
	if (counter != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	arr_num = convert_to_arr(*(vector + 1), &max_table);
	int i = 0;
	while (i < max_table * 4)
	{
		printf("%d", *(arr_num + i));
		i++;
	}
	return (0);
}
