#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int maxSize)
{
    // store maxSize
    this->maxSize = maxSize;
    // create table
    table = new ArrayList(this->maxSize);
    // fill -1 all elements
    for (int i = 0; i < maxSize; i++)
        table->add(i, -1); // -1 empty slot
    // set curSize = 0
    curSize = 0;
}

HashTable::~HashTable()
{
    delete table;
}

void HashTable::display()
{
    // 0:   4
    // 1:   12
    // 2:   8
    // 3:   -
    // 3/4(75%)
    for (int i = 0; i < maxSize; i++)
    {
        printf("%3d: ", i);
        if (table->get(i) < 0) // -1 empty
            printf("%3s\n", "-");
        else // any value (not empty)
            printf("%3d\n", table->get(i));
    }
    printf("%d/%d (%0.2f%%)\n", curSize, maxSize, (double)curSize / (double)maxSize * 100.0);
}

void HashTable::addKey(int key)
{
    for (int i = 0; i < maxSize; i++)
    {
        int index = hashFunction(key, maxSize, i);
        // check, is slot i empty
        if (table->get(index) < 0)
        { // no collision
            table->set(index, key);
            curSize++;
            break;
        }
        // empty
        cout << "Collision at index " << index << endl;
    }
    // check rehash
    double percent = (double)curSize / (double)maxSize * 100.0;
    if (percent >= REHASH_THRESHOLD)
        rehash();
}

void HashTable::searchKey(int key)
{
    for(int i = 0; i < maxSize; i ++)
    {
        int element = hashFunction(key, maxSize, i);
        if(table->get(element) == key)
        {
            table->get(element);
            cout << "Found index at " << element << endl;
            break;
        }
        cout << "Not found index at " << element << endl; 

    }
}

int HashTable::probFunction(int i)
{
    return i; // f(i) = i linear probing
    // return i * i; // f(i) = i^2 quadratic probing
}

int HashTable::hashFunction(int key, int n, int i)
{
    return (key % n + probFunction(i)) % n;
}

void HashTable::rehash()
{
    int oldSize = maxSize;
    int newSize = REHASH_EXPAND * oldSize;

    // create new table
    ArrayList *newTable = new ArrayList(newSize);
    maxSize = newSize;
    for (int i = 0; i < maxSize; i++)
        newTable->add(i, -1);
    curSize = 0;

    // transfer data from table to new table
    for (int i = 0; i < oldSize; i++)
    {
        if (table->get(i) >= 0) // any value
        {
            int key = table->get(i);

            for (int j = 0; j < maxSize; j++)
            {
                int index = hashFunction(key, maxSize, j);
                if (newTable->get(index) < 0)
                {
                    newTable->set(index, key);
                    curSize++;
                    break;
                }
                // not empty
                cout << "Collision at index " << index << endl;
            }
        }
    }
    // delete ole table
    delete table;
    
    // set table  point to new table 
    table = newTable;
}
