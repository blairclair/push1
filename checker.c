/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:34:04 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/03 11:17:06 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_to_end(t_args **head, int arg, int num_args)
{
	t_args	*newnode;
	t_args	*last;

	newnode = (t_args*)ft_memalloc(sizeof(t_args));
	last = (*head);
	newnode->arg = arg;
	newnode->num_args = num_args;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		(*head) = newnode;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newnode;
	newnode->prev = last;
}

void	print_list(t_args *stack_a, t_args *stack_b)
{
	while (stack_a)
	{
		printf("a: %d\n", stack_a->arg);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("b: %d\n", stack_b->arg);
		stack_b = stack_b->next;
	}
}

void	get_list(t_args **stack_a, int num_args, char *arg_list[])
{
	int	i;

	i = 0;
	while (++i < num_args + 1)
	{
		add_to_end(stack_a, ft_atoi(arg_list[i]), num_args);
	}
}

/*
int	sort_by_instructions_p2(int *args_a, int *args_b, char *str, t_arg_nums *nums)
{
	if (!ft_strcmp(str, "ra") && nums->num_args_a > 1)
		rot_up(args_a, nums->num_args_a);
	else if (!ft_strcmp(str, "rb") && nums->num_args_b > 1)
		rot_up(args_b, nums->num_args_b);
	else if (!ft_strcmp(str, "rr") && nums->num_args_a > 1 &&
	nums->num_args_b > 1)
	{
		rot_up(args_a, nums->num_args_a);
		rot_up(args_b, nums->num_args_b);
	}
	else if (!ft_strcmp(str, "rra") && nums->num_args_a > 1)
		rot_down(args_a, nums->num_args_a);
	else if (!ft_strcmp(str, "rrb") && nums->num_args_b > 1)
		rot_down(args_b, nums->num_args_b);
	else if (!ft_strcmp(str, "rrr") && nums->num_args_a > 1 &&
	nums->num_args_b > 1)
	{
		rot_down(args_a, nums->num_args_a);
		rot_down(args_b, nums->num_args_b);
	}
	else
		return (0);
	return (1);
}

int    sort_by_instructions(int *args_a, int *args_b,
char *str, t_arg_nums *nums)
{
	int	check;

	check = 1;
	if (!ft_strcmp(str, "sa") && nums->num_args_a > 1)
		ft_num_swap_individual(args_a, 0);
	else if (!ft_strcmp(str, "sb") && nums->num_args_b > 1)
		ft_num_swap_individual(args_b, 0);
	else if (!ft_strcmp(str, "ss") && nums->num_args_a > 1 && nums->num_args_b > 1)
	{
		ft_num_swap_individual(args_a, 0);
		ft_num_swap_individual(args_b, 0);
	}
	else if (!ft_strcmp(str, "pa") && nums->num_args_b > 0)
		push_to_other(args_a, args_b, nums->num_args_a, nums->num_args_b);
	else if (!ft_strcmp(str, "pb") && nums->num_args_a > 0)
		push_to_other(args_b, args_a, nums->num_args_b, nums->num_args_a);
	else
		check = sort_by_instructions_p2(args_a, args_b, str, nums);
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
	{
		(str[1] == 'a') ? nums->num_args_a++ : nums->num_args_a--;
		(str[1] == 'b') ? nums->num_args_b++ : nums->num_args_b--;
	}
	return (check == 1 ? 1 : 0);
}*/

int		sort_by_instructions(t_args **stack_a, t_args **stack_b, char *str)
{
		// printf("str: %s\n", str);
	(*stack_b)->arg = 1;
	if (!ft_strcmp(str, "sa"))
		ft_num_swap_individual(stack_a);
	else if (!ft_strcmp(str, "pb"))
	{
		
	}
	return (1);
}

int		check_if_sorted(t_args *stack_a)
{
	int	temp;

	while (stack_a)
	{
		if (stack_a->next)
			temp = stack_a->next->arg;
		if (temp < stack_a->arg)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_instructions(t_args *stack_a, t_args *stack_b)
{
	char	*str;
	int		ret;

	str = ft_memalloc(5);
	print_list(stack_a, stack_b);
	while ((ret = read(1, str, 5) > 0))
	{
		str[ret + 1] = '\0';
		sort_by_instructions(&stack_a, &stack_b, str);
		print_list(stack_a, stack_b);
	}
	return (1);
}
/*
int	*check_instructions(int *args_a, t_arg_nums *nums)
{
	char	*str;
	int		ret;
	int		*args_b;

	str = ft_memalloc(5);
	args_b = ft_memalloc(nums->num_args_a * sizeof(int*) + 1);
	while ((ret = read(1, str, 5)) != 0)
	{
		str[ret - 1] = '\0';
		if (!sort_by_instructions(args_a, args_b, str, nums))
		{
			ft_putstr_fd("Error\n", 2);
			free(args_b);
			return (NULL);
		}
	}
	if (check_if_sorted(args_a, nums))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(args_b);
	return (args_a);
}*/

int	main(int argc, char *argv[])
{
	t_args	*stack_a;
	t_args	stack_b;
	int		check;

	check = is_safe(argc, argv);
	stack_b.num_args = 0;
	if (check == 0)
		return (0);
	else if (check == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	get_list(&stack_a, argc - 1, argv);
	check_instructions(stack_a, &stack_b);
	// print_list(stack_a);
	if (check_if_sorted(stack_a))
		printf("yes\n");
	else
		printf("no\n");
	return (0);
}
