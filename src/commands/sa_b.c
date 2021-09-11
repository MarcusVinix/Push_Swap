/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:54:42 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/10 21:30:25 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa_b(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	first = (*stack);
	second = first->next;
	tmp = second->next;
	second->next = NULL;
	second->prev = NULL;
	first->next = tmp;
	first->prev = second;
	if (tmp)
		tmp->prev = first;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack, t_swap *swap)
{
	if (swap->size_a <= 1)
		return ;
	sa_b(stack);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack, t_swap *swap)
{
	if (swap->size_b <= 1)
		return ;
	sa_b(stack);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	if (swap->size_a <= 1 && swap->size_b <= 1)
		return ;
	sa(stack_a, swap);
	sb(stack_b, swap);
	ft_putendl_fd("ss", 1);
}
