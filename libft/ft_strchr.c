/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:27:24 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:44 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char const *str, int ch)
{
	int				i;
	unsigned char	search;

	i = 0;
	search = (unsigned char)ch;
	while (str[i])
	{
		if (str[i] == search)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == search)
		return ((char *)&str[i]);
	return ((char *)0);
}
