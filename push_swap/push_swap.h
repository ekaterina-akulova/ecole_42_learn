/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:01:00 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 00:01:01 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "my_libft/libft.h"

typedef struct s_stack {
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	int		*b_score;
	int		zero;
	int		size;
	int		*index;
	char	*answer;
	int		schet;
	int		max;
	int		min;
}				t_stack;

int				*ft_ialloc(size_t count, size_t size);
void			ft_error(t_stack *stack);
void			ft_initiate(int argc, t_stack *stack);
int				check_arg(t_stack *stack, char *argv);
void			ft_swap_a(t_stack *stack);
void			ft_swap_b(t_stack *stack);
void			ft_swap_swap(t_stack *stack);
void			ft_push_a(t_stack *stack);
void			ft_push_b(t_stack *stack);
void			ft_rotate_a(t_stack *stack);
void			ft_rotate_b(t_stack *stack);
void			ft_rotate_rotate(t_stack *stack);
void			ft_rev_rotate_a(t_stack *stack);
void			ft_rev_rotate_b(t_stack *stack);
void			ft_rev_rotate_rotate(t_stack *stack);
void			ft_sorting(t_stack *stack);
int				ft_check_stack(t_stack *stack);
void			ft_answer(t_stack *stack, char *str);
void			ft_finish(t_stack *stack);
void			ft_radix_sorting(t_stack *stack);
int				ft_etoi(const char *str, t_stack *stack);
void			ft_indexing(t_stack *stack);
void			ft_sort_it(t_stack *stack);
void			ft_min_max(t_stack *stack);
void			ft_calc_score(t_stack *stack, int i);
int				ft_min_score(t_stack *stack);
void			ft_push_min_score(t_stack *stack, int index, int j);
void			sort_part(t_stack *stack);
#endif
