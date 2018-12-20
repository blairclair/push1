/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:09:13 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/19 16:09:15 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_stack_a(t_args **stack_a, int num_args, char *argv[])
{
    int i;

    i = 1;
    while (i < num_args +1)
    {
        add_to_end(stack_a, num_args, ft_atoi(argv[i]));
        i++;
    }
}

void	add_to_end(t_args **stack_ab, int num_args, int arg)
{
	t_args	*newnode;
	t_args	*last;

	newnode = (t_args*)ft_memalloc(sizeof(t_args));
	last = (*stack_ab);
	newnode->num_args = num_args;
	newnode->arg = arg;
	newnode->next = NULL;
	if (*stack_ab == NULL)
	{
		newnode->prev = NULL;
		(*stack_ab) = newnode;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newnode;
	newnode->prev = last;
}

int		check_if_done(t_args *stack_a)
{
	int	temp;

	while (stack_a)
	{
		if (!stack_a || !stack_a->next)
			return (1);
		if (stack_a->next != NULL)
			temp = stack_a->next->arg;
		if (temp < stack_a->arg)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void    print_list(t_args *stack_a, t_args *stack_b)
{
    ft_printf("stack a:\n");
    if (stack_a)
    {
        printf("    num args: %d\n", stack_a->num_args);
        while (stack_a)
        {
            printf("%d\n", stack_a->arg);
            stack_a = stack_a->next;
        }
    }
    ft_printf("\nstack b:\n");
    if (stack_b)
    {
        printf("    num args: %d\n", stack_b->num_args);
        while (stack_b)
        {
            printf("%d\n", stack_b->arg);
            stack_b = stack_b->next;
        }
    }
}
