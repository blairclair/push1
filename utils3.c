/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:50:53 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 10:50:57 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_pos_no_one(t_args *stack_a, int arg, int lowest)
{
	int	i;

	i = 0;
	while (stack_a && stack_a->arg <= arg && stack_a->arg != lowest)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}