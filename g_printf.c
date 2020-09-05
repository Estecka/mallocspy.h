/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:56:00 by abaur             #+#    #+#             */
/*   Updated: 2020/09/05 18:56:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

#if SPYVERBOSE
# include <stdio.h>

int			(*g_printf)(const char*, ...) = &printf;

#else

int			(*g_printf)(const char*, ...) = &noprintf;

static int	noprintf(const char *s, ...)
{
	return (0);
}

#endif
