/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/23 10:53:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOCSPY_INTERNALS_H
# define MALLOCSPY_INTERNALS_H

# include "mallocspy.h"

typedef struct s_spyptr	t_spyptr;
struct	s_spyptr
{
	void	*adress;
	size_t	size;
};

short	spyexpand(void);

#endif
