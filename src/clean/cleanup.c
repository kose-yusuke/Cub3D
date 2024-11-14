#include "cub3d.h"

void	clean_up_grid(char **grid, int rows)
{
	int i;

	if (!grid)
		return ;
	i = 0;
	while (i < rows)
	{
		xfree(grid[i]);
		i++;
	}
	xfree(grid);
}
