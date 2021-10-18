#include<iostream>

using namespace std;


int dp(int* save, int* arr, int N, int dest, int mask){
    // cout << dest <<"< " << mask <<"\n";
    if(save[(dest<<N) + mask] == -1){
        int min_ = INT32_MAX;
        int prev_mask = mask & (~ (1<<dest));
        bool is_first = true;
        for(int i = 1;i<N;i++){
            int tmp = 1 << i;
            if(tmp == (tmp & prev_mask)){
                is_first = false;
                if(dp(save,arr,N,i,prev_mask)!= INT32_MAX && arr[i*N+dest]!= INT32_MAX){
                    min_ = min(min_, dp(save,arr,N, i, prev_mask)+ arr[i*N + dest]);
                }
            }
        }
        if(is_first){
            min_ = arr[dest];
        }
        save[(dest<<N)+ mask] = min_;
        // cout << dest <<"< " << mask << ":"<< min_ << "\n"; 
    }
    return save[(dest <<N)+ mask];
}

//마지막으로 방문한 국가, 그리고 출발점, 도착점을 포함한 경유지에 대한 비트마스크
//출발점은 임의로 고정해도 상관없으므로 0으로 가정한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int arr[N*N];
    for(int i = 0;i<N*N;i++){
        cin >> arr[i];
        if(arr[i] == 0){
            arr[i] = INT32_MAX;
        }
    } 
    //도착 - 경유지, 출발은 0에서 하는 것으로 가정
    int save[N *(1<<N)];
    fill(save, save + N*(1<<N), -1);
    save[1] = 0;
    int min_ = INT32_MAX;
    for(int i = 1; i <N;i++){
        if(arr[i*N] != INT32_MAX && dp(save, arr, N, i, (1<<N)-1)!=INT32_MAX){
            min_ = min(min_, dp(save, arr, N, i, (1<<N)-1)+ arr[i*N]);
        }
    }
    cout << min_ <<"\n";
    return 0;
}