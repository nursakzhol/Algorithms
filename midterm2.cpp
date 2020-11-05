#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

vector<char> ch;


void quicksort(vector<char> &ch, int l, int r)
{
    int i =  l;
    int j = r;
    char p = ch[(l+r)/2];

    while (i < j)
    {
        while(ch[i] < p) i++;
        while(ch[j] > p) j--;
        if(i <= j)
        {
            swap(ch[i], ch[j]);
            i++;
            j--;
        }
    }

    if(l < j)
        quicksort(ch, l, j);
    if(i < r)
        quicksort(ch, i, r);
    
}



void dividevow(vector<char> ch){
   
    vector<char> vowel;
    vector<char> cons, result;
    for (int i = 0; i < ch.size(); i++)
    {
        if(ch[i] == 'a' ||ch[i] == 'e' || ch[i] == 'u' || ch[i] == 'o' || ch[i] == 'i')
            vowel.push_back(ch[i]);
        else
            cons.push_back(ch[i]);

    }
    if(vowel.size() > 1)
    quicksort(vowel, 0, vowel.size() - 1);
    if(cons.size() > 1)
    quicksort(cons, 0, cons.size() -1);
    

    for(int i = 0; i < vowel.size(); i++)
        result.push_back(vowel[i]);

    for (int i = 0; i < cons.size(); i++)
    {
        result.push_back(cons[i]);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    
    
}

int main(){
    int n;
    cin >> n;
    char s;

    for (int i = 0; i < n; i++){    
        cin >> s;
        ch.push_back(s);
    }
    dividevow(ch);
    return 0;
}