//FOUR PILLARS (ENCAPSULATION , )

#include<iostream>
using namespace std;

//ENCAPSULATION
/*
class employee{
    private:
        string name;
        int age;
        int height;
    public:
        void setAge(int x){
            age = x;
        }
        int getAge(){
            return this->age;
        }
};

int main(){
    employee e;
    e.setAge(34);
    
    cout<<"The age of student is "<<e.getAge()<<endl;

    return 0;
}
*/
/*OUTPUTS
The age of student is 34
*/


//INHERITENCE
/*
class human{
    public:
        int height;
        int weight;
        int age;

        int getAge(){
            return this->age;
        }
        void setAge(int a){
            age = a;
        }
};
class male : public human{
    public:
        string color;

        void sleep(){
            cout<<"Male sleeping"<<endl;
        }
};
int main(){
    male m1;
    cout<<m1.age<<endl;
    cout<<m1.weight<<endl;
    cout<<m1.height<<endl;

    cout<<m1.color<<endl;

    m1.sleep();
    m1.setAge(23);
    cout<<m1.getAge()<<endl;
    return 0;
}
*/
/*OUTPUTS
-1074627723
1972948160
6422476

Male sleeping
23
*/

//single inheritance
/*
class animal{
    public:
    int age;
    int weight;

    void speak(){
        cout<<"Speaking "<<endl;
    }
};
class dog : public animal{

};
int main(){
    dog d;
    d.speak();
    cout<<d.age<<endl;

    return 0;
}
*/
/*OUTPUTS
Speaking 
6422352
*/

//multilevel inheritance
/*
class animal{
    public:
    int age;
    int weight;

    void speak(){
        cout<<"Speaking "<<endl;
    }
};
class dog : public animal{

};
class germanShepherd : public dog{

};
int main(){
    germanShepherd g;
    g.speak();
    cout<<g.age<<endl;

    return 0;
}
*/
/*OUTPUTS
Speaking 
6422352
*/

//multiple inheritance
/*
class animal{
    public:
    void bark(){
        cout<<"Barking "<<endl;
    }
};
class human{
    public:
    string color;
    
    void speak(){
        cout<<"Speaking "<<endl;
    }
};
class hybrid : public animal ,public human{

};

int main(){
    hybrid h;

    h.bark();

    h.speak();

    return 0;
}
*/
/*OUTPUTS
Barking 

Speaking
*/

//heirarical inhertiance
/*
class A {
    public:
    void fun1(){
        cout<<"Inside fun 1 "<<endl;
    }
};
class B : public A{
    public:
    void fun2(){
        cout<<"Inside fun 2 "<<endl;
    }
};
class C : public A{
    public:
    void fun3(){
        cout<<"Inside fun 3 "<<endl;
    }
};
int main(){
    A a;
    a.fun1();

    B b;
    b.fun1();
    b.fun2();

    C c;
    c.fun1();
    c.fun3();

    return 0;
}
*/
/*OUTPUTS
Inside fun 1 

Inside fun 1
Inside fun 2

Inside fun 1
Inside fun 3
*/

//hybrid inheritance
/*
class A {
    public:
    void fun1(){
        cout<<"fun1"<<endl;
    }
};
class D {
    public:
    void fun4(){
        cout<<"fun4"<<endl;
    }
};
class B : public A{
    public:
    void fun2(){
        cout<<"fun2"<<endl;
    }
};
class C : public A , public D{
    public:
    void fun3(){
        cout<<"fun3"<<endl;
    }
};
int main(){

    A a;
    a.fun1();

    B b;
    b.fun1();
    b.fun2();

    C c;
    c.fun1();
    c.fun3();
    c.fun4();

    D d;
    d.fun4();


    return 0;
}
*/
/*OUTPUTS
fun1

fun1
fun2

fun1
fun3
fun4

fun4
*/

//inheritance ambiguity
/*
class A {
    public:
    void fun(){
        cout<<"i am fun from A"<<endl;
    }
};
class B {
    public:
    void fun(){
        cout<<"i am fun form B"<<endl;
    }
};
class C : public A , public B{

};
int main(){

    C c;

    // c.fun();           // not work due to ambiguity
    c.A ::fun();

    c.B ::fun();

    return 0;
}
*/
/*OUTPUTS
i am fun from A

i am fun form B
*/


//POLYMORPHISM (compile/static and run time/dynamic)

//compile time polymorphism (function overloading)
/*
class A {
    public:
    void sayHello(){
        cout<<"hello"<<endl;
    }
    void sayHello(string name){
        cout<<"hello "<<name<<endl;
    }
};
int main(){
    A a;
    a.sayHello();
    a.sayHello("shivam");

    return 0;
}
*/
/*OUTPUTS
hello
hello shivam
*/

//compile time polymorphism (operator overloading)
/*
class B{
    public:
    int a ; 
    int b;

    int add(){
        return a + b;
    }

    void operator+ (B &b){
        int v1 = this->a;
        int v2 = b.a;
        cout<<"output : "<<v2 - v1 <<endl;

        cout<<"I am + operator "<<endl;
    }

    void operator() (){
        cout<<"I am bracket"<<endl;
    }
};
int main(){
    B b1 , b2;
    b1.a = 4;
    b2.a = 7;

    b1 + b2 ;

    b1();
}
*/
/*OUTPUTS

output : 3
I am + operator

I am bracket
*/

//run time polymorphism (method / functional overriding)
/*
class animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class dog : public animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};
int main(){
    dog d;
    d.speak();

    return 0;
}
*/
/*OUTPUTS
Barking                    if dog -> speak not then "Speak" output
*/


//ABSTRACTION
//implementation hiding
