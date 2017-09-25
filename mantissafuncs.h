#pragma once


int findDecimal(char numString[]);

bool mantissa(char numString[], int& numerator, int& denominator)
{
	bool retVal = true; // assume value is good
	// This variable checks whether we have encountered a space. Leading and trailing spaces are a-ok,
	// but if there's a space in the middle of the number that's no good
	bool space = false;

	// starting with variable initializing
	char currentChar = '1'; // the char we're looking at. Initialized to 1, but this is arbitrary.
	int iterator = 0; // where we are in the array
	int decimalPlacement = 0; // This will record where the decimal pt is in the array
	int mantissaSize = 0; // current size of the mantissa
	numerator = 0; // initialize the numerator
	denominator = 1; // denominator starts at 1, so currently assuming it's a whole number

	// Find where the mantissa starts. There are checks in this function for bad characteristic.
	// This is because if the characteristic is bad, there's no point in doing the work for mantissa.
	iterator = findDecimal(numString);
	//When finding the mantissa, we want to start directly after the decimal point. 
	decimalPlacement = iterator; 

	while (currentChar != '\0' && retVal != false)
	{
		// we continue iterating. It's unnecessary to iterate if we got a bad array.
		currentChar = numString[iterator];
		// You can't have a decimal point after the decimal point so the check is simpler
		if (space == true)
		{
			if (currentChar != ' ')
			{
				if (currentChar == '\0')
				{
					break; // if we find the terminator, it's still a good value
				}
				// if we're in space mode and we find something else, there's spaces just in the middle. That's bad.
				else
				{
					retVal = false;
					break;
				}
			}
		}
		// if the chars are anything other than 0-9 and we're not in space mode, all other chars are bad
		if (numString[iterator] > '9' || numString[iterator] < '0' && space == false)
		{
			if (currentChar == ' ')
			{
				space = true;
			}
			else if(currentChar == '\0')
			{
				break; // if we hit the null terminator, just break. It's still a good mantissa.
			}
			else
			{
				retVal = false;
				break;
			}
		}
	
		
		// iterator adds one
		iterator++;
		// mantissa grows now that we've gone past the decimal point
		mantissaSize++;
		
	}
	iterator--; // Now that we've hit the null terminator, move backwards one.
	currentChar = numString[iterator];

	// Check that there aren't any trailing 0s or spaces
	while ((currentChar == '0' || currentChar == ' ') && retVal != false)
	{
		// If the current character is a space or 0, mantissa size shrinks. 0s and spaces do not make large mantissa.
		mantissaSize--;
		// We also iterate backwards. If we hit the decimal point, that is neither a 0 nor a space so 
		// we shouldn't hit the characteristic.
		iterator--;
		currentChar = numString[iterator];
	}

	// We want to preserve mantissaSize but we also need to get to the correct power of 10, so
	// I'm making a version we can safely change.
	int denominatorCounter = mantissaSize;
	while (denominatorCounter > 0 && retVal != false)
	{
		// multiply denominator by ten for each number in the mantissa.
		denominator *= 10;

		denominatorCounter--; // count backwards some more until we reach size 0.

	}

	// Using the variable for a new purpose: now it counts what power of ten this part of the mantissa is at.
	// We start at a power of 10 less than the denominator because the denominator is always one more power of ten.
	denominatorCounter = denominator / 10;
	//This might be redundant since a char can have int math done on it.
	int currentDigit = 0; 
	// Check the retVal so we don't loop unnecessarily.
	if (retVal == true)
	{
		// This loop starts after the decimal point, and ends before the first garbage char or the null terminator.
		for (int i = decimalPlacement; i < (mantissaSize + decimalPlacement); i++)
		{
			//Start at the digit immediately after the decimal point. Numbers have ascii codes that don't actually
			// correspond their value so subtracting 48 (the ascii value of 0) converts them.
			currentDigit = numString[i] - 48;
			// Multiply it by ten.
			currentDigit *= denominatorCounter;
			// Add it onto the numerator.
			numerator += currentDigit;
			// Divide our counter by 10 so we multiply the next digit by a power of 10 less.
			// This way, it should work like this: Say we have the number 4.134
			// 134 is the mantissa. We start at 1, multiply it by 100
			// Then multiply 3 by 10 because counter went down, current digit proceeded.
			// Added to 100 = 130
			// 4*1 = 4, 130 + 4 = 134.
			// As we go farther into the mantissa, our powers of ten are less powerful.
			denominatorCounter /= 10;
		}
	}


	return retVal;
}

int findDecimal(char numString[])
{
	bool space = true;
	bool firstNonZero = false;

	int retVal = 0;
	char currentChar = numString[retVal];
	while (currentChar != '.')
	{
		if (firstNonZero == true)
		{
			firstNonZero = false;
		}
		// Currentchar goes over the char array
		currentChar = numString[retVal];
		// Check if we're still in the leading spaces. But only if space is still true. 
		if (currentChar != ' ' && space == true)
		{
			space = false;
			firstNonZero = true;
		}
		// if currentChar is greater than ascii 9, less than ascii decimal pt, or equals /, the data is bad
		// '/' is the character between 0-9 and decimal pt, so it is specifically enumerated.
		// Not important until we are out of leading spaces.
		if ((currentChar > '9' || currentChar < '.' || currentChar == '/') && space == false)
		{
			if (firstNonZero == true && (currentChar == '+' || currentChar == '-'))
			{
				firstNonZero = false;
			}
			else
			{
				retVal = false;
				break;
			}

		}
		// Iterator goes up. We don't know how long the characteristic goes, so we cannot use a for loop.
		retVal++;
	}
	return retVal;
}
