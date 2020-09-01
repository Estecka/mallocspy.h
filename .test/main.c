/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:03 by abaur             #+#    #+#             */
/*   Updated: 2020/01/27 12:55:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mallocspy.h"

#include <stdio.h>

static void TestLog(size_t expected)
{
	printf("\nSpyLog\n");
	size_t got = spylog();
	if (got != expected)
		printf("Expected %zu, got %lu\n", expected, got);
}

extern int main(void)
{
	void* p;
	unsigned long lu;
	short b;
	void* vars[64];

	// Initialize mallocs with dummy pointers.
	for (int i=0; i<64; i++)
		vars[i] = (void*)(long)i;

	printf("\nSpyReg\n");
	for (int i=0; i<64; i++)
	{
		p = spyreg(vars + i);
		if (p != (vars + i))
			printf("[%i] Expected %p, got %p\n", i, vars+i, p);
	}
	p = spyreg(NULL);
	if (p != NULL)
		printf("[NULL] Got %p\n", p);

	TestLog(64);

	printf("\nSpyClean\n");
	for (int i=0; i<32; i++)
		vars[i] = NULL;
	lu = spyclean();
	if (lu != 32)
		printf("Expected 32, got %lu\n", lu);

	TestLog(32);

	printf("\nSpyUnreg (w/ unregistered)\n");
	for (int i=0; i<32; i++)
	{
		b = spyunreg(vars + i);
		if (b)
			printf("[%i] Got %ds\n", i, b);
	}
	printf("\nSpyUnreg (w/ registered)\n");
	for (int i=32; i<64; i++)
	{
		b = spyunreg(vars + i);
		if (!b)
			printf("[%i] Got %ds\n", i, b);
	}

	TestLog(0);



	printf("\nSpyMalloc\n");
	for (int i=0; i<64; i++)
	{
		p = spymalloc(vars + i, sizeof(int));
		if (p != vars[i])
			printf("[%i] Expected %p, got %p\n", i, vars[i], p);
	}

	TestLog(64);

	printf("\nSpyFree (w/ registered)\n");
	for (int i=0; i<32; i++)
	{
		b = spyfree(vars + i);
		if (!b)
			printf("[%i] Expected 1, got %is\n", i, b);
		if (vars[i] != NULL)
			printf("[%i] Expected NULL, got %p\n", i, vars[i]);
	}
	printf("\nSpyFree (w/ unregistered)\n");
	for (int i=0; i<32; i++)
	{
		spyfree(vars + i);
		if (!b)
			printf("[%i] Expected 1, got %is\n", i, b);
		if (vars[i] != NULL)
			printf("[%i] Expected NULL, got %p\n", i, vars[i]);
	}

	TestLog(32);

	printf("\nSpyFlush\n");
	lu = spyflush();
	if (lu != 32)
		printf("Expected 32, got %lu\n", lu);
	for (int i=32; i<64; i++)
		if (vars[i] != NULL)
			printf("[%i] Expected NULL, got %p\n", i, vars[i]);
	
	TestLog(0);
}
