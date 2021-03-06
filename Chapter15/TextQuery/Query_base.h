#ifndef _INCLUDE_QUERY_
#define _INCLUDE_QUERY_
#include <iostream>
class Query_base{
    friend class Query;
protected:
    using line_no = TextQuery::line_no; //用于eval函数

    virtual ~Query_base() = default;
private:
    //eval 返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery&) const =0;
    //rep 是表示查询的一个string
    virtual std::string rep() const = 0;
};

class Query{
    //这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
    friend Query operator~(const Query&);
    friend Query operator&(const Query&,const Query&);
    friend Query operator|(const Query&,const Query&);
public:
    Query(const std::string &);//构建一个新的wordQuery
    QueryResult eval(const TextQuery& t)const
            {return q->eval(t);}
    std::string rep() const{return q->rep();}
private:
    Query(std::shared_ptr<Query_base> Query):q(Query){}
    std:shared_ptr<Query_base> q;
};
inline Query::Query(const std::string &s):q(new WordQuery(s)){};


std::ostream &
operator<<(std::ostream &os,const Query &query)
{
    //Query：：rep通过Query_base 指针对rep进行了虚调用
    return os<<query.rep();
}

class WordQuery:public Query_base{
    friend class Query;

    WordQuery(const std::string &s):query_word(s){ }
    //具体的类：wordQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery& t) const
    {return t.query(query_word);}
    std::string rep() const {return query_word;}
    std::string query_word; //要查找的单词
};

class NotQuery:public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){}
    //具体的类：NotQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery& t) const;
    std::string rep() const {return "~("+query.rep()=")";}

    Query Query;
};
inline  Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base{
    protected:
        BinaryQuery(const Query &l,const Query &r,std::string s):
        lhs(l),rhs(r),opSym(s){ }
        //抽象类：BinaryQuery不定义eval     ==不定义抽象基类的虚函数，则派生类还是抽象类
        std::string rep() const {return "("+lhs.rep()+" "
                                            +opSym+" "
                                            +rhs.rep()+")";}
        Query lhs,rhs;  //左侧和右侧运算对象
        std::string opSym;  //运算符的名字
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query &left,const Query &right):BinaryQuery(left,right,"&"){}
    //具体的类：AndQuery 继承了rep并且定义了其他纯虚函数
    QueryResult eval(const TextQuery& ) const;
};

inline Query operator&(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery:public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):BinaryQuery(left,right,"|"){ }
    QueryResult eval(const TextQuery& ) const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
//返回运算对象查询结果set的并集 
QueryResult 
OrQuery::eval(const TextQuery& text) const
{
    //通过Query成员lhs和rhs进行虚调用
    //通过eval返回每个运算对象的QueryResult
    auto right = rhs.eval(text),left=lhs.eval(text);
    //将左侧运算对象的行号拷贝到结果set中
    auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
    //插入右侧运算符所得的行号  
    ret_lines->insert(right.begin(),right.end());
    //返回一个新的QueryResult，它表示lhs和rhs的并集
    return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult
AndQuery::eval(const TextQuery& text) const
{
    //通过Query成员lhs和rhs进行虚调用
    //通过eval返回每个运算对象的QueryResult
    auto right = rhs.eval(text),left=lhs.eval(text);
    //保存left和right交集的set
    auto ret_lines = make_shared<set<line_no>>();
    //将两次范围的交集写入一个目的迭代器中 本次使用标准库算法set_intersection来合并两个set
    //本次调用的目的迭代器向ret添加元素
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),
        inserter(*ret_lines,ret_lines->begin()));
    
    //返回一个新的QueryResult，它表示lhs和rhs的并集
    return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult
NotQuery::eval(const TextQuery& text) const
{
    //通过Query运算对象对eval进行虚调用
    auto result = query.eval( text);
    //开始时结果set为空
    auto ret_lines = make_shared<set<line_no>>();
    //我们必须在运算对象出现的所有行周进行迭代
    auto beg =result.begin(),end = result.end();
    //对输入文件的每一行，如果行不在result中，则将其添加到ret_lines
    auto sz - result.get_file->size();

    for(size_t n=0;n!=sz;++n)
    {
        //如果我们还没有处理完result的所有行
        //检查当前行是否存在
        if(beg == end||*beg!=n)
        {
            ret_lines->insert(n);//如果不在result当中，添加这一行
        }
        else if(beg != end)
        {
            ++beg;  //否则继续获取result的下一行（如果有的话）
        }
    }
     return QueryResult(rep(),ret_lines,left.get_file());
}
#endif