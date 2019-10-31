/* -------------------------------------------------

FILE:		strprgms.h
DESCRIPTION:	strprgms header file for Project 5 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Necessary for using myStringCopy()

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-09	1.0 Created this file; Moved func declarations from WIP proj5.cpp
*/

#ifndef STRPRGMS_H
#define STRPRGMS_H

#include <iostream>

// Taken from Project 4
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);

#endif
