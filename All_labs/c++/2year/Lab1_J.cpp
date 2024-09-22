#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
int main(){
	deque<int> dq;
	char c;
	int num;
	int size=0;
	vector<int> v;
	while(1){
		cin>>c;
		if(c=='!'){
			break;
		}
		if(c=='+'){
			cin>>num;
			dq.push_front(num);
			size++;
		}
		if(c=='-'){
			cin>>num;
			dq.push_back(num);
			size++;
		}
		if(c=='*'){
			if(size==1){
				v.push_back(dq.front()+dq.back());
				dq.pop_front();
				size--;
			}else if(size>=2){
				v.push_back(dq.front()+dq.back());
				dq.pop_front();
				dq.pop_back();
				size-=2;
			}else{
				v.push_back(-1);
			}
			
		}
		
	}
	for(int i=0;i<v.size();i++){
		if(v[i]==-1){
			cout<<"error"<<endl;
		}else{
			cout<<v[i]<<endl;
		}
	}
	cout<<size;
	return 0;

}
	



