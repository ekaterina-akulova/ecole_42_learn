/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:07:36 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:41:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/15/21.
//
#include "checker.h"

void	ft_rotate_a_2(t_stack_ab *stack)
{
	long	temp;
	int		i;

	i = 0;
	temp = stack->a[0];
	while (i < (stack->a_size - 1))
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void	ft_rotate_b_2(t_stack_ab *stack)
{
	long	temp;
	int		i;

	i = 0;
	temp = stack->b[0];
	while (i < (stack->b_size - 1))
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}

void	ft_rev_rotate_a_2(t_stack_ab *stack)
{
	long	temp;
	int		i;

	temp = stack->a[stack->a_size - 1];
	i = 1;
	while (i < stack->a_size)
	{
		stack->a[stack->a_size - i] = stack->a[stack->a_size - i - 1];
		i++;
	}
	stack->a[0] = temp;
}

void	ft_rev_rotate_b_2(t_stack_ab *stack)
{
	long	temp;
	int		i;

	temp = stack->b[stack->b_size - 1];
	i = 1;
	while (i < stack->b_size)
	{
		stack->b[stack->b_size - i] = stack->b[stack->b_size - i - 1];
		i++;
	}
	stack->b[0] = temp;
}

void	ft_rotate_rotate_2(t_stack_ab *stack)
{
	ft_rotate_a_2(stack);
	ft_rotate_b_2(stack);
}
