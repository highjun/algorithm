#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    int x[N];
    for(int  i =0;i<N;i++) cin >> x[i];
    int start = 0, end= 0;
    int sum_ = x[0];
    int min_ = INT32_MAX;
    while(true){
        if(sum_ >= S){
            min_ = min(min_, end-start+1);
            sum_ -= x[start];
            start++;
            if(start == N) break;
        }else{
            end++;
            if(end == N) break;
            sum_ += x[end];
        }
    }
    cout << (min_==INT32_MAX?0: min_) << "\n";
    return 0;
}