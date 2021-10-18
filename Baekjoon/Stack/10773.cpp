#include<iostream>
#include<stack>
using namespace std;

int main(){
    int K;
    cin >> K;
    stack<int> s;
    for(int i = 0; i<K; i++){
        int x; 
        cin >> x;
        if(x!= 0){
            s.push(x);
        }else{
            s.pop();
        }    
    }
    long long cnt = 0;
    while(!s.empty()){
        cnt += s.top();
        s.pop();
    }
    cout << cnt << endl;
    return 0;
}