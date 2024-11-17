#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void helper_func(long long int* f, string pattern)
{
    f[0] = f[1] = 0;
    long long int m = pattern.length();
    for (long long int i = 2; i <= m; i++)
    {
        long long int j = f[i - 1];
        while (j > 0 && pattern[j] != pattern[i - 1])
        {
            j = f[j];
        }
        if (pattern[j] == pattern[i - 1])
        {
            f[i] = j + 1;
        }
        else
        {
            f[i] = 0;
        }
    }
}

bool knuth_morris_algorithm(string text, string pattern, int &pos)
{
    // cout<<text<<" "<<pattern<<endl;
    long long int f[pattern.length() + 1];
    helper_func(f, pattern);
    long long int i = 0, j = 0;
    long long int n = text.length(), m = pattern.length();
    while (j < n)
    {
        if (text[j] == pattern[i])
        {
            i++;
            j++;
            if (i == m){
                // cout<<i<<" "<<j<<endl;
                pos=j-i+1;
                return true;
            }
        }
        else if (i > 0)
            i = f[i];
        else
            j++;
    }
    
    return false;
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    int pos=0;
    vector<int> v;
    int sum=0;
    while(knuth_morris_algorithm(s1,s2,pos)){
        v.push_back(pos+sum);
        s1.erase(pos-1,s2.size());
        sum+=s2.size();
        // cout<<s1;
    }
    cout<<v.size()<<endl;
    for (int j = 0; j < v.size(); j++){
        cout<<v[j]<<' ';
    }
    
}