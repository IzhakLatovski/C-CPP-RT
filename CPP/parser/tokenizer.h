#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <queue>
#include <string>

using namespace std;

class tokenizer_t
{
	public:
		virtual ~tokenizer_t(){};
		tokenizer_t(){delimiters_m="=+-&*; (){}[]<>\t\v\f\r\n";};
		queue<string>& tokenize(const string& myString);

	private:
		queue<string> tokens_m;
		string delimiters_m;

		tokenizer_t(const tokenizer_t& temp);
		tokenizer_t& operator=(const tokenizer_t& temp);
};

#endif