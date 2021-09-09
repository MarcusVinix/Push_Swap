/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:44:06 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/08 17:06:42 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	if (str)
		free(str);
}

void	check_int(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strchr(str, '-'))
	{
		if (len > 11)
			errors();
	}
	else
		if (len > 10)
			errors();
}

void	check_args(char *argc, t_stack **tmp)
{
	int	i;
	char	**str;
	t_stack *new;

	i = 0;
	str = ft_split(argc, ' ');
	while (str[i])
	{
		check_int(str[i]);
		(*tmp)->num = ft_atoi(str[i++]);
		printf("NODE %i: %i\n", i, (*tmp)->num);
		new = new_node();
		new->prev = *tmp;
		(*tmp)->next = new;
		(*tmp) = new;
	}
	free_split(str);
}

void	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
			errors();
		if (!(ft_isdigit(str[i])))
			errors();
		i++;
	}
}

void	parser_args(t_swap *swap, int argv, char **argc)
{
	int	i;
	t_stack	*tmp;

	tmp = new_node();
	i = 1;
	while (i <= argv)
	{
		printf("%i: %s\n", i, argc[i]);
		check_number(argc[i]);
		check_args(argc[i], &tmp);
		i++;
	}
	printf("TESTE: %i\n", tmp->num);
	swap->stack = tmp->prev;
	swap->first = take_first(tmp);
	check_duplicates(swap->first);
	printf("first is %i\n", swap->first->num);
}
