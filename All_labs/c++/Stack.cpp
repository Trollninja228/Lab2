#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int main(){
	stack<int> st;
	/* 
	Задача круглые, квадратные и фигурные скобки. решить черерез stack
	[]  from up to bottom
	[2]
	[5]
	[3]
	*/
	st.push(3);
	st.push(5);
	st.push(2);
	cout<<st.empty()<<endl;
	cout<<st.size()<<endl;
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.push(2);
	while(st.empty()==false){
		cout<<st.top()<<endl;
		st.pop();
	}
}
	


