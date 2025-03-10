/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:43:47 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 12:22:40 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index(t_list **stack_a, int size)
{
	int		*arr;
	int		i;
	t_list	*tmp;

	arr = NULL;
	arr = init_array(*stack_a, size);
	arr = sort_array(arr, size);
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break ;
			}
			else
				i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

int	get_min_pos(t_list **stack)
{
	t_list	*tmp;
	int		index;
	int		min_pos;

	tmp = *stack;
	index = __INT_MAX__;
	get_pos(stack);
	while (tmp)
	{
		if (tmp->index < index)
		{
			index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	int		size_b;
	int		size_a;
	t_list	*tmp;
	t_list	*tmp_a;

	wanted_pos(stack_a, stack_b);
	tmp = *stack_b;
	tmp_a = *stack_a;
	size_a = ft_stack_size(tmp_a);
	size_b = ft_stack_size(tmp);
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = (size_b - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
	do_cheapest(stack_a, stack_b);
}

void	do_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = __INT_MAX__;
	while (tmp)
	{
		if (my_abs(tmp->cost_a) + my_abs(tmp->cost_b) < cheapest)
		{
			cheapest = my_abs(tmp->cost_a) + my_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	sort(stack_a, stack_b, cost_a, cost_b);
}

int	my_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
