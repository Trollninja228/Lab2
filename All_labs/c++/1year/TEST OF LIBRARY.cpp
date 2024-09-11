#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <Student.h>
using namespace std;
int main(){
	freopen("Students.txt","r",stdin);
	int n;
/*  s.id="23B001";
	s.name="Timur";
	s.age=18;
	s.gpa=22.5;
	*/
	cin>>n;
	vector<Student> s;
	Student s1;
	for(int i=0;i<n;i++){
		//cin>>s[i].id>>s[i].name>>s[i].age>>s[i].gpa;
		s1.in();
		s.push_back(s1);
	}
	sort(s.begin(),s.end(), sortByAgeGPA);
	for(int i=0;i<n;i++){
		s[i].out();
	}
}
	


