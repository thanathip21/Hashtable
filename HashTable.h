#if !defined(_HASHTABLE_H_)
#define _HASHTABLE_H_
#include "../ArrayList/ArrayList.h"

#define INIT_TABLE_SIZE 4
#define REHASH_THRESHOLD 80.0
#define REHASH_EXPAND 2.0


class HashTable 
{
private:
    ArrayList *table;
    int curSize;
    int maxSize;
public:
    HashTable(int maxSize = INIT_TABLE_SIZE);
    ~HashTable();

    void display();
    void addKey(int key);
    void searchKey(int key); 

private:
    int probFunction(int i);
    int hashFunction(int key, int n, int i);
    void rehash();
};



#endif // _HASHTABLE_H_
