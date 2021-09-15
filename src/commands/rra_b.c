/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:22 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/15 12:21:49 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rra_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	last = (t_stack *)ft_lstlast((t_list *)(*stack));
	first = last;
	last->prev->next = NULL;
	last->next = NULL;
	first->prev = NULL;
	first->next = (*stack);
	(*stack)->prev = first;
	(*stack) = first;

	return (0);
}

void	rra(t_stack **stack, t_swap *swap)
{
	if (swap->size_a <= 1)
		return ;
	rra_b(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack, t_swap *swap)
{
	if (swap->size_b <= 1)
		return ;
	rra_b(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	if (swap->size_a <= 1 && swap->size_b <= 1)
		return ;
	rra(stack_a, swap);
	rrb(stack_b, swap);
	ft_putendl_fd("rrr", 1);
}
