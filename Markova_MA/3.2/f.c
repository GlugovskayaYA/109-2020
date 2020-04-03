#include"f.h"
double p (double (*f)(double), double x1, double x3, double eps, ErrorCode *perr)
{
	double x2 = gold(f, x1, x3, eps, perr), u;
	if(perr)
	{
		return 0;
	}
	else
	{
		f3 = (*f)(x3);
		f1 = (*f)(x1);
		f2 = (*f)(x2);
		u = x2 - ((x2 - x1) * (x2 - x1) * (f2 - f3) - (x2 - x3) * (x2 - x3) * (f2 - f1)) / ((x2 - x1) * (f2 - f3) - (x2 - x3) * (f2 - f1)) * 0.5;
		if ((u >= a) && (u <= b))
		{
			*perr = OK;
			return f(u);
		}
		else
		{
			*perr = ER;
			return 0;
		}
	}
}
double gold(double (*f)(double), double a, double b, double eps, ErrorCode *perr)
{
	int check = 1;
    double phi, x1, x2;
    phi = (1+sqrt(5))/2;
    x1 = b - (b - a)/phi;
    x2 = a + (b - a)/phi;
    if((*f)(x1) >= (*f)(x2))
    {
		a = x1;
    }
	else
    {
		b = x2;
    }
	while (fabs(b - a) => eps)
    {
    x1 = b - (b - a)/phi;
    x2 = a + (b - a)/phi;
		if( x1 != a && x2 != b))
		{
			if((*f)(x1) >= (*f)(x2))
			{
				a = x1;
			}
			else
			{
				b = x2;
			}
		}
		else
		{
			return(x1);
			break;
		}
		if(check > T)
		{
			*perr  = ER;
			return 0;
		}
		check++;
    }
    return (a + b)/2;
}