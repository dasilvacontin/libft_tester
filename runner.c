/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:57:32 by dda-silv          #+#    #+#             */
/*   Updated: 2014/11/08 12:50:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test_macros.h"
#include "tests_mem.h"
#include "tests_str.h"

int	all_tests()
{
	tests_mem();
	tests_str();
	return (tests_failed > 0);
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

