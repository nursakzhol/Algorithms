#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
    int q, b, c;
    cin >> q >> b >> c;
    a.push_back(q);
    a.push_back(b);
    a.push_back(c);
    }
    

    return 0;
}