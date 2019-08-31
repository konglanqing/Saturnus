//my_strcat.c


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* my_strcat(char *des,char *src)
{
	assert(des!=NULL && src!=NULL);
	char *tem = des;
	while(*des != '\0')
	    des++;
	while((*des++ = *src++)!= 0);
	
	return tem;
}

int main ()
{
	char str1[10] = "hello , ";
	char *str2 = "mygrilfriend";
	printf("str1:%s \n",str1);
	printf("str2:%s \n",str2);
	printf("strcat:%s \n",my_strcat(str1,str2));
	return 0;
}
