/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:35:06 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 10:35:08 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    init_stack_a(t_args **stack_a, int num_args, char *argv[], int i)
{
	int	j;

	if (i == 0)
		j = num_args;
	else
		j = num_args + 1;
    while (i < j)
    {
        add_to_end(stack_a, num_args, ft_atoi(argv[i]));
        i++;
    }
}