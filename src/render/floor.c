/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:39:44 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/31 18:03:58 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_floor_and_ceiling(t_mgr *mgr) 
{
    int y = 0;
    while (y < SCREEN_HEIGHT / 2) {
        int x = 0;
        while (x < SCREEN_WIDTH) {
            put_pixel_to_image(mgr, x, y, 0x000033);
            put_pixel_to_image(mgr, x, SCREEN_HEIGHT - y - 1, 0x0000FF);
            x++;
        }
        y++;
    }
}

// ステップベクトルの計算
void calculateFloorCeilingSteps(t_mgr *mgr, float rowDistance, 
                                float *floorStepX, float *floorStepY, float *floorX, float *floorY) 
{
    float rayDirX0 = mgr->player.dir.x - mgr->player.camera_plane.x;
    float rayDirY0 = mgr->player.dir.y - mgr->player.camera_plane.y;
    float rayDirX1 = mgr->player.dir.x + mgr->player.camera_plane.x;
    float rayDirY1 = mgr->player.dir.y + mgr->player.camera_plane.y;

    *floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
    *floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;
    *floorX = mgr->player.pos.x + rowDistance * rayDirX0;
    *floorY = mgr->player.pos.y + rowDistance * rayDirY0;
}

// 床と天井の描画を呼び出すメイン関数
void castFloorAndCeiling(t_mgr *mgr) 
{
    int y = 0;
    while (y < SCREEN_HEIGHT / 2) {
        float floorX, floorY, floorStepX, floorStepY;
        int p = y - SCREEN_HEIGHT / 2;
        float rowDistance = 0.5 * SCREEN_HEIGHT / p;

        calculateFloorCeilingSteps(mgr, rowDistance, &floorStepX, &floorStepY, &floorX, &floorY);
        draw_floor_and_ceiling(mgr);
        y++;
    }
}


