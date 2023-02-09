/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:40 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 21:36:15 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int		i;
	int		argc;
	int		*stack_a;
	int		*stack_b;
	int		n_arg;
	int		size_b;
	int		n_instraction;
	char	*line;
	char	*s_join;
	char	**resulting;
	int		rule;
}			t_stack;

char		*get_next_line(int fd);
char		*ft_strjoin(char *sta, char *buffer);
char		*ft_save_next(char *sta);
char		*ft_calloc(int count, int size);
// int		ft_strlen(char *str);

//operation
void		rev_rotate(int argc, int *stack);
void		rrr(int argc, int size_b, int *stack_a, int *stack_b);
void		rotate(int argc, int *stack);
void		rr(int argc, int size_b, int *stack_a, int *stack_b);
void		swap(int argc, int *stack);
void		ss(int argc, int size_b, int *stack_a, int *stack_b);
void		push_a(int *argc, int *size_b, int *stack_a, int *stack_b);
void		push_b(int *argc, int *size_b, int *stack_a, int *stack_b);

//errur
int			number(char *str);
int			chek_double(int *str, int number);
int			chek_plus(int argc, char *argv[]);
int			*chek(int argc, char *argv[], int *number_argument);
int			chek_digit(char *str);
void		errur(void);

//libft
char		**ft_split(char *str, char c, int number_argument);
int			ft_atoi(char *str);
size_t		ft_strlen(const char *s);

//checker
void		free_split(char **split, char *sjoin, char x);
int			chek_join(char *str);
void		free_join(t_stack *f);
int			execut_instraction(t_stack *exu, int i);
void		chek_free(t_stack *s);

#endif