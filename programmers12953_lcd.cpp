#include <string>
#include <vector>

using namespace std;
int gcd,lcd;//최대 공약수, 최소 공배수

//유클리드 알고리즘
int Euclidean(int x,int y){
    if(x<y) swap(x,y);//x가 더 크도록
    while(y!=0){
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int solution(vector<int> arr) {
    int answer = 1;
    //최소 공배수 구하기
    lcd = arr[0];
    for(int i=1;i<arr.size();i++){
        gcd = Euclidean(lcd,arr[i]);//최대 공약수
        lcd = lcd*arr[i]/gcd;//최소 공배수
    }
    return lcd;
}
