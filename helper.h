#include<iostream>
#include<fstream>
using namespace std;

char* bufferToChar(istream& fr, char delimiter, char* str)
{
	char buffer[100] = { 0 };
	int i = 0;
	while (i < 99)
	{
		fr >> buffer[i];
		if (buffer[i] == delimiter)
			break;
		i++;
	}
	int length = i;
	str = new char[length];
	for (int j = 0; j < length; j++)
	{
		str[j] = buffer[j];
	}
	str[length] = '\0';
	return str;
}

char** bufferTo2dchar (istream& fr, char delimiter, char breaker, char** str, int& count)
{
	char buffer[20][20];
	int r = 0;
	int c = 0;
	while (r < 20 && c < 20)
	{
		fr >> buffer[r][c];
		if (buffer[r][c] == delimiter)
			break;
		if (buffer[r][c] == breaker)
		{
			buffer[r][c] = '\0';
			r++;
			c = 0;
		}
		else
			c++;
	}
	str = new char* [r];
	for (int i = 0; i < r; i++)
	{
		str[i] = new char[c + 1];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			str[i][j] = buffer[i][j];
		}
	}
	count = r;
	return str;
}

int stringLength( char* array)
{
	int length =0;  
	for (int i = 0; array[i] != NULL; i++)  //using loop until NULL operator
	{
		length++;
	}
	return length;
}

char* stringConcatenate(char* array1,char* array2)
{
	int index =0;
	for (int i =0; array1[i] != NULL; i++)
	{
		array1[i] = array1[i];
		index++;
	}
	for (int j =0; array2[j] != NULL; j++)
	{
		array1[index] = array2[j];
		index++;
	}
	array1[index] = NULL;
	return array1;
}

char* stringCopy(char* array2, char* array1)
{
	int i;
	for (i = 0; array1[i] != '\0'; i++)
	{
		array2[i] = array1[i];
	}
	array2[i] = '\0';
	return array2;
}

int stringCompare(char* array1, char* array2)
{

	if (stringLength(array1) > stringLength(array2))
		return 1;
	else if (stringLength(array1) < stringLength(array2))
		return -1;
	int size = stringLength(array1);
	for (int i = 0; i < size; i++) {
		if (array1[i] == array2[i])
			continue;
		else
			return -99;
	}
	return 0;
}

//char* buffer(const char array[], char* arr)
//{
//
//	arr = nullptr;
//	int i = 0;
//	while (array[i] != '\0')
//	{
//		arr[i] = array[i];
//		i++;
//	}
//	arr[i] = '\0';
//	return arr;
//}
