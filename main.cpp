#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

int buildLIST();
void driver(int& num);
void numLENGTH(int& num,int& length);
int powerOF(int& ten,int& length);

int main () {
	int num = 0;
	
	num = buildLIST();
	driver(num);
    
    return 0;
}
int buildLIST(){
	int getINT;
	
	cout << "This Program takes a non-negative integer and reverses it." << endl;
	cout << "Please enter an Integer: ";
	cin >> getINT;
	if(getINT <= 0){
		cout << "ERROR integer must be larger than zero!" << endl;
		buildLIST();
	}
}
void driver(int& num){
	int length = 0;
	int ten = 10;
	
	numLENGTH(num, length);
	cout << "Number is length: " << length << " to the 10th power" << endl;
	num = powerOF(ten, length);
	cout << "First number to the power of " << num << endl;
	
}
void numLENGTH(int& num,int& length){	
	if(num != 0){
		num = num/10;
		cout << "num: " << num << endl;
		length++;
		numLENGTH(num,length);
	}
}
int powerOF(int& ten, int& length){
   if(length != 2){		
		ten = (ten * 10);
	    length--;
		powerOF(ten,length);
	}	
return ten;
}