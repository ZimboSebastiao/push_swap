/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 22:17:43 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int argc, char **argv)
{
	if (ft_empty(argc))
		exit(0);
	if (ft_check_int(argc, argv))
		return (1);
	if (ft_is_overflow(argc, argv))
		return (1);
	if (ft_duplicate(argc, argv))
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
