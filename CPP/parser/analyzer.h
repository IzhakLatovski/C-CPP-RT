#ifndef ANALYZER_H
#define ANALYZER_H

#include "analyzer.h"

#include <stdio>
#include <string>
#include <vector>

using namespace std;

class analyzer_t
{
	public:
		~analyzer_t();
		analyzer_t();

	private:
		analyzer_t(const analyzer_t& temp);
		analyzer_t& operator=(const analyzer_t& temp);
};

#endif