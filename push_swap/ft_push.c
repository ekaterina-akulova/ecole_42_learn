/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:06:28 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:41:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack *stack)
{
	int	i;

	if (stack->b_size > 0)
	{
		i = stack->a_size;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		while (i < stack->b_size)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->a_size++;
		stack->b_size--;
	}
	ft_answer(stack, "pa\n");
}

void	ft_push_b(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = stack->b_size;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		while (i < stack->a_size)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->b_size++;
		stack->a_size--;
	}
	ft_answer(stack, "pb\n");
}
