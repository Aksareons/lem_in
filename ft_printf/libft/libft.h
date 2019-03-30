/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:14:22 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/01 09:08:04 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>


# define GET_NEXT_LINE
# define BUF_SIZE 1


int		get_next_line(const int fd, char **line);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_putchar(char c);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t n);

void				*ft_memchr(const void *arr, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t n);

char				*ft_strcat(char *dst, const char *src);

char				*ft_strncat (char *des, const char *src, size_t n);

size_t				ft_strlcat (char *des, const char *src, size_t n);

char				*ft_strchr(const char *str, int ch);

char				*ft_strrchr(const char *str, int ch);

char				*ft_strstr(const char *dst, const char *src);

char				*ft_strnstr(const char *dst, const char *src, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void(*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(intmax_t n);

char				**ft_strsplit(char const *s, char c);

char				*ft_strndup(const char *s1, size_t n);

void				ft_swap(int *a, int *b);

double					ft_sqrt(double nb);

void				ft_print_bits(unsigned char octet);

size_t				ft_strcspn(const char *s, const char *reject);

intmax_t			ft_intlen(intmax_t i);

char				*ft_itoa_base(size_t value, int base);

#endif
