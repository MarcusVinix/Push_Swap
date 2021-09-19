/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:21:42 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 13:30:02 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rra_b(t_stack **stack)
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
	if (swap->size_b <= 1 && swap->size_a <= 1)
		return ;
	rra(stack_a, swap);
	rrb(stack_b, swap);
	ft_putendl_fd("rrr", 1);
}
