#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
void show (int a){
	cout<<a<<" ";
}
int main(){
	vector<int> v(5);
	//ещЄ есть unique он убирает повтор€ющиес€ соседние элементы тоесть было {1,3,3,3,2,1,2,2} стало {1,3,2,1,2}
	fill(v.begin(),v.end(),3);
	for_each(v.begin(),v.end(),show);
}
	


