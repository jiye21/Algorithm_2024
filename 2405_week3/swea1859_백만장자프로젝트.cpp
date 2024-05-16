#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++)
    {
        // N: 연속된 N일의 매매가
        int N;
        cin >> N;

        long long ans = 0;

        // price: 각 날의 매매가
        vector<int> price;

        for(int i=0; i<N; i++)
        {
            int a;
            cin >> a;
            price.push_back(a);
        }
        
        vector<int> max(N);
        // 맨 뒤 인덱스부터 검사
        int maxPrice = price.back();
        for(int j=N-1; j>=0; j--)
        {
            if(price[j] > maxPrice)
            {
                maxPrice = price[j];
            }
            max[j] = maxPrice;
        }

        for(int k=0; k<N; k++)
        {
            int diff = max[k] - price[k];
            if(diff > 0)
            {
                ans += diff;
            }
        }


        cout << "#" << test_case << " " << ans << '\n';
    }
}