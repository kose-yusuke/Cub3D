/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/27 17:46:59 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//if pressed ESC, window closed
int ft_event_handler(int keycode, t_mgr *mgr)
{
    if (keycode == ESC)
        ft_close(mgr);
    // else
        // ft_move_player(keycode, mgr);
    return (0);
}

//destroy window
int ft_close(t_mgr *mgr)
{
	mlx_destroy_window(mgr->mlx, mgr->win);
    exit(0);
}