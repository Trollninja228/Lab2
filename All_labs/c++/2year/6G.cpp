#include <iostream> 
#include <string> 
#include <map> 
 
using namespace std; 
 
void old_new_login(map<string, string> &logins){ 
    bool updated = true; 
 
    while(updated){ 
        updated = false; 
 
        map<string, string>::iterator it, it2; 
         
        for(it = logins.begin(); it != logins.end(); ++it){ 
            it2 = logins.find(it->second); 
                 
                if(it2 != logins.end() && it->first != it2->first){ 
                    logins[it->first] = it2->second; 
                    logins.erase(it2); 
                     
                    updated = true; 
                    break; 
                } 
                     
                 
 
        } 
    } 
} 
     
     
 
 
 
int main(){ 
 
    int n; 
    cin >> n; 
     
    map<string, string> logins; 
    for(int i = 0; i < n; i++){ 
        string first_login, second_login; 
        cin >> first_login >> second_login; 
        logins.insert({first_login, second_login}); 
    } 
 
     
    old_new_login(logins); 
 
    map<string, string>::iterator it; 
    cout << logins.size() << endl; 
    for(it = logins.begin(); it!=logins.end(); it++){ 
        cout << it->first << ' '<<it->second << endl; 
    } 
     
    return 0; 
}