#include<iostream>

using namespace std;

//왼쪽 아래의 꼭짓점과 오른쪽 위의 꼭짓점을 구한다.
int main(){
    int x1,y1;
    cin >> x1 >> y1;
    int x2,y2;
    cin >> x2 >> y2;
    int x3,y3;
    cin >> x3 >> y3;
    int min_x = min(min(x1, x2),x3);
    int min_y = min(min(y1, y2),y3);
    int max_x = max(max(x1, x2),x3);
    int max_y = max(max(y1, y2),y3);
    int result_x = (min_x+max_x)*2 - x1- x2- x3;
    int result_y = (min_y+max_y)*2 - y1- y2- y3;
    cout << result_x << " " << result_y << "\n";
    return 0;
}