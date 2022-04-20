/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:25:55 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 21:26:02 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/11/21.
//

#include "checker.h"

int	ft_eetoi(const char *str, t_stack_ab *stack)
{
	int					i;
	int					sign;
	int					res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (*str && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (i > 0 && res > (res * 10 + (str[i + 1] - 48)))
			ft_error_checks(stack);
		i++;
	}
	res *= sign;
	return (res);
}

long	check_arg(t_stack_ab *stack, char *argv)
{
	int	i;
	int	str_args;

	str_args = 0;
	i = 0;
	while (i <= (int) ft_strlen(argv) - 1)
	{
		if (((argv[i] == '-' && (ft_isdigit(argv[i + 1]) == 0))) \
			|| ((argv[i] > '9' || argv[i] < '0') && argv[i] != '-'))
			ft_error_checks(stack);
		else if (argv[i] == ' ')
			str_args = 1;
		i++;
	}
	if (str_args == 1)
		return (3333333333);
	return ((long) ft_eetoi(argv, stack));
}

void	ft_initiate(int argc, t_stack_ab *stack)
{
	if (argc <= 1)
	{
		exit(-1);
	}
	stack->a = (long *) ft_ialloc_2(argc, sizeof(long));
	if (!stack->a)
		ft_error_checks(stack);
	stack->b = (long *) ft_ialloc_2(argc, sizeof(long));
	if (!stack->b)
		ft_error_checks(stack);
	stack->size = argc - 1;
}

void	ft_fullfill(int *i, int *j, t_stack_ab *checker_stack, long *number)
{
	while (*j < *i)
		if ((*number == checker_stack->a[(*j)++] && *number != 0) \
				|| checker_stack->zero > 1)
			ft_error_checks(checker_stack);
	checker_stack->a[*i - 1] = *number;
	checker_stack->a_size++;
	(*i)++;
}

int	main(int argc, char **argv)
{
	t_stack_ab	*checker_stack;
	int			i;
	int			j;
	long		number;
	char		**array;

	checker_stack = ft_calloc(1, sizeof(t_stack_ab));
	ft_initiate(argc, checker_stack);
	i = 1;
	while (argc-- != 1)
	{
		j = 0;
		number = check_arg(checker_stack, argv[i]);
		if (number == 0)
			checker_stack->zero++;
		if (number == TERRA)
		{
			array = ft_split(argv[i], ' ');
			ft_is_terra(array, number, j, checker_stack);
		}
		else
			ft_fullfill(&i, &j, checker_stack, &number);
	}
	ft_intmax_check(0, checker_stack);
	return (0);
}
