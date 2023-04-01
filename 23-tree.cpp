//TREE
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//CREATE A BINARY TREE
class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root){

    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for insert left of "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter data for insert right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void buildFromLevelOrder(node *&root){
    queue<node *>q;
    cout<<"Enter data of root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node *root){
    queue<node * >q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node  *temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level is filled
            cout<<endl;
            if(!q.empty()){
                //queue still have child
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node *root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->right){
            q.push(temp->right);
        }
        if (temp->left){
            q.push(temp->left);
        }
    }

    while (!s.empty()){
        node* temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}

void inorderTraversal(node *root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root){
    //base case
    if(root == NULL){
        return;
    }

    //NLR
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node *root){
    //base case
    if(root == NULL){
        return;
    }

    //LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // level order traversal (DFS = Depth First Search)
    // i/o=> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout<<"The level order traversal or DFS : "<<endl;
    levelOrderTraversal(root);

    cout<<"The reverse level order traversal or revers DFS : "<<endl;
    reverseLevelOrderTraversal(root);

    
    cout<<"The Inorder Traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"The preorder Traversal : "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"The postorder Traversal : "<<endl;
    postorderTraversal(root);
    cout<<endl;
    

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);

    cout<<"The level order traversal or DFS : "<<endl;
    levelOrderTraversal(root);

    return 0;
}
/*output
Enter the data : (//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1      //just for save time)
1 
Enter data for insert left of 1
Enter the data : 3
Enter data for insert left of 3
Enter the data : 7
Enter data for insert left of 7
Enter the data : -1
Enter data for insert right of 7
Enter the data : -1
Enter data for insert right of 3
Enter the data : -11
Enter data for insert left of 11
Enter the data : -1
Enter data for insert right of 11
Enter the data : -1 
Enter data for insert right of 1
Enter the data : 5
Enter data for insert left of 5
Enter the data : 17
Enter data for insert left of 17
Enter the data : -1
Enter data for insert right of 17
Enter the data : -1
Enter data for insert right of 5
Enter the data : -1
The level order traversal or DFS :
1
3 5
7 11 17

The reverse level order traversal or revers DFS :
7 11 17 3 5 1

The Inorder Traversal :
7 3 11 1 17 5

The preorder Traversal :
1 3 7 11 5 17

The postorder Traversal :
7 11 3 17 5 1

Enter data of root (//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 ) for save time
1
Enter left node for : 1
3
Enter right node for : 1
5
Enter left node for : 3
7 
Enter right node for : 3
11
Enter left node for : 5
17
Enter right node for : 5
-1
Enter left node for : 7
-1
Enter right node for : 7
-1
Enter left node for : 11
-1
Enter right node for : 11
-1
Enter left node for : 17
-1
Enter right node for : 17
-1
The level order traversal or DFS :
1
3 5
7 11 17
*/