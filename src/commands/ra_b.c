/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:21:42 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/15 17:34:18 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ra_b(t_stack **stack)
{
	t_stack	*tmp_last;
	t_stack	*new;

	new = (*stack)->next;
	new->prev = NULL;
	tmp_last = (t_stack *)ft_lstlast((t_list *)(*stack));
	tmp_last->next = *stack;
	(*stack)->prev = tmp_last;
	(*stack)->next = NULL;
	*stack = new;
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
	if (swap->size_b <= 1 && swap->size_a <= 1)
		return ;
	ra(stack_a, swap);
	rb(stack_b, swap);
	ft_putendl_fd("rr", 1);
}
