#include <bits/stdc++.h>
using namespace std;

string addBitStrings( string first, string second );

int makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
	}
	return len1; 
}


string addBitStrings( string first, string second )
{
	string result; 
	int length = makeEqualLength(first, second);

	int carry = 0; 

	for (int i = length-1 ; i >= 0 ; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';
		int sum = (firstBit ^ secondBit ^ carry)+'0';

		result = (char)sum + result;
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}
	if (carry)
		result = '1' + result;

	return result;
}

int main()
{
	string str1 = "1100011";
	string str2 = "10";

	cout << "Sum is " << addBitStrings(str1, str2);
	return 0;
}
