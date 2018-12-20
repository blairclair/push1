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

typedef struct		s_args
{
    int				num_args;
    int				arg;
    struct s_args	*next;
    struct s_args	*prev;
}					t_args;

int					is_dup(int *dup_check, int num);
int					is_safe(int argc, char *argv[]);
void				ft_num_swap_individual(t_args **stack_ab);
void				print_list(t_args *stack_a, t_args *stack_b);
void				rot_down(t_args **stack_ab);
void				rot_up(t_args **stack_ab);
void				add_to_end(t_args **stack_ab, int num_args, int arg);
void				push_to(t_args **stack_from, t_args **stack_to);
void    			init_stack_a(t_args **stack_a, int num_args, char *argv[]);
void    			get_input(t_args *stack_a, t_args *stack_b);
void    			init_stack_a(t_args **stack_a, int num_args, char *argv[]);
void				add_to_end(t_args **stack_ab, int num_args, int arg);
int					check_if_done(t_args *stack_a);
void				print_list(t_args *stack_a, t_args *stack_b);
#endif