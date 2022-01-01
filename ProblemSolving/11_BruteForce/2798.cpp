#include<iostream>

using namespace std;

//for문으로 모든 경우의 수 조산
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    int x[N];
    for(int i = 0;i<N;i++) cin >> x[i];
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            for(int k = j+1;k<N;k++){
                int tmp = x[i] + x[j] + x[k];
                if(tmp <= M && cnt < tmp){
                    cnt = tmp;
                }
            }
        }    
    }
    cout << cnt <<"\n";

    return 0;
}