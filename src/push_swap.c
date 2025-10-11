/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 22:10:36 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int main(int argc, char **argv)
{
	if (checker(argc, argv) == 0)
		ft_printf("So far, so good!\n");
	else
		ft_printf("Error\n");

	return (0);
}