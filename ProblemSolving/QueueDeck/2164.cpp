#include<iostream>
#include<queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    queue<int> q;
    for(int i=1;i<=N; i++){
        q.push(i);
    }
    for(int i = 0; i< N-1;i++){
        q.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }
    cout <<q.front()<< endl;
    return 0;
}