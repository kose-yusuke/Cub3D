/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:28:13 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 09:31:52 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(div, fd);
		ft_putchar_fd(mod + '0', fd);
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
//     remove("tmp.txt");
//     int fd = open("tmp.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//     char    buf[1024];
// 	ft_putnbr_fd(-2147483648, fd);
//     // /* 6 */ ASSERT_EQ_STR(buf, "01-142-422147483647");
//     // ft_putnbr_fd(INT_MIN, fd); lseek(fd, 0, SEEK_SET); bzero(buf,
		// 1024); read(fd, buf, 1024);
//     // /* 7 */ ASSERT_EQ_STR(buf, "01-142-422147483647-2147483648");
//     // ft_putnbr_fd(INT_MAX - 1, fd); lseek(fd, 0, SEEK_SET); bzero(buf,
		// 1024); read(fd, buf, 1024);
//     // /* 8 */ ASSERT_EQ_STR(buf,
		// "01-142-422147483647-21474836482147483646");
//     // ft_putnbr_fd(INT_MIN + 1, fd); lseek(fd, 0, SEEK_SET); bzero(buf,
		// 1024); read(fd, buf, 1024);
//     // /* 9 */ ASSERT_EQ_STR(buf,
		// "01-142-422147483647-21474836482147483646-2147483647");
//     // close(fd);
//     // remove("tmp.txt");
// 	// return (0);
// }