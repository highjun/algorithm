#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int x[N];
    queue<int> q;
    for(int i = 1; i<=N; i++){
        q.push(i);
    }
    for(int i = 0; i<N;i++){
        int tmp;
        for(int j = 0; j< K-1; j++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        x[i] = tmp;
    }
    cout <<"<";
    cout << x[0];
    for(int i = 1;i< N; i++){
        cout <<", "<< x[i];
    }
    cout << ">" << "\n";
    return 0;
}