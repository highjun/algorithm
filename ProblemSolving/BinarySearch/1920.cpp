#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    int x[N];
    int targetlevel = 0, index = N;
    while (index >>= 1) ++targetlevel;
    for (int i = 0; i<N; i++){
        cin >> x[i];
    }
    sort(x, x+N);
    cin >> M;
    for(int i = 0; i <M; i++){
        int tmp;
        cin >> tmp;
        int idx = 0;
        for(int j = targetlevel; j >= 0; j--){
            if(((1<<j)+ idx < N)&&tmp >= x[(1<<j) + idx]){
                idx = (1 << j) + idx;
            }
            if(j == 0){
                cout << ((tmp == x[idx])? 1 : 0) << "\n"; 
            }
            // cout << "idx, j " << idx <<","<< j << "\n";
        }
        // cout << "idx " << idx << "\n"; 
    }
    return 0;
}