/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:41:53 by agrodzin          #+#    #+#             */
/*   Updated: 2019/01/08 11:10:06 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		loc_char(char *str, char c){
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}

void	swap_cmds(char buf[5], t_args **stack_a, t_args **stack_b)
{
	if (!ft_strcmp(buf, "sa"))
		call_exec(stack_a, stack_b, "sa");
	else if (!ft_strcmp(buf, "sb"))
		call_exec(stack_a, stack_b, "sb");
	else if (!ft_strcmp(buf, "ss"))
		call_exec(stack_a, stack_b, "ss");
	else if (!ft_strcmp(buf, "pb"))
		call_exec(stack_a, stack_b, "pb");
	else if (!ft_strcmp(buf, "pa"))
		call_exec(stack_a, stack_b, "pa");
	else if (!ft_strcmp(buf, "ra"))
		call_exec(stack_a, stack_b, "ra");
	else if (!ft_strcmp(buf, "rb"))
		call_exec(stack_a, stack_b, "rb");
	else if (!ft_strcmp(buf, "rr"))
		call_exec(stack_a, stack_b, "rr");
	else if (!ft_strcmp(buf, "rra"))
		call_exec(stack_a, stack_b, "rra");
	else if (!ft_strcmp(buf, "rrb"))
		call_exec(stack_a, stack_b, "rra");
	else if (!ft_strcmp(buf, "rrr"))
		call_exec(stack_a, stack_b, "rrr");
	else
		ft_putstr_fd("Error\n", 2);
	print_list(*stack_a, *stack_b);
}

void    get_input(t_args **stack_a, t_args **stack_b)
{
	char    *line;
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
}

int main(int argc, char *argv[])
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
		free_two_d(str);
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
	get_input(&stack_a, &stack_b);
	if (stack_a)
		ps_lstdel(&stack_a);
	if (stack_b)
		ps_lstdel(&stack_b);
	// printf("arg: %d\n", stack_a->arg);
	sleep(30);
	return (0);
}
