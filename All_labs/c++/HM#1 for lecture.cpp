#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int main(){
	stack<char> st;
	int n,f,count,count1,count2;
	count=0;
	count1=0;
	count2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f;
		st.push(f);
	}
	while(!st.empty()){
		if(st.top()=='('){
			count++;
		}
		if(st.top()=='['){
			count1++;
		}
		if(st.top()=='{'){
			count2++;
		}
		if(st.top()==')'){
			count--;
		}
		if(st.top()==']'){
			count1--;
		}
		if(st.top()=='}'){
			count2--;
		}
		if(count<0){
			cout<<"NO";
			return 0;
		}
		if(count1<0){
			cout<<"NO";
			return 0;
		}
		if(count2<0){
			cout<<"NO";
			return 0;
		}
		cout<<count<<endl;
		st.pop();
	}
	cout<<"YES";
}
