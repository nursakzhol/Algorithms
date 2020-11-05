#include <iostream>
#include <vector>
using namespace std;

string bin_search(vector<int> &a, int k){
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if(a[m] == k)
            return "YES" ;
        if (a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    if (a[l] == k)
        return "YES";
    if (a[r] == k)
        return "YES";
    return "NO";
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < k; j++)
    {
        cin >> b[j];
        cout << bin_search(a, b[j]) << endl;
    }
    
    

    return 0;
}