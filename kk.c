#include<stdio.h>

/* definition of constants */
#define Radius 0.995
#define Cx 0
#define Cy 0
#define Side 0.01
#define M 700
#define Num 64

/* main program */
int main()
{

	int p, q, n, w;
	double x, y, xx, yy, Incx, Incy;
	
	FILE *fp;
	
	fp = fopen("Newt.raw","w");
	
	for (p = 1; p <= M; p++)
	{
		Incy = - Side + 2*Side/M*p;
		
			printf("%i %%\n", p*100/M);

		
		for (q = 1; q <= M; q++)
		{
			Incx = - Side + 2*Side/M*q;
			
		x = Incx;
		y = Incy;
		w = 0;
		
			for ( n = 1; n <= Num; ++n)
			{
				xx = 2*x/3 - (x*x - y*y)/(x*x + y*y)/(x*x + y*y)/3;
				yy = 2*y/3 + 2*x*y/(x*x + y*y)/(x*x + y*y)/3;
				
				x = xx;
				y = yy;
				
				if ( (x-Cx)*(x-Cx) + (y-Cy)*(y-Cy) < Radius )
					{
						w = n;
					}
			 }
			
		
					
		fprintf(fp, "%c", 255*w*w/Num/Num );
		}
	}
	fclose(fp);
    return(0);
}
