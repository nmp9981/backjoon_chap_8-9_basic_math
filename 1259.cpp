#include <iostream>
using namespace std;

string n;

int main()
{
    while(cin>>n){
        if(n=="0") break;
        int n_size = n.size();
        if(n_size==1){
            cout<<"yes\n";
        }else if(n_size==2){
            if(n[0]==n[1]) cout<<"yes\n";
            else cout<<"no\n";
        }else if(n_size==3){
            if(n[0]==n[2]) cout<<"yes\n";
            else cout<<"no\n";
        }else if(n_size==4){
            if(n[0]==n[3] && n[1]==n[2]) cout<<"yes\n";
            else cout<<"no\n";
        }else if(n_size==5){
            if(n[0]==n[4]&&n[1]==n[3]) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}
