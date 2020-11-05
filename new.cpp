#include <iostream>
#include <vector>
using namespace std;
 
class Node {
    public:
    int data;
    Node *left, *right;
 
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    vector<int> ct;
    Node *root;
 
    BST(){
        root = NULL;
    }
 
    void insert(Node *&node, int data){
        if(node == NULL) {
            node = new Node(data);
        }
 
        if (data == node -> data) {
          return;
        }
 
        if(data < node->data) {
            insert(node->left, data);
        } else
        {
            insert(node->right, data);
        }
        return;
    }
 
    void inOrder (Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        if((node->left != NULL) && (node->right == NULL) || (node->left == NULL) && (node->right != NULL) )
        cout << node->data << endl;
        inOrder(node->right);
     }
 
    int findSpace(Node *node){
        if (node == NULL)
            return 0;
        node = node->right;
      
        return findSpace(node->left) + 1;
    }
 
    Node *deleteNode(Node *node, int data){
        if(node == NULL)
            return NULL;
        if(data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else
        {
            if(node->left == NULL && node->right == NULL)
                return NULL;
            else if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->right;
            else
            {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
            
        }
        return node;
    }
 
    Node *findMIn(Node *node) {
        while(node->left != NULL)
            node = node->left;
        return node;
    }
 
    Node *findMax(Node *node) {
        while (node->right!= NULL)
        {
            node = node->right;
        }
        if(node->left != 0){
            findMax(node->left);
            return node->left;
        }
        if (node->left == NULL){
            
            return node;
        }
    }

    void triangles(Node *node){
        int cnt = 0;
        if(node == NULL)
            return;
        if(node!= NULL){
        if(node->left != NULL && node->right!= NULL)
            cnt++;
        triangles(node->right);
        triangles(node->left);
        }
        ct.push_back(cnt);
        
    }

};
 
 
int main(){
    BST *bst = new BST();
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bst->insert(bst->root, a);
    }
   
    // Node *node_max = bst->findMax(bst->root);
    // cout << node_max->data;
    // bst->inOrder(bst->root);
    bst->triangles(bst->root);
    int l = 0;
    for (int i = 0; i < bst->ct.size(); i++)
    {
        if(bst->ct[i] == 1)
            l++;
    }
    
    cout << l;
    return 0;
}