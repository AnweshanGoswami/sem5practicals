# include <stdio.h>
# include <math.h>
# include <stdlib.h> // Don't forget to include this

main()
{
  int n,N; // Sample size and number of simulations
  long double theta, msum=0.0, mse; // long double is used to increase precision
  int i,j;
  printf("Enter the number of simulations");
  scanf("%d", &N);
  printf("Enter the sample size");
  scanf("%d", &n);
  printf("Enter the value of theta");
  scanf("%Lf", &theta);
  //Simulation starts to calculate MSE
  for(i=0;i<N;i++)
    {
      //Now we calculate the estimates for each sample of size n
      long double sum = 0.0; // we declare this inside the i loop because it needs to be reset at every iteration of the simulation
      for(j=0;j<n;j++)
        sum += (-1/theta)*log(1-((double)rand()/RAND_MAX));
      // We use the (double) for explicit conversion to prevent errors
      //rand() generates random uniform numbers
      // by dividing by RAND_MAX, we get a uniform number betwen 0 and 1
      // The entire RHS is an exponential random variable that we obtained using the inverse CDF function.
       float thetahat = n/sum; // we declare this inside the i loop because it needs to be reset at every iteration of the simulation. Also, thetahat=1/mean=s/sum
      msum += pow((thetahat-theta),2);
    }
  mse = msum/n;
    printf("The MSE with theta=%Lf and sample size = %n is = %Lf", theta, n, mse);
  return 0;
}
// now repeat it for different values of n and theta
