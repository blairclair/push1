/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:08:23 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 11:08:24 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_num_args(t_args *stack_a, t_args *stack_b)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		i++;
		stack_b = stack_b->next;
	}
	return (i);
}

int		get_value_after_last(t_args *stack_ab, int *sorted_arr, int num_args)
{
	int	i;

	i = 0;
	while (stack_ab->next)
		stack_ab = stack_ab->next;
	while (i < num_args)
	{
		if (sorted_arr[i] == stack_ab->arg && i + 1 != num_args)
			return (sorted_arr[i + 1]);
		if (i + 1 == num_args)
			return (sorted_arr[i]);
		i++;
	}
	return (sorted_arr[i - 1]);
}

int		get_average(t_args *stack_ab)
{
	float	num;
	int		i;

	num = 0;
	i = 0;
	while (stack_ab)
	{
		num += stack_ab->arg;
		stack_ab = stack_ab->next;
		i++;
	}
	return ((int)(num / i + 0.5));
}

int	get_value_from_pos(t_args *stack_ab, int pos)
{
	while (stack_ab && pos > 0)
	{
		stack_ab = stack_ab->next;
		pos--;
	}
	return (stack_ab->arg);
}

int		get_average_highest(t_args *stack_ab, int highest, int lowest)
{
	int	pos;
	int	num;

	pos = 0;
	num = 0;
	if (!stack_ab)
		return (0);
	while (stack_ab && stack_ab->arg <= highest && stack_ab->arg != lowest)
	{
		num += stack_ab->arg;
		pos++;
		stack_ab = stack_ab->next;
	}
	return ((int)(num / pos + 0.5));
}
