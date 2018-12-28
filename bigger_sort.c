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

int		which_side(t_args *stack_a, int arg, int pivot)
{
	while (stack_a)
	{
		if (stack_a->arg == arg)
			return (1);
		if (stack_a->arg == pivot)
			return (2);
		stack_a = stack_a->next;
	}
}



int		partition(t_args **stack_a, t_args **stack_b, int lowest, int highest)
{
	int	pivot;
	int	j;
	int	side;

	pivot = (*stack_a)->arg;
	j = lowest;
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	while (j <= highest - 1)
	{
		side = which_side(*stack_a, (*stack_a)->arg, pivot);
		if ((*stack_a)->arg < pivot && side == 1)
			(*stack_a) = (*stack_a)->next;
		else if ((*stack_a)->)
		j++;
	}
	return ();
}

int		quick_sort(t_args **stack_a, t_args **stack_b, int lowest, int highest)
{
	int	part;

	if (lowest < highest)
	{
		part = partition(stack_a, stack_b, lowest, highest)

	}
}