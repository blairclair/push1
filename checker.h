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
    int             arg;
    struct s_args   *next;
    struct s_args   *prev;
}                   t_args;

int                 is_safe(int argc, char *argv[]);
void                rot_down(int *args, int num_args);
void                ft_num_swap_individual(int *args, int pos);
void                push_to_other(int *args_one, int *args_two,
                    int num_args_one, int num_args_two);
void                rot_up(int *args, int num_args);
int                 *get_args(int *args, int num_args, char *arg_list[]);
#endif