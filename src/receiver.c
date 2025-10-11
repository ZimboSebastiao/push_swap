/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 23:44:12 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_insert(int data, t_stack *head)
{
	t_stack *temp = malloc(sizeof(t_stack));
	temp->value = data;
	temp->next = head;
	head = temp;
	return (head);
}

t_stack	*ft_receiver(int argc, char **argv)
{
	t_stack *head = NULL;
	int	i;

	i = 1;
	while (i < argc)
	{
		head = ft_insert(ft_atoi(argv[i]), head);
		print_stack(head);
		i++;
	}
	return (head);
}