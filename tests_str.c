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

#define ATOI_TEST_COUNT 9

int	test_ft_atoi()
{
	char strs[ATOI_TEST_COUNT][15] = {
		"\t\n\v\f\r -042",
		"    +007",
		"07-4",
		"00-7",
		"-007",
		"007",
		"124",
		"-235",
		".5"
	};
	int	i;
	_begin;

	_it("should return the same as libc's atoi");
	i = ATOI_TEST_COUNT;
	while (i--)
		_assert_int(ft_atoi(strs[i]), atoi(strs[i]));
	_done;

}

int test_ft_strlen()
{
	char *s;

	_begin;

	_it("should compute the length of the string s");

	s = "";
	_assert_int((int)ft_strlen(s), (int)strlen(s));
	s = "asdagewshd";
	_assert_int((int)ft_strlen(s), (int)strlen(s));

	_done;
}

int test_ft_strdup()
{
	char *s;

	_begin;

	_it("should return a pointer to the copy of the string s1");
	s = "";
	_assert_str(ft_strdup(s), strdup(s));
	s = ";nh[wERNO;";
	_assert_str(ft_strdup(s), strdup(s));

	_itx("should return NULL on malloc fail");

	_done;
}

int test_ft_strcpy()
{
	char *src;
	char dest[10];
	_begin;

	_it("should copy the string src to dst (including '\\0')");

	src = "";
	ft_strcpy(dest, src);
	_assert_str(dest, src);

	src = "abcdef";
	ft_strcpy(dest, src);
	_assert_str(dest, src);

	_it("should return dst");

	src = "";
	_assert_ptr(dest, ft_strcpy(dest, src));

	src = "abcdef";
	_assert_ptr(dest, ft_strcpy(dest, src));

	_done;
}

int test_ft_strncpy()
{
	char *src;
	char dest[10];
	_begin;

	_it("should copy at most n characters from src into dst");

	src = "abcdef";
	memset(dest, 1, 10);
	ft_strncpy(dest, src, 0);
	_assert(dest[0] == 1);

	ft_strncpy(dest, src, 4);
	_assert(!memcmp(dest, src, 4));
	_assert(dest[4] == 1);

	_it("should fill the remainder of dst is filled with \\0");

	src = "lol";
	memset(dest, 1, 10);
	ft_strncpy(dest, src, 5);
	_assert_str(dest, src);
	_assert(!dest[3] && !dest[4] && dest[5]);

	_it("should not terminate dst otherwise");

	src = "abcdef";
	memset(dest, 1, 10);
	ft_strncpy(dest, src, 0);
	_assert(dest[0] != '\0');

	ft_strncpy(dest, src, 4);
	_assert(dest[4] != '\0');

	_it("should return dst");
	_assert_ptr(ft_strncpy(dest, src, 4), dest);

	_done;
}

int	tests_str() {
	_verify(test_ft_strlen);
	_verify(test_ft_strdup);
	_verify(test_ft_strcpy);
	_verify(test_ft_strncpy);
	_verify(test_ft_atoi);
	return (0);
}

