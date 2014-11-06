/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:57:32 by dda-silv          #+#    #+#             */
/*   Updated: 2014/11/06 15:26:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test_macros.h"
#include "tests.h"

int	all_tests()
{
	_verify(test_ft_memset);
	_verify(test_ft_bzero);
	_verify(test_ft_memcpy);
	_verify(test_ft_memccpy);
	_verify(test_ft_memchr);
	_verify(test_ft_memcmp);
	return (0);
}

int	main()
{
	int result;

	tests_failed = 0;
	tests_run = 0;
	printf("\n");
	result = all_tests();

	if (result == 0) printf("All good! :D\n");
	else printf("(/>.<)/|__|\n");
	
	printf("Tests passed: %d/%d\n\n", tests_run - tests_failed, tests_run);
	return (result != 0);
}

