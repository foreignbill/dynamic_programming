#include <stdio.h>
int main(){
	int a[]={1,2,3,4,5,6,7,8,9,0},*p;
	p = a;
	printf("%x\n",*p);
	printf("%x\n",*(p+9));
}
