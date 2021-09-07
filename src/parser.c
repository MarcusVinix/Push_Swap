/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:44:06 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/07 20:36:06 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node()
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_node(t_stack *node)
{
	t_stack *tmp;

	if (!node)
		return;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	if (node)
		free(node);
	node = NULL;
}

t_stack	*take_first(t_stack *stack)
{
	//t_stack	*tmp;

//	printf("CURRENT: %i\n", stack->prev->num);
	while (stack)
	{

		//tmp = stack->prev;
		if (!stack->prev)
			break ;
		stack = stack->prev;
		printf("prev: %i\n", stack->num);

	}
	printf("prev: %i\n", stack->num);

	return (stack);
}

void	parser_args(t_swap *swap, int argv, char **argc)
{
	int	i;
	t_stack	*tmp;
	t_stack *new;

	tmp = new_node();

	
	i = 1;
	while (i <= argv)
	{
		printf("%i: %s\n", i, argc[i]);

		tmp->num = ft_atoi(argc[i]);
		printf("NODE %i: %i\n", i, tmp->num);
		new = new_node();
		new->prev = tmp;
		printf("prev test: %i\n", new->prev->num);

		tmp->next = new;
		tmp = new;
		i++;
	}
	swap->first = take_first(tmp);
	printf("first is %i\n", swap->first->num);
	free_node(swap->first);
}
