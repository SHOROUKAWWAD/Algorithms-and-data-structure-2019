/*SHOROUK G. AWWAD
30002030

*/
#include <iostream>
#include <cstdlib>

using namespace std;
// class node
class Node
{

public:
    int key;
    int value;
    // constructor
    Node (int key1, int value1)
    {
        key = key1;
        value = value1;

    }
};

class HashTable
{

private:
    Node**arr ;
    int maxSize;
    int currentSize;
public:
    // constructor with initiations
    HashTable ()
    {
        maxSize =10;
        currentSize =0;
        arr=new Node*[maxSize];
        for (int i =0; i<maxSize; i++)
        {

            arr[i]= NULL;
        }
    }
    // hash code function gives a small number as an index
    int  hashCode (int  key)
    {

        key = key % maxSize;
        return key;
    }
    // INSERT
    void insertNode(int key, int value)
    {
        // creating new node
        Node* node = new Node(key,value);
        if (currentSize >= maxSize)
        {
            cout << "the array is full!\n";
            return;
        }


        // finding a suitable index
        int index = hashCode (key);

        for (int i=0; i<maxSize; i++)
        {
            index=index+i;

            if (arr[index]== NULL)
            {

                arr[index]=node;
                currentSize++;

                return;
            }
        }

    }

    void get (int key)
    {
        // empty array condition
        if (isEmpty()== true)
        {
            cout << "the array is empty\n!";
            return;
        }
        // hashing the index
        int i= hashCode(key);

        // non-existent element
        if (arr[i]== NULL)
        {
            cout << "the key node isn't found!\n";
            return;
        }
        else
        {
// incrementing the index till it finds the key
            while(arr[i]->key!= key&& i<maxSize)
            {
                i=i+1;
            }
            if (i== maxSize)
            {
                cout << "the key doesn't exist!\n";
                return;
            }
            int d = arr[i]->value;
            cout << "the key value is: "<<d<<endl;
        }
    }
// empty check
    bool isEmpty()
    {
        if (currentSize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main ()
{
    HashTable a;
    a.insertNode (3,5);
    a.insertNode (13,8);
    a.insertNode (17,90);
    a.insertNode (19,20);
    a.get (3);
    a.get(13);
    a.get (17);
    a.get(10);
    a.get(19);


}
