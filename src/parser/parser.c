/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:44:06 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 19:37:00 by mavinici         ###   ########.fr       */
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

void	check_args(char *argc, t_stack **tmp)
{
	int		i;
	char	**str;
	t_stack	*new;

	i = 0;
	str = ft_split(argc, ' ');
	while (str[i])
	{
		(*tmp)->num = ft_atoi(str[i++]);
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
		if (str[i] == '-' && str[i + 1] == '-')
			errors();
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
			errors();
		if (!(ft_isdigit(str[i])))
			errors();
		i++;
	}
}

void	parser_args(t_swap *swap, int argv, char **argc)
{
	t_stack	*tmp;

	tmp = new_node();
	while (argv != 0)
	{
		check_number(argc[argv]);
		check_args(argc[argv], &tmp);
		argv--;
	}
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
	swap->stack_a = take_first(tmp);
	check_duplicates(swap->stack_a);
}
