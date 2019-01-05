#include <iostream>
#include <string>

#include "Quote.h"

using namespace std;

int main(int argc,char**argv)
{
    cout<<"==============stage-1==============="<<endl;
    //Bulk_quote *pBQ = new Bulk_quote(string("Sting"),19.9,10,0.9);
    Bulk_quote *pBQ = new Bulk_quote(string("Sting"),19.9);
    cout<<"===============stage-2==============="<<endl;
    Bulk_quote BQ1(*pBQ);
    cout<<"===============stage-3==============="<<endl;
    Bulk_quote BQ2;
    cout<<"===============stage-4==============="<<endl;
    BQ2 = BQ1;
    cout<<"===============stage-5==============="<<endl;
    Bulk_quote BQ3;
    BQ3 = BQ1;
    Bulk_quote BQ4(std::move(BQ3));
    return 0;
}