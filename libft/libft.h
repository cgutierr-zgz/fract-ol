/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 22:51:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/13 16:35:02 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Libft es una librería que contiene funciones básicas escritas en C
**
** Cada función contiene una explicación del proceso y de no ser obvio,
** esta explicación se ve acompañada de un pequeño ejemplo
**
** Librerias externas:
**
** <stdlib.h>
**	·malloc	| Asignación de memoria dinámica
**	·free	| Liberación de memoria dinámica
**
** <unistd.h>
**	·write	| Escritura a un file descriptor
**	·size_t | Valores positivos muy grandes
**
** <stdarg.h>
**    ·va_start	| Inicialización de va_list
**    ·va_arg	| Se consigue el siguiente valor de va_list
**    ·va_copy	| Se crea una copia de va_list
**    ·va_end	| Se libera va_list
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

/*
** Parte 1 - Funciones de la Libc
** [LIBFT]
*/

void			*ft_memset(void *b, int c, size_t len);
char			*ft_strrchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
char			*ft_strnstr(const char *str, const char *needle, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_atoi(const char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_isalpha(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isdigit(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isalnum(int c);
size_t			ft_strlen(const char *s);
int				ft_isascii(int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_isprint(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_toupper(int c);
char			*ft_strchr(const char *s, int c);
int				ft_tolower(int c);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);

/*
** Parte 2 - Funciones adicionales
** [LIBFT]
*/

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Parte extra
** [LIBFT]
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*dl)(void *));

/*
** Propias
*/

char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_base(unsigned long long number, char *base);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(int c);
int				ft_isspace_no_space(int c);
char			*ft_trimmedstr(char *str);
char			*ft_trimmedstr_no_space(char *str);
int				ft_split_n(char const *s, char c);
int				ft_atoi_noletters(const char *str);
int				ft_countchar(char *str, char c);
void			spain(void);

/*
** Get Next Line
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX_FD 5

int				get_next_line(int fd, char **line);

/*
** Printf
*/

# define RESET				"\x1b[0m"
# define WHITE				"\x1b[1m"
# define W_B_WHITE			"\x1b[47m"
# define W_B_CYAN			"\x1b[46m"
# define W_B_PURPLE			"\x1b[45m"
# define W_B_BLUE			"\x1b[44m"
# define W_B_YELLOW			"\x1b[43m"
# define W_B_GREEN			"\x1b[42m"
# define W_B_RED			"\x1b[41m"
# define WH_B_CLEAR			"\x1b[40m"
# define INVISIBLE			"\x1b[8m"
# define WHITE_BOX			"\x1b[7m"
# define WHITE_SUB			"\x1b[4m"
# define WHITE_CURS			"\x1b[3m"
# define GRAY				"\x1b[2m"
# define BLACK				"\x1b[30m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define PURPLE				"\x1b[35m"
# define CYAN				"\x1b[36m"

int				ft_printf(const char *fmt, ...);
# define SPECIFIER "ncspdiuxX%"
# define FLAGS "123456789-.0*"
/*
** This struct contains everything flag-related
*/
typedef struct s_flags
{
	int	width;
	int	precss;
	int	zero;
	int	ljust;
	int	dot;
	int	cerox;
}				t_flags;
/*
** Main struct
*/
typedef struct s_print
{
	va_list	ap;
	int		n;
	int		i;
	t_flags	flags;
}				t_print;
/*
** Flags
*/
void			ft_flags(const char *fmt, t_print *pstruct);
/*
** Specificators
*/
void			ft_handle_c_pct(t_print *pstruct, char c);
void			ft_handle_s(t_print *pstruct);
void			ft_handle_d_i(t_print *pstruct);
void			ft_handle_u(t_print *pstruct);
void			ft_handle_p(t_print *pstruct);
void			ft_handle_x_x(t_print *pstruct, char c);
/*
** Bonus
*/
void			ft_handle_n(t_print *pstruct);

#endif
