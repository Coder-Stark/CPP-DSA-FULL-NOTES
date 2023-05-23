//HEAP

#include<iostream>
#include<queue>

using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int i = size;
        arr[i] = val;

        while(i > 1){
            int parent = i/2;

            if(arr[parent] < arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                return;
            }
        }
    }
    
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
        }

        //move last element to 1/root element
        arr[1] = arr[size];

        //remove last element
        size--;

        //move root to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i] , arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i] , arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }

    }
    void print(){
        for(int i = 1 ; i <= size ; i++){
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size>1){
        //swap
        swap(arr[size], arr[1]);
        
        //remove element
        size--;

        //heapify
        heapify(arr, size, 1);
    }

}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    cout<<"After Insertion in a Heap"<<endl;
    h.print();
    cout<<endl;

    h.deleteFromHeap();
    cout<<"After Deletion in a Heap"<<endl;
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    //heap creation
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }

    cout<<endl;

    cout<<"Printing the array after heapify"<<endl;
    for(int i = 1 ; i <= n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"Printing sorted Array"<<endl;
    for(int i = 1 ; i <= n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    //Build heap using Priority queue
    //Priority is already in Max heap format

    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at Top in maxHeap "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at Top in maxHeap "<<pq.top()<<endl;

    cout<<"Size is "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }


    //Min heap using Priority queue
    priority_queue<int, vector<int>,greater<int>>pqmin;
    pqmin.push(4);
    pqmin.push(2);
    pqmin.push(5);
    pqmin.push(3);

    cout<<"Element at Top in minHeap "<<pqmin.top()<<endl;
    pqmin.pop();
    cout<<"Element at Top in minHeap "<<pqmin.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pqmin is empty"<<endl;
    }
    else{
        cout<<"pqmin is not empty"<<endl;
    }
    return 0;
}


/*output
After Insertion in a Heap
55 54 53 50 52
After Deletion in a Heap
54 52 53 50

Printing the array after heapify
55 53 54 52 50

Printing sorted Array
50 52 53 54 55

//maxHeap using pq
Element at Top in maxHeap 5
Element at Top in maxHeap 4
Size is 3
pq is not empty

//minHeap using pq
Element at Top in minHeap 2
Element at Top in minHeap 3
Size is 3
pqmin is not empty
*/


//BUILD MIN HEAP (0 INDEXING)                     {T.C = O(n)}

#include<vector>
void heapify(vector<int>&arr , int n , int i){

    int smallest = i;
    int left = 2 * i + 1 ;
    int right = 2 * i + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2-1 ; i >= 0 ; i--){
        heapify(arr, n, i);
    }
    return arr;
}

/*
OUTPUT
Sample Input 1 :
2
5
9 3 2 6 7 
4
1 3 2 4
Sample Output 1 :
1
1
*/


//KTH SMALLEST ELEMENT                  {T.C = O(N),S.C = O(K)}
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>pq;
        
        //step1- make max heap of first k elements
        for(int i = 0 ; i < k ; i++){
            pq.push(arr[i]);
        }
        
        //step2- for rest of elements
        for(int i = k ; i <= r ; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step3- return ans
        int ans = pq.top();
        return ans;
    }
};

/*
Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
*/


//IS BINARY TREE HEAP                            {T.C = O(N), S.C = O(N)}
//------------------------------------------------
// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//--------------------------------------------------
class Solution {
  public:
    int countNode(struct Node* root){
        if(root == NULL){
            return 0;
        }
        else{
            int ans = 1 + countNode(root->left) + countNode(root->right);
            return ans;
        }
    }
    bool isCBT(struct Node*root, int index,int countNode){
        if(root == NULL){
            return true;
        }
        if(index >= countNode){                                   //>= 0 indexing
            return false;
        }
        else{
            bool left = isCBT(root->left, 2*index + 1 , countNode);
            bool right = isCBT(root->right , 2*index + 2, countNode);
            return (left && right);
        }
    }
    bool isMaxOrder(struct Node* root){
        //leafnode
        if(root->left== NULL && root->right == NULL){
            return true;
        }
        
        //1 child
        if(root->right== NULL){
            return (root->data > root->left->data);
        }
        
        //2 child
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
    }
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalCount = countNode(tree);
        
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};

/*
Input:
      5
    /  \
   2    3
Output: 1
*/


//MERGE TWO BINARY MAX HEAPS                                            {T.C = O(NLOGN),S.C = O(M+N)}
class Solution{
    public:
    void heapify(vector<int>&arr , int n , int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr,n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step1 merge two arrays
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        //build heap
        int size = ans.size();
        for(int i = size/2 -1 ; i >= 0 ; i--){
            heapify(ans, size,i);
        }
        
        return ans;
    }
};


/*
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
*/


//MINIMUM COST OF ROPES                                      {T.C = O(NLOGN),S.C = O(N)}
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        //create minheap using priority queue
        priority_queue<long long , vector<long long>,greater<long long>>pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            pq.push(sum);
            cost = cost + sum;
        }
        return cost;
    }
};

/*
Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
*/


