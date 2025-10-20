/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:31 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/17 15:12:43 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

typedef struct s_best_data
{
	int		position;
	int		distance;
	t_stack	*stack;
}	t_best_data;

typedef struct s_check_data
{
	t_stack		*current;
	int			position;
	int			min;
	int			max;
	t_best_data	*best;
}	t_check_data;

int		ft_check_and_update_best(t_check_data *data);
int		ft_get_min_distance(int pos, int size);
int		ft_find_max_position_b(t_stack *stack);
int		ft_is_overflow(int argc, char **argv);
t_stack	*ft_insert(int data, t_stack *head);
int		ft_duplicate(int argc, char **argv);
int		ft_check_int(int argc, char **argv);
t_stack	*ft_receiver(int argc, char **argv);
int		ft_checker(int argc, char **argv);
void	ft_reverse_rotate_a(t_data *data);
void	ft_reverse_rotate_b(t_data *data);
void	ft_free_stack(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_small_sort(t_data *data);
void	ft_medium_sort(t_data *data);
void	ft_rotate_a_b(t_data *data);
void	ft_swap_a_b(t_data *data);
void	ft_rotate_a(t_data *data);
void	ft_rotate_b(t_data *data);
void	ft_big_sort(t_data *data);
void	ft_swap_a(t_data *data);
void	ft_swap_b(t_data *data);
void	ft_push_b(t_data *data);
void	ft_push_a(t_data *data);
void	ft_move_max_to_top_b(t_data *data);
int		ft_find_min_value(t_stack *stack);
int		ft_find_max_value(t_stack *stack);
void	ft_push_chunk_to_b(t_data *data, int min_val, int max_val);
int		ft_calculate_chunks(int size);
void	ft_process_chunks(t_data *data, int min_val, int max_val, int chunks);
void	ft_push_chunks_to_b(t_data *data);
int		ft_find_next_in_range(t_stack *stack, int min, int max);

#endif