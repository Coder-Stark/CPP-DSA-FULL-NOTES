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


//COUNT LEAF NODES
template <typename T>
class BinaryTreeNode {
  public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
};
    
//main code
void inorder(BinaryTreeNode<int> *root, int &count){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left, count);

    //leafnode
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inorder(root, count);
    
    return count;
}
/*
Sample Input 1:
3
1 -1 -1
1  2  3  -1 -1 -1 4 -1 -1
1  2 -1 -1 3 -1 4 -1 -1
Sample Output 1:
1
2
1
*/

//FOR ALL BELOW
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//HEIGHT OF BINARY TREE                       (T.C = O(N), S.C = O(N))
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        //base case
        if(node == NULL){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left , right) + 1;
        
        return ans;
    }
};
/*
Input:
     1
    /  \
   2    3
Output: 2
*/


//DIAMETER OF BINARY TREE                     (T.C = O(N^2), S.C = O(N))
class Solution {
  private:
    int height(Node* node){
        //base case
        if(node == NULL){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        //base case
        if(root == NULL){
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        
        int ans = max(op1,max(op2, op3));
        
        return ans;
    }
};
//Alternate solution                              (T.C = O(N))
class Solution {

  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int>diameterFast(Node* root){
        //base case
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>left = diameterFast(root->left);
        pair<int,int>right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
/*
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
*/


//CHECK FOR BALANCED TREE                                         (T.C = O(N^2))
class Solution{
    private:
        int height(Node* node){
            //base case
            if(node == NULL){
                return 0;
            }
            
            int left = height(node->left);
            int right = height(node->right);
            
            int ans = max(left,right) + 1;
            return ans;
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //base case
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};
//Alternate Solution                                              (T.C = O(N))
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int>isBalancedFast(Node *root){
        //base case
        if(root ==  NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int>left = isBalancedFast(root->left);
        pair<bool,int>right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int>ans;
        ans.second = max(left.second,right.second) + 1;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};
/*
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
*/


