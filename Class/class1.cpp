#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero{
    private:
        int health=0;
        char level = '?';
        char*name;
    public:
        static int timetocomplete;
    //default constructor====================
    Hero(){
        cout<<"simple Constructor called !!"<<endl;
        name = new char[100];
    }

    //parameterized constructor==============
    Hero(int health){
        cout<<"parameterized constructor called"<<endl;
        cout<<"value of this : "<<this<<endl;
        this->health = health;
    }

    //multi-parameterized constructor========
    Hero(int health,char level){
        cout<<"multi-parameterized constructor called"<<endl;
        this->health = health;
        this->level = level;
    }

    // copy constructor deep copy=======================
    Hero(Hero& temp){
        cout<<"aapna copy constructor: "<<endl;

        char*ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }

        int value = 0;
        int getHealth(){
            return health;
        }
        char getLevel(){
            return level;
        }
        void setHealth(int h){
            health = h;
        }
        void setLevel(char l){
            level = l;
        }
        void print(){
            cout<<endl;
            cout<<" [ "<<this->name<<" ";
            cout<<" "<<this->health<<" ";
            cout<<" "<<this->level<<" ] "<<endl<<endl;
        }
        void setName(char name[]){
            strcpy(this->name,name);
        }

        static int random(){
            return timetocomplete;
        }

        ~Hero(){
            cout<<" destructor called !"<<endl;
        }
};

int Hero :: timetocomplete = 5;
int main(){
//static way==================================================
    // Hero ram; // static 

    // cout<<"health of ram before setting is : "<<ram.getHealth()<<endl;
    // cout<<"level of ram before setting is : "<<ram.getLevel()<<endl;
    // cout<<"value of ram before setting is :"<<ram.value<<endl; 
    // cout<<endl;
    // cout<<endl;

    // ram.setHealth(100);
    // ram.setLevel('A');
    // ram.value =  1;

    // cout<<"health of ram after setting is : "<<ram.getHealth()<<endl;
    // cout<<"level of ram after setting is : "<<ram.getLevel()<<endl;
    // cout<<"value of ram after setting is :"<<ram.value<<endl; 

// dynamic way================================================
    // Hero*h = new Hero; // dynamic 

    // cout<<"before dynamic health values: "<<h->getHealth()<<endl;
    // cout<<"before dynamic level values: "<<h->getLevel()<<endl;
    // cout<<"before dynamic values: "<<h->value<<endl;

    // h->setHealth(20);
    // h->setLevel('C');
    // h->value = 2;

    // cout<<"dynamic after health values: "<<h->getHealth()<<endl;
    // cout<<"dynamic after level values: "<<h->getLevel()<<endl;
    // cout<<"dynamic after values: "<<h->value<<endl;
    
    // delete h;

//constructor==================================================
    // cout<<"before: "<<endl;
    // Hero ram; //static

    // Hero*h = new Hero; //dynamic 
    // delete h;
    // cout<<"after: "<<endl;

// parameterized constructor==================================
    // Hero harsh(100); //static 
    // cout<<"address of harsh is: "<< &harsh<<endl;
    // cout<<"value of health: "<<harsh.getHealth()<<endl;

    // Hero*harsh = new Hero(100); //dynamic 
    // cout<<"address of harsh is: "<<harsh<<endl;
    // cout<<"value of health: "<<harsh->getHealth()<<endl;

//copy constructor=============================================
    // Hero harsh(100,'A');
    // cout<<"values of harsh :-"<<endl;
    // harsh.print();

    // Hero yash(harsh);
    // cout<<"values of yash :-"<<endl;
    // yash.print();

//shallow copy (copy constructor)===============================

    // Hero hero1;
    // hero1.setHealth(70);
    // hero1.setLevel('D');
    // char name[6] = "harsh";
    // hero1.setName(name);

    // hero1.print();

    // Hero hero2(hero1);
    // char name1[5] = "yash";
    // hero2.setName(name1);

    // hero2.print();
    // cout<<endl<<"printing hero1 ::>"<<endl;
    // hero1.print();
    /*shallow copy constructor copys the address of the array 
      thats why it change the value of the main array */

//deep copy (copy constructor)===============================
    // Hero hero1;
    // hero1.setHealth(70);
    // hero1.setLevel('D');
    // char name[6] = "harsh";
    // hero1.setName(name);

    // hero1.print();

    // Hero hero2(hero1);
    
    // hero2.print();
    // char name1[5] = "yash";
    // hero1.setName(name1);

    // hero1.print();
    // cout<<"value of hero2 > .."<<endl;
    // hero2.print();
    /* deep copy creates new memory , not use the same memory*/

// destructor===================================================

    // Hero hero1; //static(automatically destructor called)

    // Hero*h = new Hero; //dynamic (mannualy we have to call destructor)
    // delete h;
// static keyword===============================================

    // cout<<Hero::timetocomplete<<endl; //keyword
    // cout<<Hero::random()<<endl; //function

return 0;
}