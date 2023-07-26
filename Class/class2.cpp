#include <iostream>
using namespace std;
//parent calss============
class Human{
    public:
    int height;
    int weight;
    int age;

    int getHeight(){
        return height;
    }
    int getweight(){
        return weight;
    }
    int getAge(){
        return age;
    }
    void setHeight(int height){
        this->height = height;
    }
    void setWeight(int weight){
        this->weight = weight;
    }
    void setAge(int age){
        this->age = age;
    }
};
// child class==============================================
class Male:public Human{
    public:
        string color;
    
        string getColor(){
            return color;
        }
        void setColor(string color){
            this->color = color;
        }
};
// inheritence==========================================================
/*  single inheritence
    milti-level inheritence
    multiple inheritence
    hybrid inheritence
    hierarchial inheritence
*/
//polymorphism (overloading)=============================================================
    class Overload{
        public:
        int a=2;
        int b=3;
        string s;
        char ch;
//function overloading=======================================
        void add(){
            cout<<"value of a & b: (1)-> "<<this->a<<" "<<this->b<<endl;
        }
        void add(int a){
            cout<<"value of a & b: (2)-> "<<a<<" "<<this->b<<endl;
        }
        void add(int s,int b){
            cout<<"value of a & b: (3)-> "<<a<<" "<<b<<endl;
        }
        void add(string a,int b){
            cout<<"value of a & b: (3)-> "<<a<<" "<<b<<endl;
        }
        void add(char ch,int b=3,int c = 4){
            cout<<"value of a & b: (4)-> "<<a<<" "<<b<<" "<<c<<endl;
        }
//operator overloading======================================
        void operator+(Overload &obj){
            int value1 = this->a;
            int value2 = obj.a;
            cout<<"output "<<value2 - value1<<endl;
        }
        void operator() (){
            cout<<"mai bracket hu"<<this->a<<endl;
        }
    };
class Animal{
    public:
        void speak(){
            cout<<"Speaking"<<endl;
        }
};
class Dog:public Animal{
    public:
        void speak(){
            cout<<"Barking "<<endl;
        }
};

int main(){
//inheritence=================================================

    // Male m1;
    // cout<<"height of male before call is --> "<<m1.getHeight()<<endl;
    // cout<<"weight of male before call is --> "<<m1.getweight()<<endl;
    // cout<<"age of male before call is --> "<<m1.getAge()<<endl;
    // cout<<"color of male before call is --> "<<m1.getColor()<<endl;
    // cout<<endl;
    // m1.setAge(22);
    // m1.setHeight(6);
    // m1.setWeight(64);
    // m1.setColor("skin");
    // cout<<endl;
    // cout<<"height of male after call is --> "<<m1.getHeight()<<endl;
    // cout<<"weight of male after call is --> "<<m1.getweight()<<endl;
    // cout<<"age of male after call is --> "<<m1.getAge()<<endl;
    // cout<<"color of male after call is --> "<<m1.getColor()<<endl;

// polymorphism =======================================================
    //compile time polymorphism==========================
    //function overloading===========================
    // Overload obj;
    // obj.add();
    // obj.add(12);
    // obj.add('A');
    // obj.add("harsh",12);
    
    //operator overloading===========================
    // Overload obj1,obj2;
    // obj1.a = 4;
    // obj2.a = 7;
    // obj1 + obj2; //output 3
    // obj1();  // output  = > mai bracket hu4


    //run time polymorphism==========================
    // Dog d;
    // d.speak();


return 0;
}