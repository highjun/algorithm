#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int i = 0; i<N; i++){
        cin >> x[i];
    }
    sort(x, x+N);
    // for(int i = 0; i<N; i++){
    //     cout << x[i] << " ";
    // }
    // cout << endl;
    int cnt = 0;
    for(int i = 0; i<N; i++){
        cnt += (N-i) * x[i];
    }
    cout << cnt <<endl;
    return 0;
}