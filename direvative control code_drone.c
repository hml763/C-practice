#include <Stdio.h>

int main()
{
	float setpoint, processv, error, controlv, propo, integ, errorinteg, deriv, errorderiv;
	int i;
	printf("Input setpoint, proportional, integral, derivative coefficient\n");
	scanf("%f %f %f %f", &setpoint, &propo, &integ, &deriv);
	printf("Process variable | Loop no.\n");
	for(i=0;i<1000;i++)
	{
		error = setpoint - processv;
		errorinteg = error + errorinteg;
		errorderiv = error * deriv;
		controlv = error * propo + integ * errorinteg + errorderiv;
		processv = controlv + processv;
		
		printf("%16f	%8d\n",processv,i+1);
		if((processv/setpoint) < 1.001 && (processv/setpoint) > 0.999) break;
	}
	
	return 0;
	
}
