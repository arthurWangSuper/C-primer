#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;


int main(int argc,char*argv[])
{
    const char *pstrA = "i am ";
    const char *pstrB = "a boy";

    size_t length_A = sizeof(pstrA)/sizeof(char)-1;
    size_t length_B = sizeof(pstrB)/sizeof(char)-1;

    char *strbuf = new char[length_A+length_B+1];

    strcpy(strbuf,pstrA);
    strcat(strbuf,pstrB);
    cout<<strbuf<<endl;


    string StrA("he is not");
    string StrB("she is nnn");

    StrA.append(StrB);
    
    cout<<StrA<<endl;
    /*别忘了释放内存*/
    delete[] strbuf;
    /*=12.24====================================*/
    
    const char* inputbuff = new char[3];
    string inputstr;

    cin>>inputstr;
    
    inputbuff = inputstr.c_str();

    delete[] inputbuff;
     
   // int *p = new int[3]{1,2,3,4,5};
	int *p = new int[3];
	int *p5 = new int[5]{1,2,3,4,5};
	p = p5;

    delete[] p;
    delete[] p5;
    return 0;

 }
