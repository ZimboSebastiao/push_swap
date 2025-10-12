/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:31 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 16:56:03 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <limits.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct s_stack {
	int value;
	struct s_stack *next;
}t_stack;

typedef struct s_data {
	t_stack *a;
	t_stack *b;
}t_data;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_is_overflow(int argc, char **argv);
t_stack	*ft_insert(int data, t_stack *head);
int		ft_duplicate(int argc, char **argv);
int		ft_check_int(int argc, char **argv);
t_stack	*ft_receiver(int argc, char **argv);
int		ft_checker(int argc, char **argv);
void	ft_reverse_rotate_a(t_data *data);
void	ft_reverse_rotate_b(t_data *data);
void	ft_print_stack(t_stack *head);
void	ft_small_sort(t_data *data);
void	ft_rotate_a_b(t_data *data);
void	ft_swap_a_b(t_data *data);
void	ft_rotate_a(t_data *data);
void	ft_rotate_b(t_data *data);
void	ft_swap_a(t_data *data);
void	ft_swap_b(t_data *data);
void	ft_push_b(t_data *data);
void	ft_push_a(t_data *data);
int		ft_empty(int argc);



#endif