/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:16:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:43:06 by mavinici         ###   ########.fr       */
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

	if (argv < 2)
		exit(0);
	swap.stack_b = NULL;
	swap.stack_a = NULL;
	swap.size_a = argv - 1;
	swap.size_b = 0;
	parser_args(&swap, argv - 1, argc);
	sort_node(&swap.stack_a, &swap.stack_b, &swap);
	free_node(swap.stack_a);
}
