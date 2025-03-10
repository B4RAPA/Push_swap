/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:20:49 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 12:22:02 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_numbers(t_list **stack_a, t_list **stack_b, int size)
{
	int	count;
	int	counter;

	counter = 0;
	count = 0;
	if (check_sort(stack_a) == 0)
		return (0);
	while (*stack_a && count < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	while (ft_stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (ft_stack_size(*stack_a) == 3)
		sort_three_numbers(stack_a);
	get_cost(stack_a, stack_b);
	is_sorted_stack(stack_a);
	counter += (count * 2);
	return (0);
}

void	get_pos(t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	wanted_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		target;

	tmp = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	target = 0;
	while (tmp)
	{
		target = get_wanted_pos(stack_a, tmp->index, __INT_MAX__, target);
		tmp->target_pos = target;
		tmp = tmp->next;
	}
}

int	get_wanted_pos(t_list **stack_a, int b_index, int target_index, int target)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != __INT_MAX__)
		return (target);
	tmp = *stack_a;
	while (tmp)
	{
		if (target_index > tmp->index)
		{
			target_index = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	is_sorted_stack(t_list **stack_a)
{
	int		min_pos;
	int		size_a;

	size_a = ft_stack_size(*stack_a);
	min_pos = get_min_pos(stack_a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	if (min_pos > size_a / 2)
	{
		min_pos = (min_pos - size_a);
		while (min_pos < 0)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	if (get_min_pos(stack_a) != 0)
		is_sorted_stack(stack_a);
}
