//BINARY SEARCH TREE(BST)
#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left ;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//Traversals------------------------------------------------------------------------------------------------------------
void levelOrderTraversal(Node *root){
    queue<Node * >q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node  *temp = q.front();
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
void inorderTraversal(Node *root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root){
    //base case
    if(root == NULL){
        return;
    }

    //NLR
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root){
    //base case
    if(root == NULL){
        return;
    }

    //LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
//---------------------------------------------------------------------------------------------------------------------------------

Node * minValue(Node*root){
    Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node * maxValue(Node*root){
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node *insertIntoBST(Node *root, int d){                           //(T.C = O(LOGN))
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(root->data > d){
        //insert in left of BST
        root->left = insertIntoBST(root->left, d);
    }
    else{
        //insert in right of BST
        root->right = insertIntoBST(root->right,d);
    }

    return root;
}

Node *deleteFromBST(Node *root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left, val);
        return root;
    }
}
void takeInput(Node *&root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root , data);
        cin>>data;
    }
}
int main(){
    Node *root = NULL;
    cout<<"Enter data to be inserted in BST "<<endl;
    takeInput(root);

    cout<<"The level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    
    cout<<"The Inorder Traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"The preorder Traversal : "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"The postorder Traversal : "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"The minimum value : "<<endl;
    cout<<minValue(root)->data<<endl;

    cout<<"The maximum value : "<<endl;
    cout<<maxValue(root)->data<<endl;

    cout<<"After deletion the node : "<<endl;
    // root = deleteFromBST(root,4);
    // root = deleteFromBST(root,7);
    root = deleteFromBST(root,10);

//--------------------------------------------------------------------
    
    cout<<"The level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    
    cout<<"The Inorder Traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"The preorder Traversal : "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"The postorder Traversal : "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"The minimum value : "<<endl;
    cout<<minValue(root)->data<<endl;

    cout<<"The maximum value : "<<endl;
    cout<<maxValue(root)->data<<endl;


    return 0;
}
/*
output
Enter data to be inserted in BST 
10 8 21 7 27 5 4 3 -1
The level order traversal: 
10 
8 21 
7 27 
5 
4 
3 
The Inorder Traversal : 
3 4 5 7 8 10 21 27 
The preorder Traversal : 
10 8 7 5 4 3 21 27 
The postorder Traversal : 
3 4 5 7 8 27 21 10 

The minimum value :
3
The maximum value :
27

-------------------------------------------------------------------------------
//delete 0 child node
//
After deletion the node :
The level order traversal:
10
8 21
7 27
5
3

The Inorder Traversal :
3 5 7 8 10 21 27
The preorder Traversal :
10 8 7 5 3 21 27 
The postorder Traversal :
3 5 7 8 27 21 10
The minimum value :
3
The maximum value :
27
//
-----------------------------------------------------------------------------
//delete 1 child node
//
After deletion the node :
The level order traversal:
10
8 21
5 27
4
3 

The Inorder Traversal :
3 4 5 8 10 21 27
The preorder Traversal :
10 8 5 4 3 21 27
The postorder Traversal :
3 4 5 8 27 21 10
The minimum value :
3
The maximum value :
27
//
---------------------------------------------------------------------------------
//delete 2 child node

After deletion the node :
The level order traversal:
21
8 27
7
5
4
3

The Inorder Traversal :
3 4 5 7 8 21 27
The preorder Traversal :
21 8 7 5 4 3 27
The postorder Traversal :
3 4 5 7 8 27 21 
The minimum value :
3
The maximum value :
27
*/


/*
//SEARCH IN BST
//using recursion                                                            (T.C = O(LOGN), S.C = O(N))
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(root->data > x){
        return searchInBST(root->left,x);
    } 
    else {
        return searchInBST(root->right, x);
    }
}

//using iteration                                                             (T.C = O(LOGN), S.C = O(1))
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int>*temp = root;
    while (temp != NULL) {
        if (temp->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp ->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
/*
Sample Input 2:
2
4 1
3 1 5 -1 2 -1 -1 -1 -1
4 6
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 2:
True
False
*/


//VALIDATE BST                                                  (T.C = O(N), S.C = O(N))
bool isBST(BinaryTreeNode<int>*root,int min, int max){
    //base case
    if(root == NULL){
        return true;
    }
    if(root->data > min && root->data < max){
        bool left = isBST(root->left, min , root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return isBST(root, INT_MIN, INT_MAX);
}
/*
Sample Input 1 :
2
3 1 5 -1 2 -1 -1 -1 -1
3 2 5 1 4 -1 -1 -1 -1 -1 -1
Sample Output 1 :
 true
 false

*/


//FIND KTH SMALLEST ELEMENT IN BST                                       (T.C = O(H + K), S.C = O(H))
int solve(BinaryTreeNode<int>*root, int &i , int k){
    //base case
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i , k);
    if(left != -1){
        return left;
    }
    i++;
    if(i == k){
        return root->data;
    }
    
    return solve(root->right, i , k);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i;
    int ans = solve(root, i, k);
    return ans;
}
/*
Sample Input 1:
2
3
3 1 4 -1 -1 -1 5 -1 -1
4
5 2 -1 -1 4 3 -1 -1 -1
Sample Output 1:
4   
5
*/


//PREDESSOR AND SUCCESSOR IN BST                                      (T.C = O(H), S.C = O(1))
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>*temp = root;
    int pred = -1;
    int succ = -1;

    //find key
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    //pred
    BinaryTreeNode<int>*leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        //max value of left subtree
        leftTree = leftTree->right;
    }

    //succ
    BinaryTreeNode<int>*rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        //min value of right subtree
        rightTree = rightTree->left;
    }

    pair<int,int>ans = make_pair(pred, succ);
    return ans;
}
/*
Sample Input 1:
1
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample Output 1:
8 12
*/


