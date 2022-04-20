/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:05:48 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:05:51 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	if (stack->a_size == stack->size)
		return (1);
	if (stack->b[0] && stack->a[0] < stack->b[0])
		return (0);
	i = 0;
	while (i < stack->b_size - 1)
	{
		if (stack->b[i] < stack->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	ft_sorting2(t_stack *stack)
{
	while (stack->b_size > 0)
	{
		if (stack->a_size > 1 && stack->a[0] > stack->a[stack->a_size - 1])
		{
			if (stack->b[0] < stack->b[stack->b_size - 1])
				ft_rotate_rotate(stack);
			else
				ft_rotate_a(stack);
		}
		else if (stack->b[0] < stack->b[stack->b_size - 1])
			ft_rotate_b(stack);
		if (stack->b[0] < stack->b[1])
			ft_swap_b(stack);
		if (ft_check_stack(stack))
			return ;
		ft_push_a(stack);
	}
}

void	ft_sorting(t_stack *stack)
{
	while (!ft_check_stack(stack))
	{
		while (stack->a_size > 0)
		{
			if (stack->b_size > 1 && stack->b[0] < stack->b[stack->b_size - 1])
			{
				if (stack->a[0] > stack->a[stack->a_size - 1])
					ft_rotate_rotate(stack);
				else
					ft_rotate_b(stack);
			}
			else if (stack->a[0] > stack->a[stack->a_size - 1])
				ft_rotate_a(stack);
			if (stack->a[0] > stack->a[1])
				ft_swap_a(stack);
			if (ft_check_stack(stack))
				return ;
			ft_push_b(stack);
		}
		ft_sorting2(stack);
	}
}

static void	ft_sort_it2(t_stack *stack)
{
	int	i;

	while (stack->b_size)
	{
		ft_calc_score(stack, 0);
		ft_push_min_score(stack, ft_min_score(stack), 0);
	}
	i = 0;
	while (stack->a[i] != stack->min)
		i++;
	while (stack->a[0] != stack->min)
	{
		if (stack->a_size / 2 > i)
			ft_rotate_a(stack);
		else
			ft_rev_rotate_a(stack);
	}
	free(stack->index);
}

void	ft_sort_it(t_stack *stack)
{
	int	i;

	i = 0;
	ft_min_max(stack);
	ft_indexing(stack);
	i = 0;
	while (stack->a_size != 3)
	{
		if (stack->a[0] != stack->min && \
			stack->a[0] != stack->max && \
			stack->a[0] != stack->index[stack->size / 2])
			ft_push_b(stack);
		else
			ft_rotate_a(stack);
		i++;
	}
	if ((stack->a[0] == stack->max && stack->a[1] > stack->a[2]) || \
		(stack->a[1] == stack->max && stack->a[0] < stack->a[2]) || \
		(stack->a[2] == stack->max && stack->a[0] > stack->a[1]))
		ft_swap_a(stack);
	ft_sort_it2(stack);
}
