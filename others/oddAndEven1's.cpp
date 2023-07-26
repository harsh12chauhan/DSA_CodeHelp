#include <iostream>
#include <vector>
using namespace std ;
  vector<int> evenOddBit(int n) {
      int countEven = 0;
      int countOdd = 0;
      int i = 0;
      while( n  != 0){
          int bit = n & 1;
          n = n>>1;
              if( bit == 1){
                  if((i%2) == 0){
                      countEven++;
                  }else{
                       countOdd++;
                  }
              }
          i++;
          }
        return {countEven,countOdd};
    }
int main() {
    int n;
    cout<<"enter the number: ";
    cin>>n;
   vector<int> value = evenOddBit(n);
   cout<<"even " <<value[0]<<endl;
   cout<<"odd " <<value[1]<<endl;
    return 0;
}