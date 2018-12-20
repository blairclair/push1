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
	
}

void	push_swap(t_args *stack_a, t_args *stack_b)
{

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
}