/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:09:35 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/10 21:04:35 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pa_b(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*new;

	new = (*stack_from);
	(*stack_from) = (*stack_from)->next;
	if ((*stack_from))
		(*stack_from)->prev = NULL;
	//new->next = NULL;
	//add front
	new->next = (*stack_to);
	new->prev = NULL;
	if ((*stack_to) != NULL)
		(*stack_to)->prev = new;
	(*stack_to) = new;
	return (0);
}

void	pa(t_stack **stack_to, t_stack **stack_from, t_swap *swap)
{
	if (swap->size_b <= 0)
		return ;
	pa_b(stack_to, stack_from);
	ft_putendl_fd("pa", 1);
	swap->size_a++;
	swap->size_b--;
}

void	pb(t_stack **stack_to, t_stack **stack_from, t_swap *swap)
{
	if (swap->size_a <= 0)
		return ;
	pa_b(stack_to, stack_from);
	ft_putendl_fd("pb", 1);
	swap->size_b++;
	swap->size_a--;
}
