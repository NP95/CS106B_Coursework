/*
 * File: error.h
 * -------------
 * This file defines the ErrorException class and the error function.
 */

#ifndef _error_h
#define _error_h

#include <string>
#include <exception>

/*
 * Class: ErrorException
 * ---------------------
 * This exception is thrown by calls to the error function, which makes it
 * possible for clients to respond to error conditions.  Typical code for
 * catching errors looks like this:
 *
 *    try {
 *       . . . code in which an error might occur . . .
 *    } catch (ErrorException & ex) {
 *       . . . code to handle the error condition . . .
 *    }
 *
 * If an ErrorException is thrown at any point in the range of the try
 * (including in functions called from that code), control will jump
 * immediately to the error handler.
 */

class ErrorException : public std::exception {
public:
	ErrorException(std::string msg);
	virtual ~ErrorException() throw ();
	virtual std::string getMessage();
private:
	std::string msg;
};

/*
 * Function: error
 * Usage: error(msg);
 * ------------------
 * Signals an error condition in a program by throwing an ErrorException
 * with the specified message.
 */

void error(std::string str);

#include "private/main.h"

#endif