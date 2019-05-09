//question 2.c
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class List
{
public:

    int data;
    List* next;
    List* head;
    List**point = &head;
    void push( int d)
    {
        List* temp = new List;
        temp->data = d;
        temp->next = head;
        head = temp;
        point =&head;
    }

    int countList()
    {
        int count = 0;
        List *temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void printList()
    {
        List* temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    List ()
    {
    }
};


class Tree
{
public:
    int data;
    Tree* left;
    Tree* right;
};
Tree * sortRecursion(List **my_list, int n);

Tree* sort_func(List* my_list)
{
    int n = my_list->countList();
    return sortRecursion(my_list->point, n);
}


Tree* sortRecursion(List **my_list, int n)
{

    if (n <= 0)
        return NULL;

    Tree *left = sortRecursion(my_list, n/2);
    Tree *root = new Tree();
    root->data = (*my_list)->data;
    root->left = left;
    (*my_list) = (*my_list)->next;
    root->right = sortRecursion(my_list, n - n /2-1 );
    return root;
}


void display(Tree* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    display(node->right);
    display(node->left);
}
int main()
{

    List my_list;
    my_list.head=NULL;
    my_list.push( 8);
    my_list.push( 7);
    my_list.push( 6);
    my_list.push( 5);
    my_list.push( 4);
    my_list.push( 3);
    my_list.push( 2);
    my_list.push( 1);


    my_list.printList();
    cout << "\ndisplaying tree\n";

    Tree *T = sort_func(&my_list);
    display(T);
}
