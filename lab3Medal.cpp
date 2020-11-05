#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
   int n,num,sbig = 0,fbig = 0;
   cin >> n;
   while(n > 0){
       cin >> num;
        if(num > fbig){
            sbig = fbig;
            fbig = num;
        } else if(num > sbig && num!= fbig){
            sbig = num;
        }
       n--;
   }
    cout << sbig;
    return 0;
}