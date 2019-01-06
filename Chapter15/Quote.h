//
// Created by k on 19-1-2.
//

#ifndef QUOTE_H
#define QUOTE_H


class Quote {
    public:
        Quote() =default;
        Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price) {
            std::cout<<"Quote construct"<<std::endl;
        }
        Quote(Quote&){std::cout<<"Quote copy-construct"<<std::endl;}
        // returns the total sales price for the specified number of items
        // derived classes will override and apply different discount algorithms
        virtual double net_price(std::size_t n) const
        { return n*price;}
        virtual ~Quote()= default;//dynamic binding for the destructor
        double print_total();

         void add_item(const Quote& Sale);
        void add_item(Quote&& Sale);
        virtual Quote* clone() const & {return new Quote(*this);}
        virtual Quote* clone() && {return new Quote(std::move(*this);)}

    private:
        std::string bookNo; //ISBN number of this item;
    protected:  //子类可以访问
        double price = 0.0; // normal,undiscounted price
};
double print_total(std::ostream &os,const Quote &item,size_t n)
{
    //根据传入item形参的对象类型调用Quote::net_price
    //或者Bulk_quote::net_price
    double ret = item.net_price(n);

    os<<"ISBN: "<<n<<" total due: "<<ret<<std::endl;
    return ret;
}

class Bulk_quote:public Quote{
    public:
        //Bulk_quote inherits from Quote
        Bulk_quote()= default;
        //Bulk_quote(const std::string&, double,std::size_t, double);
        //overrides the base version in order to implement the bulk purchase discount policy
        Bulk_quote(const std::string& book, double p,std::size_t qty, double disc):
            Quote(book,p),min_qty(qty),discount(disc){std::cout<<"Bulk_quote construct"<<std::endl;}
        //使用基类的构造函数
        //using Quote::Quote;
        Bulk_quote(Bulk_quote&){std::cout<<"Bulk_quote copy-construct"<<std::endl;}
        Bulk_quote& operator=(Bulk_quote&){std::cout<<"Bulk_quote assign-construct"<<std::endl;}
        //如果基类没有定义拷贝构造函数或移动拷贝函数，则这个函数是delete的
        Bulk_quote(Bulk_quote&&){std::cout<<"Bulk_quote move-construct"<<std::endl;}

        double net_price(std::size_t) const override;

        Bulk_quote* clone() const & {return new Bulk_quote(*this);}
        Bulk_quote* clone() && {return new Bulk_quote(std::move(*this))}

    private:
        std::size_t min_qty = 0; //minimum purchase for the discount to apply

        double discount = 0.0; //fractional discount to apply
};


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
