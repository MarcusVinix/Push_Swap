/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:55:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:39:39 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "utils.h"

int	check_top_b(t_stack **stack, t_swap *swap, int num)
{
	int		dif;
	int		pos;
	int		count;
	t_stack	*tmp;

	count = 0;
	dif = 2147483647;
	pos = 0;
	tmp = *stack;
	while (count < swap->size_b)
	{
		if (num - tmp->num < dif && tmp->num < num)
		{
			dif = num - tmp->num;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	if (dif == 2147483647)
		pos = check_top_b(stack, swap, 2147483647);
	return (pos);
}

void	push_number(t_stack **stack_a, t_stack **stack_b, t_swap *swap, int pos)
{
	int		pos_b;
	int		top_a;
	t_stack	*last;

	check_pos_to_push(stack_a, swap, pos);
	if (!swap->size_b)
		pb(stack_a, stack_b, swap);
	else
	{
		last = (t_stack *)ft_lstlast((t_list *)(*stack_a));
		top_a = last->num;
		pos_b = check_top_b(stack_b, swap, top_a);
		check_pos_to_push_b(stack_b, swap, pos_b);
		pb(stack_a, stack_b, swap);
	}
}

void	push_closer(t_stack **stack, t_swap *swap, int chunk)
{
	t_var	var;

	var.tmp = *stack;
	var.pos = 0;
	var.dif = 2147483647;
	var.count = 0;
	while (var.count < swap->size_a)
	{
		if (var.tmp->num < chunk)
		{
			if (var.count < var.dif)
			{
				var.pos = var.count;
				var.dif = var.count;
			}
			else if (swap->size_a - var.count < var.dif)
			{
				var.pos = var.count;
				var.dif = swap->size_a - var.count;
			}
		}
		var.tmp = var.tmp->next;
		var.count++;
	}
	push_number(stack, &swap->stack_b, swap, var.pos);
}

void	return_b_to_a(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int		count;
	int		pos;
	int		num;
	t_stack	*tmp;

	num = INT_MIN;
	count = 0;
	tmp = *stack_b;
	while (count < swap->size_b)
	{
		if (tmp->num > num)
		{
			num = tmp->num;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	check_pos_to_push_b(stack_b, swap, pos);
	while (swap->size_b)
		pa(stack_a, stack_b, swap);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int	max;
	int	las_n_chunk;

	max = 0;
	las_n_chunk = 0;
	while (!is_order(*stack_a) || swap->size_b)
	{
		if (max == 0)
		{
			las_n_chunk = -2147483648;
			max = find_n_max_chunk(stack_a, swap, &las_n_chunk, max);
		}
		if (swap->size_a > 2)
			push_closer(stack_a, swap, las_n_chunk);
		else if (swap->size_a == 2)
			push_number(stack_a, stack_b, swap, 1);
		else
		{
			push_number(stack_a, stack_b, swap, 0);
			return_b_to_a(stack_a, stack_b, swap);
		}
		max--;
	}
}
