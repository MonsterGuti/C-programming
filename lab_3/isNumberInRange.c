#include <stdio.h>

void Found(int a, int b, int c, int d, int e, int f)
{
   if (a==f||b==f||c==f||d==f||e==f)
   {
       printf("Found");
   }
   else
   {
       printf("Not Found");
   }

}

int main()
{
    int a, b, c, d, e,f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e,&f);
    Found(a,b,c,d,e,f);
}