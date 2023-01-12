#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int chek_min(int *stack_b, int size_b, int *index_min)
{
    int i;
    int min;

    i = 0;
    min = stack_b[0];
    *index_min = i;
    if (size_b > 0)
    { 
        while (i <= size_b)
        {
           
            if (stack_b[0] >= stack_b[i] && min > stack_b[i])
            {
                min = stack_b[i];
                *index_min = i;
            }
            i++;
        }
    }
    return (min);
}

int chek_max(int *stack_b, int size_b, int *index_max)
{
    int j;
    int max;

    j = 0;
    max = stack_b[0];
    *index_max = j;
    if (size_b > 0)
    {
        while(j <= size_b)
        {
            if (stack_b[0] <= stack_b[j] && max < stack_b[j])
            {
                max = stack_b[j];
                *index_max = j;
            }
            j++;
        }
    }
    return (max);
}

int opera_a(int *stack_a, int argc, int index, char chek)
{
    int contab;

    if(chek == 'i')
        contab = index;
    if (chek == 'o')
    {
        if (index >= argc / 2)
            contab = argc - index;
        else if (index < argc / 2)
            contab = index + 1;
    }
    //printf ("contba ===>%d\n", index);
    return (contab);
}

int opera_b_prim(int size_b, int value, int *stack_b, char chek)
{
    long i;
    long size;
    long contb;
    long current_diff;
    long smallest_diff;

    i = 0;
    smallest_diff = INT_MAX;
    size = 0;
    while (i <= size_b)
    {
        current_diff = (long)value - (long)stack_b[i];
        // printf ("i est ==>%ld value %d - stack_b[%ld]%d == current_diff ==> %ld\n",i,value,i,stack_b[i], current_diff);
        if (current_diff < smallest_diff)
        {
            if (current_diff > 0 && current_diff < smallest_diff)
            {
                size = i;
                smallest_diff = current_diff;
            }
        }
        i++;
    }
    // printf ("size ==>%ld\n", size);
    contb = opera_a(stack_b, size_b, size, chek);
  return (contb);
}

int find_right_pos(int size_b, int value, int *stack_b,char chek)
{
  int i;
  int size;
  int contb;
  int j;
  
  i = 0;
  j = size_b;

  while (value < stack_b[size_b])
    size_b--;
  size = size_b;
  size_b--;
  while (size_b >= 0)
  {
    if (stack_b[size_b] > stack_b[size] && stack_b[size_b] < value)
      size = size_b;
    size_b--;
  }
   //printf ("j est %d\n", j);
   //printf ("value = %d, size = %d, j = %d, chek %c \n ",value,size, j, chek);
  contb = opera_a(stack_b, j, size, chek);
  return (contb); 
}

int opera_b(int *stack_b, int value, int size_b, char chek)
{
    int contb;
    int index_min;
    int index_max;
    int size;
    int min = chek_min(stack_b, size_b, &index_min);
    //printf ("min ====> %d\n", min);
    if (value <= min)
    {
        //printf ("value  %d <= min %d \n", value, min);
        if (index_min > size_b / 2)
            contb = size_b - index_min + 1;
        else if (index_min <= size_b / 2)
            contb = index_min;
        if (chek == 'i')
            contb = index_min;
       // printf ("min ==>%d\n", min);
    }
    /*else if (stack_a[argc] > chek_max(stack_b, size_b, &index_max))
    {
        if (index_max >= size_b / 2)
            contb = size_b - index_max;
        else if (index_max < size_b / 2)
            contb = index_max + 1;   
        contb = index_max;
    }*/   
    else 
        contb =find_right_pos(size_b, value, stack_b, chek);
        //contb = opera_b_prim(size_b, value, stack_b, chek);
    return (contb);
}

void rev_rotate(int argc, int *stack, char x)
{
    int first;
    int i;

    first = stack[0];
    i = 0;
    if (argc > 1)
    {
        while (i < (argc - 1)) 
        {
            stack[i] = stack[i + 1];
            i++;
        }
        stack[i] = first;
        if (x == 'a')
            write (1, "rra\n", 4);
        if (x == 'b')
            write (1, "rrb\n", 4);
    }
}

