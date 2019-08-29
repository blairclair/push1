/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:06:10 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:27:46 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_swap_extra_simple_2(t_args **stack_a, t_args **stack_b)
{
	call_exec(stack_a, stack_b, "pb", 1);
	call_exec(stack_a, stack_b, "sa", 1);
	call_exec(stack_a, stack_b, "pa", 1);
}

void	push_swap_extra_simple(t_args **stack_a, t_args **stack_b)
{
	if ((*stack_a)->num_args == 2)
		call_exec(stack_a, stack_b, "sa", 1);
	else
	{
		if ((*stack_a)->arg > (*stack_a)->next->arg &&
				(*stack_a)->next->arg < (*stack_a)->next->next->arg)
			call_exec(stack_a, stack_b, "sa", 1);
		else if ((*stack_a)->arg < (*stack_a)->next->arg &&
				(*stack_a)->next->arg > (*stack_a)->next->next->arg &&
				(*stack_a)->arg < (*stack_a)->next->next->arg)
		{
			push_swap_extra_simple_2(stack_a, stack_b);
		}
		else if ((*stack_a)->arg > (*stack_a)->next->arg &&
				(*stack_a)->next->arg > (*stack_a)->next->next->arg)
		{
			call_exec(stack_a, stack_b, "ra", 1);
			call_exec(stack_a, stack_b, "sa", 1);
		}
		else if ((*stack_a)->arg < (*stack_a)->next->arg &&
				(*stack_a)->next->arg > (*stack_a)->next->next->arg &&
				(*stack_a)->arg > (*stack_a)->next->next->arg)
			call_exec(stack_a, stack_b, "rra", 1);
	}
}

void	push_swap(t_args *stack_a, t_args *stack_b)
{
	int	*sorted_arr;
	int	middle;

	if (check_if_done(stack_a) && stack_b == NULL)
		return ;
	sorted_arr = actual_sort(stack_a);
	middle = sorted_arr[stack_a->num_args / 2];
	if (stack_a->num_args <= 3)
		push_swap_extra_simple(&stack_a, &stack_b);
	else if (stack_a->num_args <= 5)
		push_swap_simple(&stack_a, &stack_b);
	else
		stack_a = recursive_push_swap(stack_a, stack_b, sorted_arr);
	free(sorted_arr);
	ps_lstdel(&stack_a);
}

int		main(int argc, char *argv[])
{
	t_args	*stack_a;
	t_args	*stack_b;
	int		check;
	char	**str;
	int		i;

	i = 0;
	stack_b = NULL;
	stack_a = NULL;
	if ((check = is_safe(argc, argv)) <= 0)
	{
		if (check == -1)
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (check == 3)
	{
		str = ft_strsplit(argv[1], ' ');
		init_stack_a(&stack_a, count_num_2d_args(str), str, 0);
		free_two_d(str);
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
	push_swap(stack_a, stack_b);
	return (0);
}
