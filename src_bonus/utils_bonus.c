/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:51:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/22 15:11:44 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_moves(void)
{
	char	*toa;
	char	*string;

	string = ft_strdup("Moves :                ");
	if (!string)
		exit_game(EXIT_FAILURE, STDOUT_FILENO, ERR_MEM, 0);
	toa = ft_itoa(game()->count_movements);
	ft_strlcpy(string + 8, toa, 15);
	mlx_string_put(w()->mlx, w()->mlx_win, 20, 20, 0x000000, string);
	free(toa);
	free(string);
}

void	ft_delay(float seconds)
{
	clock_t	start;

	start = clock();
	while ((clock() - start) <= seconds * CLOCKS_PER_SEC)
		;
}
