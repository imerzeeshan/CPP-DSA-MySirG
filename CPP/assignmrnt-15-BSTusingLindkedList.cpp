#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
        node *root;
    protected:
        void preorderrec(node*);
        void inorderrec(node*);
        void postorderrec(node*);
        node* deleteNode(node*,int);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        void del(int);
        node* search(int);
        ~BST();
        void showData(node*);
};
void BST::showData(node *ptr)
{
    cout<<endl<<ptr->item;
}
BST::~BST()
{
    while(root)
        del(root->item);
}
node* BST::search(int data)
{
    node *t = root;
    while(t)
    {
        if(t->item == data)
            return t;
        if(data < t->item)
            t = t->left;
        else
            t = t->right;
    }
    return t;
}
node* BST::deleteNode(node *ptr, int data)
{
    if(ptr == NULL) 
        return NULL;
    if(data < ptr->item)
        ptr->right = deleteNode(ptr->left,data);
    else if(data > ptr->item)
        ptr->right = deleteNode(ptr->right,data);
    else
    {
        //No child
        if(ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            return NULL;
        }
        //single child
        if(ptr->left == NULL || ptr->right == NULL)
        {
            node *child = ptr->left ? ptr->left : ptr->right;
            delete ptr;
            return child;
        }
        //two children
        node * pred = ptr->left, *parpred = ptr;
        while(pred->right != NULL)
        {
            parpred = pred;
            pred = pred->right;
        }
        ptr->item = pred->item;
        if(parpred->right == pred)
            parpred->right = deleteNode(pred,pred->item);
        else 
            parpred->left = deleteNode(pred,pred->item);
    }
    return ptr; 
}
void BST::del(int data)
{
    root = deleteNode(root,data);
}
void BST::postorderrec(node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<" "<<ptr->item;
    }
}
void BST::postorder()
{
    postorderrec(root);
}
void BST::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<" "<<ptr->item;
        inorderrec(ptr->right);
    }
}
void BST::inorder()
{
    inorderrec(root);
}
void BST::preorderrec(node *ptr)
{
    if(ptr)
    {
        cout<<" "<<ptr->item;
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder()
{
    preorderrec(root);
}
void BST::insert(int data)
{
    node *ptr;
    node *n = new node;
    n->left = NULL;
    n->item = data;
    n->right = NULL;
    if(root == NULL)
        root = n;
    else
    {
        ptr = root;
        while(n->item != ptr->item)
        {
            if(n->item < ptr->item)
            {
                if(ptr->left != NULL)
                    ptr = ptr->left;
                else{
                    ptr->left = n;
                    break;
                }
            }
            else
            {
                if(ptr->right != NULL)
                    ptr = ptr->right;
                else{
                    ptr->right = n;
                    break;
                }
            }
        }
        if(ptr->item == n->item)
            delete n;
    }
}
bool BST::isEmpty()
{
    return root == NULL;
}
BST::BST()
{
    root = NULL;
}
int main()
{
    BST B;
    B.insert(50);
    B.insert(90);
    B.insert(100);
    B.insert(30);
    B.insert(60);
    B.insert(70);
    B.inorder();
    B.del(90);
    cout<<endl;
    B.postorder();
    cout<<endl;
    B.inorder();
    cout<<endl;
    B.postorder();
    //B.showData(B.search(110));
    cout<<endl;
}