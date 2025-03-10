/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:19:03 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 14:36:25 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(char **argv, t_list **stack_a, int argc)
{
	int		i;
	char	**args;
	t_list	*new;

	args = argv;
	if (!args[1])
	{
		if (argc == 2)
			ft_free(args);
		exit_error(stack_a, NULL);
	}
	i = 0;
	while (args[i])
	{
		new = ft_lstnew2(ft_atoi2(args[i]));
		if (!new)
			exit_error(stack_a, NULL);
		ft_stack_add_back(stack_a, new);
		i++;
	}
	if (argc == 2)
	{
		ft_free(args);
	}
}

int	*init_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	i = 0;
	if (stack == NULL)
		exit_error(&stack, NULL);
	arr = (int *) malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (i < size && stack != NULL)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_list	*get_stack_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

// void	print_stack(t_list *stack)
// {
// 	t_list *tmp;

// 	tmp = stack;

// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		printf("%d\n", tmp->index);
// 		tmp = tmp->next;
// 	}
// }