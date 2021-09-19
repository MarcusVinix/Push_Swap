/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:25:56 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:26:39 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_n_max_chunk(t_stack **stack, t_swap *swap, int *last, int chunk)
{
	t_stack	*tmp;
	int		num;
	int		count;

	tmp = *stack;
	count = 0;
	num = 2147483647;
	while (count < swap->size_a)
	{
		if (tmp->num < num && tmp->num > *last)
			num = tmp->num;
		tmp = tmp->next;
		count++;
	}
	chunk++;
	*last = num;
	if (chunk == 25 || num == 2147483647)
		return (chunk);
	else
		chunk = find_n_max_chunk(stack, swap, last, chunk);
	return (chunk);
}

void	check_pos_to_push(t_stack **stack, t_swap *swap, int pos)
{
	while (pos != swap->size_a - 1)
	{
		if (pos <= swap->size_a / 2)
		{
			rra(stack, swap);
			if (pos != 0)
				pos--;
			else
				pos = swap->size_a - 1;
		}
		else
		{
			ra(stack, swap);
			pos++;
		}
	}
}

void	check_pos_to_push_b(t_stack **stack, t_swap *swap, int pos)
{
	while (pos != swap->size_b - 1)
	{
		if (pos <= swap->size_b / 2)
		{
			rrb(stack, swap);
			if (pos != 0)
				pos--;
			else
				pos = swap->size_b - 1;
		}
		else
		{
			rb(stack, swap);
			pos++;
		}
	}
}
