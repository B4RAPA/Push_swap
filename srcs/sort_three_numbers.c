/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:16:06 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 14:52:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_two(t_list *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if (stack == NULL || stack->next == NULL || stack->next->next == NULL)
		return (-1);
	if (a < b && b < c)
		return (1);
	else if (a < b && b > c && a < c)
		return (2);
	else if (a < b && b > c && a > c)
		return (3);
	else if (a > b && b > c)
		return (4);
	else if (a > b && b < c && a < c)
		return (5);
	else if (a > b && b < c && c < a)
		return (7);
	else
		return (6);
}

int	sort_three_numbers(t_list **stack)
{
	if (ft_stack_size(*stack) == 1)
		return (0);
	if ((ft_stack_size(*stack) == 2 && (*stack)->value > (*stack)->next->value))
		sa(stack);
	else if (ft_stack_size(*stack) == 2)
		return (0);
	else if (is_sorted_two(*stack) == 2)
	{
		rra(stack);
		sa(stack);
	}
	else if (is_sorted_two(*stack) == 3 || is_sorted_two(*stack) == 6)
		rra(stack);
	else if (is_sorted_two(*stack) == 4)
	{
		sa(stack);
		rra(stack);
	}
	else if (is_sorted_two(*stack) == 5)
		sa(stack);
	else if (is_sorted_two(*stack) == 7)
		ra(stack);
	return (0);
}
