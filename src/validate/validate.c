#include "cub3d.h"

bool	is_valid_extension(const char *path, const char *ext)
{
	const size_t	path_len = ft_strlen(path);
	const size_t	ext_len = ft_strlen(ext);

	if (!path || !ext || path_len <= ext_len)
		return (false);
	return (ft_strncmp(&path[path_len - ext_len], ext, ext_len) == 0);
}

bool	validate_map(t_map *map, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	ft_bzero(map, sizeof(t_map));
	if (!validate_map_data(fd) || !validate_map_figure(map, fd))
	{
		close(fd);
		error_exit("Invalid map");
	}
	close(fd);
	printf("map OK\n"); // TODO: remove
	return (true);
}
