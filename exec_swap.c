/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:31:57 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/10 13:31:59 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    rot_down(int *args, int num_args)
{
	int temp;

	temp = args[num_args - 1];
	while (--num_args > 0)
		args[num_args] = args[num_args - 1];
	args[0] = temp;
}


void    ft_num_swap_individual(t_args **stack_ab)
{
	int temp;

	if (!(*stack_ab)->prev && (*stack_ab)->next)
	{
		temp = (*stack_ab)->arg;
		(*stack_ab)->arg = (*stack_ab)->next->arg;
		(*stack_ab)->next->arg = temp;
	}
}

void    push_to_other(t_args **stack_from, t_args *stack_to)
{
	int i;

	i = 0;
	while (*stack_from)
		*stack_from = (*stack_from)->next;
	while (*stack_from)
	{
		(*stack_from)->next->arg = (*stack_from)->arg;
		*stack_from = (*stack_from)->prev;
	}
	/*
	while (--num_args_one >= 0)
		args_one[num_args_one + 1] = args_one[num_args_one];
	args_one[0] = args_two[0];
	i = -1;
	while (++i < num_args_two)
		args_two[i] = args_two[i + 1];
	args_two[i] = '\0';*/
}

void    rot_up(int *args, int num_args)
{
	int temp;
	int i;

	i = -1;
	temp = args[0];
	while (++i < num_args - 1)
		args[i] = args[i + 1];
	args[i] = temp;    
}

int *get_args(int *args, int num_args, char *arg_list[])
{
	int i;

	i = 0;
	while (num_args-- > 0)
	{
		if (!ft_strcmp(arg_list[i + 1], "0"))
			args[i] = 0;
		else
			args[i] = ft_atoi(arg_list[i + 1]);//the extra + 1 is to accomodate for the first argv argument being the executable name
		i++;
	}
	return (args);
}
