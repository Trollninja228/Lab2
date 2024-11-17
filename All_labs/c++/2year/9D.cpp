#include <iostream> 
#include <vector> 
#include <string> 
#include <map> 
 
 
using namespace std; 
 
int main(){ 
    string input; 
    int k; 
    cin >> input >> k; 
 
    vector<string> cities; 
    map<int, vector<string> > mostC; 
 
 
    for(int i = 0; i < k;i ++){ 
        string city; 
        cin >> city; 
        cities.push_back(city); 
        vector<string> subcities; 
        mostC[i] = subcities; 
    } 
 
     
 
    for(int idx = 0; idx < k; idx++){ 
        string city = cities[idx]; 
         
        int i = 0; 
        int j = 0; 
        vector<int> lps(input.size(), 0); 
        while(i < input.size()){ 
            char cityCh = city[j]; 
            if(cityCh < 97){ 
                cityCh+=32; 
            } 
             
            if(cityCh == input[i]){ 
                lps[i] = j + 1; 
                i++; 
                j++; 
            }else{ 
                if(j == 0){ 
                    i++; 
                }else{ 
                    j = 0; 
                } 
            } 
        } 
        mostC[lps[i - 1]].push_back(city); 
         
    }   
    map<int, vector<string> >::iterator it = mostC.begin(); 
    int maxSize = 0; 
    int maxIdx = 0; 
    for(; it != mostC.end(); it++){ 
        if(it->first > maxIdx && it->second.size() != 0){ 
            maxSize = it->second.size(); 
            maxIdx = it->first; 
        } 
    } 
    cout << maxSize << endl; 
    for(int i = 0; i < maxSize; i++){ 
        cout << mostC[maxIdx][i] << endl; 
    } 
}