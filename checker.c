/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:14:13 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:14:14 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		loc_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	swap_cmds(char buf[5], t_args **stack_a, t_args **stack_b)
{
	if (!ft_strcmp(buf, "sa"))
		call_exec(stack_a, stack_b, "sa", 0);
	else if (!ft_strcmp(buf, "sb"))
		call_exec(stack_a, stack_b, "sb", 0);
	else if (!ft_strcmp(buf, "ss"))
		call_exec(stack_a, stack_b, "ss", 0);
	else if (!ft_strcmp(buf, "pb"))
		call_exec(stack_a, stack_b, "pb", 0);
	else if (!ft_strcmp(buf, "pa"))
		call_exec(stack_a, stack_b, "pa", 0);
	else if (!ft_strcmp(buf, "ra"))
		call_exec(stack_a, stack_b, "ra", 0);
	else if (!ft_strcmp(buf, "rb"))
		call_exec(stack_a, stack_b, "rb", 0);
	else if (!ft_strcmp(buf, "rr"))
		call_exec(stack_a, stack_b, "rr", 0);
	else if (!ft_strcmp(buf, "rra"))
		call_exec(stack_a, stack_b, "rra", 0);
	else if (!ft_strcmp(buf, "rrb"))
		call_exec(stack_a, stack_b, "rrb", 0);
	else if (!ft_strcmp(buf, "rrr"))
		call_exec(stack_a, stack_b, "rrr", 0);
	else
		ft_putstr_fd("Error\n", 2);
}

void	get_input(t_args **stack_a, t_args **stack_b)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)))
	{
		line[ft_strlen(line)] = '\0';
		swap_cmds(line, stack_a, stack_b);
		free(line);
	}
	if (*stack_b == NULL && check_if_done(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (stack_a)
		ps_lstdel(stack_a);
	if (stack_b)
		ps_lstdel(stack_b);
}

int		main(int argc, char *argv[])
{
	t_args	*stack_a;
	t_args	*stack_b;
	int		check;
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
		free_two_d(str);
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
	get_input(&stack_a, &stack_b);
	return (0);
}
