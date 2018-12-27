/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:29:15 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/18 21:29:17 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
  
void delete_node(t_args **head, int n) 
{ 
    t_args  *pos;
    int     i;

    i = 1;
    if (*head == NULL || n <= 0)
        return; 
    pos = *head; 
    while (pos && i < n) 
    {
        pos = pos->next; 
        i++;
    }
    if (pos == NULL) 
        return; 
    if (*head == pos)
        *head = pos->next; 
    if (pos->next != NULL) 
        pos->next->prev = pos->prev; 
    if (pos->prev != NULL) 
        pos->prev->next = pos->next; 
    free(pos);
	pos = NULL;
}

void    rot_up(t_args **stack_ab)
{
    int first_arg;
    int num_args;

	if ((*stack_ab) == NULL)
		return ;
    num_args = (*stack_ab)->num_args;
    first_arg = (*stack_ab)->arg;
    add_to_end(stack_ab, num_args, first_arg);
    delete_node(stack_ab, 1);
}

void add_to_beginning(t_args **head, int num_args, int arg) 
{ 
    t_args *new_node;
    
    new_node = (t_args*)ft_memalloc(sizeof(t_args)); 
    new_node->arg = arg; 
    new_node->num_args = num_args;
    new_node->next = (*head); 
    new_node->prev = NULL; 
    if ((*head) != NULL) 
        (*head)->prev = new_node; 
    (*head) = new_node; 
}

void    rot_down(t_args **stack_ab)
{
    int last_arg;
    t_args  *head;

	if ((*stack_ab) == NULL)
		return ;
    head = (*stack_ab);
    while ((*stack_ab)->next)
        (*stack_ab) = (*stack_ab)->next;
    last_arg = (*stack_ab)->arg;
    (*stack_ab) = head;
    add_to_beginning(stack_ab, (*stack_ab)->num_args, last_arg);
    delete_node(stack_ab, (*stack_ab)->num_args + 1);
}

void    ft_num_swap_individual(t_args **stack_ab)
{
    int temp;

    if ((*stack_ab) && (*stack_ab)->next)
    {
        temp = (*stack_ab)->arg;
        (*stack_ab)->arg = (*stack_ab)->next->arg;
        (*stack_ab)->next->arg = temp;
    }
}

void	update_num_args(t_args *stack_ab, int new_num_args)
{
	while (stack_ab)
	{
		(stack_ab)->num_args = new_num_args;
		(stack_ab) = (stack_ab)->next;
	}
}

void	push_to(t_args **stack_from, t_args **stack_to)
{
	int	num_args;
	int	arg;

	if (!(*stack_from) || (*stack_from)->num_args <= 0)
		return ;
	if ((*stack_to))
		num_args = (*stack_to)->num_args + 1;
	else
		num_args = 1;
	arg = (*stack_from)->arg;
	add_to_beginning(stack_to, num_args, arg);
	update_num_args(*stack_to, num_args);
	num_args = (*stack_from)->num_args - 1;
	delete_node(stack_from, 1);
	update_num_args(*stack_from, num_args);
}

void	call_exec_two(t_args **stack_a, t_args **stack_b, char *choice)
{
	if (!ft_strcmp(choice, "rrb"))
	{
		// ft_printf("rrb\n");
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rr"))
	{
		// ft_printf("rr\n");
		rot_up(stack_a);
		rot_up(stack_b);
	}
	else if (!ft_strcmp(choice, "ra"))
	{
		// ft_printf("ra\n");
		rot_up(stack_a);
	}
	else if (!ft_strcmp(choice, "rb"))
	{
		// ft_printf("rb\n");
		rot_up(stack_b);
	}
	else if (!ft_strcmp(choice, "pb"))
	{
		// ft_printf("pb\n");
		push_to(stack_a, stack_b);
	}
	else if (!ft_strcmp(choice, "pa"))
	{
		// ft_printf("pa\n");
		push_to(stack_b, stack_a);
	}
}
void	call_exec(t_args **stack_a, t_args **stack_b, char *choice)
{
	g_test_line_num++;
	if (!ft_strcmp(choice, "ss"))
	{
		// ft_printf("ss\n");
		ft_num_swap_individual(stack_a);
		ft_num_swap_individual(stack_b);
	}
	else if (!ft_strcmp(choice, "sa"))
	{
		// ft_printf("sa\n");
		ft_num_swap_individual(stack_a);
	}
	else if (!ft_strcmp(choice, "sb"))
	{
		// ft_printf("sb\n");
		ft_num_swap_individual(stack_b);
	}
	else if (!ft_strcmp(choice, "rrr"))
	{
		// ft_printf("rrr\n");
		rot_down(stack_a);
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rra"))
	{
		// ft_printf("rra\n");
		rot_down(stack_a);
	}
	else
		call_exec_two(stack_a, stack_b, choice);
}