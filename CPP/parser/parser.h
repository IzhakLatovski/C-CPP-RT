#ifndef PARSER_H
#define PARSER_H

#include "analyzer.h"

#include <stdio>
#include <string>
#include <vector>

using namespace std;

class parser_t
{
	public:
		~parser_t();
		parser_t();
		void function(const char* input);

	private:
		analyzer_t m_analyzer;
		vector<string> m_token;

		parser_t(const parser_t& temp);
		parser_t& operator=(const parser_t& temp);
};

#endif