// squre root using binary search
#include <iostream>
using namespace std;

long long int sqrInteger(int x){
        int s = 0;
        int e = x;
        long long int ans = -1;
        long long int mid= s+(e-s)/2;
        while(s<=e){
            long long int num = mid * mid;
            if(num == x){
                return mid;
            }
            if(num > x){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid + 1;
            }
            mid = s +(e-s)/2;
        }
        return ans;
}
double morePrecision(int n,int precision,int tempsol){
    
    double factor = 1;
    double ans = tempsol;

    for(int i = 0; i<precision ;i++){
        factor = factor/10;
        for(double j = ans; j*j < n; j = j + factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
int n;
cout<<"Enter the number: ";
cin>>n;
int tempSol = sqrInteger(n);
cout<<"Answer is : "<<morePrecision(n, 3,tempSol);
return 0;
}