//LINKED LIST AND ITS TYPES

#include<bits/stdc++.h>
using namespace std;
//SINGLY LINKED LIST

class node{
    public:
    int data;
    node * next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node * &head , int d){
    //new node create
    node * temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node * &tail , int d){
    //new node create
    node * temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(node * &head , node * &tail, int position , int d){
    //inserting at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }
    node * temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    //inserting at end
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //new node create
    node * np = new node(d);
    np->next = temp->next;
    temp->next = np;
}
void deleteNode(int pos , node * &head){
    //delete 1st node
    if(pos == 1){
        node * temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //delete middle or last
        node * curr = head;
        node * prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(node * &head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    node * n = new node(10);
    cout<<n->data<<endl;
    cout<<n->next<<endl;

    //head pointed to n
    /*
    node * head = n;
    print(head);
    insertAtHead(head , 12);
    print(head);
    insertAtHead(head , 13);
    print(head);
    */


    //tail pointed to n
    /*
    node * head = n;
    node * tail = n;
    print(head);
    insertAtTail(tail , 12);
    print(head);
    insertAtTail(tail , 13);
    print(head);
    */

    /*
    insertAtPosition(head ,tail , 4 , 22);
    print(head);
    
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    */

    /*
    deleteNode(3 , head);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    */

    return 0;
}

/*OUTPUTS
10 
0 

10 
12 10
13 12 10

10
10 12
10 12 13

10
10 12
10 12 13
10 12 13 22

head : 10
tail : 22

10 12 22

head : 10
tail : 22

*/


//DOUBLY LINKED LIST
class node{
    public:
    int data;
    node * next;
    node * prev;

    //constructor
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    //destructor
    ~node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }
};
//traversing
void print(node * &head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLength(node * &head){
    int len = 0;
    node * temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(node * &head , node * &tail, int data){
    //empty list
    if(head == NULL){
        node * temp = new node(data);
        head = temp;
        tail = temp;
    }
    node * temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp; 
}
void insertAtTail(node * &head , node * &tail , int data){
    //empty list
    if(tail == NULL){
        node * temp = new node(data);
        head = temp;
        tail = temp;
    }
    node * temp = new node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(node * &head , node * &tail , int pos , int d){
    //insertion at start
    if(pos == 1){
        insertAtHead(head , tail , d);
        return;
    }
    
    node * temp = head;
    int cnt = 1;
    
    while(cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }

    //insertion at last
    if(temp->next == NULL){
        insertAtTail(head ,tail,d);
        return;
    }

    //at any position
    node * np = new node(d);
    np->next = temp->next;
    temp->next->prev = np;
    temp->next = np;
    np->prev = temp;
}
void deleteNode(int pos , node * &head){
    //delete 1st node
    if(pos == 1){
        node * temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //delete middle or last
        node * curr = head;
        node * prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    /*for head insertion
    node * n = new node(10);
    node * head = n;

    print(head); 

    cout<<getLength(head)<<endl;

    insertAtHead(head ,tail , 11);
    print(head);

    insertAtHead(head ,tail ,  13);
    print(head);

    insertAtHead(head ,tail, 23);
    print(head);

    insertAtHead(head ,tail, 51);
    print(head);

    cout<<getLength(head)<<endl;
    */

    /*for tail insertion
    node * n = new node(10);
    node * head = n;
    node * tail = n;

    insertAtTail(head , tail,12);
    print(head);

    insertAtTail(head ,tail,22);
    print(head);

    insertAtTail(head , tail,42);
    print(head);

    insertAtTail(head ,tail,46);
    print(head);
    */

    /*
    //for insert at position
    node * n = new node(10);
    node * head = n;
    node * tail = n;

    insertAtTail(head , tail,12);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtTail(head,tail,22);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtTail(head,tail,42);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtTail(head , tail,46);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtPosition(head , tail ,2 , 24 );
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtPosition(head , tail ,1 , 19 );
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;


    insertAtPosition(head , tail ,8 , 39 );
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    //for deletenode
    deleteNode(1 , head);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    deleteNode(3 , head);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    deleteNode(6 , head);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    return 0;

}
*/
/*OUTPUTS
10 
1
11 10
13 11 10
23 13 11 10
51 23 13 11 10
5

10 12 
10 12 22
10 12 22 42
10 12 22 42 46

10 12 
head : 10
tail : 12
10 12 22
head : 10
tail : 22
10 12 22 42
head : 10
tail : 42
10 12 22 42 46
head : 10
tail : 46
10 24 12 22 42 46
head : 10
tail : 46
19 10 24 12 22 42 46
head : 19
tail : 46
19 10 24 12 22 42 46 39
head : 19
tail : 39

memory free for node with data 19 
10 24 12 22 42 46 39
head : 10
tail : 39
memory free for node with data 12 
10 24 22 42 46 39
head : 10
tail : 39
memory free for node with data 39 
10 24 22 42 46
head : 10
tail : 39
*/


//CIRCULAR LINKED LIST
/*
class node{
    public:
    int data;
    node * next;

    //constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
void insertNode(node * &tail , int element , int d){
    //assuming that the element is present in the list

    //empty list
    if(tail == NULL){
        node * temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        node * curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        //element found after searching
        node * temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(node * tail){
    node * temp = tail;
    
    //empty list
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}
void deleteNode(node* &tail , int value){
    //empty list
    if(tail == NULL){
        cout<<"List is empty,check again"<<endl;
    }
    else{
        //non-empty list
        //assume that the value is present in the linked list
        node* prev = tail;
        node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        //for 1 node linked list
        if(curr == prev){
            tail = NULL;
        }
        //for >=2 node linked list 
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;

    }
}
int main(){
    node * tail = NULL;

    //empty list insertion
    insertNode(tail, 5 , 3);
    print(tail);
    insertNode(tail, 3 , 5);
    print(tail);
    insertNode(tail, 5 , 7);
    print(tail);
    insertNode(tail, 7 , 9);
    print(tail);

    //insertion in between
    insertNode(tail, 5 , 8);
    print(tail);
    insertNode(tail, 9 , 10);
    print(tail);
    insertNode(tail, 3 , 4);
    print(tail);

    //deletion
    /*
    deleteNode(tail , 3);
    print(tail);
    deleteNode(tail , 10);
    print(tail);
    deleteNode(tail , 5);
    print(tail);
    */
}

/*OUTPUTS
3 
3 5
3 5 7
3 5 7 9

3 5 8 7 9
3 5 8 7 9 10
3 4 5 8 7 9 10

memory is free for node with data 3
10 4 5 8 7 9
memory is free for node with data 10
9 4 5 8 7
memory is free for node with data 5
9 4 8 7
*/