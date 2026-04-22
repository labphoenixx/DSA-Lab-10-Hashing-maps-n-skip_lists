// Question 4 : Double Hashing
//  Logic: probe = (h1(k) + i * h2(k)) % M. Increment i on collision.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M, R, N;
    if (scanf("%d %d", &M, &R) != 2)
        return 0;
    if (scanf("%d", &N) != 1)
        return 0;

    int *hashTable = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++)
        hashTable[i] = -1;

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        int h1 = k % M;
        int h2 = R - (k % R);

        int probe_counter = 0;
        while (probe_counter < M)
        {
            int idx = (h1 + probe_counter * h2) % M;
            if (hashTable[idx] == -1)
            {
                hashTable[idx] = k;
                break;
            }
            probe_counter++;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (i == M - 1)
            printf("%d", hashTable[i]);
        else
            printf("%d ", hashTable[i]);
    }
    printf("\n");

    free(hashTable);
    return 0;
}