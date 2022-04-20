/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:07:20 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:07:21 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/15/21.
//
#include "checker.h"

void	ft_push_a_2(t_stack_ab *stack)
{
	int	i;

	i = 0;
	if (stack->b[0] <= INTMAX)
	{
		while (stack->a[i] <= INTMAX)
			i++;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		i = 0;
		ft_push_a_norma(stack, i);
	}
}

void	ft_push_b_2(t_stack_ab *stack)
{
	int	i;

	i = 0;
	if (stack->a[0] <= INTMAX)
	{
		while (stack->b[i] <= INTMAX)
			i++;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		i = 0;
		stack->b[0] = stack->a[0];
		ft_push_b_norma(stack, i);
	}
}

void	ft_swap_a_2(t_stack_ab *stack)
{
	if (stack->a[0] <= INTMAX && stack->a[1] <= INTMAX)
	{
		stack->a[0] = stack->a[0] + stack->a[1];
		stack->a[1] = stack->a[0] - stack->a[1];
		stack->a[0] = stack->a[0] - stack->a[1];
	}
}

void	ft_swap_b_2(t_stack_ab *stack)
{
	if (stack->b[0] <= INTMAX && stack->b[1] <= INTMAX)
	{
		stack->b[0] = stack->b[0] + stack->b[1];
		stack->b[1] = stack->b[0] - stack->b[1];
		stack->b[0] = stack->b[0] - stack->b[1];
	}
}

void	ft_swap_swap_2(t_stack_ab *stack)
{
	ft_swap_a_2(stack);
	ft_swap_b_2(stack);
}
