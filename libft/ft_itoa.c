/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:56:53 by ykoseki           #+#    #+#             */
/*   Updated: 2023/11/24 03:32:24 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	digit_len(int n)
{
	int	digit;

	digit = 1;
	if (n == 0)
		return (digit);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		digit += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static char	*itoa_helper(char *ans, int digit, int n)
{
	while (digit > 0)
	{
		if (n <= 0 && digit == 1)
			break ;
		digit--;
		ans[digit] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		digit;

	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	digit = digit_len(n);
	ans = ft_calloc(digit + 1, sizeof(char));
	if (!ans)
		return (NULL);
	if (n < 0)
		ans[0] = '-';
	else if (n == 0)
		ans[0] = '0';
	ans[digit] = '\0';
	return (itoa_helper(ans, digit, n));
}

// int	main(void)
// {
// 	printf("%s",ft_itoa(-1));
// }