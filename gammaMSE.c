# include <stdio.h>
# include <math.h>
# include <stdlib.h> // Don't forget to include this

int main() {
  int n, NN; // Sample size and number of simulations
  long double alpha = 3, beta, suma = 0.0, sumb = 0.0, msea, mseb; //for some reason long double na use karu toh nhi a rha mera
  int i, j, k;
  printf("Enter the number of simulations");
  scanf("%d", &NN);
  printf("Enter the sample size");
  scanf("%d", &n);
  printf("Enter the value of beta");
  scanf("%Lf", &beta);

  //Simulation starts to calculate MSE
  for (i = 0; i < NN; i++) {
    double sum = 0.0, sumsq = 0.0; //Vlaue is reset at every iteration, so declared inside i loop
    for (j = 0; j < n; j++) //each sample
        {
      double g = 0;
      for (k = 0; k < alpha; k++)
         g += (double) (-1 / beta)* log(1 - ((double) rand()/RAND_MAX)); //converting uniform to exp and then adding them to form gamma
      sum += g;
      sumsq += g * g;
    }
    double xbar = sum / n;
    double var = sumsq / n - xbar * xbar;
    suma += pow((xbar * xbar / var - alpha), 2);
    sumb += pow((xbar / var - beta), 2);
  }
  msea = suma / n;
  mseb = sumb / n;
  printf("MSE of alpha is = %Lf\n", msea);
  printf("MSE of beta is = %Lf\n", mseb);

  return 0;
}
