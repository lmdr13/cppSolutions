#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    vector <int> v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    sort(v.begin(), v.end());
    if (v[2] == 0) {
        cout << -1;
        return 0;
    }
    vector <int> ans(3);
    int Min = v[0]; 
    int i = 1;
    while (Min % 2 != 0) {
        Min = v[i]; 
        i++;    
        if (i == 4){
            cout << -1;
            return 0;
        }    
    }
    
    v.erase(find(v.begin(), v.end(), Min));
    cout << v[1] << v[0] << Min;
    
}