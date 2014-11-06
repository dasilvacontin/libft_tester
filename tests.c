/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:05:33 by dda-silv          #+#    #+#             */
/*   Updated: 2014/11/06 15:24:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include "../libft/libft.h"
#include <stdlib.h>

#define pt (void *)

int	test_ft_memcpy()
{
	void *src;
	void *dst1;

	_begin;

	_it("should not crash with null dest");
	ft_memcpy(NULL, pt 2, 2);
	
	_it("should not crash with null src");
	ft_memcpy(pt 2, NULL, 2);
	
	_it("should not crash with both dest and src null");
	ft_memcpy(NULL, NULL, 2);
		
	_it("should do nothing with len = 0");
	dst1 = malloc(1);
	memset(dst1, 0, 1);
	ft_memcpy(dst1, "a", 0);
	_assert(!((char *)dst1)[0]);
	
	_it("should correctly copy a string from src to dest");
	src = "je sais pas std";
	dst1 = malloc(strlen(src) + 1); 
	ft_memcpy(dst1, src, strlen(src)+1);
	_assert(((char *)dst1)[strlen(src)] == 0);
	_assert_str(src, dst1);

	_it("should return dst");
	dst1 = malloc(1);
	_assert_ptr(ft_memcpy(NULL, src, 1), NULL);
	_assert_ptr(ft_memcpy(dst1, src, 1), dst1);

	_done;
}

int test_ft_memccpy()
{
	char	*src = "w0l0l0";
	char	dst[10];
	char	dst2[10];
	void	*ret;

	_begin;

	_it("should not crash with null dest or src");
	ft_memccpy(NULL, src, '0', 1);
	ft_memccpy(dst, NULL, '0', 2);
	ft_memccpy(NULL, NULL, '0', 3);

	_it("should copy 'n' bytes from src to dst and return NULL");
	bzero(dst, 10);
	ret = ft_memccpy(dst, src, '1', strlen((const char *) src));
	_assert_str(dst, src);
	_assert_ptr(ret, memccpy(dst, src, '1', strlen((const char*) src)));
	
	_it("should return a pointer to the byte after the copy of c in the string dst");
	bzero(dst, 10);
	bzero(dst2, 10);
	ft_memccpy(dst, src, 'l', 5);
	memccpy(dst2, src, 'l', 5);
	_assert_str(dst, dst2);	
	_assert_ptr(ft_memccpy(dst, src, 'l', 5), memccpy(dst, src, 'l', 5));
	
	_done;
}

int	test_ft_memset()
{
	char src = 'a';
	char dst[5];
	
	_begin;

	_it("should not crash with null dest");
	ft_memset(NULL, 0, 1);

	_it("should not crash with len == 0");
	ft_memset(&dst, 'h', 1);

	_it("should set a single byte");
	memset(dst, 0, 5);
	ft_memset(dst, src, 1);
	_assert(dst[0] == src);
	_assert(dst[1] != src);

	_it("should set multiple bytes");
	memset(dst, 0, 5);
	ft_memset(dst, src, 4);
	int i = -1;
	while (++i < 4)
		_assert(dst[i] == src);
	_assert(dst[4] != src);

	_done;
}

int	test_ft_bzero()
{
	char	dst[5];
	
	_begin;

	_it("should not crash with null dest");
	ft_bzero(NULL, 5);

	_it("should not crash with len = 0");
	memset(dst, 1, 5);
	ft_bzero(dst, 0);
	_assert(dst[0] != 0);

	_it("should set a single byte");
	memset(dst, 1, 5);
	ft_bzero(dst, 1);
	_assert(dst[0] == 0);
	_assert(dst[1] != 0);

	_it("should set multiples bytes");
	memset(dst, 1, 5);
	ft_bzero(dst, 2);
	_assert(!dst[0] && !dst[1] && dst[2]);

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

	_it("should not crash with null string");
	ft_memchr(NULL, 1, 2);

	_it("should return the first ocurrence of 'c' in 's'");
	_assert_ptr(ft_memchr(str, '0', 5), memchr(str, '0', 5));
	_assert_ptr(ft_memchr(str, 'l', 5), memchr(str, 'l', 5));

	_it("should return null if there's no ocurrence");
	_assert_ptr(ft_memchr(str, 'k', 5), memchr(str, 'k', 5));

	_done;
}

int	test_ft_memcmp()
{
	char	s1[10];
	char	s2[10];
	
	_begin;

	_it("should not crash with null s1, s2, or n");
	ft_memcmp(NULL, s2, 2);
	ft_memcmp(s1, NULL, 2);
	ft_memcmp(NULL, NULL, 2);
	ft_memcmp(s1, s2, 0);

	_done;

}
