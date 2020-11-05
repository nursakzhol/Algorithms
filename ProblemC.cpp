#include <iostream>
#include <algorithm>

using namespace std;

int n, l1, r1, l2, r2;
int a[100010];
int k;

int number_of_less(int limit){
    int l = 0;
    int r = n - 1;
    int res = -1;

    while (l <= r)
    {
        int mid =  (l+r) / 2;
        if(a[mid] <= limit){
            res = mid;
            l = mid + 1;
        }else
        {
            r = mid - 1;
        }
        
    }
    
    if(res == -1)
        return 0;
    return res + 1;


}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < k; i++)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << number_of_less(13);
    }
    

    

    return 0;
}