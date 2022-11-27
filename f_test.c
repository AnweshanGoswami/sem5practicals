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

void f_check(float x)// Make sure to write this function before each of the t-tests. That is because it is of void type. If the t-test is done before the checking function is declared, then it assumes it's datatype to be "int", and we get an error. So either write the t-check function before those functions, or just define it at the beginning of the program
{
  float f_tab;
  printf("Enter the tabulated value of f ");
  scanf("%f",&f_tab);
  if (x<f_tab)
    printf("We do not have enough evidence to reject the null hypothesis");
  else
    printf("Reject the null hypothesis");
}

void f_test()
{
    float s1=0.0,s2=0.0,f=0.0;
    int n,m;
    printf("Enter the number of variables in population 1: ");
    scanf("%d", &n);
    float a[n];
    input(n, a);
    printf("Enter the number of variables in population 2: ");
    scanf("%d", &m);
    float b[m];
    input(m, b);
    s1 = sumsq(a, n)/(n-1);
    s2 = sumsq(b, m)/(m-1);
    f = s1/s2;
    f_check(f);
}

main()
{
    f_test();
    return 0;
}