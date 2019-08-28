/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:45:11 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 10:45:13 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	split(t_args **stack_a, t_args **stack_b, int highest, int *sorted_arr)
{
	int	pos;
	int	check;

	check = 0;
	if (!*stack_a)
		return ;
	pos = get_average_highest(*stack_a, highest, sorted_arr[0]);
	while ((*stack_a) && (*stack_a)->arg <= highest &&
	(*stack_a)->arg != sorted_arr[0])
		split_to_b(stack_a, stack_b, pos, &check);
	pos = 0;
	while (pos < check)
	{
		if ((*stack_b) && (*stack_b)->arg != get_highest_arg(*stack_b))
			call_exec(stack_a, stack_b, "rrr");
		else
			call_exec(stack_a, stack_b, "rra");
		pos++;
	}
	if (get_lowest_arg(*stack_b) == get_value_after_last(*stack_a, sorted_arr,
	(*stack_a)->num_args + (*stack_b)->num_args) && check > 0)
		recursive_function(stack_a, stack_b, sorted_arr);
}

void	split_to_b(t_args **stack_a, t_args **stack_b, int pos, int *check)
{
	if ((*stack_a)->arg >= pos)
	{
		call_exec(stack_a, stack_b, "ra");
		(*check)++;
	}
	else
		call_exec(stack_a, stack_b, "pb");
}
