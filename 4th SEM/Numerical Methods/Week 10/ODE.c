#include <stdio.h>
#include <math.h>

double func(double x, double y)
{
	return x - (y*y);
}

int main()
{
    int i, com;
    double x0, j, y0, y_2, y2, y_3, diff, corr, val_x, h, x, y, k1, k2, k3, k4, kk;
    printf("\n    ----Ordinary Differential Equations----\n\n");
    printf("Enter the value of X[0] : ");
    scanf("%lf", &x0);
	printf("Enter the value of Y[0] : ");
	scanf("%lf", &y0);
    printf("Enter the step size :  ");
    scanf("%lf", &h);
	printf("Enter the value of X where Y to be calculated :  ");
	scanf("%lf", &val_x);
	x = x0;
    y = y0;
    printf("Enter the Commands:\n Enter 1: Euler\n Enter 2: Modified Euler\n Enter 3: Runge-Kutta\nEnter here : ");
    scanf("%d", &com);
    switch(com)
    {
        case 1: printf("X\t Y\n");
                do
                {
                    printf("%0.3lf\t %lf\n", x, y);
                    y = y + h * func(x, y);
                    x = x + h;
                }while(x != val_x);
                printf("%0.3lf\t %lf\n", x, y);
                break;
        case 2: printf("Enter the number of correct decimal places : ");
                scanf("%lf", &corr);
                y_2 = y;
                y2 = y;
				printf(" X\t  Y\n");
                printf("%0.3lf\t %lf\n", x, y_2);
                do
                {
                    y_3 = y;
                    y_2 = y_3 + (h * 0.5 * (func(x,y) + func(x,y_2)));
                    diff = fabs(y - y_2);
                    y = y2;
                    printf("%0.3lf\t %lf\n", x+h, y_2);
                    do
                    {
                        y_2 = y_3 + (h * 0.5 * (func(x, y2) + func(x + h, y_2)));
                        diff = fabs(y - y_2);
                        y = y_2;
                    }while(diff * pow(10, corr) > 1);
                    x = x + h;
                    y2 = y;
                }while(x != val_x);
                printf("%0.3lf\t %lf\n", x, y);
                break;
        case 3: printf(" X\t  Y\n");
				do
        		{
        			k1 = h * func(x, y);
        			k2 = h * func((x + h/2), (y + k1/2));
        			k3 = h * func((x + h/2), (y + k2/2));
        			k4 = h * func((x + h), (y + k3));
        			kk = (k1 + 2*k2 + 2*k3 + k4)/6;
        			y = y + kk;
        			x = x + h;
        			printf("%0.3lf\t %lf\n", x, y);
        		}while(x != val_x);
                break;
		default : printf("Wrong Input\n");
    }
	return 0;
}
