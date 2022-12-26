/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:54:09 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 20:07:42 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_common_msg(void) { printf("%s%s", "Error\n", "cub3D: "); }

int print_error(char *error_msg) {
  print_common_msg();
  printf("%s \n", error_msg);
  return (EXIT_FAILURE);
}

int print_strerror(char *arg) {
  print_common_msg();
  printf("%s: %s\n", arg, strerror(errno));
  return (EXIT_FAILURE);
}