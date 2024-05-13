#include <iostream>
#include <vector>

using namespace std;

// 재료의 수 N, 제한 칼로리 L
int N, L;

int maxT;

// 재료의 벡터
vector<pair<int,int>> v;

// 맛 점수 t, 칼로리 k
void DFS(int t, int k, int cnt)
{
    if(k > L) return;

    // 완전탐색
    if(cnt == N)
    {
        if(maxT > t) return;
        else{
            maxT = t;
            return;
        }
    }

    DFS(t + v[cnt].first, k + v[cnt].second, cnt+1);  // 선택 O
    DFS(t, k, cnt+1);                               // 선택 X
    
}


int main(int argc, char** argv)
{
	int test_case;
	int T;	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> L;
        
        for(int i=0; i<N; i++)
        {   
            int T, K;
            cin >> T >> K;
            v.push_back({T,K});
        }
		
        maxT = 0;
        DFS(0, 0, 0);

        cout << "#" << test_case << " " << maxT << '\n';
        v.clear();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}