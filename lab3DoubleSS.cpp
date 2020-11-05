#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;





int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int j = 0; j < k; j++){
        cin >> b[j];
        vector<int>::iterator it, it1;
        auto it = lower_bound(a.begin(), a.end(), b[j]) - n;
        auto it1 = upper_bound(a.begin(), a.end(), b[j]) - n;
        cout << it << " " << it1 << endl;
    }

    return 0;
}