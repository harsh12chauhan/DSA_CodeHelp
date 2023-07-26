#include <iostream>
using namespace std;
int power(int n , int p ){
    int ans = 1;
    while(p--){
        ans *= n;
    }
    return ans;
}

int convertToDecimal(int n){
    int answer = 0 ;
    int i = 0;
    while (n!=0)
    {
        int bit = n & 1;
        answer = (bit * power(10,i)) + answer;
        cout<<bit<<" * "<<" ( 10 ^"<<i<<") + "<<answer<<endl;
        n = n>>1;
        i++;
    }
    return answer;
}

int reverserNumber(int n){
    int value = 0;
    while (n != 0)
    {
        int lstD = n % 10;
        value = (value + lstD)*10;
        n = n /10;
    }
    return value/10 ;
}


int main(){
int n;
cout<<"enter the number : ";
cin>>n;
int decimal = convertToDecimal(n);
// int decimal = reverserNumber(n);
cout<<decimal;

return 0;
}