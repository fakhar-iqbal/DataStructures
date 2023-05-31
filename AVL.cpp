#include<iostream>
using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int max(int a,int b){
    return (a>b)?a:b;

}
int getHeight(AVLNode* root){
    if(root==nullptr)
    return 0;
    return root->height;
}

int balanceFactor(AVLNode* root){
    if(root==nullptr)
    return 0;

    return getHeight(root->left)-getHeight(root->right);
}

AVLNode* createNode(int data){
    AVLNode* node = new AVLNode();
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    node->height=1;

    return node;
}

AVLNode* rotateRight(AVLNode* y){
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right=y;
    y->left=T2;

    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1;
    return x;//root of those
}



AVLNode* rotateLeft(AVLNode* y){
    AVLNode* x = y->right;
    AVLNode* T2 = x->left;

    x->left = y;
    y->right=T2;
    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}


void insert(AVLNode*& root,int data){
    if(root==nullptr)
    root = createNode(data);
    if(data<root->data){
        insert(root->left,data);
    }
    else if(data>root->data){
        insert(root->right,data);
    }else
    return;

    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    int balancingFactor = balanceFactor(root);
    if(balancingFactor>1 && data<root->left->data){
        root=rotateRight(root);
    }
    if(balancingFactor < -1 && data>root->right->data){
        root=rotateLeft(root);
    }
    if(balancingFactor > 1 && data>root->left->data){
        root->left = rotateLeft(root->left);
        root=rotateRight(root);
    }
    if(balancingFactor <-1 && data<root->right->data){
        root->right=rotateRight(root->right);
        root=rotateLeft(root);
    }
    
}


void inOrder(AVLNode* root){
    if(root==nullptr)
    return;
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}



int main(){
    AVLNode* root=nullptr;

    insert(root,45);
    insert(root,33);
    insert(root,3);
    insert(root,65);
    insert(root,77);
    insert(root,34);
    insert(root,67);
    insert(root,12);
    inOrder(root);

    return 0;
}

