#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    queue<int> q;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            q.push(x);
        }else if(cmd =="front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }else{
                cout  << "-1" << "\n";
            }
        }else if(cmd == "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }else{
                cout  << "-1" << "\n";
            }
        }else if(cmd == "size"){
            cout << q.size() << "\n";
        }else if(cmd == "empty"){
            cout << (q.empty()? 1 : 0) << "\n";
        }else if(cmd == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }else{
                cout  << "-1" << "\n";
            }
        }
    }
    return 0;
}