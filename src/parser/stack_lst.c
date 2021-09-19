/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:48:03 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 19:38:51 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*new_node(void)
{
	t_stack	*node;

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
	t_stack	*tmp;

	if (!node)
		return ;
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
	if (!stack)
		return (NULL);
	while (stack->prev)
	{
		if (!stack->prev)
			break ;
		stack = stack->prev;
	}
	return (stack);
}

void	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	int		len;
	int		len_2;

	len = ft_lstsize((t_list *)stack);
	while (len--)
	{
		current = stack;
		len_2 = len;
		while (len_2--)
		{
			if (current->num == stack->next->num)
				errors();
			stack = stack->next;
		}
		stack = current->next;
	}
}
