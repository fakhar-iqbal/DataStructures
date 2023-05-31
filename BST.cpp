#include<iostream>
#include<queue>
using namespace std;

//creating the structure of the tree node
struct BSTNode{
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;

};

//defining the root for the nood
BSTNode *root;

//inserting a node;
BSTNode *getNewNode(int data){
    BSTNode* p = new BSTNode();
    p->data=data;

    return p;
}

void insert(BSTNode *&root, int data){
    
    // if(root==nullptr){
    //     root = getNewNode(data);
    // }else{
    //     if(data<=root->data){
    //         insert(root->left,data);
    //     }else{
    //         insert(root->right,data);
    //     }
    // }

    BSTNode *ptr, *nodeptr, *parent;
    ptr = new BSTNode();
    ptr->data=data;
    if(root==nullptr){
        root=ptr;
    }else{
        nodeptr = root;
        parent = nullptr;
        while(nodeptr != nullptr){
            parent = nodeptr;
            if(data<=nodeptr->data){
                nodeptr = nodeptr->left;
            }else{
                nodeptr = nodeptr->right;
            }
        }
        if(data<=parent->data){
            parent->left=ptr;
            cout<<data<<" inserted"<<endl;
        }else{
            parent->right=ptr;
            cout<<data<<" inserted"<<endl;
        }
        
    }
}

bool search(BSTNode *&root,int data){
    BSTNode *current = root;
    if(root==nullptr){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<=root->data) return search(root->left,data);
    else return search(root->right,data);

}

void levelOrder(BSTNode* root){
    if(root==nullptr) return;
    {
        queue<BSTNode*> Q;
        Q.push(root);
        //while there is atleast one discovered node
        while(!Q.empty()){
            BSTNode* current = Q.front();
            cout<<current->data<<endl;
            if(current->left!=nullptr){
                Q.push(current->left);

            }if(current->right!=nullptr){
                Q.push(current->right);
            }
            Q.pop();
        }
    }
}
//checking for if the tree is BST
bool IsSubTreeLesser(BSTNode* root, int data){
    if(root==nullptr){
        return true;
    }
    if(root->data <= data && IsSubTreeLesser(root->left,data) && IsSubTreeLesser(root->right,data)){
        return true;
    }else
    return false;
}
bool IsSubTreeGreater(BSTNode* root, int data){
    if(root==nullptr) return true;
    if(root->data >data 
    && IsSubTreeGreater(root->left,data)
    &&IsSubTreeGreater(root->right,data)){
        return true;;
    }else return false;
}
bool IsBST(BSTNode* root){
    if(root==nullptr) return true;

    if(IsSubTreeLesser(root->left,root->data)
    && IsSubTreeGreater(root->right,root->data)
    && IsBST(root->left) && IsBST(root->right)
    ){
        return true;
    }else return false;
}
BSTNode* FindMin(BSTNode *root){
    if(root->left==nullptr){
        return root;
    }
    return FindMin(root->left);
}
//delete a node
BSTNode* Delete(BSTNode *root, int data){
    if(root==nullptr){
        return root;
    }
    if(data<root->data){
        root->left = Delete(root->left,data);
    }else if(data>root->data){
        root->right= Delete(root->right,data);
    }else if(data==root->data){ //get ready for deletion

    //if no subtrees or child node
    if(root->left==nullptr && root->right == nullptr){
        delete root;
        root= nullptr;
        
    }
    else if(root->left==nullptr){
        //one child case
        BSTNode* temp = root;
        root=root->right;
        delete temp;

    } else if(root->right==nullptr){
        BSTNode* temp = root;
        root= root->left;
        delete temp;
    }
    else{
        //we got two children of our node
        BSTNode* temp = FindMin(root->right);
        root->data=temp->data;
        root->right = Delete(root->right,temp->data);
    }
    


    }
    cout<<"item deleted"<<endl;
    return root;
}

void inOrder(BSTNode *root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}
void preOrder(BSTNode *root){
    if(root==nullptr) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BSTNode *root){
    if(root==nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}


int main(){

    cout<<"working on the tree!"<<endl;

    insert(root,34);
    cout<<"working"<<endl;
    preOrder(root);
    insert(root,14);
    cout<<"working"<<endl;
    preOrder(root);
    insert(root,23);
    cout<<"working"<<endl;
    preOrder(root);
    insert(root,13);
    cout<<"working"<<endl;
    preOrder(root);
    insert(root,53);
    cout<<"working"<<endl;
    insert(root,3);
    cout<<"working"<<endl;
    insert(root,11);
    cout<<"working"<<endl;
    insert(root,19);
    cout<<"working"<<endl;
    insert(root,45);
    cout<<"working"<<endl;
    cout<<"worked"<<endl;
    if(search(root,34)==true){
        cout<<"value found"<<endl;
    }else{
        cout<<"value not found!"<<endl;
    }
    levelOrder(root);
    if(IsBST(root)==true){ cout<<"yes"<<endl;}else cout<<"no"<<endl;

    Delete(root,14);
    levelOrder(root);
    return 0;
}