#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define TABLE_SIZE 42737

typedef struct __ENTRY {
    int num;
    char str[25];
    struct __ENTRY *pNext;
} entry;

entry **create_table();
int find_from_ht(const char *str, entry **table);
void append_to_ht(const char *str, const int num, entry **table);
unsigned int hash(const char *str);

#endif
