#include <stdio.h>
#include <ctype.h>

int main()
{
    int a[1000];
    int b[1000];
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d\n", &n, &m);
        int existsOne = 0;
        for (int i=0; i<n; i++)
        {
            a[i] = getchar() - '0';
            existsOne = existsOne | a[i];
        }
        if (!existsOne)
        {
            for (int i=0; i<n; i++)
            {
                printf("%d", a[i]);
            }
            printf("\n");
            continue;
        }
        for (int i=0; i<m; i++)
        {
            short existsZero = 0;
            for (int j=0; j<n; j++) 
            {
                short left = 0;
                short right = 0;
                if (!a[j])
                {
                    existsZero = 1;
                    if (j - 1 >= 0)
                        left = a[j-1];
                    if (j + 1 < n)
                        right = a[j+1];
                    if (left ^ right)
                        b[j] = 1;
                    else
                        b[j] = 0;
                }
                else
                    b[j] = 1;
            }
            short hasChanged = 0;
            for (int j=0; j<n; j++)
            {
                if (a[j] != b[j])
                    hasChanged = hasChanged | 1;
                a[j] = b[j];
            }
            if (!existsZero)
                break;
            if (!hasChanged)
                break;
        }
        for (int i=0; i<n; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
