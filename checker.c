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

void    swap_cmds(char buf[5], t_args **stack_a, t_args **stack_b)
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
    int ret;
    char    buf[5];

    while ((ret = read(1, buf, 5)) > 0)
    {
        buf[ret - 1] = '\0';
        swap_cmds(buf, &stack_a, &stack_b);
        print_list(stack_a, stack_b);
    }
}

int main(int argc, char *argv[])
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
    get_input(stack_a, stack_b);
	if (!stack_b && check_if_done(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// sleep(30);
    return (0);
}