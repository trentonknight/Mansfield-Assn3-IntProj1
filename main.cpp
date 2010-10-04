#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

int buildLIST();
void driver(int& num);
void numLENGTH(int& num,int& length);
int powerOF(int& ten,int& shrink,int& length);
void subtract(int& num,int& ten,int& shrink,int& length,int& copyLength,int& endLength);
void add(int& addNUMBERS,int& num);

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
	int shrink = 2;
	int copyLength = 0;
	int endLength = 0;
	int addNUMBERS = 0;
	
	numLENGTH(num, length);
	copyLength = length;
	endLength = length;
	addNUMBERS = num;
	cout << "Number is length: " << length << " to the 10th power" << endl;
	subtract(num,ten,shrink,length,copyLength,endLength);		
}
void numLENGTH(int& num,int& length){	
	if(num != 0){
		num = num/10;
		cout << "num: " << num << endl;
		length++;
		numLENGTH(num,length);
	}
}
int powerOF(int& ten, int& shrink, int& length){
   if(length != shrink){		
		ten = (ten * 10);
	    length--;
		powerOF(ten,shrink,length);
	}
	return ten;
}
void subtract(int& num,int& ten,int& shrink,int& length,int& copyLength,int& endLength){
		
	if(endLength != 1){
	num = powerOF(ten,shrink,length);
	cout << num << endl;
	add(addNUMBERS,num);
	length = copyLength;
	ten = 10;
	shrink++;
	endLength--;
	subtract(num,ten,shrink,length,copyLength,endLength);
	}		
}
void add(int& addNUMBERS,int& num){
	
}