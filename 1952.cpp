#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
}

//달팽이
void Snail() {
    int edge = 4 * ((min(n, m)-1) / 2);
    if (n > m) {
        if (m % 2 == 0) cout << edge + 3;
        else cout << edge + 1;
    }
    else {
        if (n % 2 == 0) cout << edge + 2;
        else cout << edge;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Snail();//달팽이
    return 0;
}
