/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:28:20 by cmanfred          #+#    #+#             */
/*   Updated: 2019/01/05 16:35:11 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 100
# endif

# define CHECKMALLOC(x) if (!x) return (-1);

# include <string.h>

int					get_next_line(const int fd, char **line);

size_t				ft_copyuntil(char **dst, char *src, char c);

void				*ft_memrealloc(void *src, size_t new_size, size_t old_size);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putstr(char const *c);

void				*ft_memalloc(size_t size);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strcat(char *s1, const char *s2);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strnew(size_t size);

void				*ft_memcpy(void *dst, const void *src, size_t n);

size_t				ft_strlen(const char *s1);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				*ft_memset(void *b, int c, size_t len);

void				*ft_memcpy(void *dst, const void *src, size_t n);

char				*ft_strdup(const char *s1);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_strjoin(const char *s1, char const *s2);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_itoa(int n);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strmap(char const *s, char (*f)(char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_striter(char *s, void (*f)(char *));

void				ft_strclr(char *s);

void				ft_strdel(char **as);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

void				*ft_memset(void *b, int c, size_t len);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					ft_isprint(int c);

int					ft_isascii(int c);

int					ft_isalnum(int c);

int					ft_isdigit(int c);

int					ft_isalpha(int c);

int					ft_atoi(const char *str);

char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strrchr(const char *s, int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strcat(char *restrict s1, const char *restrict s2);

char				*ft_strncpy(char *dst, const char *src, size_t len);

void				*ft_memmove(void *dst, const void *src, size_t len);

size_t				ft_strlcat(char *dst, const
		char *src, size_t size);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memccpy(void *dst, const void
		*src, int c, size_t n);

char				*ft_strncat(char *s1, const char
		*s2, size_t n);

void				ft_bzero(void *s, size_t n);

int					ft_intlen(int num);

char				*ft_strndup(const char *s1, size_t n);

int					ft_countwords(const char *s, char c);

int					ft_arrlen(char **arr);

int					ft_lstlen(t_list *lst);

#endif
