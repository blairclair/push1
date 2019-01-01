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

#include "push_swap.h"	

int		get_average(t_args *stack_ab)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (stack_ab)
	{
		num += stack_ab->arg; 
		stack_ab = stack_ab->next;
		i++;
	}
	num /= i;
	return (num);	
}

int		get_pos_arg(t_args *stack_ab, int arg)
{
	int	pos;

	pos = 0;
	while (stack_ab)
	{
		if (stack_ab->arg == pos)
			return (pos);
		pos++;
		stack_ab = stack_ab->next;
	}
	return (pos);
}

void	go_to_a(t_args **stack_a, t_args **stack_b)
{
	int	highest_b;
	int	last_a;
	int	pos;
	
	while ((*stack_b)->num_args > 0)
	{
		if ((*stack_b)->num_args < 13)
		{
			highest_b = get_highest_arg(*stack_b);
			last_a = get_last_arg(stack_a);
			if (highest_b == (*stack_b)->arg)
				call_exec(stack_a, stack_b, "pa");
			else
			{
				if ((*stack_b)->arg == 1 || (*stack_b)->arg == last_a + 1)
				{
					call_exec(stack_a, stack_b, "pa");
					call_exec(stack_a, stack_b, "ra");
				}
				else
					pos = get_pos_arg(*stack_a, get_highest_arg(*stack_a));
					if (pos <= (*stack_a)->num_args / 2)
						call_exec(stack_a, stack_b, "rrb");
					else
						call_exec(stack_a, stack_b, "rrb");
			}
		}
	}
}

int		get_pos_no_one(t_args *stack_a, int arg)
{
	int	i;

	i = 0;
	while (stack_a && stack_a->arg <= arg && stack_a->arg != 1)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int		get_average_highest(t_args *stack_ab, int highest)
{
	while (stack_ab && stack_ab <= highest)
	{
		stack_ab = stack_ab->next;
	}
}

void	split(t_args **stack_a, t_args **stack_b, int highest)
{
	int	pos;
	int	check;

	check = 0;
	
}

void	recursive_function(t_args **stack_a, t_args **stack_b)
{
	int	highest;
	int	average;

	average = get_average(*stack_a);
	highest = get_highest_arg(*stack_b);
	go_to_a(stack_a, stack_b);
	while (((*stack_a)->arg == get_last_arg(*stack_a) + 1
	|| (*stack_a)->arg == 1) && !check_if_done(*stack_a))
		call_exec(stack_a, stack_b, "ra");
	recursive_function(stack_a, stack_b);
	if (get_pos_no_one(*stack_a, highest))
		split(stack_a, stack_a, get_highest_arg((stack_b)));
}

t_args	*recursive_push_swap(t_args *stack_a, t_args *stack_b)
{
	int pivot_a;

	pivot_a = get_average(stack_a);
	while (get_lowest_arg(stack_a) < pivot_a)
	{
		if (stack_a->arg < pivot_a)
			call_exec(&stack_a, &stack_b, "pb");
		else
			call_exec(&stack_a, &stack_b, "ra");
	}
	return (stack_a);
}