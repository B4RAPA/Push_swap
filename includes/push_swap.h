/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:16:39 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 14:54:20 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

long	ft_atoi2(const char *str);

void	set_index(t_list **stack_a, int size);
void	get_cost(t_list **stack_a, t_list **stack_b);
void	do_cheapest(t_list **stack_a, t_list **stack_b);
int		my_abs(int nb);

int		sort_three_numbers(t_list **stack);
int		sort_numbers(t_list **stack_a, t_list **stack_b, int size);
void	sort(t_list **stack_b, t_list **stack_a, int csot_a, int cost_b);
void	reverse(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b);
void	rotating(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b);

int		check_input(const char *str);
void	check_args(char **argv, t_list **stack_a, t_list **stack_b, int argc);
int		check_sort(t_list **stack_a);
void	exit_error(t_list **stack_a, t_list**stack_b);

int		*init_array(t_list *stack, int size);
void	check_array(int *arr, int size);
int		*sort_array(int *array, int size);
int		is_sorted(int *array, int size);

void	print_stack(t_list *stack);
void	free_stack(t_list**stack);
void	init_stack(char **argv, t_list **stack_a, int argc);
void	is_sorted_stack(t_list **stack_a);
t_list	*get_stack_before_bottom(t_list *stack);

void	get_pos(t_list **stack_b);
void	wanted_pos(t_list **stack_a, t_list **stack_b);
int		get_wanted_pos(t_list **a, int b_index, int target, int target_pos);
int		get_min_pos(t_list **stack);

t_list	*ft_lstnew2(int value);
t_list	*ft_lsttail(t_list *head);
void	ft_stack_add_back(t_list **lst, t_list *new);
int		ft_stack_size(t_list *lst);
void	ft_free(char **str);

#endif