//*********************************************************************
//  CODE FILENAME:	Mansfield-ASSN3-IntProj1.cpp
//  DESCRIPTION:	Program Takes one positive integer, num, as its argument
//                  and returns the sum of the digits that comprise the integer num
//  DATE:		03OCT10
//  DESIGNER:	Jason N Mansfield
//  FUNCTIONS:	buildLIST, driver, numLENGTH, powerOF
//**********************************************************************
#include <iostream>


using namespace std;

int buildLIST();
void driver(int& num);
void numLENGTH(int& num,int& place,int& addNUMBER_TOGETHER,int& original_NUMBER,
			   int& last_NUMBER,int& current_NUMBER,int& power);
//*********************************************************************
//  FUNCTION:	main
//  DESCRIPTION: simply call the two primary functions one to get input
//               the next to sum numbers
//  CALLS TO: buildLIST, driver
//**********************************************************************
int main () {
	int num = 0;
	
	num = buildLIST();//get approved int
	driver(num);//process number
	system("PAUSE");//for windows users
    return 0;
}
//*********************************************************************
//  FUNCTION:	buildLIST
//  DESCRIPTION: gets getINT integer
//  INPUT:
//      Parameters: getINT
//  OUTPUT:	
//      Return Val: integer
//      Parameters: getINT
//  CALLS TO: buildLIST (recursive function)
//**********************************************************************
int buildLIST(){
	int getINT;
	
	cout << "This Program Takes one positive integer, num, as its argument\n"
	     << "and returns the sum of the digits that comprise the integer num." << endl;
	cout << "Please enter an Integer: ";
	cin >> getINT;
	if(getINT <= 0){
		cout << "ERROR integer must be larger than zero!" << endl;
		buildLIST();
	}
	return getINT;
}
//*********************************************************************
//  FUNCTION: driver
//  DESCRIPTION: assignes int variables and passes to numLENGTH
//  INPUT:
//      Parameters: int num
//  OUTPUT:	
//      Return Val: addNUMBER_TOGETHER
//      Parameters: handles looping int for numLENGTH: num, length, place, addNUMBER_TOGETHER,original_NUMBER,
//                  last_NUMBER,current_NUMBER,power
//  CALLS TO: numLENGTH
//**********************************************************************
void driver(int& num){
	int place = 10;///increment number power
	int power = 1;///increment sum power
	int addNUMBER_TOGETHER = 0;///int to handle sum
	int original_NUMBER = 0;///int to hold original number
	int last_NUMBER = 0;///int to hold previous number
	int current_NUMBER = 0;///int to recieve current number
	original_NUMBER = num;///get original number
	numLENGTH(num,place, addNUMBER_TOGETHER,original_NUMBER,last_NUMBER,current_NUMBER,power);
	///return sum with addNUMBER_TOGETHER
	cout << "The Total sum of digits within this integer is: " << addNUMBER_TOGETHER << endl;
	
}
//*********************************************************************
//  FUNCTION: numLENGTH
//  DESCRIPTION: primary calculation function to sum int	
//  INPUT:
//      Parameters: num,length,place,addNUMBER_TOGETHER,original_NUMBER,
//                  last_NUMBER,current_NUMBER,power
//  OUTPUT:	
//      Return Val: returns addNUMBER to driver to display sum
//      Parameters: num,length,place,addNUMBER_TOGETHER,original_NUMBER,
//                  last_NUMBER,current_NUMBER,power
//  CALLS TO: numLENGTH (recursive function)
//**********************************************************************
void numLENGTH(int& num,int& place,int& addNUMBER_TOGETHER,int& original_NUMBER,
			   int& last_NUMBER,int& current_NUMBER,int& power){
	
	if(num != 0){
		num = num/10;
		///place starts @ 10 and is * 10 each loop
		///num = 123 if number was 1234 reflecting the
		///first three int we want to remove in full number
		///to leave only 4 on first loop from 1234.
		current_NUMBER = original_NUMBER - (num * place);
		///cur = 4 - last number (on first loop last number is only zero)
		///next loop last number will be 4 of course from this loop
		current_NUMBER = current_NUMBER - last_NUMBER;
		///last = 0 + 4 on first loop since last number is zero
		///next loop it would be 8 = 4 + 4
		last_NUMBER = last_NUMBER + current_NUMBER;
		///cur = 4/1
		current_NUMBER = last_NUMBER/power;
		///first loop addNUMBER = 4 next loop it will be incremented by
		///current number in loop. For 1234 it would be add = 4 + 3 on next loop
		addNUMBER_TOGETHER = addNUMBER_TOGETHER + current_NUMBER;///sum = sum + c
		///power incremented * 10 started at 10
		power = power * 10;
		///place incremented * 10 started at 1
		place = place * 10;
		///recursive loop
		numLENGTH(num,place,addNUMBER_TOGETHER,original_NUMBER,last_NUMBER,current_NUMBER,power);
	}
}


