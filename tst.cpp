#include<iostream>
#include<string>
using namespace std;
int main(){
    string temp = "000";
    temp+=(char)'0'+1;
    cout<<temp<<endl;
    return 0;
}