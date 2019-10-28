#include "tokenizer.h"

#include <iostream>

using namespace std;

queue<string>& tokenizer_t::tokenize(const string& myString)
{
	size_t index=0;
	size_t occurance=myString.find_first_of(delimiters_m,index);
	while(occurance!=string::npos)
	{
		if(index!=occurance)	// tokenize the string till the delimiter
		{
			tokens_m.push(myString.substr(index,(occurance-index)));
		}
		if(isspace(myString[occurance])==0)		//if i'm a delimiter, im a token myself
		{
			tokens_m.push(myString.substr(occurance,1));
		}
		index=(++occurance);		// start again after the last dilimiter
		occurance=myString.find_first_of(delimiters_m,index);
	}

	return tokens_m;
}