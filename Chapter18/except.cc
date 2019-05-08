#include <iostream>
#include <stdexcept>

using namespace std;

//noexcept 承诺不抛出异常，出现在该函数的所有声明语句和定义
//因为无法确定是否可以被处理，系统的做法是终止程序
int func() noexcept(true)
{
    range_error r("error");

    throw r;

    return 0;
}

int main()
{
	try{
		func();

	}catch(const range_error& e){
		cout<<e.what()<<endl;
	}catch(...){
		//匹配所有类型并重新抛出供上级再次捕捉
		//重新抛出
		throw;
	}
}
