/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:15:54 by chtan             #+#    #+#             */
/*   Updated: 2024/07/02 16:49:34 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  42
# endif

int		ft_isalnum(int c);
int		ft_isalpha(int z);
int		ft_isascii(int a);
int		ft_isdigit(int i);
int		ft_isprint(int p);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	*ft_memmove(void *dst, const void *stc, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_putendl_fd(char *s, int fd);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strdup(char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf
int		ft_printf(const char *buffer, ...);
int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_x(unsigned int num, char c);
int		ft_print_p(uintptr_t buff);
int		ft_print_int(int nb);
int		ft_print_u(unsigned int nb);

//get next line
char	*get_next_line(int fd);
char	*ft_strrjoin(const char *s1, const char *s2);
int		ft_strrlen(char *str);
void	ft_bzerro(void *s, size_t n);
void	*ft_ccalloc(size_t count, size_t size);
char	*ft_strrrchr(const char *s, int c);
#endif
