/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:55:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 17:20:02 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_n_max_chunk(t_stack **stack, t_swap *swap, int *last, int chunk)
{
	t_stack	*tmp;
	int		num;
	int		count;

	tmp = *stack;
	count = 0;
	num = 2147483647;
	while (count < swap->size_a)
	{
		if (tmp->num < num && tmp->num > *last)
			num = tmp->num;
		tmp = tmp->next;
		count++;
	}
	chunk++;
	*last = num;
	if (chunk == 25 || num == 2147483647)
		return (chunk);
	else
		chunk = find_n_max_chunk(stack, swap, last, chunk);
	return (chunk);
}

void	check_pos_to_push(t_stack **stack, t_swap *swap, int pos)
{
	while (pos != swap->size_a - 1)
	{
		if (pos <= swap->size_a / 2)
		{
			rra(stack, swap);
			if (pos != 0)
				pos--;
			else
				pos = swap->size_a - 1;
		}
		else
		{
			ra(stack, swap);
			pos++;
		}
	}
}

void	check_pos_to_push_b(t_stack **stack, t_swap *swap, int pos)
{
	//	printf("fora NO WHIKE CHECK POS TO B, size b is %i and pos is %i\n", swap->size_b, pos);

	while (pos != swap->size_b - 1)
	{
		//printf("ENTREI NO WHIKE CHECK POS TO B, size b is %i and pos is %i\n", swap->size_b, pos);
		if (pos <= swap->size_b / 2)
		{
			rrb(stack, swap);
			if (pos != 0)
				pos--;
			else
				pos = swap->size_b - 1;
		}
		else
		{
			rb(stack, swap);
			pos++;
		}
	}
}

int	check_top_b(t_stack **stack, t_swap *swap, int num)
{
	int	dif;
	int	pos;
	int	count;
	t_stack *tmp;

	count = 0;
	dif = 2147483647;
	pos = 0;
	tmp = *stack;
	while (count < swap->size_b)
	{
		if (num - tmp->num < dif && tmp->num < num)
		{
			dif = num - tmp->num;
			pos = count;
		}
		//printf("CURRENT B is %i\n", tmp->num);
		tmp = tmp->next;
		count++;
	}
	if (dif == 2147483647)
		pos = check_top_b(stack, swap, 2147483647);
	return (pos);
}

void	push_number(t_stack **stack_a, t_stack **stack_b, t_swap *swap, int pos)
{
	int pos_b;
	int top_a;
	t_stack *last;


	check_pos_to_push(stack_a, swap, pos);
	if (!swap->size_b)
	{
		//printf("IF TO PB SIZE B IS %i\n", swap->size_b);
		pb(stack_a, stack_b, swap);
	
	}
	else
	{
	//	printf("ENTREI NO PUSH NUBMER\n");
		last = (t_stack *)ft_lstlast((t_list *)(*stack_a));
		top_a = last->num;
	//	printf("the top_a is %i size b is %i size a is %i\n", top_a, swap->size_b, swap->size_a);
	//	printf("----------------------\n");

		//print_stack(*stack_a, swap->size_a);
	//	printf("TOP A IS %i\n", top_a);
		//printf("----------------------\n");
		pos_b = check_top_b(stack_b, swap, top_a);
	//	printf("POS_B %i\n", pos_b);
		check_pos_to_push_b(stack_b, swap, pos_b);
		pb(stack_a, stack_b, swap);		
	}
}

void	push_closer(t_stack **stack, t_swap *swap, int chunk)
{
	int	count;
	int	dif;
	int	pos;
	t_stack	*tmp;

	tmp = *stack;
	pos = 0;
	dif = 2147483647;
	count = 0;
	while (count < swap->size_a)
	{
		if (tmp->num < chunk)
		{
			if (count < dif)
			{
				pos = count;
				dif = count;
			}
			else if (swap->size_a - count < dif)
			{
				pos = count;
				dif = swap->size_a - count;
			}
		}
		//printf("PUSH_CLOSER size %i\n", swap->size_a);
		//print_stack(*stack, swap->size_a);
		tmp = tmp->next;
		count++;
	}
	push_number(stack, &swap->stack_b, swap, pos);
}

void	return_b_to_a(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int	count;
	int	pos;
	int	num;
	t_stack	*tmp;

	num = INT_MIN;
	count = 0;
	tmp = *stack_b;
	while (count < swap->size_b)
	{
		if (tmp->num > num)
		{
			num = tmp->num;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	check_pos_to_push_b(stack_b, swap, pos);
	while (swap->size_b)
	{
		//printf("LOOP? sizeb %i  sizea %i\n", swap->size_b, swap->size_a);
		//printf("-------------------A------------------\n");
		//print_stack(*stack_a, swap->size_a);
		//printf("-------------------B------------------\n");
		//print_stack(*stack_b, swap->size_b);
		pa(stack_a, stack_b, swap);
	}
//printf("fora loop? \n");

}

void	sort_list(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	int	max_chunk;
	int	las_n_chunk;

	max_chunk = 0;
	las_n_chunk = 0;
	while (!is_rev_order(*stack_a) || swap->size_b)
	{
		if (max_chunk == 0)
		{
			las_n_chunk = -2147483648;
			max_chunk = find_n_max_chunk(stack_a, swap, &las_n_chunk, max_chunk);
		}
		if (swap->size_a > 2)
			push_closer(stack_a, swap, las_n_chunk);
		else if (swap->size_a == 2)
			push_number(stack_a, stack_b, swap, 1);
		else
		{
			push_number(stack_a, stack_b, swap, 0);
			return_b_to_a(stack_a, stack_b, swap);
		}
		max_chunk--;
	
	}
}
