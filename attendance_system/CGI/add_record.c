#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include<time.h>

MYSQL *conn_ptr;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;
typedef struct form_variable_st
{
	char name[250];//表单域
	char value[250];//表单值
}FORM_VAR;

//获取系统当前时间
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

//连接数据库
int db_conntection()       
{    
    conn_ptr=mysql_init(NULL);
    if(!conn_ptr)
    {
        fprintf(stderr,"mysql_init failed!\n");
        return -1;
    }
    conn_ptr=mysql_real_connect(conn_ptr,"localhost","root","7758991","staff",0,NULL,0);
    if(conn_ptr) 
    {  
        printf("Connection succeed!\n");
    }
    else
    {
        printf("Connection failed!\n");
        return -2;
    }
    return 1;
}


//关闭数据库
void db_close()		
{
    mysql_close(conn_ptr);
}

//添加刷卡记录
int addWorkinfo(char* cardID,char* time,char* photo)
{
    int res;
    char str[200];
    sprintf(str,"insert into workinfo values('%s','%s','%s')",cardID,time,photo);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
		printf("insert succeed!\n");
    }
    else 
    { 
		printf("insert failed!\n");
		return -1;
    }
    return 1;
}




/*
还原空格字符，由于在提交信息中，
用+代替了空格，故要想获取原字符串，
必须再替换回来
*/
void makespace(char *src)
{
	int i,len;
	len=strlen(src);
	for(i=0;i<len;i++)
	{
		if(src[i]=='+') src[i]=' ';
	}
}
/*
分离（表单域=表单值）对；
src为提交数据，格式为：
表单域1=表单值1&表单域2=表单值2&……&表单域n=表单值n
（1）分离表单域与表单值（用＝连接），stop为=
（2）分离值对（用&连接），stop为&
分离出的字符串放在data
完成分离后src去掉分离出的字符串和（=或&）
*/
void split(char *src,char stop, char *data)
{
	char *tmp;
	int i,len,j;
	len=strlen(src);
	tmp=src;
	for(i=0;i<len;i++)
	{
		if(src[i] != stop)
		{ data[i]=src[i];}	
		else
		{ i+=1; break;}
	}
	data[i]='\0';
	for(j=i;j<len;j++) 
        {src[j-i]=tmp[j];}
	src[len-i]='\0';
}
//将字符转为十六进制码（将“0-F”转为0-16）
int hexa(char c)
{
	switch(c)
	{
		case '0':return 0;
		case '1':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
		case 'A':return 10;
		case 'B':return 11;
		case 'C':return 12;
		case 'D':return 13;
		case 'E':return 14;
		case 'F':return 15;
	}
	return 0;
}
/*
由于在提交的信息中，任何特殊字符
用％接相应的十六进制ASCII码代替（%HH格式）；
需要进行还原
*/
void convert(char *src)
{
	int x,y,len;
	char *tmp;
	len=strlen(src);
	tmp=(char *)malloc(sizeof(char)*(len+1));
	y=0;
	for(x=0;x<len;x++)
	{
		if(src[x] != '%')
		{
			tmp[y]=src[x]; y++;
		}
		else
		{
			tmp[y]=(char)(16*hexa(src[x+1])+hexa(src[x+2]));
			y++; x=x+2;
		}
	}
	tmp[y]='\0';
	memset(src, 0, len);
	strcpy(src, tmp);
	free(tmp);
}
/*
解析提交的数据
返回（表单域=表单值）对的个数
*/
int get_input(FORM_VAR *nv)
{
	char *method;
	char *form_data=0;
	char *form_data_ptr;
	char tmp[250];
	int data_len,i;
	//读取环境变量”REQUEST_METHOD”，
        //获取提交数据的方式。
	method=getenv("REQUEST_METHOD");
	/*以GET方式传数据*/
	if(strcmp(method,"GET")==0)
	{
		//从环境变量UERY_STRING 中取出提交数据
		char *data_ptr=getenv("QUERY_STRING");
		data_len=strlen(data_ptr);
		form_data=(char*)malloc(sizeof(char)*(data_len+1));
		strcpy(form_data,data_ptr);
		form_data[data_len]='\0';
	}
	/*以POST方法传数据*/
	else if(strcmp(method,"POST")==0)
	{
		//从标准输入输出中读取相应的字符串，
		//读取长度有环境变量CONTENT_LENGTH 决定
		data_len=atoi(getenv("CONTENT_LENGTH"));
		form_data=(char*)malloc(sizeof(char)*(data_len+1));
		fread(form_data,1,data_len,stdin);
	}

	i=0;
	form_data_ptr=form_data;
	//分离出表单域和值
	while(form_data_ptr[0] != '\0')
	{
		//分理处表单域
		memset(tmp, 0, 250);		
		split(form_data_ptr,'=',tmp);
		makespace(tmp);
		convert(tmp);
		strcpy(nv[i].name,tmp);
		//分离出值
		split(form_data_ptr,'&',tmp);
		makespace(tmp);
		convert(tmp);
		strcpy(nv[i].value,tmp);
		i++;
	}
	free(form_data);
	return i--;
}

int main(void)
{
	char *cardID=NULL;
	char *time=NULL;
	char *photo=NULL;
	FORM_VAR nv[2];
        //表示返回的数据为html
	printf("Content-type: text/html; charset=utf-8\n\n");
	printf("<html>\n");
	printf("<head><title>test form response</title></head>\n");
	printf("<body>\n");
	//获取提交的数据
	if(! get_input(nv)) 
	{
		printf("no data!");
		exit(0);
	}
	cardID = &nv[0].value;
	photo = &nv[1].value;
	time=mygettime();	
    printf("%s,%s,%s\n",cardID,time,photo);
	if(db_conntection())
	{	
		if(addWorkinfo(cardID,time,photo))
			printf("1");
		db_close(); 
	}
	else 
	{
		printf("Connection failed!\n");
	}
 	printf("</body>\n");
	printf("</html>\n");
	exit(0);
}

