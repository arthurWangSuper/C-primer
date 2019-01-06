#ifndef _INCLUDE_BASKET_
#define _INCLUDE_BASKET_

class Basket{
    public:
        //Basket使用合成的默认构造函数和拷贝控制成员
        void add_item(const std::shared_ptr<Quote> &sale)
        {items.insert(sale);}
        //打印每本书的总价和购物篮中的所有书的总价。
        double total_receipt(std::ostream&) const;
    private:
        //该函数用于比较shared__ptr,multiset成员会用到它
        static bool compare(const std::shared_ptr<Quote> &lhs,
                                const std::shared_ptr<Quote> &rhs)
        {return lhs->isbn()<rhs->isbn();}
        //multiset 保存多个报价，按照compare成员排序
        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items(compare);
}
double Basket::total_receipt(std::ostream&) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter))
    {
        sum += print_total(os,**iter,items.count(*iter));
    }   
    os<<"Total Sale: "<<sum<<endl;//打印最终价格
    return sum;
}
#endif