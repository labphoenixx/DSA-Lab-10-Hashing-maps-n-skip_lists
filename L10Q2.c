// Question 2: VIP Warehouse Allocation (Linear Probing)
//  Logic: Priority linear probing. If a VIP meets a Regular, swap and keep probing.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    if (scanf("%d %d", &m, &n) != 2)
        return 0;

    int *bays = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        bays[i] = -1; // Initialize as empty

    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        int curr_id = id;
        int idx = curr_id % m;

        while (1)
        {
            // Found empty bay
            if (bays[idx] == -1)
            {
                bays[idx] = curr_id;
                break;
            }
            // Current bay has a Regular, and inserting container is VIP
            else if (bays[idx] < 1000 && curr_id >= 1000)
            {
                int temp = bays[idx];
                bays[idx] = curr_id;
                curr_id = temp; // Kicked out regular becomes the inserting container
            }
            // Move to next index
            idx = (idx + 1) % m;
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d ", bays[i]);
    printf("\n");

    free(bays);
    return 0;
}