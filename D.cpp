#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;
int main()
{
    int  a;
    cin >> a;
    vec.resize(a);
    vec[0] = (a/2)+1;
    for (int i = 1; i < a; i++){
        i % 2 == 0 ? vec[i] = vec[i-1] + i : vec[i] = vec[i-1] - i;
    }
    for (auto& a : vec){
        cout << a << ' ';
    }
}
