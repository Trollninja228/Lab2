#include <iostream> 
#include <string> 
using namespace std; 
 
void helper_func(int* f, string pattern) 
{ 
    f[0] = f[1] = 0; 
    int m = pattern.length(); 
    for (int i = 2; i <= m; i++) 
    { 
        int j = f[i - 1]; 
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
 
 
bool knuth_morris_algorithm(string text, string pattern) 
{ 
     
    int f[pattern.length() + 1]; 
    helper_func(f, pattern); 
    int i = 0, j = 0; 
    int n = text.length(), m = pattern.length(); 
    while (j < n) 
    { 
        if (text[j] == pattern[i]) 
        { 
            i++; 
            j++; 
            if (i == m) 
            { 
                 
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
 
 
 
int main() 
{ 
    string a, b; 
    cin >> a >> b; 
     
    string pat = a; 
    int repeat_count = 1; 
    while(a.length() < b.length()) 
    { 
        a += pat; 
        // cout << a << endl; 
        repeat_count++; 
    } 
 
 
    if(knuth_morris_algorithm(a, b)) 
    { 
        cout << repeat_count; 
        return 0; 
    } 
 
    a += pat; 
    repeat_count++; 
    // cout << a << endl; 
 
    if(knuth_morris_algorithm(a, b)){ 
        cout << repeat_count; 
        return 0; 
    } 
    else{ 
        cout << -1; 
    } 
 
 
    return 0; 
}