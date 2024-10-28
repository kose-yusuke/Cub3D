/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:17:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/28 15:18:52 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//count rows of map
int count_rows(t_mgr *mgr, char *map_filepath)
{
	int fd;
	int count_row;
	char *row;

	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	count_row = 0;
    while(true)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
        if (ft_strncmp(row, "1", 1) == 0)
            count_row++;
		free(row);
		row = NULL;
	}
	close(fd);
	return(count_row);
}

void parse_rgb(char *line, t_rgb *rgb)
{
    char *start;
    char *end;

    start = line + 2;

    end = ft_strchr(start, ',');
    if (end == NULL)
        exit(ft_error_message_handler("Invalid RGB format"));
    *end = '\0';
    rgb->red = ft_atoi(start);
    start = end + 1;
    end = ft_strchr(start, ',');
    if (end == NULL)
        exit(ft_error_message_handler("Invalid RGB format"));
    *end = '\0';
    rgb->green = ft_atoi(start);
    start = end + 1;
    rgb->blue = ft_atoi(start);
}

//最低限
void parse_texture_line(char *line, t_mgr *mgr, int count_row)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        mgr->textures->north_texture = ft_strdup(line + 3);
    else if (ft_strncmp(line, "SO ", 3) == 0)
        mgr->textures->south_texture = ft_strdup(line + 3);
    else if (ft_strncmp(line, "WE ", 3) == 0)
        mgr->textures->west_texture = ft_strdup(line + 3);
    else if (ft_strncmp(line, "EA ", 3) == 0)
        mgr->textures->east_texture = ft_strdup(line + 3);
    else if (ft_strncmp(line, "F ", 2) == 0)
    {
        parse_rgb(line, &mgr->textures->f_rgb);
    }
    else if (ft_strncmp(line, "C ", 2) == 0)
        parse_rgb(line, &mgr->textures->c_rgb);
    return;
}

char **read_cub_file(t_mgr *mgr, char *map_filepath)
{
    int fd;
    char *line;
    int count_row;

    fd = open(map_filepath, O_RDONLY);
    count_row = 0;
    if (fd < 0)
        exit(ft_error_message_handler("Failed to open map file"));
    mgr->map.grid = (char **)ft_calloc(mgr->map.row + 1, sizeof(char *));
	if (!mgr->map.grid)
		return NULL;
    while ((line = get_next_line(fd)) != NULL && count_row < mgr->map.row)
    {
        parse_texture_line(line, mgr, count_row);
        if (ft_strncmp(line, "1", 1) == 0)
        {
            mgr->map.grid[count_row] = ft_strdup(line);
            if (!mgr->map.grid[count_row])
            {
                close(fd);
                return NULL;
            }
            count_row++;
        }
        free(line);
        line = NULL;
    }
    close(fd);
    return (mgr->map.grid);
}
