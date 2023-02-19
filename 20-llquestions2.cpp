//DETECT LOOP (normal , floyd) , FIND STARTLOOP NODE , REMOVE LOOP

#include<iostream>
#include<map>
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
void insertAtHead(Node * &head , int d){
    //new Node create
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node * &tail , int d){
    //new Node create
    Node * temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node * &head , Node * &tail, int position , int d){
    //inserting at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }
    Node * temp = head;
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

    //new Node create
    Node * np = new Node(d);
    np->next = temp->next;
    temp->next = np;
}

void print(Node * &head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
bool detectLoop(Node * head){

    if(head == NULL){
        return false;
    }

    map<Node * , bool>visited;

    Node * temp = head;

    while(temp != NULL){
        //cycle is present
        if(visited[temp] == true){
            cout<<'present on element : '<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node * floydDetect(Node * head){
    if(head == NULL){
        return NULL;
    }
    
    Node * slow = head;
    Node * fast = head;
    
    while(slow != NULL && fast != NULL){

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            cout<<"cycle present at : "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node * getStartingNode(Node * head){
    if(head == NULL){
        return NULL;
    }

    Node * intersection = floydDetect(head);
    Node * slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeLoop(Node * head){
    if(head == NULL){
        return;
    }

    Node * startOfLoop = getStartingNode(head);
    Node * temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;

    cout<<"After remove loop LL is : "<<endl;
}
int main(){
    Node * n = new Node(10);
    Node * head = n;
    Node * tail = n;

    insertAtTail(tail , 12);
    insertAtTail(tail , 13);
    insertAtTail(tail , 16);

    // insertAtPosition(head ,tail , 4, 22);
    print(head);

    //for create a loop
    tail->next = head ->next;

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    // print(head);

    // if(detectLoop(head)){
    //     cout<<"Cycle is present"<<endl;
    // }
    // else{
    //     cout<<"Cycle is absent "<<endl;
    // }
    if(floydDetect(head)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is absent "<<endl;
    }

    Node * loop = getStartingNode(head);
    cout<<"loop starts at : "<<loop->data<<endl;

    removeLoop(head);
    print(head);

    return 0;
}


/*OUTPUTS
//normal method
10 12 13 22 
head : 10
tail : 22  
194826908812 //expected ->> present on element : 12
Cycle is present

//floyd detection method
10 12 13 16 
head : 10
tail : 16
cycle present at : 16
Cycle is present

loop starts at : 12

cycle present at : 16
After remove loop LL is :
10 12 13 16
*/


//DETECT AND REMOVE LOOP (IN CN)
/*
Node * floydDetect(Node * head){
    if(head == NULL){
        return NULL;
    }
    
    Node * slow = head;
    Node * fast = head;
    
    while(slow != NULL && fast != NULL){

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}
Node * getStartingNode(Node * head){
    if(head == NULL){
        return NULL;
    }

    Node * intersection = floydDetect(head);
    if(intersection == NULL){
        return NULL;
    }
    Node * slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head == NULL){
        return NULL;
    }

    Node * startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL){
        return head;
    }
    Node * temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
*/

/*OUTPUTS
Sample Input:
6 2
1 2 3 4 5 6 
Sample Output:
1 2 3 4 5 6
*/