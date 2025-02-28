/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:15:02 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 16:41:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
/*PART1 : libc*/
/* 1. ctype.h :  ft_ctype_classification.c*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
/* END */

/* 2. ctype.h : ft_ctype_case_mapping.c*/
int		ft_toupper(int c);
int		ft_tolower(int c);
/* END*/

/* 3. string.h & strings.h : ft_string_miscellaneous.c */
/*		1. string.h */
size_t	ft_strlen(const char *s);
void	*ft_memset(void	*s, int c, size_t n);

/*		2. strings.h*/
void	ft_bzero(void *s, size_t n);
/* END*/

/* 4. string.h : ft_string_copying.c */
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/* END*/

/* 5. string.h : ft_string_concat.c */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/* END*/

/* 6. string.h :ft_string_comparison.c */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* END*/

/* 7. string.h : ft_string_search.c */
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* END*/

/* 8. string.h : ft_string_duplicate.c*/
char	*ft_strdup(const char *s1);
/* END*/

/* 9. stdlib.h : ft_stdlib.c */

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
/* END*/
/* PART1 END */

/* PART2*/
/* 1. ft__string.c*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const	*s1, char const *set);
/* END*/

/* 2. ft__string_split.c */
char	**ft_split(char const *s, char c);
/* END*/

/* 3. ft__stdlib.c */
char	*ft_itoa(int n);
/*END*/

/* 4. ft__string_function.c */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/* END*/

/* 5. ft__print_functions.c */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/* END*/
/* PART 2 END */
/* BONUS PART */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ft___lst_bonus.c */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *n);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *n);
/*END*/

/*ft___lst_del_bonus.c*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
/*END*/

/*ft___lst_function_bonus.c*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*END*/

char	*ft_itoa_base(unsigned long n, char *base);
int		ft_atoi_base(const char *str, char *base);

/* make string */
typedef struct s_temp_str
{
	char	*str;
	size_t	len;
	size_t	cap;
}	t_temp_str;

/* ft_string_temp.c */
void	ft_string_init(t_temp_str *temp_str);
void	ft_s_append(t_temp_str *temp_str, char *str);
void	ft_c_append(t_temp_str *temp_str, char c);
void	ft_string_clear(t_temp_str *temp_str);
void	ft_string_delete(t_temp_str *temp_str);

/* ft_string_temp_function.c*/
int		ft_temp_print(t_temp_str *temp_str, int fd);
long	ft_atol_base(const char *str, char *base, int *flag);

void	*ft_malloc(size_t size);

int		ft_atof(const char *str);

#endif
