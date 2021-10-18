#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    int A,B;
    cin >> A >> B;

    cout << (double) A/B <<"\n";
    return 0; 
}