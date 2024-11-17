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
 
 
int knuth_morris_algorithm(string text, string pattern) 
{ 
    string newtext = ""; 
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
                 
                 
                return (j - i); 
            } 
        } 
        else if (i > 0) 
            i = f[i]; 
        else 
            j++; 
    } 
     
    return -1; 
} 
 
 
string newtext; 
int main() 
{ 
    string first, second; 
    cin >> first >> second; 
    int n = first.length(); 
    int pos; 
    string pat = ""; 
    for(int i = 0; i < n; i++){ 
        pat += second[i]; 
        pos = knuth_morris_algorithm(first, pat); 
        if(pos == -1){ 
            cout << pos; 
            break; 
        } 
        newtext = ""; 
 
        newtext = first.substr(pos, n - pos); 
        newtext += first.substr(0, pos); 
        // cout << newtext << endl; 
        if(newtext == second){ 
            cout << n - pos; 
            break; 
        } 
         
         
    } 
     
    // cout << -1; 
    // cout << newtext << endl; 
 
     
    return 0; 
}