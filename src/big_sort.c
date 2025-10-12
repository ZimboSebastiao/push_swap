/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 16:48:47 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_sort(t_data *data);
int		ft_pivot(t_stack *stack, int size);
void	ft_partition(t_data *data, int pivot);
void	ft_sort_recursive(t_data *data, int size);
int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *stack);

