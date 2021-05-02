#include<iostream>
#include<algorithm>

using namespace std;
struct Int2{
    int idx;
    long long cost;
};

bool compare(Int2 x, Int2 y){
    return (x.cost< y.cost) ||(x.cost ==y.cost && x.idx < y.idx);
}

int main(){
    int N;
    cin >> N;
    long long len[N-1];
    Int2 arr[N];
    for(int i=0;i<N-1; i++){
        cin >> len[i];
    }
    for(int i=0;i<N; i++){
        cin >> arr[i].cost;
        arr[i].idx = i;
    }
    sort(arr, arr+N,compare);
    int tmp = N-1;
    long long cnt = 0;
    for(int i = 0; i<N; i++){
        if(arr[i].idx < tmp){
            for(int j= arr[i].idx; j<tmp; j++){
                cnt += len[j]* arr[i].cost;
            }
            tmp = arr[i].idx;
        }
    }
    cout << cnt << endl;
    return 0;    
}