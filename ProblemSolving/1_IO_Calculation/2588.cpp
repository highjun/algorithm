#include<iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B;
    cin >> A >> B;
    int x1, x2, x3;
    x3 = A*(B/100);
    x2 = A*((B/10)%10);
    x1 = A*(B%10);
    cout << x1 <<"\n";
    cout << x2 <<"\n";
    cout << x3 <<"\n";
    cout << x1 + 10*x2 + 100*x3 <<"\n";

    return 0; 
}