//KTH LARGEST SUM SUBARRAY                                        {T.C = O(N2LOGN), S.C = O(N2)}
#include<algorithm>
int getKthLargest(vector<int> &arr, int k) {
	
  vector<int> sumStore;
  int n = arr.size();

  for (int i = 0; i < n; i++){
	  int sum = 0;
	  for(int j = i ; j < n ;j++){
		  sum = sum + arr[j];
		  sumStore.push_back(sum);
	  }
  }
  sort(sumStore.begin(),sumStore.end());

  return sumStore[sumStore.size() - k];

}

//APPROACH 2                                                     {T.C = O(N2LOGN), S.C = O(K)}
#include<queue>
int getKthLargest(vector<int> &arr, int k) {
  priority_queue<int , vector<int>,greater<int>>mini;
  int n = arr.size();

  for (int i = 0; i < n; i++){
	  int sum = 0;
	  for(int j = i ; j < n ;j++){
		  sum = sum + arr[j];
		  if(mini.size() < k){
			  mini.push(sum);
		  }
		  else{
			  if(sum > mini.top()){
				  mini.pop();
				  mini.push(sum);
			  }
		  }
	  }
  }
  
  return mini.top();
}

/*
Sample Input 1 :
2
3 3
3 -2 5
2 2
4 1
Sample output 1 :
3
4
*/


//MERGE K SORTED ARRAYS                                                    {T.C = O(N*KLOG(K)),S.C = O(N*K)}
#include <bits/stdc++.h> 
class node{
    public:
    int data;
    int i;
    int j;
    node(int data , int row , int col){
        this->data = data;
        i = row;
        j = col;
    }
};
class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node* , vector<node*>,compare>minHeap;

    //step1 - insert first k elements of all k arrays
    for(int i  = 0 ; i <  k ; i++){
        node*temp = new node (kArrays[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int>ans;
    //step2
    while(minHeap.size() > 0){
        node*tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;
        if(j+1 < kArrays[i].size()){
            node*next = new node(kArrays[i][j+1], i , j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
/*
Sample Input 1:
1
2
3 
3 5 9 
4 
1 2 3 8   
Sample Output 1:
1 2 3 3 5 8 9 
*/


//MERGE K SORTED LIST                                                   {T.C = O(NLOGK),S.C = O(K)}
class compare{
public:
    bool operator()(Node<int>*a,Node<int>*b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare>minHeap;
    //step1- insert first k elements of all k lists
    int k = listArray.size();
    for(int i = 0 ; i < k ; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }
    Node<int>*head = NULL;
    Node<int>*tail = NULL;
    while(minHeap.size() > 0){
        Node<int>*top = minHeap.top();
        minHeap.pop();
        if(top->next != NULL){
            minHeap.push(top->next);
        }
        if(head == NULL){
            //answer LL is empty
            head = top;
            tail = top;
        }
        else{
            //insertion at LL
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
/*
Sample Input 1:
 2
 3
 4 6 8 -1
 2 5 7 -1
 1 9 -1
 2
 2 6 -1
 -5 7 -1
Sample Output 1:
 1 2 4 5 6 7 8 9 -1
 -5 2 6 7 -1
*/


//SMALLEST RANGE FROM K SROTED LIST
#include<limits.h>
#include<queue>
class Node{
public:
    int data;
    int row;
    int col;
    
    Node(int d, int r, int c){
        data= d;
        row= r;
        col= c;
    }
};
class compare{
public:
    bool operator()(Node*a,Node*b){
        return a->data > b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<Node*,vector<Node*>,compare>minHeap;

    //step1- insert first k elements of all k lists and tracking main and maxi
    for(int i = 0 ; i < k ; i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new Node(element,i,0));
    }

    int start = mini;
    int end = maxi;

    //step2- process range
    while(!minHeap.empty()){
        //mini fetch
        Node*temp = minHeap.top();
        minHeap.pop();
        
        mini = temp->data;

        //range or answer updation
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        //if next element exist
        if(temp->col + 1 < n){
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new Node(a[temp->row][temp->col+1],temp->row,temp->col + 1));
        }
        else{
            break;
        }
    }

    return (end - start + 1);
}
/*
Sample Input 1 :
2
3 2
2 4 5
5 6 7
2 3
1 1
9 12
4 9
Sample Output 1 :
1
9
*/


//MEDIAN IN A STREAM                                                                     {T.C = O(NLOGN)}
#include<queue>
#include<vector>
int signum(int a,int b){
	if(a == b){
		return 0;
	}
	else if(a > b){
		return 1;
	}
	else{
		return -1;
	}
}
void callMedian(int element,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini, int &median){
	switch(signum(maxi.size(),mini.size())){
		case 0: if(element > median){            //maxheap.size() = n & minheap.size() = n
					mini.push(element);
					median = mini.top();
				}
				else{
					maxi.push(element);
					median = maxi.top();
				}
				break;

		case 1: if(element > median){           //maxheap.size() = n & minheap.size() = n-1
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				else{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;
		
		case -1:if(element > median){          //maxheap.size() = n-1 & minheap.size() = n  
					maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				else{
					maxi.push(element);
					median = (mini.top() + maxi.top())/2;
				}
				break;

	}
}
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>ans;
	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>>minHeap;
	int median = 0;
	for(int i = 0 ; i < n ; i++){
		callMedian(arr[i],maxHeap,minHeap,median);
		ans.push_back(median);
	}
	return ans;
}

/*
Sample Input 1:
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:
1 1 2
9 9 
4 
*/