#include <iostream>

using namespace std;

void quicksort(long long a[], int l, int r)
{
    int i =  l;
    int j = r;
    int p = a[(l+r)/2];

    while (i < j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(l < j)
        quicksort(a,l, j);
    if(i < r)
        quicksort(a,i, r);
    
}

void product(long long a[], int j){
    if(j < 2)
        cout << "-1" << endl;
    
    else if (j == 2)
        { 
            long long k;
            for (int i = 0; i <= j; i++)
            {
               
               k = a[0]*a[1]*a[2];
               
            }
            cout << k << endl;
            
        }
   else if(j > 2)
        {   
            
            quicksort(a,0, j);
            long long k;
            for (int i = 0; i <= j; i++)
            {
            
              k = a[j]*a[j - 1]*a[j - 2];
            
            }
            cout << k << endl;
            
        }
        
        
    
    
}

int main(){
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
       product(a, i);
    }
    
}