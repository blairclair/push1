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

int		how_many_rb(t_args *stack_b, int highest)
{
	int	track_rb;

	track_rb = 0;
	if (stack_b->arg == highest)
		return (0);
	if (stack_b->num_args == 2)
		return (1);
	while (stack_b->arg != highest)
	{
		rot_up(&stack_b);
		track_rb++;
	}
	return (track_rb);
}

int		how_many_rrb(t_args *stack_b, int highest)
{
	int	track_rrb;

	if (stack_b->arg == highest)
		return (0);
	if (stack_b->num_args == 2)
		return (1);
	track_rrb = 0;
	while (stack_b->arg != highest)
	{
		rot_down(&stack_b);
		track_rrb++;
	}
	return (track_rrb);
}

void	stack_b_sort(t_args **stack_a, t_args **stack_b)
{
	int		i;
	int		highest;
	int		track_rb;
	int		track_rrb;

	track_rrb = 0;
	i = -1;
	while ((*stack_b))
	{
		highest = get_highest_arg(*stack_b);
		track_rb = how_many_rb(*stack_b, highest);
		track_rrb = how_many_rrb(*stack_b, highest);
		if (track_rb < track_rrb)
		{
			while (++i < track_rb)
				call_exec(stack_a, stack_b, "rb");
		}
		else
		{
			while (++i < track_rrb)
				call_exec(stack_a, stack_b, "rrb");
		}
		call_exec(stack_a, stack_b, "pa");
	}
}

void	stack_a_sort(t_args **stack_a, t_args **stack_b, int pivot)
{
	int	i;
	int	mult_pivots[pivot + 1];
	int	num_check;

	i = -1;
	num_check = -1;
	while (++i < pivot)
		mult_pivots[i] = ((*stack_a)->num_args / pivot) * (i + 1);
	i = 0;
	while ((*stack_a) && !check_if_done(*stack_a))
	{
		while ((*stack_a) && num_check != (*stack_a)->arg
		&& mult_pivots[i] != (*stack_a)->arg)
		{
			if ((*stack_a)->arg <= mult_pivots[i])
				call_exec(stack_a, stack_b, "pb");
			else
			{
				num_check = (*stack_a)->arg;
				call_exec(stack_a, stack_b, "ra");//instead of just doing ra 
				//figure out which will get you to a number <= multpivot[i] faster
			}
		}
		// if (i == pivot - 1 && (*stack_a)->arg != mult_pivots[i])
		// 	call_exec(stack_a, stack_b, "pb");
		if (i < pivot - 1)
			i++;
	}
}