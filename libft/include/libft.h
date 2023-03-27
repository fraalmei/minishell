/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:40:56 by cagonzal          #+#    #+#             */
/*   Updated: 2023/03/24 09:45:10 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include "t_list.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1
# define APPFILE 2

# define BUFFER_SIZE 1

// FILE

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*get_next_line(int fd);

// MEM

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_arg(void **arg);
void		ft_free_tab(char **tab);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, unsigned int n);
void		*ft_memcpy(void *dst, const void *src, unsigned int n);
void		*ft_memmove(void *dst, const void *src, unsigned int len);
void		*ft_memset(void *dst, int c, int i);

// NBR

int			ft_abs(float num);
int			ft_atoi_base(const char *str, int str_base);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(char *s);
char		*ft_itoa(int n);

// OTHERS

int			ft_arraybi_size(char **str);
void		ft_error(int error);
int			ft_hasany(const char *str, char c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_printf(const char *str, ...);

// STR

char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(const char *s1);
int			ft_strichr(char *str, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strndup(const char *s1, unsigned int n);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
