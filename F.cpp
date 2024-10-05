#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <string> letters(n);
    unordered_map <char,int> mp;
    for(int i = 0; i<n; i++){
        cin >> letters[i];
        for(int j =0; j < letters[i].length(); j++){            
            mp[letters[i][j]]++;
        }
    }
    vector <char> popular_letters;
    int count, max = 0;
    for (auto & [first, second] : mp){
        if (second > max) {
            max=second;
            count = 0;
            popular_letters.clear();
            popular_letters.push_back(first);            
        }
        else if (max == second){
            count++;
            popular_letters.push_back(first);
        }
    }
    int ans = 0;
    for (string s : letters){
        for (auto&a:popular_letters) {
            if (s.find(a)!=-1){
                ans++;
                break;
            }            
        }
    }
    cout << n-ans;
}