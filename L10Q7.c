// Question 7: Skip List Search Path Length
//  Logic: A deterministic skip list acts like an array with leaps of 2^lvl. Steps are counted strictly by moves.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    if (scanf("%d %d", &n, &q) != 2)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find Max Level such that 2^max_level < N
    int max_lvl = 0;
    while ((1 << (max_lvl + 1)) < n)
    {
        max_lvl++;
    }

    for (int i = 0; i < q; i++)
    {
        int target;
        scanf("%d", &target);

        int curr = 0;
        int steps = 0;

        for (int lvl = max_lvl; lvl >= 0; lvl--)
        {
            int leap = 1 << lvl;

            // Move right as long as it's within bounds and <= target
            while (curr + leap < n && arr[curr + leap] <= target)
            {
                curr += leap;
                steps++;
            }
            // Move down if not at bottom level
            if (lvl > 0)
                steps++;
        }

        if (arr[curr] == target)
        {
            printf("%d ", steps);
        }
        else
        {
            printf("-1 ");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}