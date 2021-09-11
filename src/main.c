/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:16:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/10 21:31:49 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, int size)
{
	int	i;

	if (!stack || size == 0)
		return ;
	i = 0;
	while (i <= size - 1)
	{
	
		printf("%i\n", stack->num);
		stack = stack->next;
		if (!stack)
			break ;
		i++;
	}
}

int	main(int argv, char **argc)
{
	t_swap	swap;

	//printf("ARGV %i\n", argv);
	//ft_bzero(&swap.stack, sizeof(s_stack));
	if (argv < 2)
		exit(0);
	parser_args(&swap, argv - 1, argc);
	printf("------------------------------------------\n\n");
	//printf("FINAL: %i\n", swap.stack_a->num);
	//printf("STACK\n");
	print_stack(swap.first_a, ft_stack_size(swap.first_a));
	swap.size_a = ft_stack_size(swap.first_a);
	sa(&swap.first_a, &swap);
	printf("SA\n");
	printf("FIRST AFTER SA %i\n", swap.first_a->num);
	print_stack(swap.first_a, ft_stack_size(swap.first_a));
	printf("------------------------------------------\n\n");
	swap.stack_b = NULL;
	printf("AQ\n");
	swap.size_b = ft_stack_size(swap.stack_b);
	pb(&swap.stack_b, &swap.first_a, &swap);
	printf("STACK A AFTER FIRST PB\n");
	//printf("FIRST OF STACK A AFTER PA is %i\n", swap.first->num);
	print_stack(swap.first_a, ft_stack_size(swap.first_a));
	printf("STACK B AFTER FIRST PB\n");
	//printf("STACK B AFTER PA %i\n", swap.stack_b->num);
	print_stack(swap.stack_b, ft_stack_size(swap.stack_b));
	//printf("CURRENT SWAP_STACK_A %i\n", swap.stack_a->num);
	//printf("CURRENT  OF STACK B %i\n", swap.stack_b->num);
	swap.first_a = take_first(swap.stack_a);
	//printf("FIRST OF STACK A %i\n", first_a->num);
	swap.first_b = take_first(swap.stack_b);
	//printf("FIRST OF STACK B %i\n", first_b->num);
	printf("-----------------------------\n\n");
	//print_stack(first_b);
	//printf("B BEFORE PA_B2 %i\n", first_b->num);

	pb(&swap.first_b, &swap.first_a, &swap);
	//printf("TEST\n");

	//printf("B after PA_B2 %i\n", first_b->prev->num);
	printf("STACK A AFTER  SEcond PB\n");
	print_stack(swap.first_a, ft_stack_size(swap.first_a));
	printf("STACK B AFTER  SEcond PB\n");
	print_stack(swap.first_b, ft_stack_size(swap.first_b));
	printf("-----------------------------\n\n");
	//first_b = take_first(swap.stack_b);
	
	printf("TESTE ROTATE A\n");
	rra(&swap.first_a, &swap);
	print_stack(swap.first_a, ft_stack_size(swap.first_a));

	printf("TESTE ROTATE B\n");
	rrb(&swap.first_b, &swap);
	print_stack(swap.first_b, ft_stack_size(swap.first_b));
	printf("-----------------------------\n\n");
	printf("TESTE SECOND ROTATE A\n");
	rra(&swap.first_a, &swap);
	print_stack(swap.first_a, ft_stack_size(swap.first_a));

	printf("TESTE SECOND ROTATE B\n");
	ss(&swap.first_a, &swap.first_b, &swap);
	rrb(&swap.first_b, &swap);
	print_stack(swap.first_b, ft_stack_size(swap.first_b));
	printf("-----------------------------\n\n");

//	print_stack(first_b);
//	printf("TESTE %i\n", first_b->next->num);
	//first_b = take_first(swap.stack_b); 
	free_node(swap.first_a);
	free_node(swap.first_b);
}
