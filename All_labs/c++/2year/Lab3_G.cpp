#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<float> v;
	int el;
    for (int i = 0; i < n; i++) {

        cin>>el;
        v.push_back(el);
    }
    sort(v.begin(),v.end());
	int max=v[k-n];
	if(k%n==0){
		cout<<v[n-1]/(k/n);
		return 0;
	}
    for(int i=k-n+1;i<n;i++){
		if(v[i]/2>max){
			max=v[i]/2;
		}
	}
    cout<<max;
    

}