#include <iostream>
#include <queue>

using namespace std;

// 테스트 케이스 개수
int T;

// 미로의 크기 N, 미로정보 -> 0:통로, 1:벽, 2:출발, 3:도착
int N;

// 계산결과, 도착가능: 1, 불가: 0
int ans;

void BFS(char (*maze)[102], int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});

    int visited[102][102] = {0,};
    // 방문표시
    visited[x][y] = 1;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>0 && nc>0 && nr<N+1 && nc<N+1 && maze[nr][nc] != '1' && visited[nr][nc] != 1)
            {
                if(maze[nr][nc] == '3')
                {
                    ans = 1;
                    return;
                }
                q.push({nr,nc});
                visited[nr][nc] = 1;
            }
        }
    }

    // 도착불가
    ans = 0;
}

int main()
{
    cin >> T;
    for (int i=1; i<T+1; i++)
    {
        cin >> N;

        // 미로정보
        char maze[102][102];

        // 미로 시작점 정보
        int startX, startY;

        // 0행과 0열은 비우고 미로정보 입력받음
        for(int j=1; j<N+1; j++)
        {
            for(int k=1; k<N+1; k++)
            {
                char a;
                cin >> a;
                maze[j][k] = a;

                if(a == '2')
                {
                    startX = j;
                    startY = k;
                }
            }
        }

        BFS(maze, startX, startY);
        cout << "#" << i << " " << ans << '\n';
    }

}