#include<stdio.h>
#include<string.h>

int Prime[1000010],Primer[1000010];
void IsPrime()
{
  int sum = 0;
  for(int i = 2; i <= 1000000; ++i)
    if(Prime[i] == 0)
    {
      ++sum;
      Prime[i] = sum;
      for(int j = i+i; j <= 1000000; j+=i)
        Prime[j] = sum;
    }
}
int main()
{
  IsPrime();
  int N;
  while(~scanf("%d",&N))
  {
    printf("%d\n",Prime[N]);
  }
  return 0;
}
