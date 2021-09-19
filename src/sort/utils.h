/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:34:44 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:36:36 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../includes/push_swap.h"

typedef struct s_var
{
	int		count;
	int		dif;
	int		pos;
	t_stack	*tmp;
}				t_var;

#endif
