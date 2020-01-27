/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tesmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:03 by abaur             #+#    #+#             */
/*   Updated: 2020/01/23 14:05:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

#include <stdio.h>

int main(void)
{
	void* p;
	unsigned long ul;
	short b;

	printf("\n\tSpyReg :\n");
	for(int i=0; i<64; i++)
	{
		p = spyreg((void*)(unsigned long)i);
		if(p != (void*)(unsigned long)i)
			printf("[%d] Got %p.\n", i, p);
	}

	printf("\n\tSpyLog :\n");
	ul = (int)spylog();
	if (ul != 63)
		printf("Expected 63, got %lu.\n", ul);

	printf("\n\tSpyUnreg :\n");
	for(int i=0; i<32; i++)
	{
		b = spyunreg((void*)(unsigned long)i);
		if (!b)
			printf("[%d] Got %d", i, b);
	}

	printf("\n\tSpyLog :\n");
	ul = (int)spylog();
	if (ul != 32)
		printf("Expected 32, got %d.\n", (int)ul);

	printf("\n\tSpyReg duplicates : \n");
	for (int i=32; i<64; i++)
	{
		p = spyreg((void*)(unsigned long)i);
		if (p != (void*)(unsigned long)i)
				printf("[%d] Got : %p.\n", i, p);
	}

	printf("\n\tSpyUnreg duplicates :\n");
	for(int i=0; i<32; i++)
	{
		b = spyunreg((void*)(unsigned long)i);
		if (b)
			printf("[%d] Got %d", i, b);
	}

	printf("\n\tSpyFlush : \n");
	ul = spyflush();
	if (ul != 32)
		printf("Expected 32, got %lu.", ul);

	printf("\n\tSpyLog :\n");
	ul = (int)spylog();
	if (ul != 0)
		printf("Expected 0, got %d.\n", (int)ul);
}
