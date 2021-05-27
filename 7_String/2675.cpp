#include<iostream>

using namespace std;

//문자열로 입력받고, 새로운 문자열에 반복할 만큼
//개수를 더해서 추가
int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        string x;
        cin >> x;
        string y="";
        for(int i = 0; i <x.size();i++){
            for(int j = 0;j<N; j++){
                y.push_back(x[i]);
            }
        }
        cout << y <<"\n";
    }
    return 0;
}