#include "push_swap.h"

void	ft_answer(t_stack *stack, char *str)
{
	char	*temp;

	stack->schet++;
	temp = ft_strjoin(stack->answer, str);
	if (stack->answer)
		free(stack->answer);
	stack->answer = temp;
}

void	ft_indexing(t_stack *stack)
{
	long	temp;
	int		i;
	int		j;

	i = -1;
	stack->index = ft_calloc(stack->size, sizeof(long));
	if (!stack->index)
		ft_error(stack);
	while (++i < stack->size)
		stack->index[i] = stack->a[i];
	i = 1;
	while (i <= stack->size)
	{
		temp = stack->index[i];
		j = i;
		while (j > 0 && stack->index[j - 1] > temp)
		{
			stack->index[j] = stack->index[j - 1];
			j--;
		}
		stack->index[j] = temp;
		i++;
	}
/*   Updated: 2022/01/21 21:29:01 by                  ###   ########.fr       */e(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->answer)
		free(stack->answer);
	if (stack->b_score)
		free(stack->b_score);
	free(stack);
	exit(-1);
}

void	ft_finish(t_stack *stack)
{
	while (stack->b_size)
		ft_push_a(stack);
	write(1, stack->answer, ft_strlen(stack->answer));
	free(stack->a);
	free(stack->b);
	free(stack->answer);
	if (stack->size > 10)
		free(stack->b_score);
	free(stack);
	exit(0);
}

void	sort_part(t_stack *stack)
{
	if (ft_check_stack(stack))
		ft_finish(stack);
	if (stack->size > 10)
		ft_sort_it(stack);
	else
		ft_sorting(stack);
	ft_finish(stack);
}
