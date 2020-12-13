#include <stdio.h>
float const eps = 0.0000001;

float fabs(float x)
{
	if (x >= 0)
		return x;
	else
		return -x;
} 

float exp(float x)
{
	float a = 1.0;
	float s = 1.0;
	float n = 1.0;
	while (a > eps) 
	{
		a *= x / n;
		s += a;
		n += 1.0;
	}
	return s;
}

float ln(float x) 
{
	float s = 0.0;
	if (x > 0 && x <= 2)
	{
		x -= 1;
		float n = 1.0;
		float z = 1.0;
		float p = x;
		while (fabs(z * p / n) > eps)
		{
			s += z * p / n;
			z = -z;
			p *= x;
			n += 1.0;
		}
		return s;
	}
	if (x <= 0)
		return -1;
	if (x > 2)
	{
		x -= 1;
		float a = 1 / (2 * x + 1);
		float k = 1.0;
		float p = 0.0;
		while (fabs(2 * a / k) > eps)
		{
			s += 2 * a / k;
			k += 2;
			a /= ((2 * x + 1) * (2 * x + 1));
			p += 1;

		}
		return s + ln(x);
	}
}

float pow(float x, float n) {
	return exp(n * ln(x));
}

int inArr(float* a, int size)
{
	printf("Enter %d natural numbers: \n", size);
	for (int i = 0; i < size; i++, a++)
	{
		if (scanf("%f", a) != 1)
			return 1;
	}
	return 0;
}

float geom(float* a, int size)
{
	float p = 1.0;
	float n = 0.0;
	for (int i = 0; i < size; i++, a++, n++)
	{
		p *= *a;
	}
	if (p <= 0)
		return -1;
	return pow(p, 1.0 / n);
}