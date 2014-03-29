#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>

MYSQL *conn_ptr;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;

char findstr[200];//cun fang sql yu ju
char a='T';//cao zuo cheng gong fan hui xin xi
char b='F';//cao zuo shi bai fan hui xin xi

/***********************************************
jie gou ti ding yi
***********************************************/

struct struct_bill
{
   char bill_number[32];
   char bill_amount_money[8];
   char bill_datetime[10];
   char staff_number[32];
   char table_number[10];
   char bill_status[10];

};
struct struct_staff
{
	char staff_number[32];
	char staff_name[32];
	
	char staff_sex[1];
	char staff_native[32];
	char staff_address[32];
	char staff_ID_card_Number[32];
	char staff_age[2];
	char staff_level[10];
	char staff_login_pass[32];
};
struct struct_dishes
{
	char dish_number[32]	;
	char dish_name[32];
	char dish_short_name[32];
	char dish_category[1];
	char dish_price[8];
};
struct struct_dished
{
	char dish_number[32];
	char bill_number[32];
	char dished_count[8];
};
struct struct_tableinfo
{
	char table_number[10];
	char table_status[10];
};


/***********************************************
shu ju ku lian jie yu guan bi
***********************************************/

//jian li shu ju ku lian jie
int db_conntection()       
{    
    conn_ptr=mysql_init(NULL);
    if(!conn_ptr)
    {
        fprintf(stderr,"mysql_init failed!\n");
        return -1;
    }
    conn_ptr=mysql_real_connect(conn_ptr,"localhost","root",NULL,"bh1800",0,NULL,0);
    if(conn_ptr) 
    {  
        printf("Connection succeed!\n");
	//base_send(1,&a,1);
    }
    else
    {
        printf("Connection failed!\n");
	//base_send(1,&b,1);
        return -2;
	
    }
    return 0;
}


//guan bi shu ju ku lian jie
void db_close()		
{
    mysql_close(conn_ptr);
}


/***********************************************
cha xun fan hui han shu
***********************************************/
void find_send()
{
    int res;
    char result[70];
    res=mysql_query(conn_ptr,findstr);
    if(res)
    {
	printf("SELECT error:%s\n",mysql_error(conn_ptr));
	return;
    }
    else
    {
	res_ptr=mysql_store_result(conn_ptr);
	if(res_ptr)
	{
	    printf("Receive %lu rows\n",(unsigned long)mysql_num_rows(res_ptr));
	    while((sqlrow=mysql_fetch_row(res_ptr)))
	    {
		bzero(result,70);
		printf("Fetcher data...\n");
		unsigned int field_count;
    		field_count=0;
    		while(field_count<mysql_field_count(conn_ptr))
    		{
			sprintf(result,"%s%s+",result,sqlrow[field_count]);
			printf(" %s",sqlrow[field_count]);
			field_count++;	
    		}
    		printf("\n");
		printf("%s\n",&result);
                //base_send(1,result,strlen(result));
	    }
	    //base_send(1,&a,1);
	    if(mysql_errno(conn_ptr))
	    {
		fprintf(stderr,"Receive error:%s\n",mysql_error(conn_ptr));
		//base_send(1,&b,1);
		return;
	    }
	}
	mysql_free_result(res_ptr);
    }
}


/***********************************************
yuan gong cao zuo
***********************************************/

//tian jia yuan gong
int addStaff(struct struct_staff staff)
{
    int res;
    char str[200];
    sprintf(str,"insert into staff values('%s','%s','%s','%s','%s','%s','%s',' %s','%s')",staff.staff_number,staff.staff_name,staff.staff_sex,staff.staff_native,staff.staff_address,staff.staff_ID_card_Number,staff.staff_level,staff.staff_age,staff.staff_login_pass);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("insert into staff succeed!\n");
  	//base_send(1,&a,1);
    }
    else 
    { 
	printf("insert into staff failed!\n");
	//base_send(1,&b,1); 
	return -1;
    }
    return 0;
}


