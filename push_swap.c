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
		ft_printf("pb\n");
		push_to(stack_a, stack_b);
		pos--;
	}
	ft_printf("ra\n");
	rot_up(stack_a);
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
		ft_printf("pa\n");
		push_to(stack_b, stack_a);
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
			ft_printf("pb\n");
			push_to(stack_a, stack_b);
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
			{
				ft_printf("ss\n");
				ft_num_swap_individual(stack_a);
			}
			else
				ft_printf("sb\n");
			ft_num_swap_individual(stack_b);
		}
		else if (last > (*stack_b)->arg)
		{
			if ((*stack_a) && get_last_arg(*stack_a) == get_lowest_arg(*stack_a))
			{
				ft_printf("rrr\n");
				rot_down(stack_a);
			}
			else
				ft_printf("rrb\n");
			rot_down(stack_b);
		}
		else if ((*stack_b) && (*stack_b)->arg == lowest)
		{
			if ((*stack_a) && (*stack_a)->arg == get_highest_arg(*stack_a))
			{
				ft_printf("rr\n");
				rot_up(stack_a);
			}
			else
				ft_printf("rb\n");
			rot_up(stack_b);
		}
		else if ((*stack_b)->arg == highest && (*stack_b)->arg < (*stack_a)->arg)
		{
			ft_printf("pa\n");
			push_to(stack_b, stack_a);
		}
		else
		{
			ft_printf("rrb\n");
			rot_down(stack_b);

		}
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

void	should_merge(t_args **stack_a, t_args **stack_b)
{
	if (check_if_done(*stack_a) && (*stack_b) == NULL)
	{
		exit(0);
	}
	if (check_if_done((*stack_a)) && (*stack_b))
	{
		if (is_perfect_merge(*stack_a, *stack_b))
			do_merge(stack_a, stack_b);
		else
			make_merge_perfect(stack_a, stack_b);
		exit(0);
	}
}

void	push_swap_simple(t_args **stack_a, t_args **stack_b)
{
	int	pos;
	int	lowest;
	int	highest;
	int	check;

	check = -1;
	while (1)
	{
		lowest = get_lowest_arg(*stack_a);
		highest = get_highest_arg(*stack_a);
		pos = get_unsorted_pos(*stack_a, 1);
		if (!check_stack_b(*stack_b))
			resort_stack_b(stack_a, stack_b);
		if (check_if_done(*stack_a) && (*stack_b) == NULL)
			break ;
		if (check_if_done((*stack_a)) && (*stack_b))
			should_merge(stack_a, stack_b);
		if ((*stack_a)->arg > (*stack_a)->next->arg)
		{
			ft_printf("sa\n");
			ft_num_swap_individual(stack_a);
			should_merge(stack_a, stack_b);
		}
		if (check == -1)
			check = choose_rot(*stack_a, lowest);
		if ((*stack_a)->arg == lowest)
		{
			ft_printf("pb\n");
			push_to(stack_a, stack_b);
			check = -1;
			should_merge(stack_a, stack_b);
		}
		if (check != -1)
		{
			if (check == 1)
			{
				ft_printf("ra\n");
				rot_up(stack_a);
			}
			else
			{
				ft_printf("rra\n");
				rot_down(stack_a);
			}
			should_merge(stack_a, stack_b);
		}
	}
}

t_args	*push_swap(t_args *stack_a, t_args *stack_b)
{
	// if (stack_a->num_args <= 5)
	// {
	if (check_if_done(stack_a) && stack_b == NULL)
		return (stack_a);
	push_swap_simple(&stack_a, &stack_b);
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
    	init_stack_a(&stack_a, count_num_2d_args(str) - 1, str, 0);
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
	stack_a = push_swap(stack_a, stack_b);
}
