#ifndef _calctools
#define _calctools


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

double averageArray(int *givenpassedpointer, int givenfinalsize);
double averageArray(double *givenpassedpointer, int givenfinalsize);
string toBinary(int decimal);


double averageArray(int *givenpassedpointer, int givenfinalsize)
{
    int counter = 0;
    int sum = 0;
    while(counter < givenfinalsize)
    {

        sum = sum + *givenpassedpointer;
        givenpassedpointer = givenpassedpointer+1;
        counter = counter + 1;


    }

    double answer =  (sum/((double)givenfinalsize));

    return answer;
}

double averageArray(double *givenpassedpointer, int givenfinalsize)
{
    int counter = 0;
    double sum = 0;
    while(counter < givenfinalsize)
    {

        sum = sum + *givenpassedpointer;
        givenpassedpointer = givenpassedpointer+1;
        counter = counter +1;


    }

    double answer =  (sum/(givenfinalsize));

    return answer;
}

string toBinary(int decimal){

    stringstream out;

    string answer = "";

    int remainder;

    if(decimal == 0){
        return "0";
    }
    if(decimal == 1){
        return "1";
    }

    while(decimal != 0){

        remainder = decimal % 2;
        out << remainder;
        answer = out.str() + answer;
        decimal = decimal / 2.0;
        out.str("");

    }
    return answer;
}

string toDecimal(string binary){

	string returnstring;
	int i;
	int base = 0;
	
	for(i=0; i < binary.length(); i++){

		base = (base * 2) + (binary[i] - '0');

	}

	stringstream ss;
	ss << base;
	returnstring = ss.str();
	return returnstring;

}


#endif
