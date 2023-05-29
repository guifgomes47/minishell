/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:50:55 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/28 22:32:16 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//|Start: ft_printf
# define DIGITS "0123456789"
# define HEXALOW "0123456789abcdef"
# define HEXAUPP "0123456789ABCDEF"

typedef struct s_info
{
	char	type;
}			t_info;

//|MAIN FUNCTIONS:
//|file: ft_printf.c
int			ft_printf(const char *string, ...);
int			ft_vfprintf(va_list args, const char *format);
int			print_type(va_list args, t_info *info);
//|file: ft_printf_c_str.c
int			print_char(char c);
int			print_string(char *str);
//|file: ft_printf_digits.c
int			print_digits(int d);
int			print_uns_num(unsigned int d);
int			print_hexa(unsigned int d, t_info *info);
int			print_pointer(unsigned long int d);
//|UTILS-FUNCTIONS:
//|End: ft_printf

//|Start: get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
//|End: get_next_line

//|Start: Libft
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *str, size_t nbyte);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strncjoin(char *s1, char *s2);
char		*ft_strtrim(char const *str, char const *set);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putchar(int c);
int			ft_strcmp(const char *s1, const char *s2);

//|Linked list:
typedef struct s_list
{
	void	*content;
	void	*next;
}			t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **list, t_list *new);
t_list		*ft_lstrevsplit(char **str);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *list);

//|Extras
char		*ft_ulitoa_base(unsigned long int n, char *base);
char		**ft_split_cmd(char const *str, char c);
int			ft_isspace(int n);
long int	ft_atol(const char *nptr);
//|End: Libft
#endif