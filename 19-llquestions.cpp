//LINKED LIST QUESTIONS
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
//REVERSE LINKDED LIST
Node* reverseLinkedList(Node *head)
{
	if(head == NULL || head->next == NULL){
		return head;
	}
    Node * prev = NULL;
	Node * curr = head;
	Node * forward = NULL;
	while(curr != NULL){
		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;
	}
	return prev;	
}

//by recursion
void reverse(Node * &head , Node * curr , Node * prev){
	//base condition
	if(curr == NULL){
		head = prev;
		return;
	}
	Node * forward = curr->next;
	reverse(head , forward , curr);
	curr->next = prev;
}
Node * reverseLinkdeList(Node *head)
{
    Node * prev = NULL;
	Node * curr = head;
	reverse(head , curr , prev);
	return head;
}


//by recursion (2)
Node * reverse1(Node * head){
	//base condition
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node * smallHead = reverse1(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}
Node * reverseLinkdeList(Node *head)
{
	return reverse1(head);
}
/*INPUT
2
1 2 3 -1
10 20 30 40 50 -1
OUTPUT
3 2 1
50 40 30 20 10
*/


//FIND MIDDLE IN LINKED LIST
Node * getMiddle(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //for 2 nodes
    if(head->next->next == NULL){
        return head->next;
    }
    Node * slow = head;
    Node * fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head) {
    return getMiddle(head);
}


//REVERSE LIST IN K GROUPS
Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL){
        return head;
    }

    //reverse 1st k nodes
    Node * next = NULL;
    Node * curr = head;
    Node * prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next= prev;
        prev = curr;
        curr = next;
        count++;
    }

    //recursion handle
    if( next != NULL){
        head->next = kReverse(next , k);
    }

    //return head of reversed list
    return prev;
}
/*
//input
1 2 3 4 5 6 
//output
5 4 3 7 9 2 
*/


//CHECK THE LL IS CIRCULAR OR NOT
bool isCircular(Node * head){
    //empty list
    if(head == NULL){
        return true;
    }

    //1 >= node
    Node * temp = head->next;
    while( temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}
int main(){
    if(isCircular(head)){
        cout<<"link list is circular "<<endl;
    }
    else{
        cout<<"link list is not circular "<<endl;
    }
}


//SORT LINKED LIST OF 0s 1s 2s
Node* sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node * temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

/*OUTPUTS
Sample Input 1:
2
1 0 2 1 2 -1
0 0 1 2 -1
Sample Output 1:
0 1 1 2 2 -1
0 0 1 2 -1
*/


//SORT LINKED LIST OF 0s 1s 2s(data replacement not allowed)
Node * sortList(Node * head){
    Node * zeroHead = new Node (-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node (-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node (-1);
    Node * twoTail = twoHead;

    Node * curr = head;
    //create separate LL of 0s,1s,2s
    void insertTail(Node * &tail , Node * curr){
        tail->next = curr;
        tail = curr;
    }
    
    while(curr != NULL){
        int value = curr->data;
        if(value == 0){
            insertTail(zeroTail,curr);
        }
        if(value == 1){
            insertTail(oneTail,curr);
        }
        if(value == 2){
            insertTail(twoTail,curr);
        }

        curr = curr->next;
    }

    //merge 3 sublist
    //1st list not empty
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        //1st list empty
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup Head
    head = zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}


//MERGE 2 SORTED LINKED LIST
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 


// Following is the linked list node structure.

template <typename T>
class Node {
    public:
    T data;
    Node* next;
    Node(T data) {
        next = NULL;
        this->data = data;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


Node<int>* solve(Node<int>* first, Node<int>* second){
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    if(first->next ==NULL){
        first->next = second;
        return first;
    }

    while(next1 != NULL && curr2 != NULL){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){

            //add node in between the 1st ll
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //curr1 and next1 move forward
            curr1 = curr1->next;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first->data <= second->data){
        return solve(first , second);
    }
    else{
        return solve(second , first);
    }
}

/*OUTPUTS
2
1 4 5 -1
2 3 5 -1
7 8 -1
1 3 4 6 -1
Sample Output 1:
1 2 3 4 5 5 -1
1 3 4 6 7 8 -1
*/


//CHECK IF LL IS PALINDROME OR NOT
#include<vector>

class Solution{
    private:
    bool checkPalindrome(vector<int>arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    public:
    bool isPalindrome(Node * head){
        vector<int>arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);

    }
};


//CHECK IF LL IS PALINDROME OR NOT (without taking extra space)



//ADD TWO NUMBERS REPRESENTED BY LINKED LIST
class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertTail(struct Node* &head , struct Node* &tail , int val){
        Node* temp = new Node(val);
        //empty list
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first->data;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            //create node for digit and add ans in LL
            insertTail(ansHead,ansTail , digit);
            carry = sum / 10;
            if(first != NULL){
                first = first->next;
            }
            if(second != NULL){
                second = second->next;
            }
        }
        return ansHead;
    }
    public:

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step1 reverse LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 add 2 LL
        Node* ans = add(first ,second);
        
        //step3 reverse again
        ans = reverse(ans);
        
        return  ans;
    }
};

/*OUTPUTS
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
*/


//CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER (T.C = O(N) , S.C = O(N))
//create clone list method
class Solution
{
    private:
    void insertAtTail(Node * &head , Node* &tail , int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //step1 - create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead , cloneTail , temp->data);
            temp = temp->next;
        }
        
        //step2- create a map
        unordered_map<Node*,Node*>oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        //step3- set random pointer
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){

            // arb == random 
            cloneNode->arb = oldToNew[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};

/*OUTPUTS
Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
*/


//CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER (T.C = O(N) , S.C = O(1))
class Solution
{
    private:
    void insertAtTail(Node * &head , Node* &tail , int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //step1 - create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead , cloneTail , temp->data);
            temp = temp->next;
        }
        
        //step2- clonenodes add in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        //step3- copy random pointer
        temp = head;
        while(temp != NULL){
            if(temp->arb != NULL){
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }
        
        //step4- revert changes done in step2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        //step5- return ans
        return cloneHead;
    }

};

/*OUTPUTS
Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
*/


//MERGE SORT LINKDED LIST (T.C = O(NLOGN) , S.C = O(LOGN))
Node* findMid(Node * head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
Node* merge(Node* left , Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}
Node *sortLL(Node *head){
    //base case
    if(head != NULL || head->next == NULL){
        return head;
    }

    //find mid
    Node* mid = findMid(head);

    //break into two parts
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive calls to sort both halves
    left = sortLL(left);
    right = sortLL(right);

    //merge both ll
    Node* result = merge(left , right);

    return result;
}

/*OUTPUTS
I/P
3
1 -2 3 -1
9 9 -1
4 -1

O/P
Your Output
1 -2 3 -1
9 9 -1
4 -1

Desired Output
-2 1 3 -1
9 9 -1
4 -1*/