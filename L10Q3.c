// 3)  E-Commerce Shopping Cart (Implementing a Map)
#include <stdio.h>
#include <stdlib.h>

// Define map node
typedef struct Node
{
    int key;   // product id
    int value; // quantity
    struct Node *next;
} Node;

// 2) Function to insert or update
// use while loops
void insertOrUpdate(Node **hashTable, int m, int id, int qty)
{
    int idx = id % m; // Calculate hash index
    // hash function = modulus
    Node *current = hashTable[idx];

    // Case 1: If empty, create
    if (current == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = id;
        newNode->value = qty;
        newNode->next = NULL;
        hashTable[idx] = newNode;
        return;
    }

    // Case 2: Traverse and insert or update
    // This is kinda updatable
    while (current != NULL)
    {
        // If you find the key, update
        if (current->key == id)
        {
            current->value += qty;
            return;
        }

        // Or else stop exactly at last node to insert
        if (current->next == NULL)
            break;

        current = current->next;
        // iterator (? if that makes sense)
    }

    // Insert it now
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = id;
    newNode->value = qty;
    newNode->next = NULL;
    current->next = newNode;
}

// 3) Print map function
void printMap(Node **hashTable, int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("Index %d:", i);
        Node *current = hashTable[i];

        if (current == NULL)
        {
            printf("Empty\n");
        }
        else
        {
            while (current != NULL)
            {
                printf("[%d:%d] ", current->key, current->value);

                if (current->next != NULL)
                {
                    printf("-> ");
                }

                current = current->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    int m, q;
    scanf("%d %d", &m, &q);

    // Initialize hashtable to null using calloc
    Node **hashTable = (Node **)calloc(m, sizeof(Node *));

    for (int i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);

        if (query == 1)
        {
            int id, qty;
            scanf("%d %d", &id, &qty);
            insertOrUpdate(hashTable, m, id, qty);
        }

        else if (query == 2)
        {
            printMap(hashTable, m);
        }
    }

    return 0;
}