#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
using namespace std; 
 
unsigned long long int hash_rolling(const string &s) { 
    unsigned long long int h = 0; 
    unsigned long long int pow = 1; 
    for (unsigned long long int i = 0; i < s.length(); i++) { 
        h = (h + (s[i] - 97) * pow); 
        pow = (pow * 2); 
    } 
    return h; 
} 
int main(){ 
    hash_rolling("uruwoljwierfsbknu{jnfhfvebfc{pimvbdmv"); 
 
 
    unsigned long long int n; 
    cin >> n; 
    unsigned long long int nums; 
    vector<unsigned long long int> numes(n); 
    for(unsigned long long int i = 0; i < n; i++){ 
        cin >> nums; 
        numes[i] = nums; 
    } 
    string s = ""; 
    string temp = ""; 
     
    for(unsigned long long int i = 0; i < n; i++){ 
        for(char c = ' '; c <= '~'; c++){ 
             
            temp = s; 
            s += c; 
             
            if(hash_rolling(s) != numes[i]){ 
                s = temp; 
                 
            } 
             
             
        } 
    } 
 
    cout << s; 
 
 
    return 0; 
}