#include<iostream>
#include<string>

using namespace std;

class Sales_data{

	public:
		Sales_data() = default;
		Sales_data(string Isbn,unsigned units_sold):ISBN(Isbn),units_sold(units_sold){}
		Sales_data& combine(const Sales_data& rhs);
		Sales_data(istream& is);
		static int storebookNo;
		static const int test = 101;
		//static int test = 100; //error: 不支持非const类型的static成员类内初始化		
	private:
		string ISBN;
		unsigned units_sold = 0;
		double revenue =0.0;
};

int Sales_data::storebookNo = 101;

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}


int main(int argc,char*argv[])
{
	Sales_data *book = new Sales_data(string("a new lifestyle"),12);
	cout<<"helloteamate"<<endl;
	cout<<"storeBookStore"<<book->storebookNo<<endl;

	


}


