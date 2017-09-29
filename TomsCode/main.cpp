//
//  main.cpp
//  subtract_v1
//
//  Created by Tom Shannon on 9/26/17.
//  Copyright © 2017 tom. All rights reserved.
//

#include <iostream>
#include "subtract.h"
using namespace std;

int main()
{
    char result[10];
    int len = 10;
    
    cout << "Answer: 10.10  Calculated: ";
    subtract(50, 90, 100, 40, 80, 100, result, len);
    
    cout << "Answer: 1.40  Calculated: ";
    subtract(42, 20, 100, 40, 80, 100, result, len);
    
    cout << "Answer: -72.17  Calculated: ";
    subtract(-32, 9, 100, 40, 8, 100, result, len);
    
    cout << "Answer: -23.051  Calculated: ";
    subtract(17, 9, 1000, 40, 6, 100, result, len);
    
    cout << "Answer: -22.916  Calculated: ";
    subtract(17, 9, 100, 40, 6, 1000, result, len);
    
    cout << "Answer: 0.0  Calculated: ";
    subtract(0, 0, 100, 0, 0, 1000, result, len);
    
    return 0;
}
