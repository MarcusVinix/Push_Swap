/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:16:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/07 15:03:35 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argv, char **argc)
{
	t_swap	swap;

	printf("ARGV %i\n", argv);
	//ft_bzero(&swap.stack, sizeof(s_stack));
	if (argv < 2)
		exit(0);
	parser_args(&swap, argv - 1, argc);
	printf("HI\n");
}
