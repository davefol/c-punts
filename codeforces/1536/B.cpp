#include <stdio.h>

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int found = 0;
        char ans[3];
        int ansLen = 1;
        char a[1000];
        int lenOne[26];
        for (int i=0; i<26; i++)
            lenOne[i] = 0;
        int lenTwo[26][26];
        for (int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                lenTwo[i][j] = 0;
        int lenThree[26][26][26];
        for (int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                for(int k=0; k <26; k++)
                    lenThree[i][j][k] = 0;

        int n;
        scanf("%d\n", &n);
        for (int i=0; i<n; i++)
            a[i] = getchar();
        for (int i=0; i<n; i++)
            lenOne[a[i] - 'a']++;
        for (int i=0; i<26; i++)
        {
            if (!lenOne[i])
            {
                found = 1;
                ans[0] = (char)(i + 'a');
                break;
            }
        }
        if (found)
        {
            for (int i=0; i<ansLen; i++)
            {
                printf("%c", ans[i]);
            }
            printf("\n");
            continue;
        }
        for (int i=0; i<n-1; i++)
            lenTwo[a[i] - 'a'][a[i+1] - 'a']++;
        for (int i=0; i<26; i++)
        {
            for (int j=0; j<26; j++)
            {
                if (!lenTwo[i][j])
                {
                    found = 1;
                    ans[0] = char(i + 'a');
                    ans[1] = char(j + 'a');
                    ansLen = 2;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
        {
            for (int i=0; i<ansLen; i++)
            {
                printf("%c", ans[i]);
            }
            printf("\n");
            continue;
        }
        for (int i=0; i<n-2; i++)
            lenThree[a[i] - 'a'][a[i+1] - 'a'][a[i+2] - 'a']++;
        for (int i=0; i<26; i++)
        {
            for (int j=0; j<26; j++)
            {
                for (int k=0; k<26; k++)
                {
                    if (!lenThree[i][j][k])
                    {
                        found = 1;
                        ans[0] = char(i + 'a');
                        ans[1] = char(j + 'a');
                        ans[2] = char(k + 'a');
                        ansLen = 3;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
        for (int i=0; i<ansLen; i++)
        {
            printf("%c", ans[i]);
        }
        printf("\n");
        continue;
    }
    return 0;
}
