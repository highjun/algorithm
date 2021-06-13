#include<iostream>

using namespace std;

//counting sort
//각 수를 counting해서 정렬
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt[10000];
    fill(cnt, cnt+10000,0);
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        cnt[tmp-1]++;
    }
    for(int i = 0 ;i<10000;i++){
        for(int j = 0; j<cnt[i]; j++){
            cout << i+1 <<"\n";
        }
    }
    return 0;
}