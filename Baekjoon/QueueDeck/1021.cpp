#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    deque<int> dq;
    int cnt = 0;
    for(int i = 1; i<=N ;i++){
        dq.push_back(i);
    }
    for(int i = 0; i<M; i++){
        int nxt;
        cin >> nxt;
        int tmp_cnt = 0;
        while(dq.front() != nxt){
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
            tmp_cnt += 1;
        }
        dq.pop_front();
        cnt += min(N-i-tmp_cnt, tmp_cnt);
    }
    cout << cnt << "\n";
    
    return 0;
}