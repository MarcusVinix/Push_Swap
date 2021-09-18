/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:17:55 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 19:27:46 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;
typedef struct s_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*first_a;
	t_stack	*first_b;
	int		size_a;
	int		size_b;
}				t_swap;

void	parser_args(t_swap *swap, int argv, char **argc);
void	free_node(t_stack *node);
t_stack	*take_first(t_stack *stack);
t_stack	*new_node(void);
void	check_duplicates(t_stack *stack);
void	errors(void);
int		ft_stack_size(t_stack *lst);
void	print_stack(t_stack *stack, int size);

//commands
void	sa(t_stack **stack, t_swap *swap);
void	sb(t_stack **stack, t_swap *swap);
void	ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	pa(t_stack **stack_to, t_stack **stack_from, t_swap *swap);
void	pb(t_stack **stack_from, t_stack **stack_to, t_swap *swap);
void	rr(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	ra(t_stack **stack, t_swap *swap);
void	rb(t_stack **stack, t_swap *swap);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	rra(t_stack **stack, t_swap *swap);
void	rrb(t_stack **stack, t_swap *swap);

//sort
void	sort_node(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	sort_three(t_stack **stack, t_swap *swap);
void	sort_four(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_swap *swap, int n);
void	sort_list(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
int		is_order(t_stack *stack, t_swap *swap);
int		is_rev_order(t_stack *stack);
int		ft_min_num(t_stack **stack);
int		ft_max_num(t_stack **stack);

void	check_pos_to_push(t_stack **stack, t_swap *swap, int pos);
#endif
