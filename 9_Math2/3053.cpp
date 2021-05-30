#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


//택시 기하학에서의 원은 거리가 같은 점을 의미한다.
//다이아몬드 형태가 되므로 넓이가 2가 된다.
int main(){
    int R;
    cin >> R;
    cout << fixed << setprecision(6);
    cout << R*R*M_PI << "\n";
    cout << (double)R*R*2 << "\n";
    return 0;
}