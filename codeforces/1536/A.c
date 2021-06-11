#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int nice = 1;
        while(n--) 
        {
            int x;
            scanf("%d", &x);
            if (x < 0)
                nice = 0;
        }
        if (!nice)
            printf("NO\n");
        else
        {
            printf("YES\n");
            printf("101\n");
            for (int i=0; i<101; i++)
                printf("%d ", i);
            printf("\n");
        }
    }
}
