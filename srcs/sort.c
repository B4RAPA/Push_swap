/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:12:45 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 12:22:27 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (*stack_b)
	{
		while (cost_a != 0 || cost_b != 0)
		{
			if (cost_a < 0 || cost_b < 0)
				reverse(stack_a, stack_b, &cost_a, &cost_b);
			if (cost_a > 0 || cost_b > 0)
				rotating(stack_a, stack_b, &cost_a, &cost_b);
			(*stack_b)->cost_a = cost_a;
			(*stack_b)->cost_b = cost_b;
		}
		if (cost_a == 0 && cost_b == 0)
			pa(stack_a, stack_b);
		if (*stack_b)
			get_cost(stack_a, stack_b);
	}
}

void	reverse(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a) += 1;
		(*cost_b) += 1;
	}
	if (*cost_a < 0)
	{
		rra(stack_a);
		(*cost_a) += 1;
	}
	if (*cost_b < 0)
	{
		rrb(stack_b);
		(*cost_b) += 1;
	}
}

void	rotating(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	if (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a) -= 1;
		(*cost_b) -= 1;
	}
	if (*cost_a > 0)
	{
		ra(stack_a);
		(*cost_a) -= 1;
	}
	if (*cost_b > 0)
	{
		rb(stack_b);
		(*cost_b) -= 1;
	}
}

int	check_sort(t_list **stack_a)
{
	int	*arr;

	arr = init_array(*stack_a, ft_stack_size(*stack_a));
	if (is_sorted(arr, ft_stack_size(*stack_a)) == 0)
	{
		free (arr);
		return (0);
	}
	free (arr);
	return (-1);
}
