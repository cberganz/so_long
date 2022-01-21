/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:51:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 12:33:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(void)
{
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(game()->count_movements, 1);
	ft_putchar_fd('\n', 1);
}
