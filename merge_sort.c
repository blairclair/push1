/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:04:56 by agrodzin          #+#    #+#             */
/*   Updated: 2019/08/28 17:19:16 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	merge(int nums[], int left, int middle, int right)
{
	int	i;
	int	j;
	int	k;
	int	temp1[middle - left + 1];
	int	temp2[right - middle];

	j = -1;
	i = -1;
	while (++i < (middle - left + 1))
		temp1[i] = nums[left + i];
	while (++j < (right - middle))
		temp2[j] = nums[middle + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < (middle - left + 1) && j < (right - middle))
	{
		nums[k] = (temp1[i] <= temp2[j]) ? temp1[i++] : temp2[j++];
		k++;
	}
	while (i < (middle - left + 1))
		nums[k++] = temp1[i++];
	while (j < right - middle)
		nums[k++] = temp2[j++];
}

void	merge_sort(int nums[], int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		merge_sort(nums, left, middle);
		merge_sort(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}
}

int		*actual_sort(t_args *stack_a)
{
	int	*nums;
	int	len;
	int	i;

	len = 0;
	i = 0;
	nums = ft_memalloc(stack_a->num_args * sizeof(int*) + 5);
	while (stack_a)
	{
		nums[len] = stack_a->arg;
		len++;
		stack_a = stack_a->next;
	}
	nums[len + 1] = '\0';
	merge_sort(nums, 0, len - 1);
	return (nums);
}
