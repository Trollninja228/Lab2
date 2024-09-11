#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <Queue>
using namespace std;
int main(){
	/*
	[3][5][2][] from left to right
	*/
	queue<int> q;
	q.push(3);
	q.push(5);
	q.push(2);
	cout<<"Front:"<<q.front()<<endl;
	cout<<"Back:"<<q.back()<<endl;
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
}
