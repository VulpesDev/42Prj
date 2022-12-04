/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:45:22 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/03 16:43:24 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
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
        int	ci = 'k';
        s = "bounjour";
        printf("%c\n", *ft_strchr(s, 'b'));
        ci = 'y';
        s = "Sync in inky";
        printf("%c\n", *ft_strchr(s, ci));

	printf("\n%s\n", "strrchr");
	ci = 'k';
	s = "karaoke";
	printf("%c\n", *ft_strrchr(s, ci));
	ci = 'y';
	s = "Sync in inky";
	printf("%c\n", *ft_strrchr(s, ci));

	printf("\n%s\n", "isascii");
	c = 97;
	printf("%d\n", ft_isascii(c));
	c = (unsigned char)210;
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
	
	printf("\n%s\n", "memmove");
	char	src2[50] = "Hello";
	printf("Src: %s\n", src2 + 1);
	memmove(src2, src2 + 1, 5);
	printf("Dest: %s\n", src2);

	printf("\n%s\n", "strncmp");
	char	s1[50] = "test\200";
	char	s2[50] = "test\0";
	printf("My:%d Real:%d\n", ft_strncmp(s1, s2, 6), strncmp(s1, s2, 6));

	printf("\n%s\n", "memchr");
	char	what[50] = "Hello";
	printf("Actual memory:%p\n", &what[2]);
	printf("Memory found:%p\n", ft_memchr(what, 'l', 5));

	printf("\n%s\n", "strnstr");
	char *ptr;
	ptr = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	printf("%s\n", ptr ? ptr :"0");

	printf("\n%s\n", "strlcpy");
	char dest10[50];
	char src10[50] = "Hello!";
	printf("%ld\n", ft_strlcpy(dest10, src10, 6));
	printf("%s\n", dest10);

	printf("\n%s\n", "strlcat");
	char dest20[50] = "0123456789";
	char src20[50] = "absdf";
	printf("%zu\n", ft_strlcat(dest20, src20, 0));
	printf("%s\n", dest20);

	printf("\n%s\n", "atoi");
	char number[50] = "+-54";
	printf("mine:%d real:%d\n", ft_atoi(number), atoi(number));

	printf("\n%s\n", "calloc");
	char *whatt = ft_calloc(10, sizeof(char));
	whatt[0] = 'w';
	whatt[1] = 'h';
	printf("%s\n", whatt);

	printf("\n%s\n", "strtrim");
	printf("%s\n", ft_strtrim("aaaeeHelloaaee", "ae"));

	printf("\n%s\n", "split");
	char	**result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	int	ii;
	ii = 0;
	while (result[ii] != (void *)0)
	{
		printf("%s\n", result[ii]);
		ii++;
	}
	return (0);
}
