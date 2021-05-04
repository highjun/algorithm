#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    deque<int> q;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push_back"){
            int x;
            cin >> x;
            q.push_back(x);
        }else if(cmd == "push_front"){
            int x;
            cin >> x;
            q.push_front(x);
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
        }else if(cmd == "pop_front"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop_front();
            }else{
                cout  << "-1" << "\n";
            }
        }else if(cmd == "pop_back"){
            if(!q.empty()){
                cout << q.back() << "\n";
                q.pop_back();
            }else{
                cout  << "-1" << "\n";
            }
        }
    }
    return 0;
}