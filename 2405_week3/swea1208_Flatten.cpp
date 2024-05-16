#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;

int main()
{
    for(int test_case=1; test_case<=10; test_case++)
    {
        int cnt;
        int height[100] = {0,};
        cin >> cnt;
        for(int i=0;i<100;i++)
        {
            cin >> height[i];
        }

        sort(height, height+100);
        for(int j=0;j<cnt;j++)
        {
            height[99] -= 1;
            height[0] += 1;

            sort(height, height+100);
        }

        ans = height[99] - height[0];

        cout << "#" << test_case << " " << ans << '\n';
    }
}