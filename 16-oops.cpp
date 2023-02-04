//OOPS

#include<iostream>
#include<string.h>
// #include "file name"
using namespace std;
class hero{
private:
    int health;
public:
    char level;
    char *name;
    static int timeToComplete;

    //default constructor
    hero(){
        cout<<"Default Constructor called"<<endl;
        name = new char[100];
    }

    //parameterised constructor
    hero(int health){
        cout<<"this-> "<<this<<endl;
        this->health = health;
    }
    //parameterised constructor
    hero(int health , char level){
        cout<<"this-> "<<this<<endl;
        this->health = health;
        this->level = level;
    }

    //copy constructor
    // hero(hero &temp){
    //     cout<<"copy constructor called "<<endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    //copy constructor for deep copy
    hero(hero &temp){
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;
        cout<<"copy constructor called "<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }


    void print(){
        cout<<"health : "<<this->health<<endl;
        cout<<"level : "<<this->level<<endl;
        cout<<"name : "<<this->name<<endl;
    }
    

    int gethealth(){
        return health;
    }
    int getlevel(){
        return level;
    }

    void sethealth(int h){
        health = h;
    }
    void setlevel(char l){
        level = l;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }

    static int random(){
        // return health;             //cannot access that
        return timeToComplete;
    }

    //destructor
    ~hero(){
        cout<<"Destructor called"<<endl;
    }
    
};
//initialization for static
int hero :: timeToComplete = 5;

int main(){ 
    //static allocation
    hero h1;
    cout<<"size: "<<sizeof(h1)<<endl;
    cout<<"for empty objects sizeof obj is 1"<<endl;               //1

    // h1.health = 78;
    // cout<<"health is : "<<h1.health<<endl;

    h1.sethealth(78);
    h1.level = 'a';
    cout<<"health is : "<<h1.gethealth()<<endl;
    cout<<"level is : "<<h1.level<<endl;


    //daynamic allocation
    hero * h2 = new hero;                             //simialry( int * a = new int;)
    h2->sethealth(90);
    h2->setlevel('b');

    cout<<"health by dereference : "<<(*h2).gethealth()<<endl;
    cout<<"health by arrow : "<<h2->gethealth()<<endl;
    
    cout<<"level by dereference : "<<(*h2).level<<endl;
    cout<<"level by arrow : "<<h2->level<<endl;

    hero h3(10);
    cout<<"Address of h3 : "<<&h3<<endl;                 //same as paramaterised constructor address

    hero h4(10, 'c');
    cout<<"Address of h4 : " <<&h4 <<endl;                 //same as paramaterised constructor address

    hero h5(90 , 'c');
    h5.print();

    hero h6(h5);                                        //copy constructor
    // hero h6 = h5;                                    //same above 
    h6.print();

    hero h7;
    h7.sethealth(12);
    h7.setlevel('D');
    char name[7] = "Shivam";
    h7.setName(name);
    h7.print();

    //use default copy constructor
    hero h8(h7);
    h8.print();

    h7.name[0] = 'T';                                   //shallow copy (change original name)
    h7.print();

    // h8.print();                                      //print name : Thivam   (default copy constructor called == shallow copy)                                 
    h8.print();                                         //print name : shivam   (original (copy constructor called) == deep copy)                                  

    //copy assignment operator
    h7 = h8;
    cout<<endl;
    h7.print();
    h8.print();

    //its belong to class not object
    cout<<hero:: timeToComplete<<endl;

    cout<<hero :: random()<<endl;


}   


/*OUTPUT
Default Constructor called
size: 12
for empty objects sizeof obj is 1

health is : 78
level is : a

Default Constructor called      
health by dereference : 90      
health by arrow : 90

level by dereference : b        
level by arrow : b

this-> 0x61fee4

Address of h3 : 0x61fee4   

this-> 0x61fed8

Address of h4 : 0x61fed8   

this-> 0x61fecc

health : 90
level : c
//name : â∞∟╟♦$☺         //wrong name due to uncomment our copy constructor

health : 90
level : c
name : â∞∟╟♦$☺

Default Constructor called      
health : 12
level : D
name : Shivam

//default copy constructor called
health : 12
level : D
name : Shivam

health : 12
level : D
name : Thivam

health : 12
level : D
// name : Thivam
name : Shivam

health : 12
level : D
name : Shivam
health : 12
level : D
name : Shivam

5

5

//desturctor not called for static memory , only for dynamic memory
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
*/