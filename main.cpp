#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

int buildLIST();
void driver(int& num);
void numLENGTH(int& num,int& length,int& place,int& addNUMBER_TOGETHER,int& original_NUMBER,int& last_NUMBER,int& current_NUMBER,int& power);
int powerOF(int& ten,int& shrink,int& length);

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
	int place = 10;
	int power = 1;
	int addNUMBER_TOGETHER = 0;
	int original_NUMBER = 0;
	int last_NUMBER = 0;
	int current_NUMBER = 0;
	original_NUMBER = num;
	numLENGTH(num, length, place, addNUMBER_TOGETHER,original_NUMBER,last_NUMBER,current_NUMBER,power);
	cout << "Number is length: " << length << " to the 10th power" << endl;
	
}
void numLENGTH(int& num,int& length,int& place,int& addNUMBER_TOGETHER,int& original_NUMBER,int& last_NUMBER,int& current_NUMBER,int& power){
	
	if(num != 0){
		num = num/10;
		cout << "num place: " << num * place << endl;
		current_NUMBER = original_NUMBER - (num * place);
		current_NUMBER = current_NUMBER - last_NUMBER;
		cout << "num subtracted from last num: " << current_NUMBER << endl;
		last_NUMBER = last_NUMBER + current_NUMBER;
		current_NUMBER = last_NUMBER/power;
		cout << "cur: " << current_NUMBER << endl;
		addNUMBER_TOGETHER = addNUMBER_TOGETHER + current_NUMBER;
		cout << "Total Numbers." << addNUMBER_TOGETHER << endl;
		power = power * 10;
		place = place * 10;
		length++;
		numLENGTH(num,length,place,addNUMBER_TOGETHER,original_NUMBER,last_NUMBER,current_NUMBER,power);
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

