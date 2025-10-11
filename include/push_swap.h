/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:31 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 22:18:10 by zimbo            ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2);
int	ft_is_overflow(int argc, char **argv);
int	ft_duplicate(int argc, char **argv);
int	ft_check_int(int argc, char **argv);
int	checker(int argc, char **argv);
int	ft_empty(int argc);

#endif