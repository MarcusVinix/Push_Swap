/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:59:56 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 18:41:28 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_max_num(t_stack **stack)
{
	int		max_tmp;
	t_stack	*tmp;

	tmp = *stack;
	max_tmp = 0;
	if (tmp)
		max_tmp = tmp->num;
	while (tmp)
	{
		if (tmp->num > max_tmp)
			max_tmp = tmp->num;
		tmp = tmp->next;
	}
	return (max_tmp);
}

int	ft_min_num(t_stack **stack)
{
	int		min_tmp;
	t_stack	*tmp;

	tmp = *stack;
	min_tmp = 0;
	if (tmp)
		min_tmp = tmp->num;
	while (tmp)
	{
		if (tmp->num < min_tmp)
			min_tmp = tmp->num;
		tmp = tmp->next;
	}
	return (min_tmp);
}

void	sort_three(t_stack **stack, t_swap *swap)
{
	int	max_num;
	t_stack	*tmp;
	max_num = ft_max_num(stack);
	tmp = (t_stack *)ft_lstlast((t_list *)(*stack));
	if (tmp->num == max_num)
		ra(stack, swap);
	else if ((*stack)->next->num == max_num)
		rra(stack, swap);
	tmp = (t_stack *)ft_lstlast((t_list *)(*stack));
	
	if (tmp->num > (*stack)->next->num)
		sa(stack, swap);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_swap *swap, int n)
{
	int	min;
	int	count;
	int	pos;
	t_stack	*tmp;

	count = 0;
	min = 2147483647;
	tmp = (*stack_a);
	while (count < swap->size_a)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			pos = count;
		}
		count++;
		tmp = tmp->next;
	}
	check_pos_to_push(stack_a, swap, pos);
	pb(stack_a, stack_b, swap);
	if (n == 5)
		sort_five(stack_a, stack_b, swap, 4);
	else
		sort_three(stack_a, swap);
	pa(stack_a, stack_b, swap);
}

//void	sort_four(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
//{
//	int	min_num;
//
//	min_num = ft_min_num(stack_a);
//	while ((*stack_a)->num != min_num)
//		ra(stack_a, swap);
//	pb(stack_a, stack_b, swap);
//	sort_three(stack_a, swap);
//	pa(stack_a, stack_b, swap);
//}
//
//void	sort_five(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
//{
//	int	min_num;
//	t_stack *tmp;
//
//	tmp = (t_stack *)ft_lstlast((t_list *)(*stack_a));
//	min_num = ft_min_num(stack_a);
//	while (*stack_a)
//	{
//		if (min_num == tmp->num)
//		{
//			pb(stack_a, stack_b, swap);
//			break ;
//		}
//		rra(stack_a, swap);
//		tmp = (t_stack *)ft_lstlast((t_list *)(*stack_a));
//	}
//	tmp = (t_stack *)ft_lstlast((t_list *)(*stack_a));
//	min_num = ft_min_num(stack_a);
//	while (*stack_a)
//	{
//		if (min_num == tmp->num)
//		{
//			pb(stack_a, stack_b, swap);
//			break ;
//		}
//		rra(stack_a, swap);
//		tmp = (t_stack *)ft_lstlast((t_list *)(*stack_a));
//	}
//	sort_three(stack_a, swap);
//	pa(stack_a, stack_b, swap);
//	pa(stack_a, stack_b, swap);
//}
//
