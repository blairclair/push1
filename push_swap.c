/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:06:10 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/19 15:06:11 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_highest_arg(t_args *stack_a, t_args *stack_b)
{
	int	temp;

	temp = 0;
	if (stack_a != NULL)
	{
		temp = stack_a->arg;
		while (stack_a)
		{
			if (temp < stack_a->arg)
				temp = stack_a->arg;
			stack_a = stack_a->next;
		}
	}
	if (stack_b != NULL)
	{
		while (stack_b)
		{
			if (temp < stack_b->arg)
				temp = stack_b->arg;
			stack_b = stack_b->next;
		}
	}
	return (temp);
}

int		get_lowest_arg(t_args *stack_a, t_args *stack_b)
{
	int	temp;

	temp = 0;
	if (stack_a != NULL)
	{
		temp = stack_a->arg;
		while (stack_a)
		{
			if (temp > stack_a->arg)
				temp = stack_a->arg;
			stack_a = stack_a->next;
		}
	}
	if (stack_b != NULL)
	{
		while (stack_b)
		{
			if (temp > stack_b->arg)
				temp = stack_b->arg;
			stack_b = stack_b->next;
		}
	}
	return (temp);
}

int	get_unsorted_pos(t_args *stack_a)//not zero based
{
	int	temp;
	int	i;

	i = 1;
	if (stack_a == NULL)
		return (-1);
	while (stack_a)
	{
		temp = stack_a->arg;
		if (stack_a->next)
		{
			if (temp > stack_a->next->arg)
				return (i + 1);
		}
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	push_swap_simple(t_args *stack_a, t_args *stack_b)
{
	int	pos;
	int	lowest;
	int	highest;

	pos = get_unsorted_pos(stack_a);
	lowest = get_lowest_arg(stack_a, stack_b);
	highest = get_highest_arg(stack_a, stack_b);
//	stack_b = NULL;
	
}

void	push_swap(t_args *stack_a, t_args *stack_b)
{
	// if (stack_a->num_args <= 5)
	// {
		push_swap_simple(stack_a, stack_b);
	// }

}

int		main(int argc, char *argv[])
{
	t_args  *stack_a;
    t_args  *stack_b;
    int     check;

	stack_b = NULL;
	stack_a = NULL;
    if ((check = is_safe(argc, argv)) <= 0)
    {
        if (check == -1)
            ft_putstr_fd("Error\n", 2);
        return (0);
    }
    init_stack_a(&stack_a, argc - 1, argv);
	push_swap(stack_a, stack_b);
}