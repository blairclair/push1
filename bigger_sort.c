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

t_args	*list_dup(t_args *lst)
{
	t_args	*new_list;
	int		i;
	int		num;

	i = 0;
	num = lst->num_args;
	new_list = NULL;
	while (lst)
	{
		add_to_end(&new_list, num, lst->arg);
		lst = lst->next;
	}
	return (new_list);
}

void	stack_a_sort(t_args **stack_a, t_args **stack_b)
{
	int	i;
	int	lowest;
	int	check_ra;
	int	check_rra;
	t_args	*head;

	while ((*stack_a) && !check_if_done(*stack_a))
	{
		i = 0;
		lowest = get_lowest_arg(*stack_a);
		head = list_dup(*stack_a);
		check_ra = how_many_rb(head, lowest);
		head = list_dup(*stack_a);
		check_rra = how_many_rrb(head, lowest);
		if (check_ra < check_rra)
		{
			while (++i <= check_ra)
				call_exec(stack_a, stack_b, "ra");
		}
		else
		{
			while (++i <= check_rra)
				call_exec(stack_a, stack_b, "rra");
		}
		call_exec(stack_a, stack_b, "pb");
	}
	while (*stack_b)
		call_exec(stack_a, stack_b, "pa");
}