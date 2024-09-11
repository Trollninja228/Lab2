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

	


