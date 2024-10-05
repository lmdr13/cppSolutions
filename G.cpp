#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector <pair <int, int>> path;
    set <pair <int, int>> pathSet;
    vector <vector <char> > vec(n,vector<char>(m));
    for (int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> vec[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x = j;
            int y = i;
            while (true){
                if (x >= m or y >= n or x < 0 or y < 0 or vec[y][x] == '1') {
                    for (auto& [first, second]: pathSet){
                        vec[first][second] = '1';
                    }
                    break;
                }                
                pathSet.insert(make_pair(y,x));
                path.push_back(make_pair(y,x));
                if (pathSet.size()!=path.size() or vec[y][x] == '0') {
                    for (auto& [first, second]: path){
                        vec[first][second] = '0';
                    }
                    break;
                }                    

                
                if(vec[y][x]=='D') y++;
                else if (vec[y][x]=='U') y--;
                else if (vec[y][x]=='L') x--;
                else if (vec[y][x]=='R') x++;
            }
            path.clear();
            pathSet.clear();
        }
    }
    int ans = 0;
    for(auto&a:vec){
        for(int j =0; j < a.size();j++) {
            if (a[j] == '0')  ans++;
        }
    }
    cout << ans;
}