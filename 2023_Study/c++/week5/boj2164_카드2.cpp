#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;

    deque<int> dq;

    for(int i=1; i<=N; i++){
        dq.push_back(i);
    }

    while(dq.size()>1){
        dq.pop_front();

        int top = dq.front();
        dq.pop_front();
        dq.push_back(top);
    }

    cout << dq.front();

}