/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:25:46 by maddou            #+#    #+#             */
/*   Updated: 2023/02/09 21:30:02 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	i;
	int	min;
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;
	int	argc;
	int	size_b;
	int	*stack_a;
	int	*stack_b;
	int	*c_stack;
	int	n_arg;
}		t_stack;

void	ft_sorting(t_stack *s);
void	ft_move(t_stack *st);
void	swap(int argc, int *stack, char x);
void	ss(int argc, int size_b, int *stack_a, int *stack_b);
void	rev_rotate(int argc, int *stack, char x);
void	rrr(int argc, int size_b, int *stack_a, int *stack_b);
void	rotate(int argc, int *stack, char x);
void	rr(int argc, int size_b, int *stack_a, int *stack_b);
void	push_a(int *argc, int *size_b, int *stack_a, int *stack_b);
void	push_b(int *argc, int *size_b, int *stack_a, int *stack_b);
int		number(char *str);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *str, char c, int number_argument);
void	errur(void);
void	ft_free(char **split, int *stack_a, char *sjoin);
int		chec_space_null(int argc, char *argv[]);
char	*join(int argc, char *argv[]);
int		*chek(int argc, char *argv[], int *number_argument);
int		chek_plus(int argc, char *argv[]);
int		chek_digit(char *str);
int		chek_double(int *str, int number);
int		opera_a(int *stack_a, int argc, int index, char chek);
int		find_right_pos(int size_b, int value, int *stack_b, char chek);
int		opera_b(int *stack_b, int value, int size_b, char chek);
int		besta_index(int *stack_a, int *stack_b, int argc, int size_b);
void	ft_swap(int argc, int size_b, int *stack_a, int *stack_b);
int		chek_min(int *stack_b, int size_b, int *index_min);
//void	move_min(int *stack_b, int size_b, int best_b, int operation);
void	move_othersb(int *stack, int total, int best, int operation);
void	move_othersa(int *stack, int total, int best, int operation);
void	calcul_move_min(int *stack_a, int *stack_b, int size_b, int argc);
int		chek_number(int *stack_b, int valeurStack_a, int size_b);
//int		main(int argc, char *argv[]);
void	free_split(char **split, char *sjoin);
void	free_stack(int *stack_a, int *stack_b);
void	ft_sort3(int argc, int *stack_a, int *stack_b, char x);
void	ft_sort5(int argc, int size_b, int *stack_a, int *stack_b);
void	ft_sort4(int argc, int size_b, int *stack_a, int *stack_b);
void	ft_sort2(int argc, int *stack_a, int *stack_b);
int		chek_order(int *str, int number);
void	larger(int *stack_a, int *stack_b, int argc, int size_b);
void	smaller(int *stack_a, int *stack_b, int argc, int size_b);
void	copier_stack(t_stack *sta);
#endif