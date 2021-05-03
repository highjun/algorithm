#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Int2{
    int idx;
    int val;
};

int main(){
    int N;
    cin >> N;
    int x[N];
    int result[N];
    for(int i = 0; i< N; i++){
        cin >> x[i];
    }
    stack<Int2> s;
    for(int i = 0; i< N; i++){
        while(!s.empty() && s.top().val< x[i]){
            Int2 tmp = s.top();
            result[tmp.idx] = x[i];
            s.pop();
        }
        Int2 a;
        a.idx = i;
        a.val = x[i];
        s.push(a);
    }
    while(!s.empty()){
        Int2 tmp = s.top();
        result[tmp.idx] = -1;
        s.pop();
    }
    for(int i = 0;i<N;i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}