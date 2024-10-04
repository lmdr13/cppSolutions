#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector < vector<char>> letters(n, vector<char>(n));
    unordered_map <char,int> mp;
    for(int i = 0; i<n; i++){
        for(int j =0; j < n; j++){
            cin >> letters[i][j];
            mp[letters[i][j]]++;
        }
    }
    vector <char> popular_letters;
    int count, max = 0;
    for (auto & [first, second] : mp){
        if (second > max) {
            max=second;
            count = 0;
            popular_letters.push_back(first);
        }
        else if (max == second){
            count++;
            popular_letters.push_back(first);
        }
        if(mp[popular_letters[popular_letters.size()-1]]<max) popular_letters.clear();
    }
    if ()
}