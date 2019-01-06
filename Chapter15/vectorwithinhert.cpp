#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Quote.h"

using namespace std;

int main(int argc,char**argv)
{

    vector<shared_ptr<Quote>> basket;    
    //Bulk_quote *pBQ = new Bulk_quote(string("Sting"),19.9,10,0.9);
    //basket.push_back(make_shared<Quote>("Sting",19.9));
    basket.push_back(make_shared<Bulk_quote>("justin",19.9,10,0.25));
    
    //cout<<basket.back()->net_price(15)<<endl;
    double sum = 0.0;

    for(auto elem:basket)
        sum += elem->net_price(10);
    cout<<"total price: "<<sum<<endl;
    return 0;
}