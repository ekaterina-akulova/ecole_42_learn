/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:45:17 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/13 16:45:19 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define BUFFER_SIZE 10000

typedef struct s_buffer
{
	va_list		args;
	char		buffer[BUFFER_SIZE];
	long		buff_i;
	long		written;
}				t_buffer;

typedef struct s_flags
{
	int			space;
	int			plus;
	int			dot;
	long		width;
	int			hash;
	int			precision;
	int			b_preci;
	int			b_left_aligned;
	int			b_zero_padding;
	int			b_only_once;
	int			b_num_zero;
	long		to_write;
	int			num_len;
	int			zeros;
	long		negative;
	int			count_minus;
	int			anotherwidth;
	int			countspace;
	long		neg_num;
	int			count_plus;
}				t_flags;

int				ft_printf(const char *s, ...);
int				helpme(char *str, int *i);
void			helpme_2(t_flags *flags, char *str, int *i);
void			helpme_3(t_flags *flags, char *str, int *i);
void			helpme_4(t_flags *flags, char *str, int *i);
void			helpme_5(t_flags *flags, char *str, int *i);
void			helpme_6(t_flags *flags, char *str, int *i);
void			helpme_7(t_buffer *b, t_flags *f, int c);
int				helpme_8(int len, t_buffer *b, t_flags *f, char *print);
void			helpme_9(t_buffer *b, t_flags *f, char *print);
void			helpme_10(t_flags *f, int length);
void			helpme_11(t_buffer *b, t_flags *f, long num);
void			helpme_12(t_flags *f, t_buffer *b, long num);

int				ft_width_handler(int width, int minus, int zero);
char			*type_c(t_buffer *b, t_flags *f, int c, char *str);
char			*type_s(t_buffer *b, t_flags *f, char *print, char *str);
char			*type_s_left(t_buffer *b, t_flags *f, char *print, char *str);
char			*type_di1(t_buffer *b, t_flags *f, long num, char *str);
char			*type_di2(t_buffer *b, t_flags *f, long num, char *str);
char			*type_u(t_buffer *b, t_flags *f, unsigned int num, char *str);
char			*type_p(t_buffer *b, t_flags *f, \
				unsigned long int num, char *str);
char			*type_x(t_buffer *b, t_flags *f, unsigned int c, char *str);

long			ft_putnbr_len(t_flags *f, long n);
int				ft_putchar_fd(char c, int fd);
long			ft_puthexa_len(t_buffer *b, t_flags *f, unsigned long x);
void			ft_putnbr(t_buffer *b, t_flags *f, long n);
void			ft_puthexa(t_buffer *b, t_flags *f, \
				unsigned long x, char *type);

int				ft_is_type(char c);
void			read_flags(t_flags *flags, char *str, int *i);
void			width_precision(t_flags *f, char *str, int *i);
char			*read_format(t_buffer *b, t_flags *f, char *str);
char			*placeholders(t_flags *f, char *str);

void			write_and_clear(t_buffer *b);
void			add_to_buffer(t_buffer *b, t_flags *f, char c);

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
char			*conversion_helper(t_buffer *b, t_flags *f, \
				char *str, char type);
#endif
