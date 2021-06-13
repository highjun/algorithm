#include<iostream>
#include<algorithm>

using namespace std;

bool compare(string x, string y){
    return x.size() < y.size() || x.size() == y.size() && x < y;
}

// 단어의 사전 순 비교는 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    string x[N];
    for(int i = 0;i<N;i++) cin >> x[i];
    sort(x, x+N, compare);
    for(int i = 0;i<N;i++){
        if(i == 0 ||(i > 0 &&x[i] != x[i-1]))
            cout << x[i] << "\n";
        
    } 
    return 0;
}