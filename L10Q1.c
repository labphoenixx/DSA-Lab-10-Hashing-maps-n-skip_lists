// 1)  Sorted Intersector (Chaining with Ordered Insert)

#include <stdio.h>
#include <stdlib.h>

// 1) Define a Node for our chained linked lists
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 2) Funcn to insert a value into hash table (in sorted order, asc)
void insertSorted(Node **hashTable, int m, int value)
{
    int idx = value % m; // calclualting hash index

    // Now, create the node:
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // There are 2 cases
    // Case 1: when the List is empty ORRR the new value is
    // smaller than the head's value
    if (hashTable[idx] == NULL || hashTable[idx]->data >= value)
    {
        newNode->next = hashTable[idx];
        hashTable[idx] = newNode;
        return;
    }

    // Case 2: Traverse to find correct postion insorted order
    Node *current = hashTable[idx];
    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    // Insert the newNode after current
    newNode->next = current->next;
    current->next = newNode;
}

// 3) Function to search a value in hashTable
int search(Node **hashTable, int m, int value)
{
    int idx = value % m;
    // cuz that's our hash function
    Node *current = hashTable[idx];

    while (current != NULL)
    {
        if (current->data == value)
            return 1;

        if (current->data > value)
            return 0;

        current = current->next;
        // imp, don't forget
    }

    return 0; // cuz if you exit the loop, current is 0 thus exit loop
}

int main()
{
    int m, nA, nB;

    // read'em
    scanf("%d %d %d", &m, &nA, &nB);

    // Initialize hasTable pointers to null after creating it ofc
    Node **hashTable = (Node **)malloc(m * sizeof(Node *));
    for (int i = 0; i < m; i++)
        hashTable[i] = NULL;

    // Read database Aand insert it to hashTable
    for (int i = 0; i < nA; i++)
    {
        int value;
        scanf("%d", &value);
        insertSorted(hashTable, m, value);
    }

    // Array to store the matching intersections in order
    int *result = (int *)malloc(nB * sizeof(int));
    int resultCount = 0;

    // read database B, search in hasTable and collect matches
    for (int i = 0; i < nB; i++)
    {
        int val;
        scanf("%d", &val);
        if (search(hashTable, m, val))
            result[resultCount++] = val;
    }

    // print o/p
    if (resultCount == 0)
    {
        printf("Intersection : None\n");
    }

    else
    {
        printf("Intersection:");
        for (int i = 0; i < resultCount; i++)
        {
            printf(" %d", result[i]);
        }
        printf("\n");
    }

    free(result);
    free(hashTable);

    return 0;
}