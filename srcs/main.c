/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:16:58 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/25 14:57:19 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit_error(&stack_a, &stack_b);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ++argv;
	check_args(args, &stack_a, &stack_b, argc);
	init_stack(args, &stack_a, argc);
	set_index(&stack_a, ft_stack_size(stack_a));
	if (ft_stack_size(stack_a) <= 3)
		sort_three_numbers(&stack_a);
	else if (ft_stack_size(stack_a) > 3)
		sort_numbers(&stack_a, &stack_b, ft_stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	check_input(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_args(char **argv, t_list **a, t_list **stack_b, int argc)
{
	long	tmp;
	int		i;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			if (argc == 2)
				ft_free(argv);
			exit_error(a, stack_b);
		}
		if (check_input(argv[i]) != 1)
		{
			if (argc == 2)
				ft_free(argv);
			exit_error(a, stack_b);
		}
		i++;
	}
}

void	exit_error(t_list **stack_a, t_list**stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (0);
}
