/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_overloads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:29:00 by abaur             #+#    #+#             */
/*   Updated: 2020/09/02 19:29:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

extern void		*spymalloc(void **variable, size_t size)
{
	return (spymalloclvl(g_spylevel, variable, size));
}

extern void		*spyreg(void *ptr)
{
	return (spyreglvl(g_spylevel, ptr));
}

extern size_t	spyflush(void)
{
	return (spyflushlvl(g_spylevel));
}

