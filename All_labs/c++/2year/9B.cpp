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
 
 
string knuth_morris_algorithm(string text, string pattern) 
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
                newtext = text.substr(0, (j - i)); 
                // cout << newtext << endl; 
                newtext += text.substr((j-i) + m, n - m); 
                // cout << newtext << endl; 
                 
                 
                return newtext; 
            } 
        } 
        else if (i > 0) 
            i = f[i]; 
        else 
            j++; 
    } 
     
    return text; 
} 
 
 
 
int main() 
{ 
    string a, b; 
    int n; 
    cin >> a >> n; 
    cin >> b; 
    string text = b; 
    string newtext; 
    int checker = 0; 
    for(int i = 0; i < n; i++){ 
        newtext = knuth_morris_algorithm(text, a); 
        // cout << text << endl; 
        if(text != newtext){ 
            checker++; 
            text = newtext; 
        } 
        else{ 
            break; 
        } 
         
    } 
     
    if(checker < n){ 
        cout << "NO"; 
    } 
    else cout << "YES"; 
     
 
 
    return 0; 
}