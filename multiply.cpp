//Cole Sitzberger
//Multiply

#include <iostream>

using namespace std;
int multiplyDigit(char firstnum[], char secondnum[]);
bool multiply(unsigned int chara1, unsigned int mantiU1, unsigned int mantiO1, unsigned int chara2, unsigned int mantiU2, unsigned int mantiO2, char result[], int len);
int findZeros(int mantiO);
void print(char num[]);

int main()
{
	//test
	char result[5];
	if (multiply(21, 31, 100, 3, 99, 10000, result, 5))
	{
		print(result);
	}
	else
	{
		cout << "error"<< endl;
	}
}


bool multiply(unsigned int charactersic1, unsigned int  mantissaNumerator1, unsigned int mantissaD1, unsigned int charactersic2, unsigned int mantissaNumerator2, unsigned int mantissaD2, char result[], int len)
{
	//convert params int char[] so they can be operated on as one number in multiplyDigit
	
	//create an array to hold the first number being multiplied 
	char firstNumber[10000];
	//create an array to hold the product
	char ret[10000];
	//Intialize 
	for (int i = 0; i < 100; i++)
	{
		//Setting all chars in array to /0 so the end can be found 
		firstNumber[i] = '/0';
	}
	//set the first slot in the array to the charactersic
	firstNumber[0] = charactersic1;
	//set the second slot to a decimal
	firstNumber[1] = '.';
	//find the number of zeros
	if (mantissaD1 > 1)
	{	
		int loopcount = 2;
		for (int j = 0; j < findZeros(mantissaD1); j++)
		{
			
			firstNumber[j] = 0;
		}
		
	}
	firstNumber[99] = '/0';
	//finds the point in the array to place the first part of the mantissa 
	int loopone = 2;
	while(true)
	{
		
		if (firstNumber[loopone] == '/0')
		{
			firstNumber[loopone] = mantissaNumerator1;
			break;
		}
		loopone++;
			 
	}
	// repeat the previous portion for the second number 
	char secondNumber[100];
	for (int i = 0; i < 100; i++)
	{
		secondNumber[i] = '/0';
	}
	secondNumber[0] = charactersic2;
	secondNumber[1] = '.';

	if (mantissaNumerator2 > 1)
	{
		int loopcount = 2;
		for (int j = 0; j < findZeros(mantissaD2); j++)
		{
			
			secondNumber[2] = 0;
		}
		
	}
	secondNumber[99] = '/0';
	int looptwo = 2;
	while (true)
	{
		
		if (secondNumber[looptwo] == '/0')
		{
			secondNumber[looptwo] = mantissaNumerator2;
			false;
		}
		looptwo++;
	}
	
	
	
	//Multiply using the two loops to cycle through each digit of the numbers
	//starting from the back and moving to the front  
	for (int x = looptwo; x >= 0; x--)
	{
		if (firstNumber[loopone] != '.' || firstNumber[loopone] != '/0')
		{
			for (int z = loopone; z >= 0; z--)
			{
				if (secondNumber[looptwo] != '.' || secondNumber[looptwo] != '/0')
				{
					ret[loopone] = firstNumber[loopone] * secondNumber[looptwo];
				}

			}
		}
	}
	
	//
	int loopcount = len;
	//round the answer off to the desired length
	while (true)
	{
		

		if (ret[loopcount] != '/0')
		{
			ret[loopcount] == '/0';
		}
		else
		{
			ret[loopcount - 1] == ret[loopcount] + 1;
			false;
		}
	}

	bool retval(true);

	return retval;

}

//determines the number of zeros from the mantissa 
int findZeros(int mantiO)
{
	

	//counts the multiples of ten to detirmine the number of zeros
	int loopcount = mantiO%10;
	
	return loopcount;

}



void print(char num[])
{	
	int loopcount = 0;
	while (true)
	{
		if (num[loopcount != '/0'])
		{
			cout << num[loopcount];
			loopcount++;
		}
		else
		{
			false;
		}
		
	}
	cout << endl;
}