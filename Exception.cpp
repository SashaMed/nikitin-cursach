#include "Exception.h"

string Exception::what()
{
	return error_message;
}