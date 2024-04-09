#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
bool isOdd(int a){
	if(a%2==0){
		return false;
	}
	return true;
}
using namespace std;
int main(){
	int a[5]={3,5,2,9,10};
	vector<int> v(a,a+5);
	cout<<count_if(v.begin(),v.end(),isOdd);//адреса начала и конца, и бул условие, или бул функция
}
	


