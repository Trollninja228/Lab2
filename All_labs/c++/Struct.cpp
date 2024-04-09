#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct Student{		//property,field,attributes
	string	id;
	string name;
	int age;
	float gpa;
	void in(){
		cin>>id>>name>>age>>gpa;
	}
	void out(){
		cout<<id<<" "<<name<<" "<<age<<" "<<gpa<<endl;
	}
};
//Comparator
bool sortByAge(Student s1, Student s2){
	return s1.age<s2.age;
}
bool sortByAgeGPA(Student s1, Student s2){
	if (s1.age==s2.age){
		return s1.gpa>s2.gpa;
	}
	return s1.age<s2.age;
}
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
	


