#include <exception>
#include <iostream>
#include <vector>

void exceptions()
{
	using namespace std;

	// Simple
	try
	{
		throw 2;
	}
	catch (int e)
	{
		cout << "Caught exception " << e << endl;
	}

	try
	{
		vector<int> vec(-1);
	}
	catch (exception &e)
	{
		cout << "Standard exception " << e.what() << endl;
	}
}