/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:33:36 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/27 16:33:40 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	recursive_function(t_args **stack_a, t_args **stack_b, int *sorted_arr)
{
	int	check;
	int	highest;

	if ((*stack_b) == NULL || (*stack_b)->num_args == 0)
		return ;
	highest = get_highest_arg(*stack_b);
	go_to_a(stack_a, stack_b, sorted_arr);
	check = VALUE_AFTER_LAST;
	while (((*stack_a)->arg == check
	|| (*stack_a)->arg == sorted_arr[0]) && !check_if_done(*stack_a))
	{
		call_exec(stack_a, stack_b, "ra", 1);
		check = VALUE_AFTER_LAST;
	}
	recursive_function(stack_a, stack_b, sorted_arr);
	if (get_pos_no_one(*stack_a, highest, sorted_arr[0]) >= 20)
		split(stack_a, stack_b, highest, sorted_arr);
	back_to_before(stack_a, stack_b, highest, sorted_arr);
}

void	back_to_before(t_args **stack_a, t_args **stack_b,
int highest, int *sorted_arr)
{
	int	check;

	while (*stack_a && (*stack_a)->arg <= highest &&
	(*stack_a)->arg != sorted_arr[0])
	{
		check = VALUE_AFTER_LAST;
		if ((*stack_a)->arg == check)
			call_exec(stack_a, stack_b, "ra", 1);
		else
			call_exec(stack_a, stack_b, "pb", 1);
	}
	check = VALUE_AFTER_LAST;
	if (get_lowest_arg(*stack_b) == check)
		recursive_function(stack_a, stack_b, sorted_arr);
}

t_args	*recursive_push_swap(t_args *stack_a, t_args *stack_b, int *sorted_arr)
{
	int pivot_a;
	int	pos;
	int	highest_a;
	int	len;

	if (check_if_done(stack_a))
		return (stack_a);
	len = stack_a->num_args;
	pivot_a = get_average(stack_a);
	while (len-- > 0)
	{
		stack_a->arg < pivot_a ? call_exec(&stack_a, &stack_b, "pb", 1) :
		call_exec(&stack_a, &stack_b, "ra", 1);
	}
	recursive_function(&stack_a, &stack_b, sorted_arr);
	highest_a = get_highest_arg(stack_a);
	pos = get_pos_no_one(stack_a, highest_a, sorted_arr[0]);
	if (pos >= 20)
	{
		split(&stack_a, &stack_b, get_highest_arg(stack_a), sorted_arr);
		split(&stack_a, &stack_b, get_highest_arg(stack_a), sorted_arr);
	}
	back_to_before(&stack_a, &stack_b, highest_a, sorted_arr);
	return (stack_a);
}
