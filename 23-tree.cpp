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
Enter the data : 11
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


//BOTTOM VIEW OF BINARY TREE                                             (T.C = O(NLOGN), S.C = O(N))
class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
            // if(topNode.find(hd) == topNode.end()) only for top view
            topNode[hd] = frontNode->data;
            
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
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
*/


//LEFT VIEW OF BINARY TREE                                              (T.C = O(N), S.C = O(H))       
void solve(Node *root, vector<int>&ans , int level){
    //base case
    if(root == NULL){
        return;
    }
    
    //we entered into new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   solve(root, ans, 0);
   return ans;
}
/*
Input:
   1
 /  \
3    2
Output: 1 3
*/


//RIGHT VIEW OF BINARY TREE                                              (T.C = O(N), S.C = O(N))       
class Solution
{
    public:
    
    void solve(Node *root, vector<int>&ans , int level){
    //base case
    if(root == NULL){
        return;
    }
    
    //we entered into new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
    
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
       solve(root, ans, 0);
       return ans;
    }
};
/*
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
*/


//SUM OF THE LONGEST BLODDLINE OF A TREE / OR                              (T.C = O(N), S.C = O(N))   
// SUM OF NODES ON THE LONGEST PATH FROM ROOT TO LEAF NODE    
class Solution
{
public:
    void solve(Node* root, int sum, int&maxSum, int len, int&maxLen){
        //base case
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(maxSum, sum);
            }
            return;
        }
        
        sum = sum + root->data;
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = 0;
        
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
};
/*
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
*/


//LOWEST COMMON ANCESTOR IN A BINARY TREE                        (T.C = O(N), S.C = O(H))               
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
       if(root == NULL){
           return NULL;
       }
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node *leftAns = lca(root->left, n1, n2);
       Node *rightAns = lca(root->right, n1, n2);
       
       if(leftAns != NULL && rightAns != NULL){
           return root;
       }
       else if(leftAns != NULL && rightAns == NULL){
           return leftAns;
       }
       else if(leftAns == NULL && rightAns != NULL){
           return rightAns;
       }
       else{
           return NULL;
       }
    }
};
/*
Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
*/


//K SUM PATHS                                                               (T.C = O(N^2))  
class Solution{
  public:
    void solve(Node *root, int k, int&count, vector<int>&path){
        //base case
        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        //check k sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1 ; i >=0 ; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int>path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
/*
Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
*/
//ALTERNATIVE                                  (T.C = O(N), S.C = O(H))
#include <unordered_map>
class Solution{
public:
    void solve(Node *root, int k, int &count, unordered_map<int, int> &sumMap, int runningSum){
        if(root == NULL){
            return;
        }
        
        runningSum += root->data;
        
        if(sumMap.find(runningSum - k) != sumMap.end()){
            count += sumMap[runningSum - k];
        }
        
        if(sumMap.find(runningSum) == sumMap.end()){
            sumMap[runningSum] = 1;
        }
        else{
            sumMap[runningSum]++;
        }
        
        solve(root->left, k, count, sumMap, runningSum);
        solve(root->right, k, count, sumMap, runningSum);
        
        sumMap[runningSum]--;
    }
    
    int sumK(Node *root,int k){
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        int count = 0;
        solve(root, k, count, sumMap, 0);
        return count;
    }
};


//KTH ANCESTOR IN A TREE                                                (T.C = O(N), S.C = O(N))
#include<climits>
Node *solve(Node *root, int&k , int&node){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    
    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);
    
    //return back to upward
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;
    }
}
/*
Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
*/


//MAXIMUM SUM OF NON-ADJACENT NODES                               (T.C = O(N), S.C = O(H))
class Solution{
  public:
    //<int,int> == <sum with include root node, sum with exclude root node>
    pair<int,int>solve(Node *root){
        //base case
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        
        pair<int,int>res;
        
        res.first = root->data + left.second + right.second;
        res.second = max(left.first,left.second) + max(right.first,right.second);
        
        return res;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans = solve(root);
        return max(ans.first,ans.second);
    }
};
/*
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
*/


//CONSTRUCT TREE FROM INORDER AND PREORDER              (T.C = O(N^2), S.C = O(N))
//ERROR
class Solution{
public:
    int findPosition(int in[], int element, int n){
        for(int i = 0 ; i < n ; i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        //base case
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        //create root node for element
        int element = pre[index++];
        Node* root = new Node(element);
        
        //find element's index in inOrder
        int position = findPosition(in , element, n);
        
        //in case of preorder and inorder, we first build left subtree
        root->left = solve(in, pre, index, inOrderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inOrderEnd, n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node *ans = solve(in ,pre ,preOrderIndex ,0,n-1,n);
        
        return ans;
    }
};
//Alternate solution                                    (T.C = O(NLOGN), S.C = O(N)) 
class Solution{ 
public:
    void createMapping(int in[], map<int,int>&nodeToIndex, int n){
        for(int i = 0 ; i < n ; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node *solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int,int>&nodeToIndex){
        //base case
        if(preOrderIndex >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        //create root node for element
        int element = pre[preOrderIndex++];
        Node* root = new Node (element);
        
        //find element's index in inOrder
        int position = nodeToIndex[element];
        
        root->left = solve(in, pre, preOrderIndex, inOrderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, preOrderIndex, position+1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = n-1;
        map<int,int>nodeToIndex;
        
        //create mapping node to index
        createMapping(in, nodeToIndex, n);
        
        Node *ans = solve(in ,pre ,preOrderIndex ,inOrderStart, inOrderEnd ,n , nodeToIndex);
        
        return ans;
    }
};
/*
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
*/


//TREE FROM POSTORDER AND INORDER                       (T.C = O(NLOGN), S.C = O(N))   
void createMapping(int in[], map<int,int>&nodeToIndex, int n){
    for(int i = 0 ; i < n ; i++){
        nodeToIndex[in[i]] = i;
    }
}
Node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int>&nodeToIndex){
    //base case
    if(index < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    //create root node for element
    int element = post[index--];
    Node* root = new Node(element);
    
    //find element's index in inOrder
    int position = nodeToIndex[element];
    
    //in case of postorder and inorder, we first build right subtree
    root->right = solve(in, post, index, position+1, inOrderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inOrderStart, position-1, n, nodeToIndex);
    
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    map<int,int>nodeToIndex;
    
    //create mapping node to index
    createMapping(in, nodeToIndex, n);
    
    Node *ans = solve(in ,post ,postOrderIndex ,0,n-1,n , nodeToIndex);
    
    return ans;
}
/*
Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
*/


//BURNING TREE                                                    (T.C = O(N), S.C = O(H)) 
class Solution {
  public:
    //create mapping and find target node
    Node* createMapping(Node* root, int target , map<Node* ,Node*>&nodeToParent){
        Node* res = NULL;
        queue<Node*>q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node*front = q.front();
            q.pop();
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*>&nodeToParent){
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root] = true;
        int ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i = 0 ; i < size ; i++){
                //process neighbour nodes
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>nodeToParent;
        Node *targetNode = createMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};
/*
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation:
If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
*/


//FLATTEN BINARY TREE TO LINKED LIST                                       (T.C = O(N), S.C = O(1))
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node *curr = root;
        while(curr != NULL){
            if(curr->left){
                Node *pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
/*
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
*/