//LCA OF TWO NODES IN A BST
//using recursion                                                 (T.C = O(H), S.C = O(H))
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	//base case
    if(root == NULL){
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    
    if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    
    return root;
}
//using iteration                                                (T.C = O(H), S.C = O(1))
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    while(root != NULL){
        if(root->data < P->data && root->data < Q->data){
            return LCAinaBST(root->right,P,Q);
        }

        else if(root->data > P->data && root->data > Q->data){
            return LCAinaBST(root->left,P,Q);
        } 
        else {
          return root;
        }
    }
}
/*
Sample Input 1 :
2
3 5
2 1 3 -1 -1 -1 5 -1 -1
1 3
2 1 4 -1 -1 3 -1 -1 -1
Sample Output 1:
3
2
*/


//TWO SUM IV- INPUT IN A BST                                   (T.C = O(N), S.C = O(H))
void inorder(BinaryTreeNode<int>*root,vector<int>&n){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorder(root->left,n);
    n.push_back(root->data);
    inorder(root->right,n);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>n;

    //store in vector in sorted array
    inorder(root,n);

    //2 pointer approach
    int i = 0 ; 
    int j = n.size()-1;

    while(i < j){
        int sum = n[i] + n[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
/*
Sample Input 1:
1
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
14
Sample Output 1:
True
*/ 


//FLATTEN BST TO A SORTED LIST                                      (T.C = O(N), S.C = O(H))
void inorder(TreeNode<int>*root,vector<int>&n){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorder(root->left, n);
    n.push_back(root->data);
    inorder(root->right, n);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    //store in inorder list
    vector<int>n;
    inorder(root,n);

    int size = n.size();

    TreeNode<int>* newRoot = new TreeNode<int> (n[0]);
    TreeNode<int>* curr = newRoot;

    //for pointer L -> NULL && R -> next node
    for(int i = 1 ; i < size ; i++){
        TreeNode<int>*temp = new TreeNode<int>(n[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //for pointer L -> NULL && R-> NULL
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

/*
Sample Input 1
2
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
5 -5 8 -1 -1 -1 -1
Sample Output 1
2 -1 6 -1 8 -1 10 -1 11 -1 12 -1 15 -1 -1
-5 -1 5 -1 8 -1 -1
*/


//NORMAL BST TO BALANCED BST                                        (T.C = O(N), S.C = O(N))
void inorder(TreeNode<int>*root,vector<int>&n){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorder(root->left, n);
    n.push_back(root->data);
    inorder(root->right, n);
}
TreeNode<int>* inorderToBST(int s, int e, vector<int>&n){
    //base case
    if(s > e){
        return NULL;
    }

    //find mid
    int mid = (s + e)/2;

    //make tree
    TreeNode<int>*root = new TreeNode<int>(n[mid]);
    root->left = inorderToBST(s , mid-1, n);
    root->right = inorderToBST(mid+1, e, n);

    return root;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    //store in inorder list
    vector<int>n;
    inorder(root,n);
    int size = n.size()-1;

    return inorderToBST(0, size,n);
}
/*
Sample Input 1:
1
10 6 -1 4 -1 -1 -1
Sample Output 1:
4 6 10
*/


//PREORDER TRAVERSAL OF A BST / BST FROM PREORDER                                     (T.C = O(N), S.C = O(N))
BinaryTreeNode<int>*solve(vector<int>&preorder, int mini, int maxi, int &i){
    //base case
    if(i >= preorder.size()){
        return NULL;
    }
    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    //creating tree
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini , root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}
/*
Sample Input 1:
1
6
10 4 3 7 40 55 
Sample Output 1:
3 5 7 10 40 50
*/

 
//MERGE TWO BSTs                                                           (T.C = O(N1 + N2), S.C = O(N1 + N2))
void inorder(TreeNode<int>*root,vector<int> &n){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorder(root->left,n);
    n.push_back(root->data);
    inorder(root->right,n);

}
vector<int>mergeArrays(vector<int>&a, vector<int>&b){
    vector<int>ans(a.size() + b.size());
    
    int i = 0 , j = 0 , k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}
TreeNode<int>* inorderToBST(int s , int e , vector<int>&in){
    //base case
    if(s > e){
        return NULL;
    }

    //create BST
    int mid = (s + e)/2;
    TreeNode<int>*root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid-1,in);
    root->right = inorderToBST(mid+1,e,in);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step1 - store in two inorder vectors
    vector<int>n1,n2;
    inorder(root1,n1);
    inorder(root2,n2);

    //step2 - merge two inorder vectors
    vector<int>mergeArray = mergeArrays(n1, n2);

    //step3 - inorder vector to BST
    int s = 0 , e = mergeArray.size()-1;
    return inorderToBST(s, e , mergeArray);

}
/*
Sample Input 2:
1
4 2 7 -1 3 -1 -1 -1 -1  
5 1 7 -1 -1 -1 -1
Sample Output 2:
1 2 3 4 5 7 7 
*/


//LARGEST BST
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>*root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data , right.maxi);
    currNode.mini = min(root->data , left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }

    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root,maxSize);

    return maxSize;
}
/*
Sample Input 1 :
2
13 -1 18 -1 27 -1 29 -1 40 -1 -1 
3 1 5 8 0 2 6 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
5
3
*/