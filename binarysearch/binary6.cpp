// book alaocation problem
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool isPossible( vector<int> &pages ,int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i =0 ;i<n;i++){
        if((pageSum + pages[i]) <= mid){
            pageSum += pages[i];
        }else{
            studentCount++;
            if(studentCount > m || pages[i] > mid){
                return false;
            }
            pageSum = pages[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> &pages, int n, int b)
{

    if( n < b){
        return -1;
    }
	int s =0;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        sum += pages[i];
    }
    int e = sum;
    int mid = s + (e - s)/2;
    int ans = -1;
    
    while(s<=e){
        if(isPossible(pages,n,b,mid)){
            ans = mid;
            e = mid - 1; 
        }else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int main(){
vector<int> pages = {10 ,20 ,30 ,40 ,50 };
int n = 5;
int m = 6;
int value  = allocateBooks(pages,n,m);
cout<<value;
return 0;
}