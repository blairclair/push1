/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:08:29 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:21:57 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_merge(t_args **stack_a, t_args **stack_b)
{
	int	num_args;

	num_args = 1;
	while (((*stack_b)->next))
	{
		(*stack_b = (*stack_b)->next);
		num_args++;
	}
	while ((*stack_b))
		(*stack_b) = (*stack_b)->prev;
	while (num_args > 0)
	{
		call_exec(stack_a, stack_b, "pa", 1);
		if (*stack_b)
			(*stack_b) = (*stack_b)->next;
		num_args--;
	}
}

int		should_merge(t_args **stack_a, t_args **stack_b)
{
	if (check_if_done(*stack_a) && (*stack_b) == NULL)
	{
		return (1);
	}
	if (check_if_done((*stack_a)) && (*stack_b))
	{
		if (is_perfect_merge(*stack_a, *stack_b))
			do_merge(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int		get_loc_arg(t_args *stack_a, int arg)
{
	int	loc;

	loc = 0;
	while (stack_a)
	{
		if (stack_a->arg == arg)
			return (loc);
		stack_a = stack_a->next;
		loc++;
	}
	return (loc);
}

void	rot_to_top_simple(t_args **stack_a, t_args **stack_b, int loc)
{
	int	half_size;
	int	i;

	i = 0;
	half_size = (*stack_a)->num_args / 2;
	if (loc < half_size)
	{
		while (i < loc)
		{
			call_exec(stack_a, stack_b, "ra", 1);
			i++;
		}
	}
	else
	{
		while (i < (*stack_a)->num_args - loc)
		{
			call_exec(stack_a, stack_b, "rra", 1);
			i++;
		}
	}
}

int		push_swap_simple(t_args **stack_a, t_args **stack_b)
{
	int	lowest;

	while (1)
	{
		lowest = get_lowest_arg(*stack_a);
		if (check_if_done(*stack_a) && *stack_b == NULL)
			return (1);
		if (should_merge(stack_a, stack_b))
			return (1);
		if ((*stack_a)->arg == lowest)
			call_exec(stack_a, stack_b, "pb", 1);
		else
			rot_to_top_simple(stack_a, stack_b, get_loc_arg(*stack_a, lowest));
	}
}
