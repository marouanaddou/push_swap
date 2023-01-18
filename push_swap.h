#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void swap(int argc, int *stack, char x);
void ss(int argc, int size_b,int *stack_a, int *stack_b);
void rev_rotate(int argc, int *stack, char x);
void rrr(int argc, int size_b, int *stack_a, int *stack_b);
void rotate(int argc, int *stack, char x);
void rr(int argc, int size_b, int *stack_a, int *stack_b);
void push_a(int *argc, int *size_b, int *stack_a, int *stack_b);
void push_b(int *argc, int *size_b, int *stack_a, int *stack_b);
int	number(char *str);
size_t	ft_strlen(const char *s);
int	ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *str, char c);
void errur();
void ft_free(char **split, int *stack_a,char *sjoin, int number);
int chec_space_null(int argc, char *argv[]);
char *join(int argc, char *argv[]);
int *chek(int argc, char *argv[], int *number_argument);
int chek_plus(int argc, char *argv[]);
int chek_digit(char *str);
int chek_dobble(int *str, int number);
int opera_a(int *stack_a, int argc, int index, char chek);
int find_right_pos(int size_b, int value, int *stack_b,char chek);
int opera_b(int *stack_b, int value, int size_b, char chek);
int besta_index(int *stack_a, int *stack_b, int argc, int size_b);
void ft_swap(int argc, int size_b, int *stack_a, int *stack_b);
int chek_min(int *stack_b, int size_b, int *index_min);
void move_min(int *stack_b, int size_b, int best_b, int operation);
void move_othersb(int *stack, int total, int best, int operation);
void move_othersa(int *stack, int total, int best, int operation);
void calcul_move(int *stack_a, int *stack_b, int size_b, int argc);
int chek_number(int *stack_b, int valeurStack_a, int size_b);
#endif