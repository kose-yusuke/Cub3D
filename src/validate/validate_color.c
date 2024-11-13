#include "cub3d.h"
#include "ft_strtol.h"

static bool	is_valid_color(char *str, char **endptr)
{
	long	color;

	errno = 0;
	color = ft_strtol(str, endptr, 10);
	if (errno != 0 || color < 0 || color > 255)
		return (false);
	return (true);
}

static bool	is_valid_end(char **endptr, char expected_char)
{
	skip_space(endptr);
	return (**endptr == expected_char);
}

bool	is_valid_color_setting(char *setting, t_check_list *check_list)
{
	char	*color;
	char	*endptr;

	color = setting;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, ','))
	{
		check_list->invalid = true;
		return (false);
	}
	color = endptr + 1;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, ','))
	{
		check_list->invalid = true;
		return (false);
	}
	color = endptr + 1;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, '\n'))
	{
		check_list->invalid = true;
		return (false);
	}
	return (true);
}
