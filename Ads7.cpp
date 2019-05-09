#include <iostream>
using namespace std;

template <class T>
class Stack
{
public :
    void push (T value)
    {
        if (!isFull())
        {
            stacknode* a= new stacknode;
            a->data = value ;
            if (Top == NULL)
            {
                Top = a;
                Top -> next =a;
                current_size ++;
            }
            else
            {
                a->next =Top;
                Top = a;
                current_size ++;
            }
        }
        else
        {
            cout << "The list is full; can't push "<<value<<"!\n";
        }
    }

    T pop()
    {

        if (!isEmpty())
        {
            T d =Top->data;
            delete [] Top;
            Top =Top->next;

            current_size --;
            return d;
        }
        else
        {

            cout << "the list is empty; popping NULL!\n";
            return (T)NULL;

        }


    }
    bool isFull ()
    {
        if (current_size==size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty ()
    {
        if (current_size ==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Stack (int newsize )
    {
        cout << "lol\n";
        size = newsize;
    }
    Stack ()
    {
        size =10;
        current_size =0;
    }
    int getsize(){
    return current_size;
    }


private :
    struct stacknode
    {
        T data;
        stacknode * next  ;
    };
    stacknode* Top;
    int current_size=0;
    int size=0;

};
template <class T>
class Queue{
public :

Queue (){

}
void enqueue (T elem){
a.push(elem);
}

 T dequeue(){
     int l = a.getsize();
  for (int i=0; i<l; i++)
    b.push(a.pop());

   T elem = b.pop();

   l=b.getsize();
   for (int i=0; i<l; i++)
    a.push(b.pop());
return elem;
}

display (){
int l = a.getsize();

cout << "Displaying \n";
for (int i=0; i<l; i++)
    cout << dequeue()<<endl;

}

private:
    Stack<T> a;
    Stack<T> b;

};

int main ()
{
    Stack <int> a;

    Stack <int> b (6);
    Queue <int> m;

    m.enqueue (1);
    m.enqueue (2);

    m.display();

    a.push (2);
    a.push (3);
    b.push (4);
    b.push (3);
    b.push (1);
    b.push (5);
    b.push (7);
    b.push (8);
    b.push (9);

   /* cout <<"Dequeue \n";
    cout <<m.dequeue()<<endl;

    cout <<m.dequeue()<<endl;*/

    cout << "popping A \n";
    cout << a.pop()<<endl;
    cout << a.pop()<<endl;
    cout << "popping b\n";
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
    cout << b.pop()<<endl;
}

