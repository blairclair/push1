/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:29:15 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/27 12:49:05 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void delete_node(t_args **head, int n) 
{
	t_args* tmp = *head; 
   	int		i;
	t_args	*nextTmp;
	i = 0;
	if (*head == NULL) 
	   return; 
    if (n == 0) 
    { 
        *head = tmp->next; 
        free(tmp);  
        return; 
    } 
	while (i < n && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL || tmp->next == NULL) 
         return; 
   	nextTmp = tmp->next->next; 
    free(tmp->next);
    tmp->next = nextTmp;   
} 

void	rot_up(t_args **stack_ab)
{
	int first_arg;
	int num_args;

	if ((*stack_ab) == NULL)
		return ;
	num_args = (*stack_ab)->num_args;
	first_arg = (*stack_ab)->arg;
	add_to_end(stack_ab, num_args, first_arg);
	delete_node(stack_ab, 0);
}

void	add_to_beginning(t_args **head, int num_args, int arg)
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

void	rot_down(t_args **stack_ab)
{
	int		last_arg;
	t_args	*head;

	if ((*stack_ab) == NULL)
		return ;
	head = (*stack_ab);
	while ((*stack_ab)->next)
		(*stack_ab) = (*stack_ab)->next;
	last_arg = (*stack_ab)->arg;
	(*stack_ab) = head;
	add_to_beginning(stack_ab, (*stack_ab)->num_args, last_arg);
	delete_node(stack_ab, (*stack_ab)->num_args - 1);
}

void	ft_num_swap_individual(t_args **stack_ab)
{
	int	temp;

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
	delete_node(stack_from, 0);
	update_num_args(*stack_from, num_args);
}
