#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int kol;
	cin>>kol;
	int arr[kol];
	for(int i=0;i<kol;i++){
		int num;
		cin>>num;
		arr[i]=num;
	}
	for (int o=0;o<kol;o++){
		int num=arr[o];
		queue<int> q;
		int i=0;
		while(num>0){
			q.push(num);
			for(int i=0; i<num;i++){
				q.push(q.front());
				q.pop();
			}
			num--;
		}
		vector<int> v;
		int p=0;
		while(!q.empty()){
			v.push_back(q.front());
			q.pop();
		}
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}
