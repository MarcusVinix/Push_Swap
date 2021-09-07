/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:17:55 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/07 17:49:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;
typedef struct s_swap
{
	t_stack	*stack;
	t_stack *first;
}				t_swap;

void	parser_args(t_swap *swap, int argv, char **argc);

#endif
