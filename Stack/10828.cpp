#include<iostream>
#include<stack>

using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> s;
    
    for(int i= 0; i<N ;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            s.push(x);
        }else if(cmd == "top"){
            if(s.empty()){
                cout << -1 << endl;
            }else{
                cout << s.top() << endl;
            }
        }else if(cmd == "pop"){
            if(s.empty()){
                cout << -1 << endl;
            }else{
                cout << s.top() << endl;
                s.pop();
            }
        }else if(cmd == "size"){
            cout << s.size() << endl;
        }else if(cmd == "empty"){
            cout << (s.empty()? 1: 0) << endl;
        }
    }
    return 0;
}