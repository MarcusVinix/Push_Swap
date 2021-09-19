/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:09:35 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:12:44 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*p_aux(t_stack **stack_from)
{
	t_stack	*last_from;
	t_stack	*first;
	t_stack	*new;

	first = (*stack_from);
	last_from = *stack_from;
	while (last_from->next->next)
		last_from = last_from->next;
	new = last_from->next;
	last_from->next = NULL;
	(*stack_from)->prev = first;
	(*stack_from) = first;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	pa_b(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!*stack_from)
		return ;
	if (!(*stack_from)->next)
	{
		new = *stack_from;
		*stack_from = NULL;
	}
	else
		new = p_aux(stack_from);
	tmp = *stack_to;
	if (!tmp)
	{
		*stack_to = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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

void	pb(t_stack **stack_from, t_stack **stack_to, t_swap *swap)
{
	if (swap->size_a <= 0)
		return ;
	pa_b(stack_to, stack_from);
	ft_putendl_fd("pb", 1);
	swap->size_b++;
	swap->size_a--;
}
