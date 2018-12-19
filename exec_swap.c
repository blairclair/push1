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

#include "checker.h"

void deleteNode(t_args **head_ref, t_args *del) 
{ 
    if (*head_ref == NULL || del == NULL) 
        return; 
    if (*head_ref == del) 
        *head_ref = del->next; 
    if (del->next != NULL) 
        del->next->prev = del->prev; 
    if (del->prev != NULL) 
        del->prev->next = del->next; 
    free(del); 
} 
  
void deleteNodeAtGivenPos(t_args **head_ref, int n) 
{ 
    t_args  *current;
    int     i;

    i = 1;
    if (*head_ref == NULL || n <= 0) 
        return; 
    current = *head_ref; 
    while (current && i < n) 
    {
        current = current->next; 
        i++;
    }
    if (current == NULL) 
        return; 
    deleteNode(head_ref, current); 
} 


void push(t_args** head_ref, int num_args, int arg) 
{ 
    t_args *new_node;
    
    new_node = (t_args*)malloc(sizeof(t_args)); 
    new_node->arg = arg; 
    new_node->num_args = num_args;
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
    (*head_ref) = new_node; 
}

void    rot_down(t_args **stack_ab)
{
    int last_arg;
    t_args  *head;

    head = (*stack_ab);
    while ((*stack_ab)->next)
        (*stack_ab) = (*stack_ab)->next;
    last_arg = (*stack_ab)->arg;
    (*stack_ab) = head;
    push(stack_ab, (*stack_ab)->num_args, last_arg);
    deleteNodeAtGivenPos(stack_ab, (*stack_ab)->num_args + 1);
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

