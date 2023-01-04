#include <math.h>
#include <stdio.h>
#include <complex.h>

int	main(void)
{
	complex	c;
	complex	z;
	int k = 0;

	z = 0;
	c = 0.1 + 0.1*I;
	while (k < 100 && z != INFINITY)
	{
		z = pow(z, 2) + c;
		k++;
	}
	return (0);
}