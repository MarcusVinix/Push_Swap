/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:22 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 19:56:45 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ra_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	last = *stack;
	while (last->next->next)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->prev = NULL;
	first->next = (*stack);
	(*stack)->prev = first;
	(*stack) = first;
	return (0);
}

void	ra(t_stack **stack, t_swap *swap)
{
	if (swap->size_a <= 1)
		return ;
	ra_b(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack, t_swap *swap)
{
	if (swap->size_b <= 1)
		return ;
	ra_b(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	if (swap->size_a <= 1 && swap->size_b <= 1)
		return ;
	ra(stack_a, swap);
	rb(stack_b, swap);
	ft_putendl_fd("rr", 1);
}
