/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:00:21 by nrouvroy          #+#    #+#             */
/*   Updated: 2019/01/15 10:26:52 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <wchar.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define FT_MIN(x , y) (x) < (y) ? (x) : (y)
# define FT_MAX(x , y) (x) > (y) ? (x) : (y)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *str, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *src, int c, size_t len);
int				ft_memcmp(const void *str1, const void *str2, size_t len);

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *substr);
char			*ft_strnstr(const char *str, const char *substr, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_atoi(const char *str);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				ft_map_cu(char *str, int i);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t len);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
char			*ft_itoa(int n);

void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_str_isnum(char *str);
char			**ft_strcut(char *str, int n);
long int		ft_map_err(int mode);
int				ft_countwords(char const *str, char c);
t_list			*ft_lst_reverse(t_list *alst);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_str_isalnum(const char *str);
int				ft_str_isalpha(const char *str);
int				ft_str_isascii(const char *str);
int				ft_str_isdigit(const char *str);
int				ft_str_islower(const char *str);
int				ft_str_isupper(const char *str);
void			ft_str_tolower(char *str);
char			*ft_str_toupper(char *str);
int				ft_str_contains(char *str, char c);
char			*ft_itoa_base(int value, int base);
int				ft_abs(int n);
long long int	ft_pow(int n, int exp);
int				ft_sqrt(int n);
int				ft_max(int *tab, size_t length);
int				ft_min(int *tab, size_t length);
char			*ft_mjoin(int count, ...);
void			ft_putwchar(wchar_t c);
void			ft_putwchar_fd(wchar_t c, int fd);
void			ft_putwstr(const wchar_t *str);
void			ft_putwstr_fd(const wchar_t *str, int fd);
void			ft_putnwstr_fd(const wchar_t *str, size_t length, int fd);

#endif
