#include <math.h>

//Professor Ethan Miller's square root code from Piazza
double square_root (double x) {

  double m, l = 0.0;
  double h = (x < 1) ? 1 : x;
  double range = 20;
  do {
    m = (l + h) / 2.0;
    if (m * m < x) {
      l = m;
    } else {
      h = m;
    }
    
   range = (l > h) ? l - h : h - l;
  } while (range > 1e-10);
  return m;
}

double my_abs(double x){
	
	// If x is negative, make it positive
	if (x < 0){
	return -x;
	}
	return x;
}


//Professor Ethan Miller's Exp fucntion from asg2.pdf
static double Exp(double x) {
	double EPSILON = 10e-10;
	double t = 1.0;
	double y = 1.0;
	for (double k = 1.0; t > EPSILON; k += 1.0) {
		t *= x / k;
		y += t;
		}
	return y;
}

double my_sin(double x) {
	
	int n_cap = 20;
	
	// Fixing x to be in range [0,2pi]
	if (x > (2 * M_PI)){
		while (x>(2*M_PI)){
			x = x - 2.0*M_PI;
		}
	}
	else if (x < 0){
		while (x < 0){
			x = x + 2.0*M_PI;
		}
	}
	
	//creating variables for loop
        double approx = x;
        double approx_term = x;
        	
        //Creating and adding terms based on taylor series sin approximation.
	for (int n = 1; n < n_cap; n++)
	{
		approx_term = approx_term * ( (x/(2.0*(double)n)) * (x /((2.0*(double)n)+1)));
		if ((n % 2) == 1){
			approx = approx - approx_term;	
		}
		else{
			approx = approx + approx_term;
		}
	}
	return approx;
}

double my_cos(double x){
	//Since cos is sin but shifted, we just call sin with the shift of 3pi/2 then flipped over x axis 
	return -my_sin(x + (3*M_PI/2));

}

double my_arcsin(double x){
	
	//Making sure that if x is very close to 1, it is over
	double z_n = 0;
	double z_n1 = 0;
	
	if (my_abs(x)==1.0){
		return x * M_PI/2;
	}
	
	//Loop finding better values of z until the difference is less than 10e-10
	do{
		z_n1 = z_n;
		z_n = ((z_n1) - ((my_sin(z_n1) - x)/(cos(z_n1))));
	}while (my_abs(z_n - z_n1) >= 10e-10);

	return z_n;
}

double my_arccos(double x){
	
	//Use the equivalence between arccos and arcsin to be able to use arcsin
	return ((M_PI/2.0) - my_arcsin(x));
}

double my_arctan(double x){
	
	//Returning arcsin(x/(sqrt(x^2 + 1)))
	double denom = (x*x) + 1;
	double val = square_root(denom);
	double re = x / val;
	return (my_arcsin(re));
}

double my_log(double x){
	
	double a_n = 1.0;
	double a_n1 = 1.0;
	double e_a;
	
	
	//Loop finding better values of a until the new guess is less than 10e-10;
	do{
		a_n = a_n1;
		e_a = Exp(a_n);
		
		a_n1 = a_n + ((x - e_a)/e_a);

	}while(my_abs(a_n - a_n1) > 10e-10);	
	return a_n1;
}
