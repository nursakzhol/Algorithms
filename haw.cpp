#include <iostream>
#include <vector>
#define ll long long

using namespace std;


int hash(string s){
int p = 31;
ll p_pow = 1;
ll sum = 0;
ll n = s.size() - 1;
for(int i = 0; i < n; i++){
    sum += (s[i] - 'a' + 1) * p_pow;
    p_pow *= p;
}
return sum;
}

int main(){
    int n;
    vector<string> st;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        st.push_back(s);
    }

    for (int i = 0; i < st.size(); i++)
    {
        if(hash(st[i]) == hash(st[i+1])){
           cout << "Good" << endl;
        }
        else
        {
            cout << "Not good" << endl;
        }
        
    } 
    

    return 0;
}