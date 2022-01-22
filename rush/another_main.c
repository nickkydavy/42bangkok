/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:17:24 by pnimwata          #+#    #+#             */
/*   Updated: 2022/01/23 00:04:48 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	putnbr(char *c)
{
	char	*proto_num;
	int	index;

	proto_num = "0123456789";
	index = 0;
	while (*(proto_num + index) != '\0')
	{
		if(*c == *(proto_num + index))
			return (index);
		index++;
	}
	return (-1);
}

int	count_char_num(char *num)
{
	int	count = 0;
	int	index = 0;

	while (*(num + index) != '\0')
	{
		if (*(num + index) >= '0' && *(num + index) <= '9')
			count++;
		index++;
	}
	return (count);
}
/*
int	*convert_to_arr(char *str, int *max_num)
{
	int	*new_arr;
	int	index;

	index = 0;
	while (index < max_num)
	{
		
	}
	return (new_arr);
}*/

int	main(int counter, char **vector)
{
	int	*arr_num;
	int	max_vector;
	int	max_vector_nbr;

	max_vector_nbr = count_char_num(*(vector + 1));
	arr_num = malloc(max_vector_nbr * 4);
	max_vector = sizeof (*(vector + 1));
	if (counter != 2 )
	{
		write(1, "error\n", 6);
		return (0);
	}
	int 	i ;
	int	arr_i;
	char	*c;

	i = 0;
	arr_i = 0;
	while (i < max_vector_nbr * 2 - 1) 
	{
		c = *(vector + 1) + i; // 4
		if (*c == ' ')
		{
			i++;
			continue;
		}
		if (*c >= '0' && *c <= '9')
		{
			*(arr_num + arr_i) = putnbr(c);
			arr_i++;
		}
		else
		{
			write(1, "error format\n", 12);
			return (0);
		}
		i++;	
	}
	i = 0;
	while (i < max_vector_nbr)
	{
		printf("%d", *(arr_num + i));
		i++;
	}
	return (0);
}
