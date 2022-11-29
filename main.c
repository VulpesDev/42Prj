/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:45:22 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/29 18:39:35 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<strings.h>
#include "libft.h"

int	main(void)
{
	char	c;
	char	*s;

	printf("\n%s\n", "isalpha");
	c = '1';
	printf("%d\n", ft_isalpha(c));
	c = 's';
        printf("%d\n", ft_isalpha(c));
	c = 'A';
        printf("%d\n", ft_isalpha(c));

	printf("\n%s\n", "isdigit");
	c = '0';
	printf("%d\n", ft_isdigit(c));
	c = '9';
        printf("%d\n", ft_isdigit(c));
	c = 'a';
        printf("%d\n", ft_isdigit(c));

	printf("\n%s\n", "isalnum");
	c = 'a';
	printf("%d\n", ft_isalnum(c));
	c = '5';
	printf("%d\n", ft_isalnum(c));
	c = '%';
	printf("%d\n", ft_isalnum(c));

	printf("\n%s\n", "isprint");
	c = 'a';
	printf("%d\n", ft_isprint(c));
	c = 12;
	printf("%d\n", ft_isprint(c));
	c = '\0';
	printf("%d\n", ft_isprint(c));

	printf("\n%s\n", "toupper");
	c = 'g';
	printf("%c\n", ft_toupper(c));
	c = '?';
	printf("%c\n", ft_toupper(c));
	c = 'D';
	printf("%c\n", ft_toupper(c));

	printf("\n%s\n", "tolower");
        c = 'g';
        printf("%c\n", ft_tolower(c));
        c = '?';
        printf("%c\n", ft_tolower(c));
        c = 'D';
        printf("%c\n", ft_tolower(c));

	printf("\n%s\n", "strchr");
        c = 'k';
        s = "karaoke";
        printf("%c\n", *ft_strchr(c, s));
        c = 'y';
        s = "Sync in inky";
        printf("%c\n", *ft_strchr(c, s));

	printf("\n%s\n", "strrchr");
	c = 'k';
	s = "karaoke";
	printf("%c\n", *ft_strrchr(c, s));
	c = 'y';
	s = "Sync in inky";
	printf("%c\n", *ft_strrchr(c, s));

	printf("\n%s\n", "isascii");
	c = 97;
	printf("%d\n", ft_isascii(c));
	c = 210;
        printf("%d\n", ft_isascii(c));

	printf("\n%s\n", "strlen");
	s = "Forest"; // should be 6
	printf("%ld\n", ft_strlen(s));
	s = "Mountain"; // should be 8
	printf("%ld\n", ft_strlen(s));

	char	str[50] = "Multi Very What";
	printf("\n%s\n", "memset");
	ft_memset(str, '.', 3*sizeof(char));
	printf("%s\n", str);

	printf("\n%s\n", "bzero");
	char	buffer[50] = "Hello brothers!";
	printf("Before: %s\n", buffer);
	ft_bzero(buffer, 1*sizeof(char));
	printf("After: %s\n", buffer);

	printf("\n%s\n", "memcpy");
	char	dest[50];
	char	src[50] = "Hello OOOOO";
	ft_memcpy(dest, src, 5 * sizeof(char));
	printf("%s\n", dest);

	return(0);
}
