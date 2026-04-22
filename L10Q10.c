// Logic: O(N+M) Rolling Hash using strictly the formula and Base tracking method defined in the PDF.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 29
#define MOD 1000000007

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    char *T = (char *)malloc((n + 1) * sizeof(char));
    char *P = (char *)malloc((m + 1) * sizeof(char));
    scanf("%s", T);
    scanf("%s", P);

    if (n < m)
    {
        return 0;
    }

    long long *power = (long long *)malloc((n + 1) * sizeof(long long));
    power[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * BASE) % MOD;
    }

    long long Hp = 0;
    for (int i = 0; i < m; i++)
    {
        long long val = P[i] - 'a' + 1;
        Hp = (Hp + (val * power[i]) % MOD) % MOD;
    }

    long long currentHash = 0;
    for (int i = 0; i < m; i++)
    {
        long long val = T[i] - 'a' + 1;
        currentHash = (currentHash + (val * power[i]) % MOD) % MOD;
    }

    // Compare first window: We must shift Hp by power[0] (which is 1)
    if (currentHash == (Hp * power[0]) % MOD)
    {
        printf("0 ");
    }

    for (int i = 1; i <= n - m; i++)
    {
        long long old_val = T[i - 1] - 'a' + 1;
        long long new_val = T[i + m - 1] - 'a' + 1;

        // Remove the old character's contribution
        currentHash = (currentHash - (old_val * power[i - 1]) % MOD + MOD) % MOD;
        // Add the new character's contribution
        currentHash = (currentHash + (new_val * power[i + m - 1]) % MOD) % MOD;

        // To compare cleanly without division/modular inverse, we shift the pattern's hash up by power[i]
        if (currentHash == (Hp * power[i]) % MOD)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(T);
    free(P);
    free(power);
    return 0;
}