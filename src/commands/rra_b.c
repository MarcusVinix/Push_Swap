/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:22 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 17:02:01 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ra_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	//printf("---------------STACK B rotate PP--------------------\n");
	//print_stack(*stack, ft_lstsize((t_list *)(*stack)));
	//printf("-----------------------------------\n");

	last = *stack;
	while (last->next->next)
		last = last->next;
	//last = (t_stack *)ft_lstlast((t_list *)(*stack));
	first = last->next;
	//printf("last is %i first %i new first %i\n", last->num, (*stack)->num, first->num);
	//printf("SEG FAULT NOT HERE size a is %i\n", ft_lstsize((t_list *)(*stack)));
	last->next = NULL;
	//printf("SEG FAULT HERE\n");

	//last->next->next = NULL;
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
	//printf("ESTE È A LISTA B DO ROTATE\n");
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
