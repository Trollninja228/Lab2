#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <time.h>
using namespace std;
int gen(){
	srand(time(0));
	return rand()%23+2000;
}
int main(){
	vector<int> v(5);
	srand(time(0));
	cout<<rand()<<endl;//[0-RAND_MAX]=> RAND_MAX~>32000
	cout<<rand()%10<<endl;//генерация от 0 до 9
	cout<<rand()%23+2000<<endl;//генерация от 2000 до 2023
	generate(v.begin(),v.end(),gen);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
	


