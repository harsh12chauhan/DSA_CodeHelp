#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main(){

//creation ==========================
    // map<string,int> mp; //prints in sequencial order
    unordered_map<string,int> m; // prints in random order

//insertion =========================
    //1 way -> 
    pair<string,int> p = make_pair("harsh",3);
    m.insert(p);
    //2 way -> 
    pair<string,int> p2("hello",1);
    m.insert(p2);
    //3 way -> 
    pair<string,int> p3 = {"hey",3};
    m.insert(p3);
    //4 way ->
    m["newhello"] = 1;
    //this will update the value
    m["newhello"] = 3;

//searching ========================
    cout<<m["harsh"]<<endl;
    cout<<m.at("hey")<<endl;

    // below line is tricky --
    cout<<m["bottle"]<<endl;   // this will create new entry if not present in map
    cout<<m.at("bottle")<<endl; // this will through error if not present in map


// size ==========================
    cout<< m.size()<<endl;

// count =======================
    cout<<m.count("harsh")<<endl; //if element is present the 1 else 0

//erase =======================
    m.erase("harsh"); // this will erase the entry of element

// accessing key values in map ============
    //1 way ---------------------->
    // cout<<"printing the key values of map ->"<<endl;
    // for(auto i:m){
    //     cout<<i.first <<" -> "<<i.second<<endl;
    // }
    // cout<<endl;

    // 2  way ------------------->
    cout<<"printing the key values of map ->"<<endl;
    unordered_map<string,int> :: iterator it  = m.begin();

    while(it != m.end()){
        cout<<it->first <<" -> "<<it->second<<endl;
        it++;
    }
    cout<<endl;

return 0;
}