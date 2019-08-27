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
# define VALUE_AFTER_LAST get_value_after_last(*stack_a, sorted_arr, ((*stack_b) ? (*stack_b)->num_args : 0) + (((*stack_a))? (*stack_a)->num_args : 0));

typedef struct		s_args
{
    int				num_args;
    int				arg;
    struct s_args	*next;
    struct s_args	*prev;
}					t_args;


void	            ps_lstdel(t_args **alst);
void 				add_to_beginning(t_args **head, int num_args, int arg);
int					is_dup(int *dup_check, int num, int numDup);
int					is_safe(int argc, char *argv[]);
void				ft_num_swap_individual(t_args **stack_ab);
void				print_list(t_args *stack_a, t_args *stack_b);
void				rot_down(t_args **stack_ab);
void				rot_up(t_args **stack_ab);
void				add_to_end(t_args **stack_ab, int num_args, int arg);
void				push_to(t_args **stack_from, t_args **stack_to);
void    			get_input(t_args **stack_a, t_args **stack_b);
void				add_to_end(t_args **stack_ab, int num_args, int arg);
int					check_if_done(t_args *stack_a);
void				print_list(t_args *stack_a, t_args *stack_b);
void				delete_node(t_args **head, int n);
void				resort_stack_b(t_args **stack_a, t_args **stack_b);
void				init_stack_a(t_args **stack_a, int num_args, char *argv[], int i);
void				call_exec(t_args **stack_a, t_args **stack_b, char *choice);
void				push_swap(t_args *stack_a, t_args *stack_b);
int					is_backwards(t_args *stack_a, int highest);
int					get_last_arg(t_args *stack_ab);
int					get_lowest_arg(t_args *stack_ab);
int					get_highest_arg(t_args *stack_ab);
void				stack_a_sort(t_args **stack_a, t_args **stack_b);
void				stack_b_sort(t_args **stack_a, t_args **stack_b);
void				separate_stacks(t_args **stack_a, t_args **stack_b, int pivot);
t_args				*recursive_push_swap(t_args *stack_a, t_args *stack_b, int *arr);
void				recursive_function(t_args **stack_a, t_args **stack_b, int *sorted_arr);
void				split(t_args **stack_a, t_args **stack_b, int highest, int *sorted_arr);
void				back_to_before(t_args **stack_a, t_args **stack_b, int highest, int *sorted_arr);
void				go_to_a(t_args **stack_a, t_args **stack_b, int *sorted_arr);
int					get_pos_no_one(t_args *stack_a, int arg, int lowest);
int					*actual_sort(t_args *stack_a);
int					get_value_after_last(t_args *stack_ab, int *sorted_arr, int num_args);
#endif