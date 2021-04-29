#include<iostream>

using namespace std;

int cache[1000];

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int i = 0; i<N;i++){
        cin >>x[i];
    }
    for(int i = 0; i<N; i++){
        int max_ = 0;
        for(int j = 0; j<i; j++){
            if(x[j]< x[i]){
                max_ = max(max_ , cache[j]);
            }
        }
        cache[i] = max_ + 1;
    }
    int max_ = 0;
    for (int i = 0; i<N;i++){
        max_ = max(cache[i], max_);
    }
    cout << max_ <<endl;
    return 0;
}