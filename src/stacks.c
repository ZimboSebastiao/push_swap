/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:31 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 14:16:34 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_b(t_data *data)
{
	ft_swap_a(data);
	ft_swap_b(data);
	ft_putstr_fd("ss\n", 1);
}

void	ft_rotate_a_b(t_data *data)
{
	ft_rotate_a(data);
	ft_rotate_b(data);
	ft_putstr_fd("rr\n", 1);
}

void	ft_reverse_rotate_a_b(t_data *data)
{
	ft_reverse_rotate_a(data);
	ft_reverse_rotate_b(data);
	ft_putstr_fd("rrr\n", 1);
}