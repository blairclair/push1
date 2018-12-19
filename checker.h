/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:35:25 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/02 09:35:27 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"

typedef struct  s_args
{
    int             num_args;
    int             arg;
    struct s_args   *next;
    struct s_args   *prev;
}                   t_args;

int is_dup(int *dup_check, int num);
int is_safe(int argc, char *argv[]);
void ft_num_swap_individual(t_args **stack_ab);
void    print_list(t_args *stack_a, t_args *stack_b);
void    rot_down(t_args **stack_ab);
#endif