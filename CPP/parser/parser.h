#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include "analyzer.h"

using namespace std;


class parser_t
{
	public:
		virtual ~parser_t();
		parser_t();
		void parse(const char* fileName);

	private:
		parser_t(const parser_t& temp);
		parser_t& operator=(const parser_t& temp);

		tokenizer_t* tokenizer_m;
		analyzer_t* analyzer_m;
};

#endif