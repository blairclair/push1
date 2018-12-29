/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:06:10 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/22 18:44:44 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_highest_arg(t_args *stack_ab)
{
	int	temp;

	temp = 0;
	if (stack_ab != NULL)
	{
		temp = stack_ab->arg;
		while (stack_ab)
		{
			if (temp < stack_ab->arg)
				temp = stack_ab->arg;
			stack_ab = stack_ab->next;
		}
	}
	return (temp);
}

int		get_lowest_arg(t_args *stack_ab)
{
	int	temp;

	temp = 0;
	if (stack_ab != NULL)
	{
		temp = stack_ab->arg;
		while (stack_ab)
		{
			if (temp > stack_ab->arg)
				temp = stack_ab->arg;
			stack_ab = stack_ab->next;
		}
	}
	return (temp);
}

int	get_unsorted_pos(t_args *stack_ab, int stack)//not zero based
{
	int	temp;
	int	i;

	i = 0;
	if (stack_ab == NULL)
		return (-1);
	while (stack_ab)
	{
		temp = stack_ab->arg;
		if (stack_ab->next)
		{
			if (temp > stack_ab->next->arg && stack == 1)
				return (i + 1);
			else if (temp < stack_ab->next->arg && stack == 2)
				return (i + 1);
		}
		stack_ab = stack_ab->next;
		i++;
	}
	return (i);
}

int		pos_as_last_value(t_args *stack_a, int pos)
{
	int	arg;

	while (stack_a && pos > 0)
	{
		stack_a = stack_a->next;
		pos--;
	}
	if (stack_a)
		arg = stack_a->arg;
	else
		return (0);
	while (stack_a->next)
		stack_a = stack_a->next;
	if (arg > stack_a->arg)
		return (1);
	return (0);
}

void	make_pos_last_value(t_args **stack_a, t_args **stack_b, int pos)
{
	while (pos > 1)
	{
		call_exec(stack_a, stack_b, "pb");
		pos--;
	}
	call_exec(stack_a, stack_b, "ra");
}

int		is_perfect_merge(t_args *stack_a, t_args *stack_b)
{
	int	temp;
	int	first;

	first = stack_a->arg;
	while (stack_a)
	{
		if (!stack_a || !stack_a->next)
		{
			if (!stack_a->next)
				temp = stack_a->arg;
			break ;
		}
		if (stack_a->next != NULL)
			temp = stack_a->next->arg;
		if (temp < stack_a->arg)
			return (0);
		stack_a = stack_a->next;
	}
	if (stack_b->arg > first)
		return (0);
	while (stack_b->next)
		stack_b = stack_b->next;
	while (stack_b)
	{
		if (!stack_b || !stack_b->prev)
			return (1);
		if (stack_b->prev != NULL)
			temp = stack_b->prev->arg;
		if (temp < stack_b->arg)
			return (0);
		stack_b = stack_b->prev;
	}
	return (1);
}

void	do_merge(t_args **stack_a, t_args **stack_b)
{
	int	num_args;

	num_args = 1;
	while (((*stack_b)->next))
	{
		(*stack_b = (*stack_b)->next);
		num_args++;
	}
	while ((*stack_b))
		(*stack_b) = (*stack_b)->prev;
	while (num_args > 0)
	{
		call_exec(stack_a, stack_b, "pa");
		if (*stack_b)
			(*stack_b) = (*stack_b)->next;
		num_args--;
	}
}

int		last_as_first_value(t_args *stack_ab, int lowest)
{
	while (stack_ab->next)
		stack_ab = stack_ab->next;
	if (stack_ab->arg == lowest)
		return (1);
	return (0);
}

int		check_stack_b(t_args *stack_b)
{
	int	temp;

	if (!stack_b)
		return (1);
	while (stack_b)
	{
		if (!stack_b || !stack_b->next)
			return (1);
		if (stack_b->next != NULL)
			temp = stack_b->next->arg;
		if (temp > stack_b->arg)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

void	make_merge_perfect(t_args **stack_a, t_args **stack_b)
{
	int	lowest_a;
	int	highest_b;

	lowest_a = get_lowest_arg(*stack_a);
	highest_b = get_highest_arg(*stack_b);
	if (highest_b > lowest_a)
	{
		while (1)
		{
			call_exec(stack_a, stack_b, "pb");
			lowest_a = get_lowest_arg(*stack_a);
			highest_b = get_highest_arg(*stack_b);
			if (highest_b < lowest_a)
			{
				resort_stack_b(stack_a, stack_b);
				break ;
			}
		}
	}
	do_merge(stack_a, stack_b);
}

int		get_last_arg(t_args *stack_ab)
{
	while (stack_ab->next)
		stack_ab = stack_ab->next;
	return (stack_ab->arg);
}

void	resort_stack_b(t_args **stack_a, t_args **stack_b)
{
	int	pos;
	int	lowest;
	int	highest;
	int	last;

	while (1)
	{
		lowest = get_lowest_arg(*stack_b);
		highest = get_highest_arg(*stack_b);
		pos = get_unsorted_pos(*stack_b, 2);
		last = get_last_arg(*stack_b);
		if (check_stack_b(*stack_b))
			break ;
		else if ((*stack_b)->next && (*stack_b)->arg < (*stack_b)->next->arg)
		{
			if (*stack_a && (*stack_a)->next && (*stack_a)->arg > (*stack_a)->next->arg)
				call_exec(stack_a, stack_b, "ss");
			else
				call_exec(stack_a, stack_b, "sb");
		}
		else if (last > (*stack_b)->arg)
		{
			if ((*stack_a) && get_last_arg(*stack_a) == get_lowest_arg(*stack_a))
				call_exec(stack_a, stack_b, "rrr");
			else
				call_exec(stack_a, stack_b, "rrb");
		}
		else if ((*stack_b) && (*stack_b)->arg == lowest)
		{
			if ((*stack_a) && (*stack_a)->arg == get_highest_arg(*stack_a))
				call_exec(stack_a, stack_b, "rr");
			else
				call_exec(stack_a, stack_b, "rb");
		}
		else if ((*stack_b)->arg == highest && (*stack_b)->arg < (*stack_a)->arg)
			call_exec(stack_a, stack_b, "pa");
		else
			call_exec(stack_a, stack_b, "rrb");
	}
}

int		choose_rot(t_args *stack_a, int lowest)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->arg == lowest)
			break ; 
		i++;
		stack_a = stack_a->next;
	}
	if (i > stack_a->num_args / 2)
	{
		return(2);
	}
	return (1);
}

