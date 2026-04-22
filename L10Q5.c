// Question 5: Lazy Deletion in Linear Probing
//  Logic: Treat -2 as empty space ONLY during insertion. Probe past -2 during search/deletion.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, q;
    if (scanf("%d %d", &m, &q) != 2)
        return 0;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    for (int i = 0; i < q; i++)
    {
        int type, x;
        scanf("%d %d", &type, &x);

        int idx = x % m;
        int start = idx;

        if (type == 1)
        { // Insert
            while (hashTable[idx] != -1 && hashTable[idx] != -2 && hashTable[idx] != x)
            {
                idx = (idx + 1) % m;
                if (idx == start)
                    break;
            }
            if (hashTable[idx] == -1 || hashTable[idx] == -2)
            {
                hashTable[idx] = x;
            }
        }
        else if (type == 2)
        { // Delete
            while (hashTable[idx] != -1)
            {
                if (hashTable[idx] == x)
                {
                    hashTable[idx] = -2;
                    break;
                }
                idx = (idx + 1) % m;
                if (idx == start)
                    break;
            }
        }
        else if (type == 3)
        { // Search
            int found = 0;
            while (hashTable[idx] != -1)
            {
                if (hashTable[idx] == x)
                {
                    found = 1;
                    break;
                }
                idx = (idx + 1) % m;
                if (idx == start)
                    break;
            }
            printf("%s\n", found ? "Found" : "Not Found");
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d ", hashTable[i]);
    }
    printf("\n");

    free(hashTable);
    return 0;
}