/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:20:06 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/11 15:29:37 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h>

/*
** ============================================================================
** STRUCTURES
** ============================================================================
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
** ============================================================================
** MANDATORY FUNCTIONS - Character classification and conversion
** ============================================================================
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** ============================================================================
** MANDATORY FUNCTIONS - String manipulation
** ============================================================================
*/

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);

/*
** ============================================================================
** MANDATORY FUNCTIONS - Memory manipulation
** ============================================================================
*/

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/*
** ============================================================================
** MANDATORY FUNCTIONS - String creation and manipulation
** ============================================================================
*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char delimiter);

/*
** ============================================================================
** MANDATORY FUNCTIONS - Conversion and utility
** ============================================================================
*/

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** ============================================================================
** MANDATORY FUNCTIONS - File descriptor output
** ============================================================================
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
** ============================================================================
** BONUS FUNCTIONS - Linked list manipulation
** ============================================================================
*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** ============================================================================
** FT_PRINTF FUNCTIONS - Custom printf implementation
** ============================================================================
*/

// Main printf function
int		ft_printf(const char *format, ...);

// Printf helper functions
void	printf_putnbr(long long n, int *printed_chars);
void	print_char(const char **str, va_list args, int *printed_chars);
void	print_string(const char **str, va_list args, int *printed_chars);
void	print_integer(const char **str, va_list args, int *printed_chars);
void	print_percentage(const char **str, int *printed_chars);
void	print_hex(const char **str, va_list args, int *printed_chars);
void	convert_hex(unsigned long int hex, int upcase_mod, int *printed_chars);
void	print_pointer(const char **str, va_list args, int *printed_chars);

/*
** ============================================================================
** GET_NEXT_LINE FUNCTIONS - Line reading from file descriptor
** ============================================================================
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main get_next_line function
char	*get_next_line(int fd);

// Get_next_line helper functions
char	*append_to_line(char *line, char *buffer);
char	*update_buffer(char *str);

#endif
