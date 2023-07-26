#include <iostream>
using namespace std;
// used for macros
#define PI 3.14

//used for globle variables
int size = 5;
void fun1(){
    cout<<"the value of globle variable in fun1: "<<size<<endl;
}

void fun2(){
    cout<<"the value of globle variable in fun2: "<<size<<endl;
}

//used for inline functions 
inline int getMax(int a,int b){
    return (a>b)?a:b;
}

//used for default argument
int sum(int a,int b =2){
    return (a + b);
}

int main(){
// macros===================================
    // int r = 5;
    // double areaofcircle = 2*PI*r;
    // cout<<areaofcircle<<endl;

//globle variables=========================
    //cout<<"the value of globle variable in main: "<<size<<endl;
    //fun1();
    //fun2();

//Inline functions ==========================
    // int a = 2;
    // int b = 3;
    // int ans = getMax(a,b);
    // cout<<ans<<endl;

//default arguments========================
    // int a = 2;
    // int b = 3;
    // cout<<"only passing 'a' as the argument : "<<sum(a)<<endl;
    // cout<<"passing both(a,b) as the argument :"<<sum(a,b)<<endl;



return 0;
}