int		should_merge(t_args **stack_a, t_args **stack_b)
{
	if (check_if_done(*stack_a) && (*stack_b) == NULL)
	{
		return (1);
	}
	if (check_if_done((*stack_a)) && (*stack_b))
	{
		if (is_perfect_merge(*stack_a, *stack_b))
			do_merge(stack_a, stack_b);
		else
			make_merge_perfect(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int		get_something(t_args *stack_a, int lowest)
{
	int	tmp;
	int	i;
	int	num;
	int	divi;

	i = 0;
	tmp = stack_a->arg;
		// printf("tmp: %d\n", tmp);
	num = stack_a->num_args;
	divi = num % 2;
	while (stack_a)
	{
		if (stack_a->arg == lowest)
			break ;
			i++;
		stack_a = stack_a->next;
	}
	// printf("i: %d\n", i);
	if ((i > num / 2))// || (i == num / 2 && divi == 0))
		return (3);
	return (1);
}

int		push_swap_simple(t_args **stack_a, t_args **stack_b)
{
	int	pos;
	int	lowest;
	int	highest;
	int	check;
	int	last;

	check = -1;
	while (1)
	{
		lowest = get_lowest_arg(*stack_a);
		highest = get_highest_arg(*stack_a);
		pos = get_unsorted_pos(*stack_a, 1);
		last = get_last_arg(*stack_a);
		if (check_if_done(*stack_a) && (*stack_b) == NULL)
			return (1);
		if (check_if_done((*stack_a)) && (*stack_b))
		{
			if (should_merge(stack_a, stack_b))
				return (1);
		}

		if (check == -1)
			check = get_something(*stack_a, lowest);
		if ((*stack_a)->arg == lowest)
		{
			call_exec(stack_a, stack_b, "pb");
			check = -1;
			if (should_merge(stack_a, stack_b))
				return (1);
		}
		if ((*stack_a)->arg > (*stack_a)->next->arg)
		{
			if (is_backwards(*stack_a, highest) && (*stack_b))
				call_exec(stack_a, stack_b, "sa");
			else if (get_something(*stack_a, lowest) == 1 && check != 3)
			{
				call_exec(stack_a, stack_b, "ra");
				check = 1;
			}
			else if (lowest == last && check != 1)
			{
				call_exec(stack_a, stack_b, "rra");
				check = 3;
			}
			else
				call_exec(stack_a, stack_b, "sa");
			if (should_merge(stack_a, stack_b))
				return (1);
		}
		else if (check != -1)
		{
			if ((*stack_a)->arg != lowest && (*stack_a)->next &&
			 (*stack_a)->next->arg == highest && last != lowest)
			{
				call_exec(stack_a, stack_b, "ra");
				call_exec(stack_a, stack_b, "ra");
				check = 1;
			}
			else if (check == 1)
				call_exec(stack_a, stack_b, "ra");
			else if (check == 3)
				call_exec(stack_a, stack_b, "rra");
			if (should_merge(stack_a, stack_b))
				return (1);
		}
		if (g_test_line_num > 30)
			return (1);
	}
}

t_args	*push_swap(t_args *stack_a, t_args *stack_b)
{
	// if (stack_a->num_args <= 5)
	// {

	g_test_line_num = 0;
	if (check_if_done(stack_a) && stack_b == NULL)
		return (stack_a);
	if (stack_a->num_args <= 5)
		push_swap_simple(&stack_a, &stack_b);
	else
		quick_sort(&stack_a, &stack_b, 0, stack_a->num_args);

	// printf("line num %d\n", g_test_line_num);
	// }
	return (stack_a);
}

int		main(int argc, char *argv[])
{
	t_args  *stack_a;
	t_args  *stack_b;
	int     check;
	char	**str;

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
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
	push_swap(stack_a, stack_b);
}
