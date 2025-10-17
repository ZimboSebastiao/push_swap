/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:10:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:45:15 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_check_data(t_check_data *check_data,
t_best_data *best, int min, int max)
{
	check_data->best = best;
	check_data->min = min;
	check_data->max = max;
}

void	ft_process_current_node(t_check_data *check_data,
t_stack *current, int position)
{
	check_data->current = current;
	check_data->position = position;
	ft_check_and_update_best(check_data);
}
