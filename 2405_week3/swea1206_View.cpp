#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 건물 개수 N
// 4 <= N <= 1000
// 맨 왼쪽 2칸, 맨 오른쪽 2칸에는 건물이 없다. 

int main()
{
    for(int i=1; i<11; i++)
    {
        int N;
        cin >> N;

        // 건물 높이 배열
        int heightArr[1001] = {0,};

        int ans = 0;
        
        for(int j=0; j<N; j++)
        {
            cin >> heightArr[j];
        }

        for(int k=2; k<N-2; k++)
        {
            if(heightArr[k] > heightArr[k-1] && heightArr[k] > heightArr[k-2]
            && heightArr[k] > heightArr[k+1] && heightArr[k] > heightArr[k+2])
            {
                vector<int> vec = {heightArr[k-2], heightArr[k-1], heightArr[k+1], heightArr[k+2]};
                sort(vec.begin(), vec.end());

                ans += heightArr[k] - vec[3];
            }
        }


        cout << "#" << i << " " << ans << '\n';
    }


}