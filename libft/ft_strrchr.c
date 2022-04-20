/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:20:03 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:28:24 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//#include <string.h>
char	*ft_strrchr(const char *s, int c)
{
	const char	*found;
	const char	*p;

	c = (unsigned char) c;
	if (c == '\0')
		return (ft_strchr (s, '\0'));
	found = NULL;
	p = ft_strchr(s, c);
	while (p != NULL)
	{
		found = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return ((char *) found);
}
/*int main()
{
        char src[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
    printf("%s\n",ft_strrchr(src, '\0'));
    printf("%s\n",strrchr(src, '\0'));
    
}
*/
