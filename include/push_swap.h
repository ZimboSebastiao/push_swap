/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:31 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 23:07:28 by zimbo            ###   ########.fr       */
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

int		ft_strcmp(const char *s1, const char *s2);
t_stack	*ft_insert(int data, t_stack *head);
int		ft_is_overflow(int argc, char **argv);
int		ft_duplicate(int argc, char **argv);
int		ft_check_int(int argc, char **argv);
t_stack	*ft_receiver(int argc, char **argv);
int		checker(int argc, char **argv);
void	print_stack(t_stack *head);
int		ft_empty(int argc);



#endif