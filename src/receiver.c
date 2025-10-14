/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/14 06:04:05 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_insert(int data, t_stack *head)
{
	t_stack	*current;
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->value = data;
	temp->next = NULL;
	if (head == NULL)
		return (temp);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	return (head);
}

t_stack	*ft_receiver(int argc, char **argv)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		head = ft_insert(ft_atoi(argv[i]), head);
		if (!head)
			return (NULL);
		i++;
	}
	return (head);
}
