/* -------------------------------------------------

FILE:		strprgms.cpp
DESCRIPTION:	strprgms .cpp file for Project 5 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Necessary for using myStringCopy()

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-09	1.0 Created this file; Moved func implementations from WIP proj5.cpp
*/

#include "strprgms.h"

/* -----------------------------------------------------------------------------
FUNCTION:          myStringLength()
DESCRIPTION:       Finds and returns the length of a given string
RETURNS:           size_t (like an int)
NOTES:             
------------------------------------------------------------------------------- */

size_t myStringLength(const char * str)
{
	size_t i = 0;
	
	while (*str++)
	{
		i++;
	}
	
	return i;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCompare()
DESCRIPTION:       Compares two char arrays 
RETURNS:           int
NOTES:             return value is less than 0 if str1 is less than str2,
					greater than 0 if str1 is greater than str2, 0 if they're ==
------------------------------------------------------------------------------- */

int myStringCompare(const char * str1, const char * str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	
	return *str1 - *str2;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCopy()
DESCRIPTION:       Copies a char array to a destination
RETURNS:           pointer to a char
NOTES:             
------------------------------------------------------------------------------- */

char* myStringCopy(char * destination, const char * source)
{
	while ((*destination++ = *source++));
	
	return destination;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCat()
DESCRIPTION:       Adds (concatenates) a char array to a destination
RETURNS:           pointer to a char
NOTES:             
------------------------------------------------------------------------------- */

char* myStringCat(char * destination, const char * source)
{
	while (*destination)// Goes until '\0', then stops there
	{
		destination++;
	}
	
	// Same basic function as myStringCopy()
	while ((*destination++ = *source++));
	
	return destination;
}
