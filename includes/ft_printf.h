/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:53:23 by vgosset           #+#    #+#             */
/*   Updated: 2016/05/10 16:36:25 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_struct
{
	char		*block;
	int			hash;
	int			moins;
	int			plus;
	int			zero;
	int			space;
	int			larg;
	int			prec;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	char		type;
}				t_struct;

int				g_ret;

int				ft_printf(const char *format, ...);
int				check_format(const char *format);
int				check_options(const char format, t_struct *form);
int				check_type(const char format);
int				check_minimal_large(const char format, t_struct *form);
int				check_precision(const char format, t_struct *form);
int				check_block(char *block, t_struct *form);
int				set_block(const char *format, va_list va);
int				display_block(t_struct *form, va_list va, int i);
int				ft_isspace(int c);
int				ft_count_long(long n);
int				ft_count_base(unsigned long n, int base);
int				ft_count_wchar(unsigned int wchar);

long			ft_power(long nb, int i);
long long		check_display_block_d(t_struct *form, va_list va);
uintmax_t		check_display_block_o(t_struct *form, va_list va);
uintmax_t		check_display_block_x(t_struct *form, va_list va);
uintmax_t		check_display_block_u(t_struct *form, va_list va);
unsigned long	check_display_block_p(va_list va);

void			ft_putint(int c);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putstr(char const *s);
void			ft_putwstr(wchar_t *str);
void			set_format(const char *format, va_list va);
void			check_size_modifier(const char *format, t_struct *form);
void			init_struct(t_struct *form);
void			print_oct(char *mask);
void			ft_bzero(void *s, size_t n);
void			checkflags(t_struct *form, char a, char b);
void			set_c(t_struct *form, va_list va);
void			set_s(t_struct *form, va_list va);
void			set_wchar_s(t_struct *form, va_list va);

char			*set_moins_d_2(t_struct *form, char *str, long long n,
				char *larg);
char			*set_moins_d_norm(t_struct *form, char *s, char *larg,
				long long n);
char			*set_d_0_neg(char *str, int nbr0, long long n);
char			*set_d_plus_space(char *str, char c);
char			*set_larg(t_struct *form, char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(intmax_t nbr, int base);
char			*u_itoa_base(uintmax_t nbr, int base);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
char			*ui_to_bits(unsigned int u);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*place(int n, char c);
char			*place_s(int n, char c);
char			*set_upper(char *str);
char			*set_d(t_struct *form, va_list va);
char			*set_octal(t_struct *form, va_list va);
char			*set_hex(t_struct *form, va_list va);
char			*set_u(t_struct *form, va_list va);
char			*set_p(t_struct *form, va_list va);
char			*set_tag(t_struct *form);

char			**uni_mask(char *bits);
char			**uni_mask_1(char *bits, char *mask, size_t b_len, int m_len);
char			**ft_strsplit(char const *s, char c);

size_t			ft_words(char const *str, char c);
size_t			ft_strlen(const char *s);

#endif
