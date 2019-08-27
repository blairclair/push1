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

void    init_stack_a(t_args **stack_a, int num_args, char *argv[], int i)
{
	int	j;

	if (i == 0)
		j = num_args;
	else
		j = num_args + 1;
    while (i < j)
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
	while (last->next)
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
        ft_printf("    num args: %d\n", stack_a->num_args);
        while (stack_a)
        {
            ft_printf("%d\n", stack_a->arg);
            stack_a = stack_a->next;
        }
    }
    ft_printf("\nstack b:\n");
    if (stack_b)
    {
        ft_printf("    num args: %d\n", stack_b->num_args);
        while (stack_b)
        {
            ft_printf("%d\n", stack_b->arg);
            stack_b = stack_b->next;
        }
    }
}

int		is_backwards(t_args *stack_a, int highest)
{
	int	tmp;
	if (stack_a->arg != highest)
		return (0);
	while (stack_a)
	{
		if (stack_a->next)
			tmp = stack_a->next->arg;
		if (tmp > stack_a->arg)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}


void	ps_lstdel(t_args **alst)
{
	t_args	*n_list;
	t_args	*next1;

	n_list = *alst;
	while (n_list)
	{
		next1 = n_list->next;
		free(n_list);
		n_list = next1;
		*alst = NULL;
	}
}