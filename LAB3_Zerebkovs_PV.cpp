#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string> 




std::vector<int> answer = {};
std::vector<int> values = {};

std::string ConvertArrValuesToString(std::vector<int> arr) {
    std::string output = "";
    for (int i = 0; i < arr.size(); i++) {
        output.append(std::to_string(arr.at(i)) + " ");
     }
    
    return output;
}


bool FindSumOfNumbers(int number, int index) {
    if (number == 0) {
        return true;
    }
    else if (index == values.size()-1) {
        return false;
    }
    else if (number < values.at(index)) {
        return FindSumOfNumbers(number, index+1);
    }

    if (FindSumOfNumbers(number - values.at(index), index+1)) {
        answer.push_back(index);
        return true;
    }

    if (FindSumOfNumbers(number, index+1)) {
        return true;
    }

    return false;
}



int main()
{
    int arraySize = 0;
    printf("Enter array size= "); scanf("%d", &arraySize);

    
     
    for (int i = 0; i <= arraySize; i++) {
        int value=0;
        printf("Enter array value %d: ", i); scanf("%d", &value);
        values.push_back(value);
    }

    int K = 0;

    printf("Enter number to find= "); scanf("%d", &K);

    std::string eneteredValues = ConvertArrValuesToString(values);

    std::cout << "Entered values: "+eneteredValues << "\n";

    if (FindSumOfNumbers(K, 0)) {

        std::string result = ConvertArrValuesToString(answer);

        std::cout << "Indexes: " + result << "\n";
    }
    else {
        std::cout << "Can't find sum" << "\n";
    }

    return 0;
}

