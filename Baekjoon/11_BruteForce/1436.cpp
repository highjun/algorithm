#include<iostream>

using namespace std;

//무식하게 Counting
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int check = 0;
    while(cnt < N){
        check++;
        int num = check;
        int tmp = 0;
        while(num != 0){
            if(num%10==6) tmp++;
            else tmp = 0;
            if(tmp == 3) break;
            num /= 10;
        }
        if(tmp == 3) cnt++;
    }
    cout << check << "\n";
    return 0;
}