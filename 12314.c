#include<stdio.h>
#include<math.h>
int main()
{
	double pi;
	int n;
	double a = 1.0;
	scanf("%d", &n);
	for (int i=1; ; i++)
	{
		a += (pow(-1,i)) / (2 * i + 1);

		if (2 * i - 1 >= pow(10, n))
			break;
	}
	pi = 4.0*a;
	printf("%lf", pi);
}