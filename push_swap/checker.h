//
// Created by Gail Derrick on 12/11/21.
//

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "my_libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define AER 2222222222
# define TERRA 3333333333
# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stack_ab {
	long	*a;
	long	*b;
	int		a_size;
	int		b_size;
	int		size;
	int		zero;
}				t_stack_ab;

void	ft_gnl_using(t_stack_ab *checker_stack, int i);
void	ft_not_terra(int j, int i, long number, t_stack_ab *checker_stack);
int		ft_eetoi(const char *str, t_stack_ab *stack);
int		ft_isspace(char c);
void	ft_is_terra(char/*   Updated: 2022/01/21 21:29:01 by                  ###   ########.fr       */k(int i, t_stack_ab *checker_stack);
long	check_arg(t_stack_ab *stack, char *argv);
void	ft_initiate(int argc, t_stack_ab *stack);
long	*ft_ialloc_2(size_t count, size_t size);
void	fuck_you_norma(char *line, t_stack_ab *stack_ab);
void	ft_push_a_norma(t_stack_ab *stack, int i);
void	ft_push_b_norma(t_stack_ab *stack, int i);
void	fuck_you_norma_3(char **array, t_stack_ab *stack);
void	fuck_you_norma_5(t_stack_ab *stack);
void	fuck_this_shit_fuck_this_world_your_fucking_fuck(t_stack_ab *stack);
void	ft_push_a_2(t_stack_ab *stack);
void	ft_push_b_2(t_stack_ab *stack);
void	ft_swap_a_2(t_stack_ab *stack);
void	ft_swap_b_2(t_stack_ab *stack);
void	ft_swap_swap_2(t_stack_ab *stack);
void	ft_rotate_a_2(t_stack_ab *stack);
void	ft_rotate_b_2(t_stack_ab *stack);
void	ft_rev_rotate_a_2(t_stack_ab *stack);
void	ft_rev_rotate_b_2(t_stack_ab *stack);
void	ft_rotate_rotate_2(t_stack_ab *stack);
void	ft_rev_rotate_rotate_2(t_stack_ab *stack);
int		ft_strcmp(char *s1, char *s2);
void	ft_error_checks(t_stack_ab *stack);
int		ft_check_commands(char *line, t_stack_ab *stack_ab);
int		ft_check_stacks(t_stack_ab *stack_ab);

#endif //PUSH_SWAP_CHECKER_H
