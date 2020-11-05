#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MaxHeap{
    public:
    vector<int> a;
    int key;
    int parent(int i){
        return (i-1) / 2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    void SiftUp(int i){
        while(int(a.size()) - 1 > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
       
    }

    int SiftDown(int i){
        if (i > int(a.size()) - 1)
            return 0;
      
        int swapId = i;

        if(left(i) <= int(a.size()) - 1 && a[i] < a[left(i)]){
            swapId = left(i);
        }
        if(right(i) <= int(a.size()) - 1 && a[swapId] < a[right(i)]){
            swapId = right(i);
        }
 
        if(swapId!=i){
            swap(a[i], a[swapId]);
            return SiftDown(swapId);
        } else
        {
            return i + 1;
        }
    }

    void deletenode(int i){
        cout << a[i] << endl;
        swap(a[i],a[int(a.size()) - 1]);
        a.pop_back();
        
        if(a[i] > a[parent(i)])
            SiftDown(i);
        else
            SiftUp(i);
    }

    void insert(int k){
        a.push_back(k);
        int i = a.size() - 1;
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        // cout << i+1 << endl;
    }

    pair<int, int> extractMax(){
        int maxNum = a[0];
        swap(a[0], a[int(a.size())-1]);
        a.pop_back();
        if(a.empty()){
            return make_pair(0, maxNum);
        } else
        {
            return make_pair(SiftDown(0), maxNum);
        }
        
       
    }

    int extractMin()
    {
        int minim = a[0];
        for (int i = 0; i < int(a.size()) - 1; i++)
        {
            int minimum = min(minim, a[i]);
            return minimum;
        }
        
        
    }
    bool isEmpty(){
        return a.size() == 0;
    }

    int getMax(){
        return a[0];
    }


    void increaseKey(int i, int new_number){
        a[i] = a[i] + new_number;
        SiftDown(i);
    }
    
    void decreaseKey(int i, int new_number){
        a[i] = a[i] - new_number;

    }
    
   
    void print() {
        for (int i = 0; i < int(a.size()); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    int getSize(){
        return int(a.size());
    }

    void heap_sort(){
        for(int i = int(a.size()) - 1; i >= 0;i-- ){
            swap(a[0], a[i]);
            SiftDown(i);
        }
    }

    void build_heap2(){
        for(int i = int(a.size()) - 1 ; i >= 0; i--)
        
            SiftDown(i);

    }
};

int main(){
    MaxHeap *PriorityQueue = new MaxHeap();
    // vector<int> inputt;
    // int k, a;
    // cin >> k;
    // for(int i = 0; i < k; i++){
    //     cin >> a;
    //     PriorityQueue->insert(a);
    //     inputt.push_back(a);        
    // }

    // int b;
    // cin >> b;
    // for(int j = 0; j < b; j++){
    //     int c,d;
    //     cin >> c >> d;
    //     PriorityQueue->decreaseKey(c-1, d);
    //     cout << PriorityQueue->SiftDown(c-1) << endl;
    // }
    
    // for(int i=0; i<k - 1; i++){
    //     pair<int, int> z = PriorityQueue->extractMax();
    //     cout <<z.first << " " << z.second << "\n";
    // }
   
    int n, x;
    long long k = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        PriorityQueue->insert(a);
    }
 
    for(int i = 0; i < x; i++){
        
        k += PriorityQueue->getMax();
        PriorityQueue->increaseKey(0, -1);
    }
   
    cout << k;


    // int n,m,j,k;
    // cin >> n >> m;
    
    // for(int i = 0; i < m; i++){
    //     cin >> j;
    //     if(j == 1){
    //         if(PriorityQueue->getSize() == 0)
    //             cout << "-1" << endl;
    //         else{
    //             pair<int, int> z = PriorityQueue->extractMax();
    //             cout <<z.first << " " << z.second << "\n";
    //         }
    //     }
    //     if(j == 2){
    //         cin >> k;
    //         if(PriorityQueue->getSize() + 1 > n)
    //             cout << "-1" << endl;
    //         else
    //         {
    //             PriorityQueue->insert(k);
    //         }
    //     }
    //     if(j == 3){
    //         int o;
    //         cin >> o;
    //         if(PriorityQueue->getSize() + 1 >  o )
    //                PriorityQueue->deletenode(o - 1);
    //         else
    //         {
    //             cout << "-1" << endl;
    //         } 
    //     }    
    // }
    // PriorityQueue->build_heap2();
    
    // int n = PriorityQueue->a.size();
    // vector<int> sorted;
    // PriorityQueue->print();
    
    // for (int i = 0; i < n; i++) {
    //     pair<int, int> z = PriorityQueue->extractMax();
    //     sorted.push_back(z.second);        
    // }
    // reverse(sorted.begin(), sorted.end());
    // for(int i = 0; i < int(sorted.size()); i++){
    //     PriorityQueue->insert(inputt[i]);
    // }
    
    // PriorityQueue->build_heap2();


    // for(int m = 0; m < k - 1;m++){
    //     PriorityQueue->extractMax();
       
    //     PriorityQueue->print();
    // }

    
    // for(int j = 0; j < n;j++ ){
    //     cout << sorted[j] << " ";
    // }
    
    
    
    return 0;
}