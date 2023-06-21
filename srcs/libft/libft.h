/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:24:52 by wmari             #+#    #+#             */
/*   Updated: 2022/12/22 08:47:46 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_libftlist
{
	void				*content;
	struct s_libftlist	*next;
}				t_libftlist;

int				ft_atoi(const char *str);
void			ft_bzero(void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *dest, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_itoa(int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
t_libftlist		*ft_libftlstnew(void *content);
void			ft_libftlstadd_front(t_libftlist **alst, t_libftlist *new);
int				ft_libftlstsize(t_libftlist *lst);
t_libftlist		*ft_libftlstlast(t_libftlist *lst);
void			ft_libftlstadd_backk(t_libftlist **alst, t_libftlist *new);
void			ft_libftlstdelone(t_libftlist *lst, void (*del)(void*));
void			ft_libftlstclear(t_libftlist **lst, void (*del)(void*));
void			ft_libftlstiter(t_libftlist *lst, void (*f)(void *));
t_libftlist		*ft_libftlstmap(t_libftlist *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