//shan chu yuan gong
int deleteStaff(struct struct_staff staff)	
{
    int res;
    char str[100];
    sprintf(str,"DELETE FROM staff WHERE staff_number='%s'",staff.staff_number);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("Delete staff succeed!\n");
	//base_send(1,&a,1);
    }
    else 
    { 
	printf("Delete staff failed!\n"); 
	//base_send(1,&b,1);
	return -1;
    }
    return 0;
}


//geng xin yuan gong xin xi
int updateStaff(struct struct_staff staff)
{
    int res;
    char str[200];
    sprintf(str,"update staff set staff_number='%s',staff_name='%s',staff_sex='%s',staff_native='%s',staff_address='%s',staff_ID_card_Number='%s',staff_level='%s',staff_age='%s',staff_login_pass='%s'where staff_number='%s'",staff.staff_number,staff.staff_name,staff.staff_sex,staff.staff_native,staff.staff_address,staff.staff_ID_card_Number,staff.staff_level,staff.staff_age,staff.staff_login_pass,staff.staff_number);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("Update staff succeed!\n"); 
        //base_send(1,&a,1);
    }
    else 
    { 
	printf("Update staff failed!\n"); 
	//base_send(1,&b,1);
        return -1;
    }
    return 0;
}

/***********************************************
tai wei guan li
***********************************************/

//ti wei chu shi hua
int initTables()	
{
    bzero(findstr,200);
    sprintf(findstr,"select table_status from tableinfo");
    find_send();
    bzero(findstr,200);
    return 0;
}

//kai tai && yu ding && qu xiao yu ding
int newTable(struct struct_tableinfo table)	
{
    int res;
    char str[100];
    sprintf(str,"update tableinfo set table_status='%s'where table_number='%s'",table.table_status,table.table_number);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("update tableinfo succeed!\n");
	//base_send(1,&a,1);
    }
    else 
    { 
	printf("update tableinfo failed!\n"); 
	//base_send(1,&b,1);
	return -1;
    }
    return 0;
}


/***********************************************
zhang dan && dian cai xin xi chu li
***********************************************/

//huo qu dian cai xin xi
int getDishedInfo(struct struct_dished dished)
{
    int res;
    char str[200];
    sprintf(str,"insert into dished values('%s','%s','%s')",dished.dish_number,dished.bill_number,dished.dished_count);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("insert into dished succeed!\n");
  	//base_send(1,&a,1);
    }
    else 
    { 
	printf("insert into dished failed!\n"); 
	//base_send(1,&b,1);
	return -1;
    }
    return 0;
}

//huo qu zhang dan xin xi
int getBillInfo(struct struct_bill bill)
{
    int res;
    char str[200];
    sprintf(str,"insert into bill values('%s','%s','%s','%s','%s','%s')",bill.bill_number,bill.bill_amount_money,bill.bill_datetime,bill.staff_number,bill.table_number,bill.bill_status);
    res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("insert into bill succeed!\n");
  	//base_send(1,&a,1);
    }
    else 
    { 
	printf("insert into bill failed!\n"); 
	//base_send(1,&b,1);
	return -1;
    }
    return 0;
}     

//cha kan zhang dan xin xi
void initBills()
{
	int res;
	bzero(findstr,sizeof(findstr));
	
	sprintf(findstr,"select table_number,bill_number,bill_amountMoney,bill_status from bill");
	find_send();
	bzero(findstr,sizeof(findstr));	
}


//cha xun zhang dan xiang xi xin xi
void queryBill(char tablenumber[32])
{
	bzero(findstr,sizeof(findstr));
	sprintf(findstr,"select t1.bill_number,t3.dish_name,dish_price,t2.dished_count from bill t1,dished t2,dishes t3 where t3.dish_number in (select dish_number from dished where t2.bill_number=(select bill_number from bill where table_number='%s' and bill_status='0')) and t1.bill_number=(select bill_number from bill where table_number='%s' and bill_status='0') and t3.dish_number=t2.dish_number group by dish_name;",tablenumber,tablenumber);
	printf("%s\n",findstr);	
	find_send();	
	bzero(findstr,sizeof(findstr));
		
}

