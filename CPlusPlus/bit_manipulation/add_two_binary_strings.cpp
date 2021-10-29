//Make them equal sized by adding 0s at the beginning of smaller string.
// Perform bit addition
//Time Complexity: O(log(m)+n1+n2) ; m->decimal representation of the sum of the binary numbers;n1->length of bit-1;n2->length of bit-2
//Space Complexity:O(1)
#include <bits/stdc++.h>
using namespace std;

string addBitStrings( string first, string second );
// Helper method: given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
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
	// make the lengths same before adding
	int length = makeEqualLength(first, second);

	int carry = 0; 

	for (int i = length-1 ; i >= 0 ; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';
		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry)+'0';

		result = (char)sum + result;
		// boolean expression for 3-bit addition
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}
	// if overflow, then add a leading 1
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
