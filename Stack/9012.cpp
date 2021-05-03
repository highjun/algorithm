#include<iostream>
#include<stack>

using namespace std;

int main(){

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        stack<int> s;
        string par;
        cin >>par;
        bool pass = true;
        for(int j = 0; j< par.length(); j++){
            if(par[j] == '('){
                s.push(1);
            }else{
                if(s.empty()){
                    pass = false;
                    break;
                }else{
                    s.pop();
                }
            }
        }
        if(!s.empty()){
            pass = false;
        }
        cout << (pass ? "YES" : "NO") << endl;
    }
    return 0;
}