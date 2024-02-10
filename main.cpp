/***************************
 * ID: 65020751
 * NAME: MR.Thanathip Isariyathamakul
 * DESCRIPTION: Testing for HashTable
 ***************************/

#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{

    HashTable hash;
    int choice, key;
    do
    {
        cout << endl;
        hash.display();
        cout << "_______________________" << endl;
        cout << " 1: Add key, addKey()" << endl;
        cout << " 2: Search key, searchKey()" << endl;
        cout << " 0: exit" << endl;

        // user chioce
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter your key : ";
            cin >> key;
            cout << endl;
            hash.addKey(key);
            break;

        case 2:
            cout << "Enter your key: ";
            cin >> key;
            cout << endl;
            hash.searchKey(key);
            break;

        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Wrong choice, try again..." << endl;
        }

    } while (choice != 0);
    return 0;
}