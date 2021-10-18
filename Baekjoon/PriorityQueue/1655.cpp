#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 2n번째면 기존 중앙값과 비교해서 더 크면 중앙값 안 바뀜
// 2n+1 번째면 (n,n) 기존 중

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int , vector<int>, less<int>> max_q;
    priority_queue<int , vector<int>, greater<int>> min_q;
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(i == 0){
            max_q.push(tmp);
        }else{
            if(i%2 == 1){// n n+1로 분배
                if(tmp > max_q.top()){
                    min_q.push(tmp);
                }else{
                    max_q.push(tmp);
                    tmp = max_q.top();
                    max_q.pop();
                    min_q.push(tmp);
                }
            }else{// n n으로 분배
                if(tmp >= min_q.top()){
                    min_q.push(tmp);
                    tmp = min_q.top();
                    min_q.pop();
                    max_q.push(tmp);
                }else{
                    max_q.push(tmp);
                }
            }
        }
        // cout << (min_q.empty()? 0: min_q.top()) <<" " << (max_q.empty()? 0: max_q.top()) <<"\n";
        cout << max_q.top() <<"\n";
    }
    return 0;
}