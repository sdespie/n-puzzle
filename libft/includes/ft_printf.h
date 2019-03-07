/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:07:37 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 17:17:41 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"
# include "get_next_line.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct	s_data
{
	char		*ret;
	char		*str;
	intmax_t	count;
}				t_data;

/*
**f[0]:flagm
**f[1]:flagz
**f[2]:flagh
**f[3]:flagp
**f[4]:flags
**f[5]:width
**f[6]:length
**f[7]:prec
**f[8]:type
**f[9]:precf
*/

typedef struct	s_conv
{
	int			f[10];
	char		*to_conv;
	char		*free;
}				t_conv;

int				ft_printf(const char *format, ...);
int				ft_repart(va_list ap, t_data *data);
t_data			*ft_data_init(const char *string, t_data *data);
int				ft_data_free(int ret, t_data *data);
void			ft_printadd(char c, t_data *data);
void			ft_printaddstr(char *s, t_data *data);
int				ft_percent_hand(t_data *data);
int				ft_parse(t_conv *conv);
int				ft_parse_util(int i, t_conv *conv);
t_conv			*ft_conv_init(t_data *data, t_conv *conv);
int				ft_iso(int mode, char c);
void			ft_conv_free(t_conv *conv);
int				ft_getdigitnbr(int n);
char			ft_getlength(char *convl, t_conv *conv);
int				ft_process(va_list ap, t_conv *conv, t_data *data);
int				ft_setarg(va_list ap);
int				ft_setarg_util(va_list ap);
int				ft_setarg_util_util(va_list ap);
int				ft_noflags(t_conv *conv);
int				ft_type_s(va_list ap, t_conv *conv, t_data *data);
int				ft_type_gs(va_list ap, t_conv *conv, t_data *data);
int				ft_type_p(va_list ap, t_conv *conv, t_data *data);
int				ft_type_d(va_list ap, t_conv *conv, t_data *data);
int				ft_type_gd(va_list ap, t_conv *conv, t_data *data);
int				ft_type_i(va_list ap, t_conv *conv, t_data *data);
int				ft_type_o(va_list ap, t_conv *conv, t_data *data);
int				ft_type_go(va_list ap, t_conv *conv, t_data *data);
int				ft_type_u(va_list ap, t_conv *conv, t_data *data);
int				ft_type_gu(va_list ap, t_conv *conv, t_data *data);
int				ft_type_x(va_list ap, t_conv *conv, t_data *data);
int				ft_type_gx(va_list ap, t_conv *conv, t_data *data);
int				ft_type_c(va_list ap, t_conv *conv, t_data *data);
int				ft_type_gc(va_list ap, t_conv *conv, t_data *data);
int				ft_type_b(va_list ap, t_conv *conv, t_data *data);
int				ft_type_per(va_list ap, t_conv *conv, t_data *data);
char			*ft_type_d_der(t_conv *conv, char *str);
int				ft_empty_proc(t_conv *conv, t_data *data);
void			ft_type_c_util(t_conv *conv, char c, t_data *data);
int				ft_wstrwlen(t_conv *conv, int l, wchar_t *str, t_data *data);
char			*ft_width_str(char *str, char c, t_conv *conv);
char			*ft_type_d_len(va_list ap, t_conv *conv);
char			*ft_type_d_flags(char *str, t_conv *conv);
char			*ft_type_d_util(char *str, t_conv *conv, intmax_t l, char *stb);
char			*ft_type_d_utils(char *str, char *stb, t_conv *conv);
char			*ft_type_u_util(t_conv *conv, char *str, char *stb);
char			*ft_type_u_m(t_conv *conv, char *str, char *stb);
char			*ft_type_u_e(t_conv *conv, char *str, char *stb);
int				ft_type_gc_util(t_conv *conv, wchar_t chr, size_t lc,
		t_data *data);
size_t			chrsize(wchar_t chr);
size_t			ft_get_str_len(intmax_t n);
char			*ft_pf_itoa(intmax_t n);
int				ft_count(int value, int base);
char			*ft_pf_uitoa_base(uintmax_t n, int base);
char			*ft_type_u_len(va_list ap, t_conv *conv, int base);
char			*ft_type_u_flags(char *str, t_conv *conv);
char			*ft_type_c_flags(t_conv *conv, char c);
int				ft_wconv(t_data *data, t_conv *conv);
char			*ft_strjoinfn(char *s1, const char *s2);
char			*ft_strjoinnf(const char *s1, char *s2);
char			*ft_strjoinff(char *s1, char *s2);
char			*ft_type_d_der_mdr(t_conv *conv, char *str, size_t l);
char			*ft_type_u_utils_utils(char *stb);
#endif
