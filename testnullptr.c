
#include "types.h"
#include "stat.h"
#include "user.h"



#define NULL ((void *) 0)


int main(int argc, char const *argv[])
{
	int a = 5;
	int *pa = &a;
	pa = NULL;
	int b = *pa;
	b *= 2;
	printf(1, "The value of nullptr is %p\n", *pa);
	exit();
}