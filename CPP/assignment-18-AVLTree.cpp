#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *right;
    int item;
    node *left;
    int height;
};
class AVL
{
    private:
        node * root;
    protected:
        node* insertion(node*,int);
        node* deletion(node*,int);
        void inorderrec(node*);
        node* minValueNode(node*);
    public:
        AVL(); 
        int getBalanceFactor(node*);
        int getHeight(node*);
        node* leftRotate(node*);
        node* rightRotate(node*);
        void insert(int);
        void updateAnscestorsHeights(node*,int);
        void inorder();
        void del(int);
};
node* AVL::minValueNode(node *ptr)
{
    node *current = ptr;

    /*Loop down to find the leftmost leaf*/
    while(current->left != NULL)
        current = current->left;

    return current;
}
node* AVL::deletion(node* ptr,int data)
{      
    
    if (ptr == NULL) 
        return ptr; 

    if ( data < ptr->item ) 
        ptr->left = deletion(ptr->left, data);  
    else if( data > ptr->item ) 
        ptr->right = deletion(ptr->right,data); 
    else
    { 
        // node with only one child or no child 
        if( (ptr->left == NULL) || (ptr->right == NULL) ) 
        { 
            node *temp = ptr->left ? ptr->left :ptr->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = ptr; 
                ptr = NULL; 
            } 
            else // One child case 
                *ptr = *temp; 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            node* temp = minValueNode(ptr->right); 
  
            ptr->item = temp->item; 
  
            // Delete the inorder successor 
            ptr->right = deletion(ptr->right,temp->item); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (ptr == NULL) 
        return ptr; 
  
    
    ptr->height = 1 + max(getHeight(ptr->left),getHeight(ptr->right)); 
  
    
    int balance = getBalanceFactor(ptr);  
  
    // Left Left Case 
    if (balance > 1 && getBalanceFactor(ptr->left) >= 0) 
        return rightRotate(ptr); 
  
    // Left Right Case 
    if (balance > 1 && getBalanceFactor(ptr->left) < 0) 
    { 
        ptr->left = leftRotate(ptr->left); 
        return rightRotate(ptr); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalanceFactor(ptr->right) <= 0) 
        return leftRotate(ptr); 
  
    // Right Left Case 
    if (balance < -1 && getBalanceFactor(ptr->right) > 0) 
    { 
        ptr->right = rightRotate(ptr->right); 
        return leftRotate(ptr); 
    } 
  
    return ptr; 
 
}
void AVL::del(int data)
{
    root = deletion(root,data);
}

void AVL::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<" "<<ptr->item<<"("<<getBalanceFactor(ptr)<<")";
        inorderrec(ptr->right);
    }
}
void AVL::inorder()
{
    inorderrec(root);
}
void AVL::updateAnscestorsHeights(node *ptr,int data)
{
    if(data == ptr->item)
        ptr->height = 1;
    else
    {
        if(data < ptr->item)
        {
            updateAnscestorsHeights(ptr->left,data);
        }
        else if(data > ptr->item)
        {
            updateAnscestorsHeights(ptr->right,data);
        }
        ptr->height = max(getHeight(ptr->left),getHeight(ptr->right)) + 1;
    }
}
node* AVL::insertion(node *ptr, int data)
{
    if(ptr == NULL)
    {
        node *n = new node;
        n-> left = NULL;
        n->item = data;
        n->right = NULL;
        n->height = 1;
        return n;
    }
    if(data < ptr->item)
        ptr->left = insertion(ptr->left,data);
    else if(data > ptr->item)
        ptr->right = insertion(ptr->right,data);
    else // duplicate value not allowed;
        return ptr;
 
    /* 2. Update height of this ancestor node*/
    ptr->height = 1 + max(getHeight(ptr->left),getHeight(ptr->right));

    /* 3. Get the balance factor of this ancestor node to check whether
        ancestor node to check whether this node became unbalanced*/
    int balance = getBalanceFactor(ptr);

    /*If this node becames unbalanced, then there are 4 cases*/

    //Left Left case
    if(balance > 1 && data < ptr->left->item)
        return rightRotate(ptr);

    //Right Right Case
    if(balance < -1 && data > ptr->right->item)
        return leftRotate(ptr);
    
    //Left Right Case
    if(balance > 1 && data > ptr->left->item)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //Right Left Case
    if(balance < -1 && data < ptr->right->item)
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    /* return the (unchanged) node pointer*/
    return ptr;
}
void AVL::insert(int data)
{
    root = insertion(root,data);
}
node* AVL::rightRotate(node *A)
{
    node *B = A->left;
    node *RT = B->right;

    B->right = A;
    A->left = RT;

    //edit heights
    A->height = max(getHeight(A->left),getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left),getHeight(B->right)) + 1;

    return B;
}
node* AVL::leftRotate(node *A)
{
    node *B = A->right;
    node *LT = B->left;

    B->left = A;
    A->right = LT;

    //edit heights
    A->height = max(getHeight(A->left),getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left),getHeight(B->right)) + 1;

    return B;
}
int AVL::getHeight(node *ptr)
{
    if(ptr == NULL)
        return 0;
    return ptr->height;
}
int AVL::getBalanceFactor(node *ptr)
{
    if(ptr == NULL)
        return 0;
    return getHeight(ptr->left) - getHeight(ptr->right);
}

AVL::AVL()
{
    root = NULL;
}
int max(int a,int b)
{
    return (a>b?a:b);
}
int main()
{
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(90);
    tree.insert(110);

    tree.inorder();

    tree.del(110);
    cout<<endl;
    tree.inorder();
    return 0;
}