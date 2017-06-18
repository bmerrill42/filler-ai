/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:57:29 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:31:13 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# define BUFF_SIZE 32

enum	e_sides {FREE_LEFT, FREE_RIGHT, FREE_BOTH};

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef char		t_stackelem;
typedef struct		s_stack
{
	t_stackelem		*contents;
	int				top;
	int				max_size;
}					t_stack;

char				*ft_tolower_str(char *str);
char				*ft_itoa_u(uintmax_t n);
char				*ft_strjoin_free(char const *s1, char const *s2, int side);
char				*ft_itoa_base(uintmax_t value, int base);
int					get_next_line(const int fd, char **line);
void				ft_stackpush(t_stack *stack, t_stackelem element);
t_stackelem			ft_stackpop(t_stack *stack);
int					ft_stackisfull(t_stack *stack);
int					ft_stackisempty(t_stack *stack);
void				ft_stackinit(t_stack *stack, int maxsize);
void				ft_stackdestroy(t_stack *stack);
int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(intmax_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *string1, const char *string2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strcspn(const char *s1, const char s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t siz);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little, size_t len
);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strspn(const char *s1, const char *s2);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wordcount(char const *str, char c);
#endif
