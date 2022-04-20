/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:03:11 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:03:13 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_max(t_stack *stack)
{
	int	j;

	j = 0;
	stack->min = stack->a[0];
	stack->max = stack->a[stack->size - 1];
	while (j < stack->size)
	{
		if (stack->a[j] < stack->min)
			stack->min = stack->a[j];
		if (stack->a[j] > stack->max)
			stack->max = stack->a[j];
		j++;
	}
}

static void	ft_calc_score2(t_stack *stack, int i, int j)
{
	while (j < stack->a_size - 1)
	{
		if (stack->a[j] < stack->b[i] && stack->a[j + 1] > stack->b[i])
		{
			if (stack->a_size / 2 > j)
				stack->b_score[i] = stack->b_score[i] + j + 1;
			else
				stack->b_score[i] += stack->b_size - j;
			break ;
		}
		j++;
	}
}

void	ft_calc_score(t_stack *stack, int i)
{
	free(stack->b_score);
	stack->b_score = ft_calloc(stack->b_size, sizeof (int));
	while (i < stack->b_size)
	{
		if (stack->b_size / 2 >= i)
			stack->b_score[i] = i;
		else
			stack->b_score[i] = stack->b_size - i;
		if (stack->a[0] < stack->b[i] || \
		stack->a[stack->a_size - 1] > stack->b[i])
		{
			ft_calc_score2(stack, i, 0);
		}
		i++;
	}
}

int	ft_min_score(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < stack->b_size)
	{
		if (stack->b_score[i] < stack->b_score[min])
			min = i;
		i++;
	}
	return (min);
}

void	ft_push_min_score(t_stack *stack, int index, int j)
{
	int	temp;

	temp = stack->b[index];
	while (stack->b[0] != temp)
	{
		if (stack->b_size / 2 > index)
			ft_rotate_b(stack);
		else
			ft_rev_rotate_b(stack);
	}
	if (stack->a[0] < stack->b[0] || stack->a[stack->a_size - 1] > stack->b[0])
	{
		while (stack->a[j] > stack->b[0] || stack->a[j + 1] < stack->b[0])
			j++;
		while (stack->a[0] < stack->b[0] || \
			stack->a[stack->a_size - 1] > stack->b[0])
		{
			if (stack->a_size / 2 > j)
				ft_rotate_a(stack);
			else
				ft_rev_rotate_a(stack);
		}
	}
	ft_push_a(stack);
}
