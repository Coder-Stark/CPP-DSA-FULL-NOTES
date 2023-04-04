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
//Alternate solution                                      (T.C = O(N))
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


//DETERMINE IF 2 TREE'S ARE IDENTICAL                                (T.C = O(N), S.C = O(H))
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //base case
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1 != NULL && r2 == NULL){
            return false;
        }
        if(r1 == NULL && r2 != NULL){
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool value = r1->data == r2->data;
        
        if(left && right && value ){
            return true;
        }
        else{
            return false;
        }
    }
};
/*
Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
*/


//SUM TREE                                           (T.C = O(N), S.C = O(H))
class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node *root){
        //base case
        if(root == NULL){
            pair<bool,int>p = make_pair(true, 0);
            return p;
        }
        
        //leaf node manage
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int>leftAns = isSumTreeFast(root->left);
        pair<bool,int>rightAns = isSumTreeFast(root->right);
        
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool cond = root->data == leftAns.second + rightAns.second;
        
        pair<bool,int>ans;
        
        if(left && right && cond){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};
/*
Input:
    3
  /   \    
 1     2

Output: 1
*/


//ZIG ZAG TREE TRAVERSAL                            (T.C = O(N), S.C = O(N))
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	//base case
    	if(root == NULL){
    	    return result;
    	}
    	
    	bool leftToRight = true;
    	
    	queue<Node*>q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int>ans(size);
    	    
    	    //level process
    	    for(int i = 0 ; i < size;i++){
    	        Node *frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert and reverse insert
    	        int index = leftToRight ? i : size-i-1;
    	        ans[index] = frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    
    	    //level direction change
    	    leftToRight = !leftToRight;
    	    for(auto i : ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
};
/*
Input:
        1
      /   \
     2     3
    / \   /  \
   4   5 6    7
Output:
1 3 2 4 5 6 7
*/


//BOUNDARY TRAVERSAL OF BINARY TREE                                       (T.C = O(N), S.C = O(H))
class Solution {
public:
    void traversalLeft(Node *root, vector<int>&ans){
        //base case
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        ans.push_back(root->data);
        
        if(root->left){
            traversalLeft(root->left, ans);
        }
        else{
            traversalLeft(root->right, ans);
        }
    }
    
    void traversalLeaf(Node *root, vector<int>&ans){
        //base case
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);
    }
    
    void traversalRight(Node *root, vector<int>&ans){
        //base case
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            traversalRight(root->right, ans);
        }
        else{
            traversalRight(root->left, ans);
        }
        
        //store after returning back / reverse right print
        ans.push_back(root->data);
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        //base case
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        //left part store/print
        traversalLeft(root->left, ans);
        
        //leaf part stor/print
        //left subtree leaf part
        traversalLeaf(root->left, ans);
        //right subtree leaf part
        traversalLeaf(root->right, ans);
        
        //Right part store/print
        traversalRight(root->right, ans);
        
        return ans;
    }
};
/*
Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
*/


//VERTICAL TRAVERSAL OF BINARY TREE                                 (T.C = O(N), S.C = O(N))
#include<map>
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int> > > nodes;
        queue<pair<Node*,pair<int,int> > > q;
        vector<int>ans;
        
        //base case
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(root, make_pair(0, 0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>>temp = q.front();
            q.pop();
            
            //extract values
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1, lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1, lvl+1)));
            }
        }
        for(auto i : nodes){
            for(auto j : i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
/*
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
*/


//TOP VIEW OF BINARY TREE                                               (T.C = O(NLOGN), S.C = O(N))
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        //base case
        if(root == NULL){
            return ans;
        }
        
        map<int,int>topNode;
        queue<pair<Node*,int> >q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //maintain 1:1 mapping
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        return ans;
    }

};
/*
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/