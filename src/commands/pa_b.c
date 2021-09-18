/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:09:35 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 17:20:31 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pa_b(t_stack **stack_to, t_stack **stack_from, t_swap *swap)
{
	t_stack	*new;
	t_stack	*last_from;
	t_stack	*first;
	(void)swap;
	
//printf("---------------STACK A BEFORE PP--------------------\n");
//print_stack(*stack_from, swap->size_a);
//printf("---------------STACK B-from BEFORE PP--------------------\n");
//print_stack(*stack_to, swap->size_b);
//printf("-----------------------------------\n");



	if (!*stack_from)
		return (0);
	if (!(*stack_from)->next)
	{
		new = *stack_from;
		*stack_from = NULL;
	}
	else
	{
		first = (*stack_from);
		last_from = *stack_from;
		while (last_from->next->next)
			last_from = last_from->next;
		new = last_from->next;
		//if (last_from->prev)
		//	last_from->prev->next = NULL;
		last_from->next = NULL;
		(*stack_from)->prev = first;
		(*stack_from) = first;
		new->prev = NULL;
		new->next = NULL;
	}
	//new->next = NULL;
	//add front
	//ft_lstadd_back((t_list **)stack_to, (t_list *)new);
	t_stack *tmp;
	//t_stack *first_to;
	//first_to = *stack_to;
	tmp = *stack_to;
	if (!tmp)
	{
		*stack_to = new;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	//(*stack_to) = first_to;


	return (0);
}

void	pa(t_stack **stack_to, t_stack **stack_from, t_swap *swap)
{
	if (swap->size_b <= 0)
		return ;
	pa_b(stack_to, stack_from, swap);
	ft_putendl_fd("pa", 1);
	swap->size_a++;
	swap->size_b--;
}

void	pb(t_stack **stack_from, t_stack **stack_to, t_swap *swap)
{
	if (swap->size_a <= 0)
		return ;
	pa_b(stack_to, stack_from, swap);
	ft_putendl_fd("pb", 1);
	swap->size_b++;
	swap->size_a--;
}
