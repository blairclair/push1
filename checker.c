/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:41:53 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/18 20:41:54 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_cmds(char buf[5], t_args **stack_a, t_args **stack_b)
{
    if (!ft_strcmp(buf, "sa"))
        ft_num_swap_individual(stack_a);
	else if (!ft_strcmp(buf, "sb"))
		ft_num_swap_individual(stack_b);
	else if (!ft_strcmp(buf, "ss"))
	{
		ft_num_swap_individual(stack_a);
		ft_num_swap_individual(stack_b);
	}
	else if (!ft_strcmp(buf, "pb"))
		push_to(stack_a, stack_b);
	else if (!ft_strcmp(buf, "pa"))
		push_to(stack_b, stack_a);
	else if (!ft_strcmp(buf, "ra"))
		rot_up(stack_a);
	else if (!ft_strcmp(buf, "rb"))
		rot_up(stack_b);
	else if (!ft_strcmp(buf, "rr"))
	{
		rot_up(stack_a);
		rot_up(stack_b);
	}
	else if (!ft_strcmp(buf, "rra"))
        rot_down(stack_a);
	else if (!ft_strcmp(buf, "rrb"))
		rot_down(stack_b);
	else if (!ft_strcmp(buf, "rrr"))
	{
		rot_down(stack_a);
		rot_down(stack_b);
	}
	else
        ft_putstr_fd("Error\n", 2);
}

void    get_input(t_args *stack_a, t_args *stack_b)
{
    char    *line;

	while (get_next_line(0, &line) > 0)
    {
        swap_cmds(line, &stack_a, &stack_b);
    }
	if (stack_b == NULL && check_if_done(stack_a))
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
	}
	else
		init_stack_a(&stack_a, argc - 1, argv, 1);
    get_input(stack_a, stack_b);
	// sleep(30);
    return (0);
}