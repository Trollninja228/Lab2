#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//written by n-n06;

int hash_rolling(string s, int p) {
    int h = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        h = (h + (int)s.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    return h;
}

vector<int> rabin_karp(string text, string pattern, int p) {
    int n = text.length();
    int m = pattern.length();

    vector<int> positions;

    int target_hash = hash_rolling(pattern, p);

    int hash_i = 0;
    int pow = 1;
    int pow_store;

    for (int i = m - 1; i >= 0; i--) {
        pow_store = pow;
        hash_i = (hash_i + (int)text.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    
    if (hash_i == target_hash && text.substr(0, m) == pattern) {
        positions.push_back(0);
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = (((hash_i - ((int)text.at(i - 1)%p)) * pow_store) * 128 % p + text.at(i + m - 1)) % p;
        if (hash_i == target_hash) {
            if (text.substr(i, m) == pattern)
                cout << i << ' '<<m << ' ' << text.substr(i, m) << endl;
                positions.push_back(i);
        }
    }

    return positions;
}

int bin_search(vector<int> arr, int beg, int end, int key){
	int mid=(beg+end)/2;
	if(arr[mid]==key){
        // cout<<"search"<<endl<<arr[mid]<<" "<<key;
		return mid;
	}
	if(beg>=end){
		// cout<<"not found"<<endl;
		return -1;
	}
	//recursion
	if(key<arr[mid])
		return bin_search(arr,beg,mid-1,key);
	else
		return bin_search(arr,mid+1,end,key);
	
}

int main() {
    int p = 5003;
    string s;
    cin>>s;
    long long int n;
    cin>>n;
    vector<string> v(n);
    vector<int> v1[n];
    vector<int> v2(s.size());
    for(int i=0;i<n;i++){
        cin>>v[i];
        v1[i]=rabin_karp(s,v[i],p);
        v2[i]=0;
    }
    
    int sum=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<v1[i].size();j++){
    //         for(int k=0;k<){}
    //         v2[v1[i][j]]=1;
    //     }
    // }
    // cout<<sum<<" "<<s.size()<<endl;
    int res=bin_search(v2,0,v2.size()-1,0);
    if(res==-1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
