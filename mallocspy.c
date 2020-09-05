/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:03 by abaur             #+#    #+#             */
/*   Updated: 2020/01/27 12:06:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

extern void		*spymalloclvl(unsigned int level, void **variable, size_t size)
{
	*variable = malloc(size);
	if (!*variable)
		return (NULL);
	if (!spyreglvl(level, variable))
	{
		free(*variable);
		return (NULL);
	}
	return (*variable);
}

extern short	spyfree(void **ptr)
{
	if (spyunreg(ptr))
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		return (1);
	}
	else if (ptr && *ptr && SPYVERBOSE && SPYBRAVE)
	{
		(*g_printf)("Attempting to free the pointer anyway.\n");
		free(*ptr);
		ptr = NULL;
	}
	else if (SPYVERBOSE)
		(*g_printf)("The pointer was not freed.\n");
	return (0);
}

extern size_t	spyclean(void)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (++i < g_spycap)
		if (g_spylist[i].ptr && !*g_spylist[i].ptr)
		{
			g_spylist[i] = (t_spyvar){0, NULL};
			count++;
		}
	return (count);
}
