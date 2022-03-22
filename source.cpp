#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <fstream>


//Не забудь запустить профайлер сюда

int main(){
long children;
long capacity;
long buff;
bool fl = false;
std::ifstream input("test_input1.txt");
long k = 0;
std::deque <long> c_w;

input>>children;
input.ignore(1);
input>>capacity;

while(input){
	input>>buff;
	input.ignore(1);
	c_w.push_back(buff);
}buff = 0;


std::sort(c_w.begin(),c_w.end());

while(c_w.empty() != true){
	for(long j = k + 1;j < children;j++){
		if(c_w[k] + c_w[j] <= capacity){
			c_w.erase(c_w.begin() + j);
			c_w.erase(c_w.begin() + k);
			buff++;
			children-=2;
			fl = true;
			break;
		}
	}
	if(fl == false){
		while(c_w.empty() != true){
			buff++;
			c_w.erase(c_w.begin());
		}
	}
	fl = false;
}

std::cout <<buff;
}

// 7 2 3 9 
// 2 3 7 9
// 9 2 9 
