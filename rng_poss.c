/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng_poss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:41:40 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/24 16:41:43 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int		is_good_two(char *str, char num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == num)
			return (0);
		i++;
	}	
	return (1);
}

void	assign_arr(int *arr)
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = '\0';
}

int		grab_from_arr(int arr[6])
{
	int		in;
	int		tmp;

	srand(time(0));
	in = rand() % 5 + 1;
	while (1)
	{
		if (in == 5 && arr[in - 1] == -1)
		{
			in = 1;
		}
		else if (arr[in - 1] != -1)
		{
			tmp = arr[in - 1];
			arr[in - 1] = -1;
			return (tmp);
		}
		in++;
	}
}

char	*rng()
{
	int	i;
	char	*str;
	char	*iti;
	int		in;

 	str = ft_memalloc(20);
	srand(time(0));
	i = 0;
	while (i < 5)
	{
		in = rand() % 20000 + 1;
		iti = ft_memalloc(20);
		iti = ft_itoa_base(in, 10);
		strcat(str, iti);
		strcat(str, " ");
			i++;
	}
	return (str);
}

int		is_good(char *str, char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (1);
	while (args[i])
	{
		if (!ft_strcmp(args[i], str))
			return (0);
		i++;
	}
	return (1);
}

char	**check_all()
{
	char	**args;
	int		i;
	char	*str;

	i = 0;
	args = ft_memalloc(300000);
	while (i < 5)
	{
		if (!args[i])
			args[i] = ft_memalloc(20);
		str = rng();
		if (is_good(str, args))
		{
			strcpy(args[i], str);
			i++;
		}

	}
	return (args);
}

int		main()
{
	char **arg;
	int	i;
	t_args *stack_a;
	t_args *stack_b;
	char	**str;
	
	i = 0;
	stack_b = NULL;
	stack_a = NULL;
	// arg = check_all();
	arg = malloc(50);
	strcpy(arg[i], "5 3 2 4 1");
	// while (arg[i])
	// {
		stack_b = NULL;
		stack_a = NULL;
		str = ft_strsplit(arg[i], ' ');
		init_stack_a(&stack_a, count_num_2d_args(str) - 1, str, 0);
		print_list(stack_a, stack_b);
		push_swap(stack_a, stack_b);
		printf("g: %d\n", g_test_line_num);
		// if (g_test_line_num < 12)
		printf("arg: %s\n", arg[i]);
		i++;
	// }
	return (0);
}