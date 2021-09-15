/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:55:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/15 17:41:24 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	chuck_has(t_stack **stack, int max_num)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->num <= max_num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	short_rotate(t_stack **stack, t_swap *swap, int pos)
{
	int	i;

	i = -1;
	if (pos <= swap->size_b / 2)
	{
		while (++i < pos)
			rb(stack, swap);
	}
	else
	{
		while (++i < swap->size_b - pos)
			rrb(stack, swap);
	}
}

void	move_max_num(t_stack **stack, t_swap *swap)
{
	t_stack	*tmp;
	int		max;
	int		pos;

	pos = 0;
	max = ft_max_num(stack);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num == max)
			break;
		pos++;
		tmp = tmp->next;
	}
	short_rotate(stack, swap, pos);
}

void	check_stack_b(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	t_stack	*tmp;
	int		b_min;
	int		b_max;
	int		a_top;
	int		pos;

	pos = 0;
	b_min = ft_min_num(stack_b);
	b_max = ft_max_num(stack_b);
	a_top = (*stack_a)->num;
	tmp = *stack_b;
	if (a_top < b_min || a_top > b_max)
		return (move_max_num(stack_b, swap));
	while (tmp)
	{
		pos++;
		if (tmp->next && (a_top < tmp->num && a_top > tmp->next->num))
			break ;
		tmp = tmp->next;
	}
	short_rotate(stack_b, swap, pos);
}

void	sort_chunk(t_stack **stack_a, t_stack **stack_b, t_swap *swap, int max)
{
	while (chuck_has(stack_a, max))
	{
			if ((*stack_a)->num <= max)
			{
				check_stack_b(stack_a, stack_b, swap);
				pb(stack_a, stack_b, swap);
			}
			else
				ra(stack_a, swap);
	}
	move_max_num(stack_b, swap);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int	chunks;
	int	chunk_max_num;
	int	i;

	i = 0;
	chunks = 8;
	chunk_max_num = 0;
	if (swap->size_a > 150)
		chunks = 16;
	chunk_max_num = (ft_max_num(stack_a) - ft_min_num(stack_a)) / chunks;
	while (++i < chunks)
		sort_chunk(stack_a, stack_b, swap, chunk_max_num * i);
	sort_chunk(stack_a, stack_b, swap, ft_max_num(stack_a) + 1);
	while (swap->size_b)
		pa(stack_a, stack_b, swap);
}
