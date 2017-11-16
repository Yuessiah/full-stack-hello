#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

int find_from_ht(const char *str, entry **table)
{
    int hash_idx = hash(str);
    entry *tmp = table[hash_idx];

    while (tmp) {
        if (!strcmp(str, tmp->str))
            return tmp->num;
        tmp = tmp->pNext;
    }

    return -1;
}

void append_to_ht(const char *str, const int num, entry **table)
{
    unsigned int hash_idx = hash(str);
    entry *newEntry = (entry *) malloc(sizeof(entry));

    newEntry->num = num;
    strcpy(newEntry->str, str);

    newEntry->pNext = table[hash_idx];
    table[hash_idx] = newEntry;
}

entry **create_table()
{
    entry **table;

    table = (entry **) malloc(sizeof(entry *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;

    return table;
}

unsigned int hash(const char *str)
{
    int i = 0;
    unsigned int val = 0;
    while (str[i])
        val = val + (val << 5) + str[i++];

    return val % TABLE_SIZE;
}
