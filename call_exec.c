/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:55:46 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/27 12:55:47 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_exec_three(t_args **stack_a, t_args **stack_b, char *choice)
{
	if (!ft_strcmp(choice, "ra"))
	{
		ft_printf("ra\n");
		rot_up(stack_a);
	}
	else if (!ft_strcmp(choice, "rb"))
	{
		ft_printf("rb\n");
		rot_up(stack_b);
	}
	else if (!ft_strcmp(choice, "pb"))
	{
		ft_printf("pb\n");
		push_to(stack_a, stack_b);
	}
	else if (!ft_strcmp(choice, "pa"))
	{
		ft_printf("pa\n");
		push_to(stack_b, stack_a);
	}
}

void	call_exec_two(t_args **stack_a, t_args **stack_b, char *choice)
{
	if (!ft_strcmp(choice, "rrr"))
	{
		ft_printf("rrr\n");
		rot_down(stack_a);
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rra"))
	{
		ft_printf("rra\n");
		rot_down(stack_a);
	}
	else if (!ft_strcmp(choice, "rrb"))
	{
		ft_printf("rrb\n");
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rr"))
	{
		ft_printf("rr\n");
		rot_up(stack_a);
		rot_up(stack_b);
	}
	else
		call_exec_three(stack_a, stack_b, choice);
}

void	call_exec(t_args **stack_a, t_args **stack_b, char *choice)
{
	g_test_line_num++;
	if (!ft_strcmp(choice, "ss"))
	{
		ft_printf("ss\n");
		ft_num_swap_individual(stack_a);
		ft_num_swap_individual(stack_b);
	}
	else if (!ft_strcmp(choice, "sa"))
	{
		ft_printf("sa\n");
		ft_num_swap_individual(stack_a);
	}
	else if (!ft_strcmp(choice, "sb"))
	{
		ft_printf("sb\n");
		ft_num_swap_individual(stack_b);
	}
	else
		call_exec_two(stack_a, stack_b, choice);
}
