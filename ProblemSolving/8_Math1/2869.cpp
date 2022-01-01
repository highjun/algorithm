#include<iostream>
#include<cmath>

using namespace std;

//하루에 (A-B)미터 올라간다.
// k(A-B) + A < x < (k+1)(A-B)+A 인 k에서 답은 k+1
int main(){
    int A,B,V;
    cin >> A>>B>>V;
    if(V-A <= 0){
        cout << "1\n";
    }else{
        cout << (int) ceil((V-A)*1.0/(A-B)) +1 << "\n";
    }
    return 0;
}