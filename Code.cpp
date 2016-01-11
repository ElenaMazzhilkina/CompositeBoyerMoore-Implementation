/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 256;
static int helper[SIZE];

void preprocessPattern(string pattern, int patternLength)
{
	for(int i=0; i<SIZE; ++i)
		helper[i] = patternLength;

	for(int i=0; i<patternLength; ++i)
		helper[pattern[i]] = patternLength-1-i;
}

int find(string text, string pattern)
{
	int patternLength = pattern.length();
	int textLength = text.length();
	if(patternLength > textLength)
		return -1;

	preprocessPattern(pattern, patternLength);
	int shift = patternLength-1;
	while(shift < textLength)
	{
		int textIter = shift;
		int patIter = patternLength-1;

		while(patIter>=0 && (pattern[patIter] == text[textIter]))
		{
			patIter--;
			textIter--;
		}

		if(patIter < 0)
			return textIter+1;
		else
			shift = shift + helper[text[shift]];
	}
}

int main() {
	string text = "abcdeabf";
	string pattern = "abf";

	cout <<find(text, pattern)<<endl;

	return 0;
}

/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */