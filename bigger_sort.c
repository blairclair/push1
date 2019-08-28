/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:33:36 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/27 16:33:40 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	recursive_function(t_args **stack_a, t_args **stack_b, int *sorted_arr)
{
	int	check;
	int	highest;

	if ((*stack_b) == NULL || (*stack_b)->num_args == 0)
		return ;
	highest = get_highest_arg(*stack_b);
	go_to_a(stack_a, stack_b, sorted_arr);
	check = VALUE_AFTER_LAST;
	while (((*stack_a)->arg == check
	|| (*stack_a)->arg == sorted_arr[0]) && !check_if_done(*stack_a))
	{
		call_exec(stack_a, stack_b, "ra");
		check = VALUE_AFTER_LAST;
	}
	recursive_function(stack_a, stack_b, sorted_arr);
	if (get_pos_no_one(*stack_a, highest, sorted_arr[0]) >= 20)
		split(stack_a, stack_b, highest, sorted_arr);
	back_to_before(stack_a, stack_b, highest, sorted_arr);
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


void	back_to_before(t_args **stack_a, t_args **stack_b,
int highest, int *sorted_arr)
{
	int	check;

	while (*stack_a && (*stack_a)->arg <= highest &&
	(*stack_a)->arg != sorted_arr[0])
	{
		check = VALUE_AFTER_LAST;
		if ((*stack_a)->arg == check)
			call_exec(stack_a, stack_b, "ra");
		else
			call_exec(stack_a, stack_b, "pb");
	}
	check = VALUE_AFTER_LAST;
	if (get_lowest_arg(*stack_b) == check)
		recursive_function(stack_a, stack_b, sorted_arr);
}

void	split_to_b(t_args **stack_a, t_args **stack_b, int pos, int *check)
{
	if ((*stack_a)->arg >= pos)
	{
		call_exec(stack_a, stack_b, "ra");
		(*check)++;
	}
	else
		call_exec(stack_a, stack_b, "pb");
}

void	split(t_args **stack_a, t_args **stack_b, int highest, int *sorted_arr)
{
	int	pos;
	int	check;

	check = 0;
	if (!*stack_a)
		return ;
	pos = get_average_highest(*stack_a, highest, sorted_arr[0]);
	while ((*stack_a) && (*stack_a)->arg <= highest &&
	(*stack_a)->arg != sorted_arr[0])
		split_to_b(stack_a, stack_b, pos, &check);
	pos = 0;
	while (pos < check)
	{
		if ((*stack_b) && (*stack_b)->arg != get_highest_arg(*stack_b))
			call_exec(stack_a, stack_b, "rrr");
		else
			call_exec(stack_a, stack_b, "rra");
		pos++;
	}
	if (get_lowest_arg(*stack_b) == get_value_after_last(*stack_a, sorted_arr,
	(*stack_a)->num_args + (*stack_b)->num_args) && check > 0)
		recursive_function(stack_a, stack_b, sorted_arr);
}

t_args	*recursive_push_swap(t_args *stack_a, t_args *stack_b, int *sorted_arr)
{
	int pivot_a;
	int	pos;
	int	highest_a;
	int	len;

	if (check_if_done(stack_a))
		return (stack_a);
	len = stack_a->num_args;
	pivot_a = get_average(stack_a);
	while (len-- > 0)
	{
		stack_a->arg < pivot_a ? call_exec(&stack_a, &stack_b, "pb") :
		call_exec(&stack_a, &stack_b, "ra");
	}
	recursive_function(&stack_a, &stack_b, sorted_arr);
	highest_a = get_highest_arg(stack_a);
	pos = get_pos_no_one(stack_a, highest_a, sorted_arr[0]);
	if (pos >= 20)
	{
		split(&stack_a, &stack_b, get_highest_arg(stack_a), sorted_arr);
		split(&stack_a, &stack_b, get_highest_arg(stack_a), sorted_arr);
	}
	back_to_before(&stack_a, &stack_b, highest_a, sorted_arr);
	return (stack_a);
}

// int		get_average(t_args *stack_ab)
// {
// 	float	num;
// 	int		i;

// 	num = 0;
// 	i = 0;
// 	while (stack_ab)
// 	{
// 		num += stack_ab->arg;
// 		stack_ab = stack_ab->next;
// 		i++;
// 	}
// 	return ((int)(num / i + 0.5));
// }

// int		get_pos_arg(t_args *stack_ab, int arg)
// {
// 	int	pos;

// 	pos = 0;
// 	while (stack_ab->next)
// 		stack_ab = stack_ab->next;
// 	while (pos < stack_ab->num_args)
// 	{
// 		if (stack_ab->arg == arg)
// 			return (pos);
// 		pos++;
// 		stack_ab = stack_ab->prev;
// 	}
// 	return (pos);
// }

// int	get_value_from_pos(t_args *stack_ab, int pos)
// {
// 	while (stack_ab && pos > 0)
// 	{
// 		stack_ab = stack_ab->next;
// 		pos--;
// 	}
// 	return (stack_ab->arg);
// }

// int		get_num_args(t_args *stack_a, t_args *stack_b)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a)
// 	{
// 		i++;
// 		stack_a = stack_a->next;
// 	}
// 	while (stack_b)
// 	{
// 		i++;
// 		stack_b = stack_b->next;
// 	}
// 	return (i);
// }

// int		get_average_highest(t_args *stack_ab, int highest, int lowest)
// {
// 	int	pos;
// 	int	num;

// 	pos = 0;
// 	num = 0;
// 	if (!stack_ab)
// 		return (0);
// 	while (stack_ab && stack_ab->arg <= highest && stack_ab->arg != lowest)
// 	{
// 		num += stack_ab->arg;
// 		pos++;
// 		stack_ab = stack_ab->next;
// 	}
// 	return ((int)(num / pos + 0.5));
// }

// int		**get_chunks(int **chunks, int chunk_size, int *sorted_arr, int num_args)
// {
// 	int	i;
// 	int	j;
// 	int	chunkLoc;

// 	i = 0;
// 	j = 0;
// 	chunkLoc = 0;
// 	while (i < num_args)
// 	{
// 		if (i % chunk_size == 0 && i != 0)
// 		{
// 			chunkLoc = 0;
// 			j++;
// 			chunks[j] = ft_memalloc(sizeof(int) * chunk_size);
// 		}
// 		chunks[j][chunkLoc] = sorted_arr[i];
// 		chunkLoc++;
// 		i++;
// 	}
// 	chunks[j + 1] = NULL;
// 	return (chunks);
// }

// int		find_next_chunk_val_botton(t_args *stack_a, int *chunk, int chunk_size)
// {
// 	int	loc;

// 	loc = 0;
// 	while (stack_a->next)
// 		stack_a = stack_a->next;
// 	while (stack_a)
// 	{
// 		if (stack_a->arg >= chunk[0] && stack_a->arg <= chunk[chunk_size - 1])
// 			return loc + 1;
// 		stack_a = stack_a->prev;
// 		loc++;
// 	}
// 	return (-1);
// }

// int		find_next_chunk_val_top(t_args *stack_a, int *chunk, int chunk_size)
// {
// 	int	loc;

// 	loc = 0;
// 	while (stack_a)
// 	{
// 		if (stack_a->arg >= chunk[0] && stack_a->arg <= chunk[chunk_size - 1])
// 			return loc;
// 		stack_a = stack_a->next;
// 		loc++;
// 	}
// 	return (-1);
// }

// void	rot_to_top(t_args **stack_a, t_args **stack_b, int loc, int which_way)
// {
// 	int	half_size;
// 	int	i;

// 	i = 0;
// 	half_size = (*stack_a)->num_args / 2;
// 	if (which_way == 1)
// 	{
// 		while (i < loc)
// 		{
// 			call_exec(stack_a, stack_b, "ra");
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i < loc)
// 		{
// 			call_exec(stack_a, stack_b, "rra");
// 			i++;
// 		}
// 	}
// }


// void	rot_to_top_b(t_args **stack_a, t_args **stack_b, int loc)
// {
// 	int	half_size;
// 	int	i;

// 	i = 0;
// 	half_size = (*stack_b)->num_args / 2;
// 	if (loc < half_size)
// 	{
// 		while (i < loc)
// 		{
// 			call_exec(stack_a, stack_b, "rb");
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i < loc)
// 		{
// 			call_exec(stack_a, stack_b, "rrb");
// 			i++;
// 		}
// 	}
// }

// int		get_b_pos(t_args *stack_b, int arg)
// {
// 	int	pos;

// 	pos = 0;
// 	while (stack_b->next)
// 	{
// 		if ((arg > stack_b->arg && arg < stack_b->next->arg) || ((arg < stack_b->arg && arg > stack_b->next->arg)))
// 			return (pos);
// 		stack_b = stack_b->next;
// 		pos++;
// 	}
// 	return (pos + 1);
// }

// void	smallest_to_stack_b(t_args **stack_a, t_args **stack_b)
// {
// 	int	loc;

// 	if (!stack_b || !(*stack_b) || (*stack_b)->num_args == 0)
// 		return ;
// 	loc = get_b_pos(*stack_b, (*stack_a)->arg);
// 	rot_to_top_b(stack_a, stack_b, loc);
// }

// void	largest_b_to_a(t_args **stack_a, t_args **stack_b)
// {
// 	int	largest;
// 	int	loc;

// 	while (1)
// 	{
// 		if (!stack_b || !(*stack_b) || (*stack_b)->num_args == 0)
// 			return ;
// 		largest = get_highest_arg(*stack_b);
// 		loc = get_loc_arg(*stack_b, largest);
// 		rot_to_top_b(stack_a, stack_b, loc);
// 		call_exec(stack_a, stack_b, "pa");
// 	}
// }

// void	bigger_sort(t_args **stack_a, t_args **stack_b, int chunk_size, int *sorted_arr)
// {
// 	int	**chunks;
// 	int	num_chunks;
// 	int	first_check;
// 	int	second_check;
// 	int	i;

// 	i = 0;
// 	num_chunks = (*stack_a)->num_args / chunk_size;
// 	chunks = ft_memalloc(sizeof(int*) * num_chunks);
// 	chunks[0] = ft_memalloc(sizeof(int) * chunk_size);
// 	chunks = get_chunks(chunks, chunk_size, sorted_arr, (*stack_a)->num_args);
// 	while (1)
// 	{
// 		if (!stack_a || !(*stack_a) || (*stack_a)->num_args == 0)
// 		{
// 			largest_b_to_a(stack_a, stack_b);
// 			return ;
// 		}
// 		first_check = find_next_chunk_val_top(*stack_a, chunks[i], chunk_size);
// 		second_check = find_next_chunk_val_botton(*stack_a, chunks[i], chunk_size);
// 		if (first_check == -1 && second_check == -1)
// 			i++;
// 		rot_to_top(stack_a, stack_b, (first_check < second_check) ? first_check : second_check, (first_check < second_check) ? 1 : 2);
// 		smallest_to_stack_b(stack_a, stack_b);
// 		call_exec(stack_a, stack_b, "pb");
		
// 	}
// }
