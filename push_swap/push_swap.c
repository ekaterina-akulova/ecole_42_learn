/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:53:53 by                   #+#    #+#             */
/*   Updated: 2022/01/21 19:58:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(t_stack *stack, char *argv)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(argv) && argv[i])
	{
		if ((argv[i] > '9' || argv[i] < '0') && argv[i] != '-')
			ft_error(stack);
		i++;
	}
	return (ft_etoi(argv, stack));
}

void	ft_initiate(int argc, t_stack *stack)
{
	int	i;

	i = argc;
	stack->size = i;
	if (argc <= 1)
		ft_error(stack);
	stack->a = (int *) ft_calloc(i, sizeof(int));
	if (!stack->a)
		ft_error(stack);
	stack->b = (int *) ft_calloc(i, sizeof(int));
	if (!stack->b)
		ft_error(stack);
	stack->answer = (char *) malloc(1);
	if (!stack->answer)
		ft_error(stack);
	stack->b_score = (int *) ft_calloc(1, sizeof(int));
	stack->answer[0] = '\0';
	stack->zero = 0;
	stack->a_size = 0;
	stack->b_size = 0;
}

static void	fullfill(t_stack *stack, int i, char **array)
{
	int	j;

	while (array[i])
	{
		j = 0;
		stack->a[i] = ft_etoi(array[i], stack);
		while (j <= i - 1)
		{
			if (stack->a[i] == stack->a[j++] || stack->zero > 1)
				ft_error(stack);
			stack->a_size++;
			i++;
		}
	}
}

static void	fullfill2(t_stack *stack, int argc, char **argv, int i)
{
	int	j;
	int	number;

	while (argc-- != 1)
	{
		number = check_arg(stack, argv[i + 1]);
		if (number == 0)
			stack->zero++;
		j = 0;
		while (j < i - 1)
			if ((number == stack->a[j++] && number != 0) || stack->zero > 1)
				ft_error(stack);
		stack->a[i] = number;
		stack->a_size++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	char	**array;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ft_error(stack);
	if (argc != 2)
		i = argc;
	else
	{
		array = ft_split(argv[1], ' ');
		while (array[i++])
			;
		if (i == 2)
			return (0);
	}
	ft_initiate(i - 1, stack);
	if (argc == 2)
		fullfill(stack, 0, array);
	else
		fullfill2(stack, argc, argv, 0);
	sort_part(stack);
	return (0);
}
