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
	return (0);
}

int	get_current_pos(t_args *stack_a, int arg, int pivot, int choice)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->arg == arg && choice == 1)
			return (i);
		if (stack_a->arg == pivot && choice == 2)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	right_to_left(t_args **stack_a, t_args **stack_b, int arg, int pivot)
{
	int	pos;
	int	piv_pos;
	t_args	*head;

	piv_pos = -1;
	pos = 0;
	while ((*stack_a)->prev)
		(*stack_a) = (*stack_a)->prev;
	head = (*stack_a);
	pos = get_current_pos(*stack_a, arg, pivot, 1);
	piv_pos = get_current_pos(*stack_a, arg, pivot, 2);
	if (piv_pos == 0 && pos == 1 && (*stack_a)->arg == arg)
		call_exec(stack_a, stack_b, "sa");
	else
	{
		while (1)
		{
			pos = get_current_pos(*stack_a, arg, pivot, 1);
			piv_pos = get_current_pos(*stack_a, arg, pivot, 2);
			if (pos < piv_pos)
				break ;
			call_exec(stack_a, stack_b, "rra");
		}
	}

}

int		check_before_pivot(t_args *stack_a, int pivot)
{
	int	i;

	i = 0;
	while (stack_a && stack_a->arg != pivot)
	{
		if (stack_a->arg < pivot)
			i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int		is_done_pivot(t_args *stack_a, int pivot)
{
	while (stack_a)
	{
		if (stack_a->arg > pivot)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	stack_to_end(t_args **stack_ab)
{
	while ((*stack_ab)->next)
		(*stack_ab) = (*stack_ab)->next;
}

int		partition(t_args **stack_a, t_args **stack_b, int lowest, int highest)
{
	int	pivot;
	int	i;
	int	side;
	int	len;
	int	j;
	t_args	*head;

	head = (*stack_a);
	pivot = (*stack_a)->arg;
	if (pivot == get_lowest_arg(*stack_a) && (*stack_a)->next)
		pivot = (*stack_a)->next->arg;
	i = -1;
	j = lowest;
	while ((*stack_a && !is_done_pivot(head, pivot) && j <= highest - 1))
	{
		if (!(*stack_a)->prev)
			head = (*stack_a);
		if ((*stack_a)->arg == pivot)
			(*stack_a) = (*stack_a)->next;
		side = which_side(head, (*stack_a)->arg, pivot);
		len = check_before_pivot(head, pivot);
		if (len)
		{
			i = -1;
			while (++i < len)
				call_exec(stack_a, stack_b, "pb");
		}
		else if (((*stack_a)->arg > pivot && side == 2) || ((*stack_a)->arg == pivot))
		{
			(*stack_a) = (*stack_a)->next;
		}
		else if ((*stack_a)->arg < pivot && side == 2)
		{
			right_to_left(stack_a, stack_b, (*stack_a)->arg, pivot);
		}
		else if ((*stack_a)->arg < pivot && side == 1)
		{
			call_exec(stack_a, stack_b, "pb");
			j++;
		}
		else if ((*stack_a)->arg > pivot && side == 1)
		{
			while (which_side(head, (*stack_a)->arg, pivot) == 1)
				call_exec(stack_a, stack_b, "ra");
		}
	}
	while (*stack_b)
		call_exec(stack_a, stack_b, "pa");
	return (j + 1);
}

int		quick_sort(t_args **stack_a, t_args **stack_b, int lowest, int highest)
{
	int	part;

	if (lowest < highest)
	{
		part = partition(stack_a, stack_b, lowest, highest);
		quick_sort(stack_a, stack_b, lowest, part - 1);
		quick_sort(stack_a, stack_b, part + 1, highest);
	}
	return (1);
}