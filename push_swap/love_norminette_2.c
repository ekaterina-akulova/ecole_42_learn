/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   love_norminette_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:26:42 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 21:26:44 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/15/21.
//
#include "checker.h"

void	fuck_you_norma_3(char **array, t_stack_ab *stack)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (((array[i][j] > '9') && (array[i][j] != '\n')) \
			|| (array[i][j] == '-' && ft_isdigit(array[i][j + 1]) == 0))
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
		i++;
	}
	stack->a_size += 1;
}

void	fuck_you_norma_5(t_stack_ab *stack)
{
	if (ft_check_stacks(stack) == 0)
		write(1, "KO\n", 3);
	if (ft_check_stacks(stack) == 1)
		write(1, "OK\n", 3);
	free(stack->b);
	free(stack->a);
}

void	ft_intmax_check(int i, t_stack_ab *checker_stack)
{
	while (i < checker_stack->a_size)
	{
		if (checker_stack->a[i] > INTMAX)
			ft_error_checks(checker_stack);
		i++;
	}
	ft_gnl_using(checker_stack, 0);
}

void	ft_is_terra(char **array, long number, int j, t_stack_ab *checker_stack)
{
	int	k;
	int	i;

	i = 1;
	k = 0;
	while (array[k])
	{
		while (j < i)
			if (((number == (checker_stack->a[j++])) && number != 0) \
			|| checker_stack->zero > 1)
				ft_error_checks(checker_stack);
		checker_stack->a[i - 1] = (long)ft_atoi(array[k]);
		checker_stack->a_size++;
		k++;
		i++;
	}
	checker_stack->size += k;
}
