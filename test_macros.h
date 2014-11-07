/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:01:23 by dda-silv          #+#    #+#             */
/*   Updated: 2014/11/07 17:13:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MACROS_H
# define TEST_MACROS_H

# include <stdio.h>

int		tests_failed;
int		tests_run;

void	_color(int c);
void	_it(char *should);
void	_begin_assert();
void	_fail_test();
void	_close_pending();

# define GREEN 32
# define RED 31
# define RESET 0

# define _begin printf("%s\n", __func__ + 5)
# define _done do { _close_pending(); printf("\n"); return(0); } while(0)
# define FAIL() do { _color(RED); printf("\nfailure in %s() line %d\n", __func__, __LINE__); _color(RESET); } while(0)
# define _assert(test) do { _begin_assert(); if (!(test)) { _fail_test(); FAIL(); return 1; } } while(0)
# define _assert_int(int1, int2) do { _begin_assert(); if (int1 != int2) { _fail_test(); FAIL(); printf("expected %i to equal %i\n", int1, int2); return 1; } } while(0)
# define _assert_ptr(res1, res2) do { _begin_assert(); if (res1 != res2) { _fail_test(); FAIL(); printf("expected %p to equal %p\n", res1, res2); return 1; } } while(0)
# define _assert_str(str1, str2) do { _begin_assert(); if (strcmp(str1, str2)) { _fail_test(); FAIL(); printf("expected \"%s\" to equal \"%s\"\n", (char *)str1, (char *)str2); return 1; } } while(0)
# define _verify(test) do { int r = test(); if (r) return (r); } while(0)

#endif
