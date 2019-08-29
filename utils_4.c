/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:07:16 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:07:18 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ret_stack_b(t_args *stack_b, int temp)
{
	while (stack_b)
	{
		if (!stack_b || !stack_b->prev)
			return (1);
		if (stack_b->prev != NULL)
			temp = stack_b->prev->arg;
		if (temp < stack_b->arg)
			return (0);
		stack_b = stack_b->prev;
	}
	return (1);
}

int		is_perfect_merge(t_args *stack_a, t_args *stack_b)
{
	int	temp;
	int	first;

	first = stack_a->arg;
	while (stack_a)
	{
		if (!stack_a || !stack_a->next)
		{
			if (!stack_a->next)
				temp = stack_a->arg;
			break ;
		}
		if (stack_a->next != NULL)
			temp = stack_a->next->arg;
		if (temp < stack_a->arg)
			return (0);
		stack_a = stack_a->next;
	}
	if (stack_b->arg > first)
		return (0);
	while (stack_b->next)
		stack_b = stack_b->next;
	return (ret_stack_b(stack_b, temp));
}

int		get_lowest_arg(t_args *stack_ab)
{
	int	temp;

	temp = 0;
	if (stack_ab != NULL)
	{
		temp = stack_ab->arg;
		while (stack_ab)
		{
			if (temp > stack_ab->arg)
				temp = stack_ab->arg;
			stack_ab = stack_ab->next;
		}
	}
	return (temp);
}
