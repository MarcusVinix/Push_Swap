/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:16:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/15 18:17:13 by mavinici         ###   ########.fr       */
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
	if (argv < 2)
		exit(0);
	//swap.stack_a = NULL;
	swap.stack_b = NULL;
	swap.stack_a = NULL;
	swap.size_a = argv - 1;
	swap.size_b = 0;
	//printf("SIZE %i\n", swap.size_a);
	parser_args(&swap, argv - 1, argc);

	//print_stack(swap.stack_a, ft_lstsize((t_list *)swap.stack_a));
	sort_node(&swap.stack_a, &swap.stack_b, &swap);
	//printf("------------------------------------------\n\n");
//
//	print_stack(swap.stack_a, ft_lstsize((t_list *)swap.stack_a));

	//printf("------------------------------------------\n\n");
	//printf("FINAL: %i\n", swap.stack_a->num);
	//printf("STACK\n");
	//print_stack(swap.stack_a, ft_lstsize((t_list *)swap.stack_a));
	//swap.size_a = ft_lstsize((t_list *)swap.stack_a);
	free_node(swap.stack_a);
	//free_node(swap.first_b);
}
