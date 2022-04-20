/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:06:17 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:41:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stack)
{
	if (stack->a_size > 2)
	{
		stack->a[0] = stack->a[0] + stack->a[1];
		stack->a[1] = stack->a[0] - stack->a[1];
		stack->a[0] = stack->a[0] - stack->a[1];
	}
	ft_answer(stack, "sa\n");
}

void	ft_swap_b(t_stack *stack)
{
	if (stack->b_size > 2)
	{
		stack->b[0] = stack->b[0] + stack->b[1];
		stack->b[1] = stack->b[0] - stack->b[1];
		stack->b[0] = stack->b[0] - stack->b[1];
	}
	ft_answer(stack, "sb\n");
}

void	ft_swap_swap(t_stack *stack)
{
	ft_swap_a(stack);
	ft_swap_b(stack);
	ft_answer(stack, "ss\n");
}

void	ft_rotate_rotate(t_stack *stack)
{
	ft_rotate_a(stack);
	ft_rotate_b(stack);
	ft_answer(stack, "rr\n");
}

void	ft_rev_rotate_rotate(t_stack *stack)
{
	ft_rev_rotate_a(stack);
	ft_rev_rotate_b(stack);
	ft_answer(stack, "rrr\n");
}
