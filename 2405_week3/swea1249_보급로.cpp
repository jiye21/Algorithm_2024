#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    int T;
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++)
    {
        // 지도의 크기 N * N
        int N;
        cin >> N;

        vector<vector<int>> map(N, vector<int>(N,0));

        vector<int> a(N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                scanf("%1d", &a[j]);            
                map[i][j] = a[j];
            }
        }

        queue<pair<int,int>> q;
        q.push({0,0});

        bool visited[101][101] = {false,};
        visited[0][0] = true;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};

        // 최단경로 배열
        vector<vector<int>> min_time(N, vector<int>(N,0));
        int new_time;

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>-1 && nc>-1 && nr<N && nc<N)
                {
                    new_time = min_time[r][c] + map[nr][nc];

                    // 방문하지 않았거나 
                    // 방문할 위치의 최단경로가 현재 위치의 최단경로+방문할 곳의 map배열 값보다 크다면
                    // 최솟값으로 갱신해줌
                    if(visited[nr][nc] == false || new_time < min_time[nr][nc])
                    {
                        visited[nr][nc] = true;
                        min_time[nr][nc] = new_time;
                        q.push({nr, nc});
                    }
                }
            }

        }

        

        cout << "#" << test_case << " " << min_time[N-1][N-1] << '\n';
    }
}