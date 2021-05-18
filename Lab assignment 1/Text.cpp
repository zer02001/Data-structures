//--------------------------------------------------------------------
//
//  Laboratory 1                                          Text.cpp
//
//  SOLUTION: Array implementation of the String ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

//--------------------------------------------------------------------

Text::Text(const char* charSeq)

// Creates a string containing the delimited sequence of characters
// charSeq. Allocates enough memory for this string.
  





{

	bufferSize = strlen(charSeq);

	// Account for null

	try
	{
		buffer = new char [bufferSize];


		

		// Allocate memory
	}
	catch (bad_alloc & e)
	{
		cout << "error: allocation of mememory error" << endl;
	}

	for (int i = 0; i < bufferSize; i++) {
		buffer[i] = charSeq[i];
	}
	// Copy the string
}

//--------------------------------------------------------------------

Text::Text(const Text& valueText)

// Copy constructor, creates a copy of valueText. Called whenever
//
//   1) a string is passed to a function using call by value,
//   2) a function returns a string, or
//   3) a string is initialized using another string -- as in the
//      declarations:
//                      Text str1("First"),
//                             str2 = str1;




{
	// Allocate memory
	// Copy the string

	bufferSize = valueText.bufferSize;
	buffer = new char[bufferSize];
	for (int i = 0; i < bufferSize; i++) {
		buffer[i] = valueText.buffer[i];
	}

}

//--------------------------------------------------------------------

void Text:: operator = (const Text& other)

// Assigns other to a Text object.

{


	// Length of other



	if (other.bufferSize != bufferSize)          // If other will not fit
	{
		bufferSize = other.bufferSize;

		// Release buffer and
		//  allocate a new
	   //  (larger) buffer
	}
	for (int i = 0; i < bufferSize; i++) {
		buffer[i] = other.buffer[i];
	}

	// Copy other
}

//--------------------------------------------------------------------

Text:: ~Text()

// Frees the memory used by the Text object buffer.

{
	delete[] buffer;
}

//--------------------------------------------------------------------

int Text::getLength() const

// Returns the number of characters in the Text object buffer (excluding the
// null character).

{
	return strlen(buffer);
}

//--------------------------------------------------------------------

char Text:: operator [] (int n) const

// Returns the nth character in a Text object -- where the characters are
// numbered beginning with zero.

{

	if (n >= bufferSize || n < 0)
		return '\0';
	return buffer[n];


	return buffer[n];



}

//--------------------------------------------------------------------

void Text::clear()

// Clears a Text object -- i.e., makes it empty. The buffer size
// remains unchanged.

{

	for (int i = 0; i < bufferSize; i++) {
		buffer[i] = '\0';
	}



}

//--------------------------------------------------------------------

void Text::showStructure() const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
	// Loop counter

	for (int i = 0; i < bufferSize ; i++) {
	
		cout << buffer[i];
	
	}
	cout << endl;




		
}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

istream& operator >> (istream& input, Text& inputText)

// (In-lab 1)  Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.

{
	const int textBufferSize = 256;     // Large (but finite)
	char textBuffer[textBufferSize];   // text buffer

	// Read a string into textBuffer, setw is used to prevent buffer
	// overflow.

	input >> setw(textBufferSize) >> textBuffer;


	
	// Apply the Text(char*) constructor to convert textBuffer to
	// a string. Assign the resulting string to inputText using the
	// assignment operator.


	char* result;
	result = (char*)malloc(textBufferSize + 1);

	for (int i = 0; i < textBufferSize; i++) {
		result[i] = textBuffer[i];


	}
	inputText = textBuffer;

	// Return the state of the input stream.

	return input;
}

//--------------------------------------------------------------------

ostream& operator << (ostream& output, const Text& outputText)

// (In-lab 1)  Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
	cout << outputText.buffer;

	return output;




}


//--------------------------------------------------------------------

Text Text::toUpper() const

// (In-lab 2)  Returns a Text object containing an upper-case copy of Text object.

{
	Text tempBuf;
	tempBuf.bufferSize = bufferSize;

	tempBuf.buffer = new char[tempBuf.bufferSize];
	for (int i = 0; i < bufferSize; i++) {
	
		tempBuf.buffer[i] = toupper(buffer[i]);
	
		


	}



// Option 1: Correct. Create correctly initialized object, and return object reference by
// dereferencing new object's address.
//return Text( tempBuf );

// Option 2: Also correct. Wordier, but perhaps easier for students to follow.
Text upper(tempBuf);
return upper;
}

//--------------------------------------------------------------------

Text Text::toLower() const

// (In-lab 2)  Returns a Text object containing a lower-case copy of Text object.

{

	Text tempbuf;

	tempbuf.bufferSize = bufferSize;

	tempbuf.buffer = new char[tempbuf.bufferSize];



	for (int i = 0; i < bufferSize; i++) {

		tempbuf.buffer[i] = tolower(buffer[i]);




	}





return Text(tempbuf);
}


//--------------------------------------------------------------------

bool Text::operator == (const Text& other) const

// (In-lab 3)  Equality relational operator. Returns true if leftText is equal to
// other. Otherwise returns false.

{

	int answer = 1;
	if (bufferSize != other.bufferSize) return false;
	else {
		for (int i = 0; i < bufferSize; i++) {

			if (other.buffer[i] != buffer[i]) answer =0; 




		}



	}

	if (answer == 0) return false;
	else return true;

}

//--------------------------------------------------------------------

bool Text::operator < (const Text& other) const

	// (In-lab 3)  "Less than" relational operator. Returns true if leftText is less
	// than other. Otherwise returns false.
{


	return (strcmp(buffer, other.buffer) < 0);





}

//--------------------------------------------------------------------

bool Text::operator > (const Text& other) const

// (In-lab 3)  "Greater than" relational operator. Returns true if leftText is
// greater than other. Otherwise returns false.

{
	return (strcmp(buffer, other.buffer) > 0);
}


