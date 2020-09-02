/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spylevel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:47:00 by abaur             #+#    #+#             */
/*   Updated: 2020/09/02 19:47:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

extern unsigned int	spylevel(void)
{
	return (g_spylevel);
}

extern unsigned int	spymount(void)
{
	return (++g_spylevel);
}
