#include<iostream>
using namespace std;

pair<int,int> backtracking(int* x,int N, int idx,int result, int n_add, int n_sub, int n_mul, int n_div){
    int max_ = INT32_MIN;
    int min_ = INT32_MAX;
    if(idx == N){
        return make_pair(result, result);
    }
    if(n_add > 0){
        max_ = max(max_,backtracking(x,N,idx+1, result+x[idx], n_add-1, n_sub, n_mul, n_div).first);
        min_ = min(min_,backtracking(x,N,idx+1, result+x[idx], n_add-1, n_sub, n_mul, n_div).second);
    }
    if(n_sub > 0){
        max_ = max(max_,backtracking(x,N,idx+1, result-x[idx], n_add, n_sub-1, n_mul, n_div).first);
        min_ = min(min_,backtracking(x,N,idx+1, result-x[idx], n_add, n_sub-1, n_mul, n_div).second);
    }
    if(n_mul > 0){
        max_ = max(max_,backtracking(x,N,idx+1, result*x[idx], n_add, n_sub, n_mul-1, n_div).first);
        min_ = min(min_,backtracking(x,N,idx+1, result*x[idx], n_add, n_sub, n_mul-1, n_div).second);
    }
    if(n_div > 0){
        max_ = max(max_,backtracking(x,N,idx+1, result/x[idx], n_add, n_sub, n_mul, n_div-1).first);
        min_ = min(min_,backtracking(x,N,idx+1, result/x[idx], n_add, n_sub, n_mul, n_div-1).second);
    }
    return make_pair(max_,min_);
}

int main(){
    int N;
    cin >> N;
    int x[N];
    int add,sub,mul,div;
    for(int i = 0 ; i<N;i++) cin >> x[i];
    cin >> add >> sub >> mul >> div;
    pair<int,int> ans = backtracking(x,N,1,x[0],add,sub,mul,div);
    cout << ans.first << "\n";
    cout << ans.second << "\n";
    return 0;
}