/*ADS8
SHOROUK GABR AWWAD
30002030
*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

enum Color {RED,BLACK};

struct Node
{

    int data;
    Color color;
    Node *right = NULL;
    Node *left = NULL;
    Node *parent = NULL;
};
class RedBlackTree
{
private:
    Node* root = NULL;
protected:
    void rotateleft (Node*& x)
    {

        Node* y = x->right;
        x->right = y->left;
        if (y->left!=NULL)
        {

            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL)
        {
            root =y;
        }
        else if (x==x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right =y;
        }
        y->left=x;
        x->parent=y;
    }
    void rotateright (Node*& node)
    {
        Node * ptr_l = node->left;
        node->left = ptr_l ->right;
        if (node->left != NULL)
        {
            node->left->parent = node;
        }
        ptr_l ->parent = node->parent;
        if (node ->parent == NULL)
        {
            root = ptr_l;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = ptr_l;
        }
        else
        {
            node->parent->right = ptr_l;
        }
        ptr_l->right = node;
        node->parent=ptr_l;
    }
public:
    RedBlackTree() {}
    void Insert(int d)
    {
        Node * z = new Node;
        z->data = d;
        Node * y =NULL;
        Node* x = root;
        while (x != NULL)
        {
            y=x;
            if (z->data < x->data)
            {
                x= x->left;
            }
            else
            {
                x= x->right;
            }

        }
        z->parent = y;
        if (y==NULL)
        {
            root =z;
        }
        else if(z->data < y->data)
        {
            y->left =z;
        }
        else
        {

            y->right = z;
        }
        z->left = NULL;
        z->right = NULL;
        z->color = RED;
// color fix up
        while ( z->parent != NULL && z->parent ->parent != NULL&& z->parent->color ==RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                y = z->parent->parent->right;

                if (y->color == RED)
                {
//first case
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color= RED;
                    z=z->parent->parent;
                }
                else if (z==z->parent->right)
                {
//second case
                    z= z->parent;
                    rotateleft(z);
                    cout << (z->parent!=NULL) << endl;
                    z->parent->color =BLACK;
                    z->parent->parent->color= RED;
                    rotateright(z);
                }


            }
            else
            {
//second main condition
                y = z->parent->parent->left;
                if (y->color == RED)
                {
//first case
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color= RED;
                    z= z->parent->parent;
                }
                else if (z==z->parent->left)
                {
//second case
                    z= z->parent;
                    rotateright(z);
                    z->parent->color =BLACK;
                    z->parent->parent->color= RED;
                    rotateleft(z->parent->parent);
                }

            }
        }
        root->color = BLACK;

    }
//DELET DELETE DELETE DELETE
// Delete function
    void Delete (Node *& z)
    {
        Node* y;
        Node* x;
        if (z->left==NULL && z->right== NULL && z->parent != NULL){
    //first main condition
            if (z== z->parent->left){

                z= z->parent;
                z->left = NULL;

            }else {
                z= z->parent;
                z->right = NULL;
            }
            x=z;

             Node* w;
            //  color fix up
            while (x!= root && x->color==BLACK)
            {
                if (x==x->parent->left)
                {
                    w=x->parent->right;
                    if (w->color ==RED)
                    {//first condition
                        w->color = BLACK;
                        x->parent->color= RED;
                        rotateleft(x->parent);
                        w= x->parent->right;
                    }
                    if (w->left->color == BLACK && w->right->color == BLACK)
                    {// first case
                        w->color = RED;
                        x=x->parent;
                    }
                    else if (w->right->color == BLACK)
                    {// second case
                        w->left->color =BLACK;
                        w->color = RED;
                        rotateright(w);
                        w=x->parent->right;
                    } // third case
                        w->color = x->parent->color;
                        x->parent->color=BLACK;
                        w->right->color=BLACK;
                        rotateleft(x->parent);
                        x=root;

                }else {

// second main condition
                w=x->parent->left;
                    if (w->color ==RED)
                    {// first condition
                        w->color = BLACK;
                        x->parent->color= RED;
                        rotateright(x->parent);
                        w= x->parent->left;
                    }
                    if (w->right->color == BLACK && w->left->color == BLACK)
                    {
                        w->color = RED;
                        x=x->parent;
                    }
                    else if (w->left->color == BLACK)
                    {//second case
                        w->right->color =BLACK;
                        w->color = RED;
                        rotateleft(w);
                        w=x->parent->left;
                   } // third case
                        w->color = x->parent->color;
                        x->parent->color=BLACK;
                        w->left->color=BLACK;
                        rotateright(x->parent);
                        x=root;

                /////////////
                }
            }
            x->color = BLACK;

        }
        else{

         if (z->left ==NULL || z->right == NULL)
        {
           y= z;
        }
        else
        {
            y = successor(z);
        }
        if (y->left!=NULL)
        {
            x=y->left;

        }
        else
        {
            x=y->right;
        }
        x->parent=y->parent;
        if (y->parent==NULL)
        {
            root=x;
        }
        else if (y==y->parent->left)
        {
            y->parent->left =x;
        }
        else
        {
            y->parent->right =x;
        }
        if (y!=z)
        {
            z->data = y->data;
        }
        if (y->color == BLACK)
        {
            Node* w;
            // write the fixup
            while (x!= root && x->color==BLACK)
            {
                if (x==x->parent->left)
                {
                    w=x->parent->right;
                    if (w->color ==RED)
                    {
                        w->color = BLACK;
                        x->parent->color= RED;
                        rotateleft(x->parent);
                        w= x->parent->right;
                    }
                    if (w->left->color == BLACK && w->right->color == BLACK)
                    {
                        w->color = RED;
                        x=x->parent;
                    }
                    else if (w->right->color == BLACK)
                    {
                        w->left->color =BLACK;
                        w->color = RED;
                        rotateright(w);
                        w=x->parent->right;
                    }///
                        w->color = x->parent->color;
                        x->parent->color=BLACK;
                        w->right->color=BLACK;
                        rotateleft(x->parent);
                        x=root;

                }else {
                //////////


                w=x->parent->left;
                    if (w->color ==RED)
                    {
                        w->color = BLACK;
                        x->parent->color= RED;
                        rotateright(x->parent);
                        w= x->parent->left;
                    }
                    if (w->right->color == BLACK && w->left->color == BLACK)
                    {
                        w->color = RED;
                        x=x->parent;
                    }
                    else if (w->left->color == BLACK)
                    {//
                        w->right->color =BLACK;
                        w->color = RED;
                        rotateleft(w);
                        w=x->parent->left;
                   } ///
                        w->color = x->parent->color;
                        x->parent->color=BLACK;
                        w->left->color=BLACK;
                        rotateright(x->parent);
                        x=root;

                /////////////
                }
            }
            x->color = BLACK;
        }
        }
    }

        Node * successor ( Node *& x)
        {
            Node* y;
            if (x-> right != NULL )
            {
                root =x->right;
                return getMinimum();
            }
            y = x-> parent;
            while (y!= NULL && x==y->right )
            {
                x=y;
                y=y->parent;
            }
            return y;
        }
// GET MINIMUM
    Node * getMinimum (){
        Node* ptr = root;
    while (ptr->left != NULL){
    ptr = ptr->left;
    }
    return ptr;
    }
//GET MAXIMUM
    Node * getMaximum ()
    {
        Node * ptr = root;
        while (ptr->right != NULL)
        {
            ptr = ptr->right;
        }
        return ptr;
    }
// Predecessor
   Node* predecessor (Node*& x){
   Node* y;
            if (x-> left != NULL )
            {
                root =x->left;
                return getMaximum();
            }
            y = x-> parent;
            while (y!= NULL && x==y->left )
            {
                x=y;
                y=y->parent;
            }
            return y;
   }
// SEARCH FUNCTION
    Node * Search (int k)
    {
        Node* x = root;

        while (x!= NULL && k != x->data)
        {
            if (k < x->data)
            {
                x=x->left;
            }
            else
            {
                x=x->right;
            }
        }
        return x;
    }
};

int main (){

RedBlackTree A;
A.Insert(4);
A.Insert(-3);
A.Insert(10);
A.Insert(2);
A.Insert(5);

//
Node* b;

unsigned int l = b->color;
b=A.getMinimum();
cout<<"minimum : "<< b->data <<endl;
if (l==0){
    cout << "color: red\n"<<endl;
}else {
    cout << "color: black\n"<<endl;
}
b= A.Search(5);
l = b->color;
cout<<"search : "<< b->data <<endl;
if (l==0){
    cout << "color: red\n"<<endl;
}else {
    cout << "color: black\n"<<endl;
}

b=A.getMaximum();
cout<<"old maximum : "<< b->data <<endl;
A.Delete(b);
l = b->color;
if (l==0){
    cout << "color: red\n"<<endl;
}else if (l==1){
    cout << "color: black\n"<<endl;
}


b=A.getMaximum();
l = b->color;
cout<<"new maximum : "<< b->data <<endl;
if (l==0){
    cout << "color: red\n"<<endl;
}else {
    cout << "color: black\n"<<endl;
}
b= A.Search(2);
l = b->color;
cout<<"search : "<< b->data <<endl;
if (l==0){
    cout << "color: red\n"<<endl;
}else {
    cout << "color: black\n"<<endl;
}
}

/* references :
the pseudo codes on the slides
the book introduction to algorithms
*/
