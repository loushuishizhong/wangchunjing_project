#include <stdio.h>
#include <time.h> 
char *mygettime()
{  
	struct tm *times;   
	static char dates[15];  
	time_t t;  
	t=time(NULL);  
	times=localtime(&t);  
	sprintf(dates,"%04d%02d%02d%02d%02d%02d",times->tm_year+1900,times->tm_mon+1,times->tm_mday,times->tm_hour,times->tm_min,times->tm_sec);  
	return dates;
}   
int main()
{     
	char *t;  
	t=mygettime();  
	printf("%s\n",t);
}
