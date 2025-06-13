#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10007 // Número primo para reduzir colisões

typedef struct Entry
{
    int key;
    int index;
    struct Entry *next;
} Entry;

Entry *hash_table[TABLE_SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % TABLE_SIZE;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    // Limpa a tabela hash
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int h = hash(nums[i]);
        Entry *e = hash_table[h];
        while (e)
        {
            if (e->key == nums[i])
            {
                if (i - e->index <= k)
                {
                    return true; // Encontrou duplicata dentro de k
                }
                else
                {
                    e->index = i; // Atualiza índice mesmo que não satisfaça k
                    break;
                }
            }
            e = e->next;
        }
        if (!e)
        {
            // Inserir novo
            Entry *new_entry = (Entry *)malloc(sizeof(Entry));
            new_entry->key = nums[i];
            new_entry->index = i;
            new_entry->next = hash_table[h];
            hash_table[h] = new_entry;
        }
    }
    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 1};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    if (containsNearbyDuplicate(nums, size, k))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
