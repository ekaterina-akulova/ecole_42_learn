//
// Created by Gail Derrick on 12/15/21.
//

#include "checker.h"

void	ft_rev_rotate_rotate_2(t_stack_ab *stack)
{
	ft_rev_rotate_a_2(stack);
	ft_rev_rotate_b_2(stack);
}

static int	ft_check_commands2(char *line, t_stack_ab *stack_ab)
{
	if (!ft_strcmp(line, "rra\n"))
		ft_rev_rotate_a_2(stack_ab);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rev_rotate_b_2(stack_ab);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_rotate_2(stack_ab);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rev_rotate_rotate_2(stack_ab);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_rotate_2(stack_ab);
	else
		return (0);
	return (1);
}

int	ft_check_commands(char *lin/*   Updated: 2022/01/21 21:29:01 by                  ###   ########.fr       */);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push_b_2(stack_ab);
	else if (!ft_strcmp(line, "sa\n"))
		ft_swap_a_2(stack_ab);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap_b_2(stack_ab);
	else if (!ft_strcmp(line, "ss\n"))
		ft_swap_swap_2(stack_ab);
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotate_a_2(stack_ab);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate_b_2(stack_ab);
	else
		return (ft_check_commands2(line, stack_ab));
	return (1);
}

int	ft_check_stacks(t_stack_ab *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1 && stack->a[i + 1] != AER)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	if (stack->b_size == 0)
		return (1);
	return (0);
}

void	ft_error_checks(t_stack_ab *stack)
{
	write(2, "Error\n", 6);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
	exit(-1);
}
