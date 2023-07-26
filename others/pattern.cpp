#include<iostream>
using namespace std;

void printpattern(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout<<" *";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<" "<<i;
        }
        for (int j = 1;j < i;j++)
        {
            cout<<" "<<i;
        }
        for (int j = i; j < n-1; j++)
        {
            cout<<" *";
        }
        cout<<endl;
    } 
}
void secondprintpattern(int n ){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout<<" *";
        }
        for (int j = 1; j < n; j++)
        {
            cout<<" "<<j;
        }
        // for (int j = n; j > i ; j--)
        // {
        //     cout<<" "<<j;
        // }
        
        
        cout<<endl;
    }
    
}

int main (){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    // printpattern(n);
    secondprintpattern(n);
    return 0;
}