// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "1DArray.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	//test assigment operator
	Array1D arr ="vinod yadav";
	Array1D arr_r ="amit c" ;
	//swap(arr, arr_r);
	arr_r = move(arr);
	cout << arr.size()<<endl;
	cout << arr << endl;
	
	cout << arr_r.size() << endl;
	cout << arr_r<< endl;

	// test move sementic

	//Array1D& ref_arr_r = arr_r;
	//auto move_cons = move(ref_arr_r); //conver rvalue ref

	//cout << "move cont" << move_cons <<endl;
	//cout << "arr_r state : " << arr_r << endl;

	
	//Array1D a = "fis global faltu";
	//Array1D new1 = "hello world";
	//new1 = move(a);

	//cout << "move assign :" << a;
	//cout << "rval_ref :" << new1;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file