#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left = NULL;
        this->right= NULL;
    }
};
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node* root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);

}
void postorder(Node* root){
    if(root==NULL) return;
    
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->val<<endl;

}
Node* insert(Node* root,int key){
    if(root == NULL) return new Node(key);
    if(key < root->val){
        root ->left = insert(root->left,key);

    }
    else {
        root->right = insert(root->right,key);
    }
    return root;

}
bool search(Node* root,int key){
    if(root == NULL) return false;
    if(root->val == key) return true;
    if(key<root->val){
       return search(root->left,key);
    }
    else{
       return search(root->right,key);
    }
}
Node* findmin(Node* root){
    if(root ==0) return NULL;
    while(root==0 && root->left == 0){
        root = root->left;
        return root;
    }

}
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findmin(root->right); // or inorder successor
        root->val= temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
int height(Node* root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left),height(root->right));

}

int main(){
    // Node*  a = new Node(1);
    // Node* b = new Node(2);
    // Node* c = new Node(3);
    // Node* d = new Node(4);
    // Node* e = new Node(5);
    // Node* f = new Node(6);

    // a->left = b;
    // a->right = c;
    // b->left = d;
    // b->right = e;
    // c->left = f;
    // cout<<endl;
    // preorder(a);
    // cout<<endl;
    // insert(a,7);
    //  preorder(a);
    // cout<<endl;
    // search(a,8);
    // findmin(a);
    // inorder(a);
    // cout<<endl; 
    Node* root = NULL;
    root = insert(root,30);
    insert(root,50);
    insert(root,70);
    insert(root,80);
    insert(root,20);
    cout<<endl;
    preorder(root);
    cout<<endl;
    deleteNode(root,30);
    preorder(root);
    height(root);


}