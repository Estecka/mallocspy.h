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

extern void		*spymalloc(void **variable, size_t size)
{
	*variable = malloc(size);
	if (!*variable)
		return (NULL);
	if (!spyreg(variable))
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
		ft_printf("Attempting to free the pointer anyway.\n");
		free(*ptr);
		ptr = NULL;
	}
	else if (SPYVERBOSE)
		ft_printf("The pointer was not freed.\n");
	return (0);
}

extern size_t	spyclean(void)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (++i < g_spycap)
		if (g_spylist[i] && !*g_spylist[i])
		{
			g_spylist[i] = NULL;
			count++;
		}
	return (count);
}
