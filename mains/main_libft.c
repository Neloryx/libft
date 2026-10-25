/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:09:17 by thdeglos          #+#    #+#             */
/*   Updated: 2026/10/25 11:44:52 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main() //isalpha
{
	printf("%d, ",ft_isalpha('A'));
	printf("%d\n",isalpha('A'));
	printf("%d, ",ft_isalpha('c'));
	printf("%d\n",isalpha('c'));
	printf("%d, ",ft_isalpha('4'));
	printf("%d\n",isalpha('4'));
}

int	main() //isdigit
{
	printf("%d, ",ft_isdigit('A'));
	printf("%d\n",isdigit('A'));
	printf("%d, ",ft_isdigit('c'));
	printf("%d\n",isdigit('c'));
	printf("%d, ",ft_isdigit('4'));
	printf("%d\n",isdigit('4'));
}

int	main() //isalnum
{
	printf("%d, ",ft_isalnum('A'));
	printf("%d\n",isalnum('A'));
	printf("%d, ",ft_isalnum('c'));
	printf("%d\n",isalnum('c'));
	printf("%d, ",ft_isalnum('4'));
	printf("%d\n",isalnum('4'));
	printf("%d, ",ft_isalnum('"'));
	printf("%d\n",isalnum('"'));
}

int	main() //isascii
{
	printf("%d, ",ft_isascii('A'));
	printf("%d\n",isascii('A'));
	printf("%d, ",ft_isascii('c'));
	printf("%d\n",isascii('c'));
	printf("%d, ",ft_isascii('4'));
	printf("%d\n",isascii('4'));
	printf("%d, ",ft_isascii('"'));
	printf("%d\n",isascii('"'));
}

int	main() //isprint
{
	printf("%d, ",ft_isprint('A'));
	printf("%d\n",isprint('A'));
	printf("%d, ",ft_isprint('c'));
	printf("%d\n",isprint('c'));
	printf("%d, ",ft_isprint('4'));
	printf("%d\n",isprint('4'));
	printf("%d, ",ft_isprint('\a'));
	printf("%d\n",isprint('\a'));
}

int	main() //strlen
{
	int	i;
	int	j;
	char	str[] = "Test";

	i = ft_strlen(str);
	j = strlen(str);
	printf("%ld, ", i);
	printf("%ld\n", j);
}

int	main() //memset
{
	char	str[] = "Test";

	ft_memset(str, 65, 4);
	printf("%s", str);
}

int	main() //bzero
{
	char	str[] = "Test";

	ft_bzero(str, 3);
	printf("%s\n", str);
	bzero(str, 3);
	printf("%s\n", str);
}

int	main() //memcpy
{
	char	src[] = "Test";
	char	dest[] = "Stes";

	ft_memcpy(dest, src, 2);
	printf("%s", src);
}

int	main() //memmove
{
	char	str[50] = "Test";

	ft_memmove(str +10, str +4, 29);
	printf("%s\n", str);
}

int	main() //strlcpy
{
	size_t	n;

	n = 4;
	char	src[] = "Test";
	char	dest[n];
	printf("%ld\n", ft_strlcpy(dest, src, n));
}

int main() //strlcat
{
	size_t	n;

	n = 5;
	char	src[] = "Test";
	char	dest[] = "Test";
	int size = ft_strlcat(dest, src, n);
	printf("%s\n taille : %d\n ", dest, size);
}

int main() //toupper
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('v'));
	printf("%c\n", ft_toupper('L'));
}

int main() //tolower
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('V'));
	printf("%c\n", ft_tolower('l'));
}

int	main() //strchr
{
	char	str[] = "Test";

	printf("%s\n", strchr(str, 't'));
	printf("%s\n", ft_strchr(str, 't'));
}

int main() //strrchr
{
	char	str[] = "Test";

	printf("%s\n", strrchr(str, 'b'));
	printf("%s\n", ft_strrchr(str, 'b'));
}

int main() //strncmp
{
	printf("%d, ", ft_strncmp("ABC", "ABC", 3));
	printf("%d\n", strncmp("ABC", "ABC", 3));

	printf("%d, ", ft_strncmp("ABC", "AB", 3));
	printf("%d\n", strncmp("ABC", "AB", 3));

	printf("%d, ", ft_strncmp("ABA", "ABZ", 3));
	printf("%d\n", strncmp("ABA", "ABZ", 3));

	printf("%d, ", ft_strncmp("ABJ", "ABC", 3));
	printf("%d\n", strncmp("ABJ", "ABC", 3));
}

int	main() //memchr
{
	char	*str = ft_memchr("o7", 'b', 0);

	printf("%s", str);
}

int main() //memcmp
{
	int	str1 [] = {54, 85, 20, 63, 21};
	int	str2 [] = {54, 85, 19, 63, 21};
	size_t n = sizeof(int) * 5;

	printf("%d, ", memcmp(str1, str2, n));
	printf("%d\n", ft_memcmp(str1, str2, n));

	printf("%d, ", memcmp(str1, str1, n));
	printf("%d\n", ft_memcmp(str1, str1, n));

	printf("%d, ", memcmp(str2, str1, n));
	printf("%d\n", ft_memcmp(str2, str1, n));
}

int main() //strnstr
{
	const char	*big = "The universe is as big as npillet";
	const char	*little = "big";
	char		*result;
	result = ft_strnstr(big, little, 40);
	if (result)
		printf("SUCCESS. Next: \"%s\"\n", result);
	else
		printf("FAILED\n");
	return (0);
}

int	main() //atoi
{
	char	p[] = "   -2134bfds4576651";

	printf("%d\n", atoi(p));
	printf("%d\n", ft_atoi(p));
}

int main(void) // calloc
{
    int *p = calloc(5, sizeof(int));
    free(p);
}

int	main() //strdup
{
	char	p[] = "Test";
	char	*result = ft_strdup(p);

	printf("%s\n", result);
	free(result);
}

int	main() //substr
{
	char	str[] = "Sashimi";
	char	*result = ft_substr(str, 11, 10);

	printf("%s", result);
	free(result);
}

int	main() //strjoin
{
	char	str1[] = "Test";
	char	str2[] = "Stes";
	char	*result = ft_strjoin(str1, str2);

	printf("%s", result);
	free(result);
}

int	main() //strtrim
{
	char	str1 [] = "****Hell**o!**";
	char	s[] = "*";
	char	*result = ft_strtrim(str1, s);

	printf("%s", result);
}

int	main() //split
{
	char	str[] = "***He***ll**o****test*one*";
	char	**p = ft_split(str, '*');
	int		i;

	i = 0;
	while (p[i] != NULL)
	{
		printf("[%s] \n", p[i]);
		i++;
	}
	ft_freeall(p);
}

int	main() //itoa
{
	char	*result = ft_itoa(0);

	printf("%s", result);
	free(result);
}

char f(unsigned int i, char c) //strmapi
{
	c += i;
	return (c);
}

int	main()
{
	char	str[] = "aaaaaa"; //should be abcdef
	char	*result = ft_strmapi(str, &f);

	printf("%s\n", result);
	free(result);
}

void f(unsigned int i, char *c) //striteri
{
	c += i;
}

int	main()
{
	char	str[] = "aaaaaa"; //should be abcdef

	ft_striteri(str, &f);
	printf("%s\n", str);
}

int	main() //putchar_fd
{
	ft_putchar_fd('b', 1);
}

int	main() //putstr_fd
{
	char	str[] = "Test";

	ft_putstr_fd(str, 0);
	printf("\n");
	ft_putstr_fd(str, 1);
	printf("\n");
	ft_putstr_fd(str, 2);
	printf("\n");
}

int	main() //putendl_fd
{
	char	str[] = "Test";

	ft_putendl_fd(str, 0);
	ft_putendl_fd(str, 1);
	ft_putendl_fd(str, 2);
}

int	main() //putnbr_fd
{
	ft_putnbr_fd(42, 1);
	printf("\n");
	ft_putnbr_fd(-42, 1);
}

int	main(void) //lstadd_front must display hello world
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("world");
	new = ft_lstnew("hello");
	ft_lstadd_front(&list, new);
	printf("%s %s\n", (char *)list->content, (char *)list->next->content);
	free(new->next);
	free(new);
	return (0);
}

int	main(void) //lstsize must display a b
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");
	a->next = b;
	b->next = c;
	printf("%d\n", ft_lstsize(a));
	free(a);
	free(b);
	free(c);
	return (0);
}

int	main(void) //lstlast must display c
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");
	a->next = b;
	b->next = c;
	printf("%s\n", (char *)ft_lstlast(a)->content);
	free(a);
	free(b);
	free(c);
	return (0);
}

int	main(void) //lastadd_back display be a b
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	ft_lstadd_back(&a, b);
	printf("%s %s\n", (char *)a->content, (char *)a->next->content);
	free(a);
	free(b);
	return (0);
}

int	main(void) //lstdelone
{
	t_list	*node;

	node = ft_lstnew(ft_strdup("bye"));
	ft_lstdelone(node, free);
	return (0);
}

int	main(void) //lstclear must display (nil)
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("a"));
	list->next = ft_lstnew(ft_strdup("b"));
	ft_lstclear(&list, free);
	printf("%p\n", (void *)list);
	return (0);
}

static void	f(void *content) // lstiter complemetary
{
	((char *)content)[0] = 'X';
}

int	main(void) // lstiter must display Xbc Xef
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("abc"));
	list->next = ft_lstnew(ft_strdup("def"));
	ft_lstiter(list, f);
	printf("%s %s\n", (char *)list->content, (char *)list->next->content);
	ft_lstclear(&list, free);
	return (0);
}

static void	*f(void *content) //lstmap complementary
{
	char	*str;

	str = ft_strdup((char *)content);
	str[0] = 'X';
	return (str);
}

int	main(void) //lstmap must display Xbc Xef
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew(ft_strdup("abc"));
	list->next = ft_lstnew(ft_strdup("def"));
	new = ft_lstmap(list, f, free);
	printf("%s %s\n", (char *)list->content, (char *)list->next->content);
	printf("%s %s\n", (char *)new->content, (char *)new->next->content);
	ft_lstclear(&list, free);
	ft_lstclear(&new, free);
	return (0);
}
