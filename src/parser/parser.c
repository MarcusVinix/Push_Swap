/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:44:06 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/17 14:24:44 by mavinici         ###   ########.fr       */
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
	int	i;
	char	**str;
	t_stack *new;

	i = 0;
	str = ft_split(argc, ' ');
	while (str[i])
	{
		(*tmp)->num = ft_atoi(str[i++]);
		//printf("NODE %i: %i\n", i, (*tmp)->num);
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
		//rintf("%i: %s\n", i, argc[i]);
		check_number(argc[argv]);
		check_args(argc[argv], &tmp);
		argv--;
	}
//	printf("TESTE: %i\n", tmp->num);
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
	//printf("TESTE2: %i\n", swap->stack_a->num);
	swap->stack_a = take_first(tmp);
	check_duplicates(swap->stack_a);
	//printf("first is %i\n", swap->first->num);
}
