/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:18:56 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 18:38:41 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_order(t_stack *stack, t_swap *swap)
{
	t_stack	*tmp;
	(void)swap;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && stack)
		if (tmp->num < stack->num)
			return (0);
	return (1);
}

int	is_rev_order(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && stack)
		if (tmp->num > stack->num)
			return (0);
	return (1);
}

void	revert(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int	i;

	i = swap->size_a;
	while (swap->size_a)
	{
		rra(stack_a, swap);
		pb(stack_a, stack_b, swap);
	}
	while (swap->size_b)
		pa(stack_a, stack_b, swap);

}

void	sort_node(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	if (is_rev_order(*stack_a))
		return ;
	else if ((*stack_a)->num > (*stack_a)->next->num && swap->size_a == 2)
		return ;
	else if ((*stack_a)->num < (*stack_a)->next->num && swap->size_a == 2)
		sa(stack_a, swap);
	else if (swap->size_a == 3)
		sort_three(stack_a, swap);
	//else if (swap->size_a == 4)
	//	sort_four(stack_a, stack_b, swap);
	else if (swap->size_a == 5 || swap->size_a == 4)
		sort_five(stack_a, stack_b, swap, 5);
	else
		sort_list(stack_a, stack_b, swap);
}
