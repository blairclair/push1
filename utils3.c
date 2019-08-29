/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:08:57 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:30:54 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_pos_no_one(t_args *stack_a, int arg, int lowest)
{
	int	i;

	i = 0;
	while (stack_a && stack_a->arg <= arg && stack_a->arg != lowest)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int		get_pos_arg(t_args *stack_ab, int arg)
{
	int	pos;

	pos = 0;
	while (stack_ab->next)
		stack_ab = stack_ab->next;
	while (pos < stack_ab->num_args)
	{
		if (stack_ab->arg == arg)
			return (pos);
		pos++;
		stack_ab = stack_ab->prev;
	}
	return (pos);
}

void	delete_node(t_args **head, int n)
{
	t_args	*tmp;
	int		i;
	t_args	*next_tmp;

	i = 0;
	tmp = *head;
	if (*head == NULL)
		return ;
	if (n == 0)
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}
	while (i < n && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL || tmp->next == NULL)
		return ;
	next_tmp = tmp->next->next;
	free(tmp->next);
	tmp->next = next_tmp;
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

int		get_highest_arg(t_args *stack_ab)
{
	int	temp;

	temp = 0;
	if (stack_ab != NULL)
	{
		temp = stack_ab->arg;
		while (stack_ab)
		{
			if (temp < stack_ab->arg)
				temp = stack_ab->arg;
			stack_ab = stack_ab->next;
		}
	}
	return (temp);
}
