#include <iostream>
using namespace std;


struct Node
{
  int data;
  struct Node * left;
  struct Node * right;
  struct Node * prev;
  
  Node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
  }

};

void BST (int num, Node * p)
{
     

   if(num < p ->data && p->left == NULL)
    {
     p->left = new Node(num);
     p;
    }
    else if (num > p ->data && p->right == NULL)
    {
      p ->right = new Node(num);
      p;
    }
    else if(num < p ->data)
    {
      p = p->left;
      BST(num, p);
    }
    else
    {
      p = p ->right;
      BST(num, p);
    }

}

void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
}



int main() 
{
  int num, Top;
  cin >> Top;
  struct Node * root = new Node(Top);
  struct Node * p ;
  p = root;

  while ( cin >> num)
  {
   BST(num, p);
    
  } 

  printPostorder(p);
  
}
