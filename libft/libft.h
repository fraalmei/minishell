/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:58:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/18 16:38:48 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

	// buffer for the get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

	// basic structure of "t_list"
	// its defined a struct type "t_list"
	// with two variables content and next (element of the list)
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *c, size_t i);
void	*ft_memset(void *dest, int c, size_t i);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_lstpst(const char *s);
char	*ft_fstpst(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

		//bonus
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

		//ft_printf
int		ft_printf(char const *str, ...);
char	*ft_chrjoin(char *s1, char s2);

		//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin_onefree(char *s1, char const *s2);

		//extras
size_t	ft_intlen(int n, int base);

		// ft_strchr_nbr
int		ft_strchr_nbr(const char *s, int c);
int		ft_strchr_cnt(const char *s, int c);

		// ft_strchr
int		ft_str_frst_chr(char *str, char c);
int		*ft_str_all_chr(char *str, char c);

		// ft_strrchr
int		ft_str_lst_chr(const char *s, int c);

		// ft_strdup
char	*ft_strndup(const char *str, unsigned int n);

		// ft_strncmp
int		ft_str_frst_cmp(const char *haystack, const char *needle);
int		ft_str_last_cmp(const char *haystack, const char *needle);
int		ft_strcmp(const char *s1, const char *s2);

		// ft_strtrim
char	*ft_strtrim_onefree(char *s1, char const *set);

		//ft_put_nbr_fd
int		ft_putnbr_base(long long int nbr, long long int i, char *base);

		//free
int		free_str(char **s);
int		free_str_str(char ***s);

		//ft_chrcmp.c
int		ft_frst_chrcmp(const char *s, int c);
int		ft_lst_chrcmp(const char *s, int c);
int		ft_chrcmp_str(const char *str, char *trim);

		//ft_strlen
size_t	ft_strlen_array(const void **string);

#endif