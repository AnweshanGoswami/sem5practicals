# include <stdio.h>
# include <math.h>

float mean(float x[], int size)
{
  float sum = 0.0;
  for (int i=0; i<size;i++)
    sum += x[i];
  return sum/size;
}

float sumsq(float x[], int size)
{
  float sum = 0.0;
  for (int i=0; i<size;i++)
    sum += pow(x[i]-mean(x,size),2);
  return sum;
}

void input(int n, float a[n])
{
    printf("Enter the values one by one: ");
    for (int i = 0; i<n;i++)
        scanf("%f", &a[i]); 
}

void t_check(float x)// Make sure to write this function before each of the t-tests. That is because it is of void type. If the t-test is done before the checking function is declared, then it assumes it's datatype to be "int", and we get an error. So either write the t-check function before those functions, or just define it at the beginning of the program
{
  float t_tab;
  printf("Enter the tabulated value of t ");
  scanf("%f",&t_tab);
  if (x<t_tab)
    printf("We do not have enough evidence to reject the null hypothesis");
  else
    printf("Reject the null hypothesis");
}


void t_diff_of_means()
{
    float x=0.0,y=0.0,s1=0.0,s2=0.0,S=0.0,t=0.0;
    int n,m;
    printf("Enter the number of variables in population 1: ");
    scanf("%d", &n);
    float a[n];
    input(n, a);
    printf("Enter the number of variables in population 2: ");
    scanf("%d", &m);
    float b[m];
    input(m, b);
    x = mean(a,n);
    y = mean(b,m);
    s1 = sumsq(a, n);
    s2 = sumsq(b, m);
    S  = sqrt((s1+s2)/(n+m-2));
    t = (x-y)/(S*sqrt(1.0/n+1.0/m));
    t_check(t);
}

void t_single_mean()
{
  float x=0.0,mew=0.0,S=0.0,t=0.0;
  int n;
  printf("Enter the number of variables in the population: ");
  scanf("%d", &n);
  float a[n];
  input(n, a);
  printf("Enter the value of population mean");
  scanf("%d", &mew);
  x = mean(a,n);
  S = sqrt(sumsq(a, n)/(n-1));
  t = (x-mew)/(S/sqrt(n));
  t_check(t);
}

void paired_t()
{
  float d=0.0,S=0.0,t=0.0;
  int n;
  printf("Enter the number of variables in population: ");
  scanf("%d", &n);
  float a[n];
  input(n, a);
  d = mean(a, n);
  S = sqrt(sumsq(a, n)/(n-1));
  t = d/(S/sqrt(n));
  t_check(t);
}

void t_co()
{
  int n; float r,t;
  printf("Enter the observed correlation coefficient: ");
  scanf("&f", &r);
  printf("Enter the number of elements");
  scanf("&d", &n);
  t = r * sqrt(n-2)/sqrt(1-r*r);
  t_check(t);
}

int main(void) 
{
  int n;
  printf("Which test do you want to do?\n");
  printf("1. t-test for single mean\n");
  printf("2. t-test for difference of means\n");
  printf("3. Paired t-test\n");
  printf("4. t-test for observed correlation coefficient\n");
  scanf("%d", &n);
  if (n == 1)
    t_single_mean();
  else if (n == 2)
    t_diff_of_means();
  else if(n == 3)
    paired_t();
  else if( n == 4)
    t_co();
  else
    printf("Wrong Choice");
return 0;
}