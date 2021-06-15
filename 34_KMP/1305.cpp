#include<iostream>

using namespace std;

void failure(int *ps,string str){
    int prev = 0;
    ps[0] = 0;
    for(int i = 1; i< str.size(); i++){
        if(str[prev]== str[i]){
            prev++;
            ps[i] = prev;
        }else{
            if(prev > 0){
                prev = ps[prev-1];
                i--;
            }else{
                ps[i] = 0;
            }
        }
    }
}

//부분수열이 절반보다 커서 겹치는 경우는 str.size -substr.size
//부분수열이 절반인 경우는 절반
//부분수열이 겹치지 않는 경우는 겹치지 않는 부분도 포함시켜야 한다.
int main(){
    int L;
    cin >> L;
    string adv;
    cin >> adv;
    int ps[adv.size()];
    failure(ps, adv);
    cout << adv.size() - ps[adv.size()-1] << "\n";

    return 0;
}