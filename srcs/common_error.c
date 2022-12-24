/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:54:09 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 16:51:30 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "cub3d.h"

static void print_common_msg(void)
{
    printf("%s%s", "Error\n", "cub3D: ");
}

int    print_error(char *error_msg)
{
    print_common_msg();
    printf("%s \n", error_msg);
    return (EXIT_FAILURE);
}

int    print_perror(void)
{
    print_common_msg();
    perror(NULL);
    return (EXIT_FAILURE);
}