#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int** arr, int m, int n, vector<pair<int, int>> positions) {
    
    int minutes = 0;
    queue<pair<int, int>> q;
    
    if(positions.empty()){
        return minutes + 1;
    }
    for(int i = 0; i < positions.size(); i++){
        q.push({positions[i].first, positions[i].second});
    }
    


    while (!q.empty()) {
        int size = q.size();  
        
        
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            
            for (int dir = 0; dir < 4; dir++) {
                int newX = x + directions[dir][0];
                int newY = y + directions[dir][1];

                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && arr[newX][newY] == 1) {
                    arr[newX][newY] = 2;  
                    q.push({newX, newY});  
                }
            }
        }
        minutes++;  
    }

    return minutes;
}



int main(){
    int m, n;
    cin >> m >> n;

    int** arr = new int*[m];
    for(int i = 0; i < m; i++){
        arr[i] = new int[n];
    }
    int pos, pos2;
    vector<pair<int, int>> positions;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            int num = arr[i][j];
            if( num == 2){
                positions.push_back({i, j});
            }
        }
    }

    int minutes;
    minutes = bfs(arr, m, n, positions);

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    bool answer = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                answer = true;
                break;
            }
        }
    }

    if(answer){
        cout << -1;
    }
    else{
        cout << minutes - 1;
    }

    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}