/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 14:45:35 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(int argc, char **argv)
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

void	ft_print_stack(t_stack *head)
{
	// ft_printf("Teste: ");
	while (head != NULL)
	{
		ft_printf("print: %d\n", head->value);
		head = head->next;
	}
	// ft_printf("\n");
}
