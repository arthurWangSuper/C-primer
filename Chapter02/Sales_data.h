#ifndef SALES_DATA
#define SALES_DATA

#include <string>
using std::string;

struct Sales_data{
	string ISBN;
	double price{0.0};
	unsigned sales = 0;
	double avenue = {0.0};
};

#endif
