#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i<N;i++){
        string cmd, arr;
        int n_arr;
        cin >> cmd >> n_arr >> arr;
        deque<int> dq;
        int tmp = 0, x = -1;
        while(arr[tmp]!='\0'){ 
            if(arr[tmp]>='0' && arr[tmp] <='9'){
                if(x == -1) x= 0;
                x= x*10 + arr[tmp] - '0';
            }else{
                if(x != -1)
                    dq.push_back(x);
                x = -1;
            }
            tmp++;
        }
        bool done= false;
        bool reverse=false;
        for(int i = 0; i<cmd.length() ; i++){
            if(cmd[i] == 'R'){
                reverse = !reverse;
            }else if(cmd[i] == 'D'){
                if(dq.empty()){
                    cout << "error" << "\n";
                    done = true;
                    break;
                }
                if(reverse){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }
        if(!done){
            cout << "[";
            if(dq.empty()){

            }else if(reverse){
                deque<int>::reverse_iterator riter;
                cout << dq.back();
                dq.pop_back();
                for(riter = dq.rbegin(); riter!=dq.rend(); riter++){
                    cout << "," <<*riter ;
                }
            }else{
                deque<int>::iterator iter;
                cout << dq.front();
                dq.pop_front();
                for(iter = dq.begin(); iter!=dq.end(); iter++){
                    cout << "," <<*iter;
                }
            }
            cout << "]" <<"\n";
        }
    }
    return 0;
}