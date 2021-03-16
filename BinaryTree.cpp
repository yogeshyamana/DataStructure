#include<bits/stdc++.h>
using namespace std;

template <typename T>
class  BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    queue<BinaryTreeNode<int>*> temp;
    temp.push(root);
    while(temp.size()!=0){
        cout<<temp.front()->data<<" : ";
        if(temp.front()->left->left!=NULL){
            cout<<" L"<<temp.front()->left->data;
            temp.push(temp.front()->left);
        }
        else{
            cout<<" L"<<"-1";
        }
        if(temp.front()->right->right!=NULL){
            cout<<" R"<<temp.front()->right->data;
            temp.push(temp.front()->right);
        }
        else{
            cout<<" R"<<"-1";
        }
        temp.pop();
        cout<<endl;
    }
}
void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<" L "<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data ";
    if(rootData== -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftchild = takeInput();
    BinaryTreeNode<int>* rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;

    return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftchildData;
        cin>>leftchildData;
        if(leftchildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightchildData;
        cin>>rightchildData;
        if(rightchildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root ;
}
int NumofNode(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+ NumofNode(root->left) + NumofNode(root->right);
}
void inorder(BinaryTreeNode<int>* root ){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
void preorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
bool checkNumber(BinaryTreeNode<int>* root, int x){
   if(root==NULL){
       return false;
   }
   if(root->data==x){
       return true;
   }
   bool res1 = checkNumber(root->left , x);
   if(res1)
        return true;

   bool res2 = checkNumber(root->right, x);
   return res2;
}
BinaryTreeNode<int>* mirrorTree(BinaryTreeNode<int>* root ){
    if(root ==NULL){
        return NULL;
    }
    mirrorTree(root->left);
    mirrorTree(root->right);
    BinaryTreeNode<int>* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pr, int inS, int inE, int prS, int prE){
    if(inS > inE){
        return NULL;
    }
    int rootData = pr[prS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex-1;
    int lprS = prS+1;
    int lprE = linE - linS + lprS ;
    int rprS = lprE +1;
    int rprE = prE;
    int rinS = rootIndex+1;
    int rinE = inE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in , pr ,linS,linE, lprS, lprE);
    root->right = buildTreeHelper(in, pr, rinS, rinE, rprS,rprE);
    return root;
}
BinaryTreeNode<int>* buildTree(int* in , int* pr, int size){
    return buildTreeHelper(in , pr , 0, size-1,0,size-1);
}
int main(){

    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);    
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;*/

    //BinaryTreeNode<int>* root = takeInputLevelWise();

    // printTreeLevelWise(root);
    // inorder(root);
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // if(checkNumber(root, 15)){
    //     cout<<"true";
    // }
    // else
    //     cout<<"false";
    //printTree(mirrorTree(root));
    int in[]= {4,2,5,1,8,6,9,3,7};
    int pr[] = {1,2,4,5,3,6,8,9,7};

    BinaryTreeNode<int>* root = buildTree(in , pr, 9);

    printTree(root);
}