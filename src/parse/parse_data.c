/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:28:53 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/16 03:14:23 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_strtol.h"

static bool	set_wallpaper(char **texture_path, char *setting)
{
	char	*trimmed_str;

	trimmed_str = prepare_trimmed_path(setting);
	if (!trimmed_str)
		return (false);
	*texture_path = trimmed_str;
	return (true);
}

static void	set_color(t_rgb *rgb, char *setting)
{
	char	*str;
	char	*endptr;

	str = setting;
	rgb->red = (int)ft_strtol(str, &endptr, 10);
	skip_space(&endptr);
	str = endptr + 1;
	rgb->green = (int)ft_strtol(str, &endptr, 10);
	skip_space(&endptr);
	str = endptr + 1;
	rgb->blue = (int)ft_strtol(str, &endptr, 10);
}

static bool	parse_setting(t_textures *textures, char *id, char *setting)
{
	if (ft_strncmp(id, "NO ", 3) == 0)
		return (set_wallpaper(&textures->north_texture_path, setting));
	else if (ft_strncmp(id, "SO ", 3) == 0)
		return (set_wallpaper(&textures->south_texture_path, setting));
	else if (ft_strncmp(id, "WE ", 3) == 0)
		return (set_wallpaper(&textures->west_texture_path, setting));
	else if (ft_strncmp(id, "EA ", 3) == 0)
		return (set_wallpaper(&textures->east_texture_path, setting));
	else if (ft_strncmp(id, "F ", 2) == 0)
		set_color(&textures->f_rgb, setting);
	else if (ft_strncmp(id, "C ", 2) == 0)
		set_color(&textures->c_rgb, setting);
	else
		return (false);
	return (true);
}

static bool	parse_line(t_textures *textures, char *line, size_t *counter)
{
	char	*id;
	char	*setting;

	skip_space(&line);
	if (*line == '\n' || *line == '\0')
		return (true);
	id = line;
	skip_nonspace(&line);
	skip_space(&line);
	if (*line == '\n' || *line == '\0')
		return (false);
	setting = line;
	if (!parse_setting(textures, id, setting))
		return (false);
	(*counter)++;
	return (true);
}

bool	parse_map_data(t_textures *textures, int fd)
{
	char	*line;
	size_t	counter;

	counter = 0;
	while (counter != REQUIRED_SETTINGS)
	{
		line = get_next_line(fd);
		if (!line)
			return (false);
		if (!parse_line(textures, line, &counter))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (true);
}
