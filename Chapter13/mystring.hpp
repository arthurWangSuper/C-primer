#ifndef _MYSTRING_
#define _MYSTRING_

class mystring{
	friend std::ostream& operator<<(std::ostream& os,const mystring& s);
	
	inline friend mystring operator+(mystring& lhs,mystring& rhs);
	inline friend void swap(mystring&,mystring&);
	public:
		mystring()=default;
		mystring(char*str);
   		mystring(const mystring& s);
		mystring& operator=(mystring& rhs);
		inline size_t size() const {return this->len;};
		inline char* pstr() const {return this->c_str;}; 
		~mystring();

	private:
		static std::allocator<char> alloc;
		char* c_str = nullptr;
		size_t len =0;
};

#endif
