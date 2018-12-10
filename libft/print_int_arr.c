/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:47:33 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/02 09:47:35 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    print_int_arr(int *num, int num_args)
{
    int i;

    i = 0;
    if (!num || !*num)
        return ;
    while (i < num_args)
    {
        ft_printf("%d\n", num[i]);
        i++;
    }
}