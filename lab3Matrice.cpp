#include <iostream>
#define MAX 800

using namespace std;



int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int minRow[MAX], maxCol[MAX];
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        minRow[i] = 1000;
        for(int j = 0; j < m; j++)
            if(a[i][j] < minRow[i])
                minRow[i] = a[i][j];
    }

    for(int j = 0; j < m; j++){
        maxCol[j] = -1000;
        for(int i = 0 ; i < n; i++)
            if(a[i][j] > maxCol[j])
                maxCol[j] = a[i][j];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((a[i][j] == maxCol[j]) && (a[i][j] == minRow[i]))
                res++;
    cout << res;
    return 0;
}