//jie zhang
int checkout(char* table_num) 	{
int res;
    char str[100];
    sprintf(str,"update bill set bill_status='1' where table_number='%s'",table_num);
		printf("%s\n",str);
	res=mysql_query(conn_ptr,str);
    if(!res) 
    {
	printf("Update bill succeed!\n"); 
        base_send(1,&a,1);
    }
    else 
    { 
	printf("Update staff failed!\n"); 
 base_send(1,&b,1);
        return -1;
    }
    return 0;
}



/***********************************************
tong bu guan li
***********************************************/

//chu shi hua cai dan
int initDishes() 
{
    bzero(findstr,200);
    sprintf(findstr,"select * from dishes");
    find_send();
    bzero(findstr,200);
    return 0;
}
void initBills()
{
	int res;
	bzero(findstr,sizeof(findstr));
	
	sprintf(findstr,"select table_number,bill_number,bill_amountMoney,bill_status from bill");
	find_send();
	bzero(findstr,sizeof(findstr));	
}


/***********************************************
tong ji guan li
***********************************************/

//tong ji yuan gong chu qin lv
int count_satff(char* startTime,char* endTime)
{
    bzero(findstr,200);
    sprintf(findstr,"select staff_name,count(bill_number) from bill t1,staff t2 where t2.staff_number in (select staff_number from bill where bill_datetime between '%s' and '%s' group by staff_number) and t1.staff_number=t2.staff_number group by t1.staff_number",startTime,endTime);
    find_send();
    bzero(findstr,200);
    return 0;
}


//tong ji cai dai 
int count_dishes(char* startTime,char* endTime)
{
    bzero(findstr,200);
    sprintf(findstr,"select dish_name,sum(dished_count) from dishes t1,dished t2 where t2.dish_number in (select dish_number from dished where bill_number in (select bill_number from bill where bill_datetime between '%s' and '%s')) and t1.dish_number=t2.dish_number group by t2.dish_number",startTime,endTime);
    find_send();
    bzero(findstr,200);
    return 0;
}

//tong ji xiao shou e
/*int count_money()
{
    bzero(findstr,200);
    sprintf(findstr,"select sum(bill_amountMoney) from bill where bill_datetime between '%s' and '%s'",startTime,endTime);
    find_send();
    bzero(findstr,200);
    return 0;
}*/

/***********************************************
cai dan guan li
***********************************************/

//tian jia cai pin
void addDishes(struct struct_dishes dishes)
{
	int res;
	
	char str[100];
	sprintf(str,"insert into dishes values('%s','%s','%s','%s','%s')",dishes.dish_number,dishes.dish_name,dishes.dish_short_name,dishes.dish_price,dishes.dish_category);
	res=mysql_query(conn_ptr,str);
	if(res==0)
	{
	    printf("insert into dishes succeed!\n");
	    //base_send(1,&a,1);
	}
	else	
	{
	    printf("insert into dishes failed!\n");
	    //base_send(1,&b,1);
	}	
	return ;
}




//shan chun cai pin
void deleDishes(char dishesnumber[32])
{
	int res;
	
	char str[200];
	sprintf(str,"delete from dishes where dish_number='%s'",dishesnumber);
	printf("%s\n",str);
	res=mysql_query(conn_ptr,str);
	if(res==0)
	{
	    printf("delete from dishes succeed!\n");
	    //base_send(1,&a,1);
	}
	else	
	{
	    printf("delete from dishes failed!\n");
	    //base_send(1,&b,1);
	}
}

//geng xin cai pin
void changeDishes(struct struct_dishes dishes)
{
	int res;
	
	char str[200];
	sprintf(str,"update dishes set  dish_name='%s',dish_short_name='%s',dish_category='%s',dish_price='%s' where dish_number='%s'",dishes.dish_name,dishes.dish_short_name,dishes.dish_category,dishes.dish_price,dishes.dish_number);
	printf("%s\n",str);
	res=mysql_query(conn_ptr,str);
	if(res==0)
	{
	    printf("update dishes succeed!\n");
	    //base_send(1,&a,1);
	}
	else	
	{
	    printf("update dishes failed!\n");
	    //base_send(1,&b,1);
	}	
}


int main()
{
    return 0;
}

