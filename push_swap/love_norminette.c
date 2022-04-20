/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   love_norminette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:02:14 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:02:16 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/15/21.
//

#include "checker.h"

void	fuck_you_norma(char *line, t_stack_ab *stack_ab)
{
	if (!ft_strcmp(line, "rrb\n"))
		ft_rev_rotate_b_2(stack_ab);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_rotate_2(stack_ab);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rev_rotate_rotate_2(stack_ab);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_rotate_2(stack_ab);
}

void	fuck_this_shit_fuck_this_world_your_fucking_fuck(t_stack_ab *stack)
{
	int	i;

	i = 0;
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

void	fuck_you_norma_2(t_stack_ab *stack)
{
	int	i;

	i = 0;
	while (stack->b[i] <= INTMAX)
		i++;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
}

void	ft_gnl_using(t_stack_ab *checker_stack, int i)
{
	char	*line;
	int		check_commands;

	line = get_next_line(0);
	while (line != NULL)
	{
		check_commands = ft_check_commands(line, checker_stack);
		if (check_commands == 0)
			ft_error_checks(checker_stack);
		line = get_next_line(0);
		i++;
	}
	fuck_you_norma_5(checker_stack);
}
