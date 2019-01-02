//
// Created by k on 19-1-2.
//

#ifndef PROJECT_QUOTE_H
#define PROJECT_QUOTE_H


class Quote {
    public:
        Quote()= default;// =default
        Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price) {}
        // returns the total sales price for the specified number of items
        // derived classes will override and apply different discount algorithms
        virtual double net_price(std::size_t n) const
        { return n*price;}
        virtual ~Quote()= default;//dynamic binding for the destructor
        double print_total();
    private:
        std::string bookNo; //ISBN number of this item;
    protected:  //子类可以访问
        double price = 0.0; // normal,undiscounted price
};

class Bulk_quote:public Quote{
        //Bulk_quote inherits from Quote
        Bulk_quote()= default;
        Bulk_quote(const std::string&, double,std::size_t, double);
        //overrides the base version in order to implement the bulk purchase discount policy
        double net_price(std::size_t) const override;
    private:
        std::size_t min_qty = 0; //minimum purchase for the discount to apply

        double discount = 0.0; //fractional discount to apply
};
Bulk_quote(const std::string& book, double p,std::size_t qty, double disc):
    Quote(book,p),min_qty(qty),discount(disc){}

    double Bulk_quote::net_price(std::size_t cnt) const
    {
        if(cnt >= min_qty)
        {
            return cnt*(1-discount)*price;
        } else{
            return cnt*price;
        }

    }
#endif //PROJECT_QUOTE_H
