/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_norma.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:08:05 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:08:07 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/9/22.
//

#include "checker.h"

void	ft_push_a_norma(t_stack_ab *stack, int i)
{
	stack->a[0] = stack->b[0];
	if (stack->b[i + 1] <= INTMAX)
	{
		while (stack->b[i + 1] <= INTMAX)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = AER;
	}
	else
		stack->b[i] = AER;
	stack->a_size++;
	stack->b_size--;
}

void	ft_push_b_norma(t_stack_ab *stack, int i)
{
	if (stack->a[i + 1] <= INTMAX)
	{
		while (stack->a[i + 1] <= INTMAX)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = AER;
	}
	else
		stack->a[i] = AER;
	stack->b_size++;
	stack->a_size--;
}
