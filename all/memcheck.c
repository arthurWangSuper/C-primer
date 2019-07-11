#include <stdlib.h>  
#include <malloc.h>  
#include <string.h>  

//需要注意的是memcpyd的最后一个参数 size
//因为memcpy函数中是用char进行处理的，因此需要计算size大小


void *my_memset(void *dst, int val,size_t size){
	if(dst == NULL){
		return (void*)0;
	}

	char *ptr = (char *)dst;
	
	while(size--){
		*ptr++ = val;
	}
	
	return dst;

}

void *my_memcpy(void *dst,void *src,int size){
	
	char *psrc = (char*)src;
	char *pdst = (char*)dst;

	//输入检查
	if( src == NULL || dst == NULL){
		return (void *)0;
	}

	//重叠性检查
	if(src<dst && src+size>dst){
			while(size--){
				*(pdst+size) = *(psrc+size);
			}
	}
	else
	{
		while(size--){
			*(pdst++)=*(psrc++);
			printf(" %d %d \n",*pdst,*psrc);
		}
	}
	return dst;

}
void test() 
{ 
	int i,j;
	char *ptr1 =(char*)malloc(sizeof(int)*10);
    char *ptr2 = (char*)malloc(sizeof(int)*10);
	
	int ptr[10] = {11,22,33,44,55,66,77,88,99,100};
	
	my_memset(ptr2,15,10*sizeof(ptr2[0]));
	//int arr[10]={5,6,7,8,9,0,1,2,3,4};	
	for(i =0;i<10;i++){
		ptr1[i] = i+1; // 内存越界
	}  
	my_memcpy(ptr+2, ptr,4*sizeof(int)); // 踩内存  
	printf("========\r\n");
	for(j=0;j<10;j++){
		printf(" %d\n",ptr2[j]);
	}
	free(ptr1);
   	free(ptr2);	
	//free(ptr);// 重复释放  
	//int *p1; 
	//*p1 = 1; // 非法指针  
} 

int main(void) 
{ 
	test(); 
	return 0; 
} 
