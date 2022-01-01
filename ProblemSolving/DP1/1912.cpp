#include<iostream>

using namespace std;

//쌓을 수 있는 개수
long long cache[100000];


int main(){
    int N;
    cin >>N;
    long long x[N];
    for(int i = 0; i<N; i++){
        cin >> x[i];
    }
    // for(int i = 0; i<N; i++){
    //     cout << x[i] <<" ";
    // }  
    // cout <<endl;
    for(int i =0 ; i<N;i++){
        if(i == 0) cache[i] = x[i];
        else
            cache[i] = max(x[i], cache[i-1]+x[i]);
    }
    long long max_ = -1000;
    for(int i = 0; i<N; i++){
        // cout << cache[i] <<" ";
        max_ = max(max_, cache[i]);
    }  
    // cout<<endl;
    cout << max_ << endl;
    return 0;
}