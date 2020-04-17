/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:15:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/07/01 21:37:27 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_putchar(char c);
void				ft_putstr(const char *str);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *str, int a, size_t b);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void	**ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char	**as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putbytes(void *src, int size);
size_t				ft_wstrlen(const wchar_t *str);
size_t				ft_strlen_free(char *str);
char				*ft_strnjoinfree(char *s1, char *s2, unsigned int n);
char				ft_issdigit(char *str);
char				*ft_memjoinfree(void *s1, void *s2, size_t l1, size_t l2);
int					ft_abs(int n);
char				*ft_strinsert(char *dst, char *str, int pos);
char				*ft_strinsertfree(char *dst, char *str, int pos);
char				*ft_strcut(char *str, int start, int end);
char				*ft_strcutfree(char *str, int start, int end);
char				*ft_strinvert(const char *str);
#endif
