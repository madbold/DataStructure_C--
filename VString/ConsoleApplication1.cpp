// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "VString.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	//test assigment operator
	//VString arr = "vinod yadav";
	//VString arr_r ="amit c" ;
	//VString init = { '1','2' };
	//swap(arr, arr_r);
	VString s = "it";
	cout << "Char at " << 5 << "is" << s.at(1) << endl;
	//cout << init;
	//cout << arr.size()<<endl;
	//cout << arr << endl;
	
	//cout << arr_r.size() << endl;
	//cout << arr_r<< endl;

	// test move sementic

	//VString& ref_arr_r = arr_r;
	//auto move_cons = move(ref_arr_r); //conver rvalue ref

	//cout << "move cont" << move_cons <<endl;
	//cout << "arr_r state : " << arr_r << endl;

	
	//VString a = "fis global faltu";
	//VString new1 = "hello world";
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