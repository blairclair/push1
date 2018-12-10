/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:34:04 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/03 11:17:06 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_to_end(t_args **head, int arg)
{
	t_args	*newnode;
	t_args	*last;

	newnode = (t_args*)ft_memalloc(sizeof(t_args));
	last = (*head);
	newnode->arg = arg;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		(*head) = newnode;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newnode;
	newnode->prev = last;
}

void	print_list(t_args *stack_a)
{
	while (stack_a)
	{
		printf("num: %d\n", stack_a->arg);
		stack_a = stack_a->next;
	}
}

void	get_list(t_args **stack_a, int num_args, char *arg_list[])
{
	int	i;

	i = 0;
	while (++i < num_args + 1)
	{
		add_to_end(stack_a, ft_atoi(arg_list[i]));
	}
}

int	main(int argc, char *argv[])
{
	t_args	*stack_a;
	
	get_list(&stack_a, argc - 1, argv);
	print_list(stack_a);
	return (0);
}
