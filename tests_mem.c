/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:05:33 by dda-silv          #+#    #+#             */
/*   Updated: 2014/11/08 12:53:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	test_ft_memset()
{
	char src = 'a';
	char dst[5];
	
	_begin;

	_it("should write len bytes of value c to the string b");

	// 0 bytes
	memset(dst, src + 1, 5);
	ft_memset(dst, src, 0);
	_assert(dst[0] != src);
	_assert(dst[1] != src);
	
	// 1 byte
	memset(dst, src + 1, 5);
	ft_memset(dst, src, 1);
	_assert(dst[0] == src);
	_assert(dst[1] != src);

	// n bytes
	memset(dst, src + 1, 5);
	ft_memset(dst, src, 4);
	int i = -1;
	while (++i < 4)
		_assert(dst[i] == src);
	_assert(dst[4] != src);

	_it("return its first argument");

	_assert(dst == ft_memset(dst, src, 0));
	_assert(dst == ft_memset(dst, src, 1));
	_assert(dst == ft_memset(dst, src, 4));

	_done;
}

int	test_ft_bzero()
{
	char	dst[5];
	
	_begin;

	_it("should write n zeroed bytes to the string s");

	// 0 bytes
	memset(dst, 1, 5);
	ft_bzero(dst, 0);
	_assert(dst[0] != 0);

	// 1 byte
	memset(dst, 1, 5);
	ft_bzero(dst, 1);
	_assert(dst[0] == 0);
	_assert(dst[1] != 0);

	// n bytes
	memset(dst, 1, 5);
	ft_bzero(dst, 2);
	_assert(!dst[0] && !dst[1] && dst[2]);

	_done;
}

int	test_ft_memcpy()
{
	void *src;
	void *dst1;

	_begin;

	_it("should copy n bytes from memory area src to memory area dst.");

	dst1 = malloc(1);
	memset(dst1, 0, 1);
	ft_memcpy(dst1, "a", 0);
	_assert(!((char *)dst1)[0]);

	src = "je sais pas std";
	dst1 = malloc(strlen(src) + 1); 
	ft_memcpy(dst1, src, strlen(src)+1);
	_assert_str(src, dst1);

	_it("should return the original value of dst");
	dst1 = malloc(5);
	_assert_ptr(ft_memcpy(dst1, src, 5), dst1);

	_done;
}

int test_ft_memccpy()
{
	char	*src = "w0l0l0";
	char	dst[10];
	char	dst2[10];
	void	*ret;

	_begin;

	_it("should copy n bytes from src to dst and return NULL");
	bzero(dst, 10);
	ret = ft_memccpy(dst, src, '1', strlen((const char *) src));
	_assert_str(dst, src);
	_assert_ptr(ret, NULL);
	
	_it("should return a pointer to the byte after the copy of c in the string dst");
	bzero(dst, 10);
	bzero(dst2, 10);
	_assert_str(dst, dst2);	
	_assert_ptr(ft_memccpy(dst, src, 'l', 5), memccpy(dst, src, 'l', 5));
	
	_done;
}

int	test_ft_memmove()
{
	return (0);
}

int	test_ft_memchr()
{
	char	*str = "b0cal";
	
	_begin;

	_it("should return the first ocurrence of c in string s");
	_assert_ptr(ft_memchr(str, '0', 5), memchr(str, '0', 5));
	_assert_ptr(ft_memchr(str, 'l', 5), memchr(str, 'l', 5));

	_it("should return null if no such byte exists within n bytes");
	_assert_ptr(ft_memchr(str, '0', 0), memchr(str, '0', 0));
	_assert_ptr(ft_memchr(str, 'k', 5), memchr(str, 'k', 5));

	_done;
}

int	test_ft_memcmp()
{
	char	s1[10];
	char	s2[10];
	
	_begin;

	_it("should not crash with len 0");
	ft_memcmp(s1, s2, 0);

	_done;

}

int tests_mem()
{
	_verify(test_ft_memset);
	_verify(test_ft_bzero);
	_verify(test_ft_memcpy);
	_verify(test_ft_memccpy);
	_verify(test_ft_memchr);
	_verify(test_ft_memcmp);
	return (0);
}