void rotate(int argc, int *stack, char x)
{
    int last;
    int i;

    i = argc - 1;
    last = stack[i];
    if (argc > 1)
    {
        while (i > 0)
        {
            stack[i] = stack[i - 1];
            i--;
        }
        stack[0] = last;        
        if (x == 'a')
            write (1, "ra\n", 3);
        if (x == 'b')
            write (1, "rb\n", 3);
    }
}

void swap(int argc, int *stack)
{
    int swap;

    if (argc > 1)
    {
        swap = stack[argc - 1];
        stack[argc - 1] = stack[argc - 2];
        stack[argc - 2] = swap;
        //write(1, "sa\n", 3);
    }
}

void push_a(int *argc, int *size_b, int *stack_a, int *stack_b) // b to a
{
    if (*argc < *size_b + *argc) //or size_b > 0
    {
        stack_a[*argc] = stack_b[*size_b - 1];
        *argc += 1;
        *size_b -= 1;
        write(1, "pa\n", 3);
    }
}

void push_b(int *argc, int *size_b, int *stack_a, int *stack_b) // a to b
{
    if (*argc > 0)
    {
        stack_b[*size_b] = stack_a[*argc - 1];
        *argc -= 1;
        *size_b += 1;
        write(1, "pb\n", 3);
    }//write(1, "pb\n", 3);     
}

int besta_index(int *stack_a, int *stack_b, int argc, int size_b)
{
    int i;
    int j;
     int best_istruction;
     int current_instruction;

    i = 0;                      /* argc ==> kif size_b */
    best_istruction = INT_MAX; /* size_b - 1 ==> m3a kaykon zayad wahad ohna kana9sooh bach nbdaw b zero tji hiya hadik */
    while(i < argc/*size_b*/)
    {
        current_instruction = opera_a(stack_a, argc - 1, i, 'o') + opera_b(stack_b, stack_a[i], size_b - 1, 'o');
        printf ("%d------------+%d----------+%d\n",i,current_instruction,stack_a[i]);
        if (current_instruction < best_istruction)
        {
            best_istruction = current_instruction;
            j = i;  
        }
        i++;
    }
    printf ("%d***----------------------***+%d\n",j,stack_a[j]);
    return (j);
}

void move_min(int *stack, int total, int best, int operation, char x)
{
    int i;

    i = 0;
    if (best > (total - 1) / 2)
    {
        while(i < operation)
        {
            rotate(total, stack,x);
            i++;
        }
    }
    else if (best <= (total - 1) / 2)
    {
        while(i < operation)
        {
            rev_rotate(total, stack,x);
            i++;
        }
    }
}

void move_others(int *stack, int total, int best, int operation,char x)
{
    int i;

    i = 0;
    if (best >= (total - 1) / 2)
    {
        while(i < operation)
        {
            rotate(total, stack,x);
            i++;
        }
    }
    else if (best < (total - 1) / 2)
    {
        while(i < operation)
        {
            rev_rotate(total, stack,x);
            i++;
        }
    }
}
void chek_move(int *stack, int total, int best, int operation,char x)
{
    int i;
    int min;
    int index_min;

    i = 0;
    min = chek_min(stack, total - 1, &index_min);
    if (stack[best] <= min)
        move_min(stack, total, best, operation, x);
    else if (stack[best] > min)
        move_others(stack, total, best, operation, x);    
}
void test_function(int *stack_a, int *stack_b, int argc, int size_b)
{
    int i = 9;
    printf ("******************************\n");
    while (i >= 0)
    {
        printf ("%d| ----------+%d | --------+%d |\n", i, stack_a[i], stack_b[i]);
        i--;
    }
    printf ("******************************\n");
}
void ft_swap(int argc,int size_b, int *stack_a, int *stack_b)
{
    int i;
    int best_a;
    int best_b;
    int conta;
    int contb;

    i = argc - 1 - 2;
    test_function(stack_a, stack_b, argc, size_b);
    push_b(&argc, &size_b, stack_a, stack_b);
    stack_a[9] = 0;
    push_b(&argc, &size_b, stack_a, stack_b);
    stack_a[8] = 0;

    test_function(stack_a, stack_b, argc, size_b);
    while (i >= 0)
    {
        best_a = besta_index(stack_a, stack_b, argc, size_b); 
        best_b = opera_b(stack_b, stack_a[best_a], size_b - 1, 'i');
        conta = opera_a(stack_a, argc - 1, best_a, 'o');
        contb = opera_b(stack_b, stack_a[best_a], size_b - 1, 'o');
        printf ("best_a >%d++--------------++conta >%d\nbest_b >%d++-----------------++contb >%d\n",best_a,conta,best_b,contb);
                                    //chek_move(stack_a, argc, best_a, conta, 'a');
        move_others(stack_a, argc, best_a, conta, 'a');
        chek_move(stack_b, size_b, best_b, contb, 'b');
        test_function(stack_a, stack_b, argc, size_b);
        push_b(&argc, &size_b, stack_a, stack_b);
        stack_a[i] = 0;
        test_function(stack_a, stack_b, argc, size_b);
        i--;
    }
     best_b = chek_min(stack_b, size_b - 1, &best_a);
     contb = opera_b(stack_b, best_b, size_b - 1, 'o');
     printf ("%d-------%d\n",contb, best_b);
     test_function(stack_a, stack_b, argc, size_b);
     chek_move(stack_b, size_b, best_a, contb, 'b');
     test_function(stack_a, stack_b, argc, size_b);
     i = 0;
     while (i < size_b + argc)
     {
         push_a(&argc, &size_b, stack_a, stack_b);
         i++;
     }
    test_function(stack_a, stack_b, argc, size_b);
    free(stack_a);
    free(stack_b);
 }

// void    print_stack(int *stack1, int *stack2, int argc)
// {
//     int    i;

//     i = -1;
//     while (++i < argc)
//         printf("%d|       %d     |       %d       |\n", i, stack1[i], stack2[i]);
//     printf("-----------------------------------|\n");
// }


int main(int argc, char **argv) {
    //int str[] = {4, 17, 6, 26, 27, 9, 7, 13, 32, 10, 20, 28, 14, 33, 39, 15, 34, 24, 2, 21, 18, 35, 23, 11, 25, 45, 44, 41, 40, 46};
    //int str[] = {4,2,1, 3, 12, 16, 19, 22, 50, 42};
    //int str[] = {9,12, 24, 4, 6, 25, 9, 40, 36};
    //int str[]= {37,44,49,12,13,24,2,25,18,5,10/*,40,36*/};
    //int str[] = {64, 39, 56 ,10, 78, 50, 29, 55, 95, 79, 23, 86, 47, 72, 51, 37, 100, 69, 1, 24, 12, 25, 53, 7 ,34, 93, 70, 27, 18, 80, 17, 46, 20 ,59 ,58, 19, 73, 28, 45, 63, 66 ,14, 32, 41, 71, 65, 67, 84, 11, 48};
    //int str[] = {34, -15, 88, 67, 58, 82, 30, 85, 39, -14, 60, -13, 94, -20, 56, 54, 71, -4, 0, 90, 44, 70, 3, 28, 75, 46,61, 66, 96, 1, 29, 43, 15, -11, 55, 41, 2, 4, 8, -18, 62, 7, -16 ,31, 6 ,74, 17, 79,156, 106, 111, 128, 145, 187, 183, 140, 136, 180, 191, 163, 182, 133, 124, 160 ,110, 193, 134, 181, 129, 190, 167, 195, 123, 117, 137, 113, 119, 158, 100 ,150, 108, 400, 135, 118, 132, 169, 179, 143, 164, 173, 141, 125, 121, 153, 112, 165,365, 302, 398, 380};
    //int str[] = {1, 18, 15, 91, 56, 62, 72, 37, 27, 98, 73, 19, 2, 85, 49, 84, 16, 13, 40, 78, 17, 30, 55, 89, 39, 7, 63, 11, 34, 94, 59, 46, 77, 50, 70, 35, 22, 79, 75, 36, 71, 52, 41, 53, 83, 86, 76, 66, 12, 48, 25, 65, 97, 82, 92, 26, 87, 20, 67, 74, 88, 58, 8, 33, 14, 10, 61, 95, 42, 99, 28, 4 ,100, 69, 21, 51, 90,201 ,93 ,81 ,57, 60, 23, 29, 45, 32, 96, 24, 9 ,68 ,43, 38, 80, 47 ,64 ,6 ,44, 5, 54, 101};
    //int str[] = {91, 14, 5, 70, 60, 23, 34, 87, 4 ,37, 9, 63, 6, 28, 30, 22, 77, 86, 68, 88, 69, 45, 62, 83, 29, 89, 50, 3, 75, 53, 19, 49, 41, 85, 64, 81, 17, 2, 52, 96, 92, 79, 59, 25, 57, 7, 42, 78, 26, 71, 93, 99, 40, 27, 55, 15, 24, 61 ,67, 73, 51, 13, 95, 1, 12, 43, 100, 8 ,97, 76, 54, 11, 84, 66, 21, 74, 36, 10, 16, 90, 33, 98, 48, 38, 44, 80, 58, 35, 82, 18, 72, 46, 94, 32, 56, 65, 47, 20, 31, 39};
    //int str[] = {-8, -26, 36, -38, 26, 18, 22, 35, 9 ,-37, 27 ,-10 ,5, -13 ,-42, 10, -40, 49, 11, 46, -12, 31, -39, 48, -45, -48, -6, 0, 28, -32, -3 ,12 ,30, -19, -27, -22 ,23 ,-49, -50, 40, 4 ,-23, -17, -2, 17, -44, -15, -41, -30, 45 ,43 ,-34, 44, -31, 33, 1 ,50 ,21 ,-43, -28, 14, 15, -21, 37, 2 ,-47, -33, 3, -1, 32, -20, -11, 6 ,24 ,-14 ,-5, -36 ,-35, -4, 13, -7, -29, 47, 7 ,34 ,-18, 8 ,16 ,20, 39, 41, 38, -24, -9, -25, 25, -16, 29, -46, 42};
    //int str[] = {5,6,7,1,12,4,13,17,14,20,2,-1.-20,-14,-30,50,49,33,44,30,9};
    //int str[] = {4,1,5,-1};
    //int str1[9] = {1,3,5,13,24,25,36,40,25};
    
    //int str1[] = {4,15,46,-3,33,-23,41,28,-39,48,43,45,-43,-35,-28,14,-12,26,12,34,-8,37,23,-27,-33,30,29,-30,3,-16,-25,16,-9,-19,1,38,-18,-46,20,8,-41,21,-7,22,32,-34,-38,-6,50,6,-17,42,40,-26,11,-15,10,5,-24,24,9,31,25,-37,-40,-45,-31,-5,-49,-1,-36,-50,17,-42,2,-29,-20,47,-14,44,-4,7,13,36,-47,-32,-11,19,27,-10,-22,-2,35,18,-13,49,0,-48,39,-21};
    
    
    //int j = argc - 1;
    // for (int i = 0; i < j; i++)
    // {
    //     str1[i] = atoi(argv[i + 1]);
    //     str2[i] = 0;
    // }
   
    //int i = argc - 1;
    int i = 0;
    // while (j < argc - 1)
    // {
    //     str1[j] = atoi(argv[j + 1]);
    //     //printf ("%d\n", str1[i]);
    //     j++;
    // }

    //int i = 0;
    // while (i < argc - 1)
    // {
    //     printf ("-----%d\n",str1[i]);
    //     i++;
    // }
    //printf ("%d", argc);
    //printf ("%d", argc);
    int *str1 = malloc((argc - 1) *sizeof(int));
    int *str2 = malloc( (argc - 1)*sizeof(int));

    while (i < argc - 1)
    {
        str1[i] = atoi(argv[/*i + 1*/ argc - i - 1]);
        i++;
    }
    //int argc = 4;
    int size_b = 0;
    //ft_swap((argc - 1) ,size_b, str1, str2);
    //push_b(&argc, &size_b, str1, str2);
    //handlar(str1, str2, argc - 1);
    ft_swap(argc - 1 ,size_b, str1, str2);
    //handlar(str1, str2, argc - 1);
} //6 14 15 19 10 7 5 2 9 4 17 16 3 12 13 18 20 11 8 1 // 19 14 2 3 10 1 18 6 16 15 // -744966108 2018183620 743299389 1567336198
//189713 95550 14835 141816 55156 50560 144349 8362 115331 10950 102219 98062 193954 39158 68675 194898 150958 105500 60859 130395 8044 25299 193439 54017 105221 50631 156687 67558 170072 183388 117954 193197 5353 90924 85389 141680 21891 1670 190709 25060