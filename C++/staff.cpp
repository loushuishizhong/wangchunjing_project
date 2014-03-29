#include<iostream>
#include<string>
#include<fstream>
using namespace std;



class time
{
public:
	int year;
	int month;
	int day;
	void set1()
	{
		cout<<"工作时间:"<<endl;
		cin>>year>>month>>day;
		if(month<1||month>12)
		{
			cout<<"日期输入错误！"<<endl<<"请重新输入:"<<endl;
			set1();
		}
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
            if(day<1||day>31)
			{
				cout<<"日期输入错误！"<<endl<<"请重新输入:"<<endl;
				set1();
			}
		}
		if(month==4||month==6||month==9||month==11)
		{
            if(day<1||day>30)
			{
				cout<<"日期输入错误！"<<endl<<"请重新输入:"<<endl;
				set1();
			}
		}
		if(year%4==0&&year%100!=0||year%400==0)
        {
		    if(month==2)
			{
			    if(day<1||day>29)
				{
					cout<<"日期输入错误！"<<endl<<"请重新输入:"<<endl;
					set1();
				}
			}
		}
		   else if(month==2)
		   {
			   if(day<1||day>28)
			   {
				   cout<<"日期输入错误！"<<endl<<"请重新输入:"<<endl;
				   set1();
			   }
		   }
	}
	void display1()
	{
		 cout<<"工作时间:"<<year<<" "<<month<<" "<<day;
	}
};


class workers:public time                                       //员工类
{
public:
	string num;
	string name;
	string sex;
	int age;
	string group;
	string job;
	string telephone;
    int person;
	int award;
    int lost;
	int pay;
	virtual void set()
	{
        cout<<"输入基本信息:"<<endl;
		cout<<"编号,姓名:"<<endl;
		cin>>num>>name;
		cout<<"性别:(nan/nv):";
		cin>>sex;
		if(sex!="nan"&&sex!="nv")
		{
			cout<<"性别输入错误!"<<endl<<"请重新输入性别:";
			cin>>sex;
		}
		cout<<"年龄:";
		cin>>age;
		if(age<0||age>100)
		{cout<<"年龄错误!"<<endl<<"请重新输入年龄:";
		cin>>age;}
		cout<<"部门:";
		cin>>group;
		set1();
		cout<<"职务,联系方式:"<<endl;
		cin>>job>>telephone;
		cout<<"奖金,扣发工资,基本工资:"<<endl;
	    cin>>award>>lost>>pay;
		if(pay<0)
		{cout<<"基本工资不能小于0!"<<endl<<"请重新输入:";
		cin>>pay;}
	}
    virtual int money()
	{
		return (pay+award-lost);
	}
    virtual void display()
	{		
		cout<<endl<<"输出基本信息:"<<endl;
		cout<<"编号:"<<num<<" 姓名:"<<name<<" 性别:"<<sex<<" 年龄:"<<age<<" 部门:"<<group;
		display1();
		cout<<" 职务:"<<job<<" 联系方式:"<<telephone<<endl;
		cout<<"奖金:"<<award<<"扣发工资:"<<lost<<"基本工资:"<<pay;
		cout<<"实发工资:"<<money()<<endl;
	}
};



class manager:virtual public workers                            // 经理类
{
public:
	int jibie;
	int jintie;

	virtual void set()
	{
		workers::set();
		cout<<"级别和职务津贴:"<<endl;
		cin>>jibie>>jintie;
	}
	virtual int money()
	{return (pay+award-lost+jintie);}
	virtual void display()
	{
		workers::display();
		cout<<"级别:"<<jibie<<"职务津贴:"<<jintie<<endl;
	}
};

class saler:virtual public workers                              //销售人员类
{
public:
	int sale;
	double precent;
    virtual void set()
	{
		workers::set();
		cout<<"销售额:"<<endl;
		cin>>sale;
	}
	
		
	virtual int money()
	{
	    if(sale>=50000) precent=0.1;
		else if(sale<50000&&sale>=20000) precent=0.07;
		else if(sale<20000&&sale>=5000) precent=0.05;
		else precent=0.03;
	
		return (pay+award-lost+sale*precent);
	}
	virtual void display()
	{
		workers::display();
		cout<<"销售额:"<<sale<<"提成比例:"<<precent<<endl;
	}
};


class technology:virtual public workers                         //技术人员类
{
public:
	int worktime;
	int per;
	virtual void set()
	{
		workers::set();
		cout<<"工作时数:"<<endl;
		cin>>worktime;
	}
    virtual int money()
	{
		if(worktime>=200) per=10;
		else if(worktime<200&&worktime>=15) per=7;
		else if(worktime<150&&worktime>=100) per=5;
		else per=3;
		return (pay+award-lost+worktime*per);
	}
    virtual void display()
	{
		workers::display();
		cout<<"工作时数:"<<worktime<<"每小时金额:"<<per<<endl;
	}
};



class salemanage:virtual public saler,virtual public manager                   //销售经理类
{
public:
	 virtual void set()
	{
		 manager::set();
		cout<<"销售额:"<<endl;
		cin>>sale;
	}
	virtual int money()
	{
		if(sale>=50000) precent=0.1;
		else if(sale<50000&&sale>=20000) precent=0.07;
		else if(sale<20000&&sale>=5000) precent=0.05;
		else precent=0.03;
		return (pay+award-lost+sale*precent+jintie);
	}
	virtual void display()
	{
		manager::display();
		cout<<"销售额:"<<sale<<"提成比例:"<<precent<<endl;
	}
};



class techmanage:virtual public manager,virtual public technology               //技术总监类
{
public:
	virtual void set()
	{
		manager::set();
		cout<<"工作时数:"<<endl;
		cin>>worktime;
	}
   virtual int money()
	{
		if(worktime>=200) per=10;
		else if(worktime<200&&worktime>=15) per=7;
		else if(worktime<150&&worktime>=100) per=5;
		else per=3;
		return (pay+award-lost+worktime*per+jintie);
	}
	virtual void display()
	{
		manager::display();
	}
};




class manage                                                    //管理类
{
public:
	int j,aa,bb,cc,dd,j1,j2,j3,j4,nn;
	workers w;
	saler *p,p1,p2[100],p3[100],p4;
	technology *q,q1,q2[100],q3[100],q4;
	techmanage *t,t1,t2[100],t3[100],t4;
	salemanage *s,s1,s2[100],s3[100],s4;
	void open1()                                                 //打开文件
	{
		int x=-1,o=-1,u=-1,g=-1;
		ifstream infile1("E://t1.txt");
	    if(!infile1)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	   do
		{
			x++;
			infile1>>s3[x].salemanage::num;
			infile1>>s3[x].salemanage::name;
			infile1>>s3[x].salemanage::sex;
			infile1>>s3[x].salemanage::age;
			infile1>>s3[x].salemanage::group;
			infile1>>s3[x].salemanage::year;
			infile1>>s3[x].salemanage::month;
			infile1>>s3[x].salemanage::day;
			infile1>>s3[x].salemanage::job;
			infile1>>s3[x].salemanage::telephone;
			infile1>>s3[x].salemanage::award;
			infile1>>s3[x].salemanage::lost;
			infile1>>s3[x].salemanage::pay;
			infile1>>s3[x].salemanage::jibie;
			infile1>>s3[x].salemanage::jintie;
			infile1>>s3[x].salemanage::sale;			
		}	
		while(s3[x].salemanage::age>0);		
		infile1.close();
		s=s3;aa=x-1;
	

		ifstream infile2("E://t2.txt");
	    if(!infile2)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	    do	
		{
			o++;
			infile2>>t3[o].techmanage::num;
			infile2>>t3[o].techmanage::name;
			infile2>>t3[o].techmanage::sex;
			infile2>>t3[o].techmanage::age;
			infile2>>t3[o].techmanage::group;
			infile2>>t3[o].techmanage::year;
			infile2>>t3[o].techmanage::month;
			infile2>>t3[o].techmanage::day;
			infile2>>t3[o].techmanage::job;
			infile2>>t3[o].techmanage::telephone;
			infile2>>t3[o].techmanage::award;
			infile2>>t3[o].techmanage::lost;
			infile2>>t3[o].techmanage::pay;
			infile2>>t3[o].techmanage::jibie;
			infile2>>t3[o].techmanage::jintie;
			infile2>>t3[o].techmanage::worktime;
			
		}
		while(t3[o].techmanage::age>0);	
		infile2.close();
		t=t3;bb=o-1;
	

		ifstream infile3("E://t3.txt");
	    if(!infile3)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	   do
		{
			u++;
			infile3>>p3[u].saler::num;
			infile3>>p3[u].saler::name;
			infile3>>p3[u].saler::sex;
			infile3>>p3[u].saler::age;
			infile3>>p3[u].saler::group;
			infile3>>p3[u].saler::year;
			infile3>>p3[u].saler::month;
			infile3>>p3[u].saler::day;
			infile3>>p3[u].saler::job;
			infile3>>p3[u].saler::telephone;
			infile3>>p3[u].saler::award;
			infile3>>p3[u].saler::lost;
			infile3>>p3[u].saler::pay;
			infile3>>p3[u].saler::sale;			
		}	
		while(p3[u].saler::age>0);
		infile3.close();
		p=p3;cc=u-1;
	

		ifstream infile4("E://t4.txt");
	    if(!infile4)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	    do
		{
			g++;
			infile4>>q3[g].technology::num;
			infile4>>q3[g].technology::name;
			infile4>>q3[g].technology::sex;
			infile4>>q3[g].technology::age;
			infile4>>q3[g].technology::group;
			infile4>>q3[g].technology::year;
			infile4>>q3[g].technology::month;
			infile4>>q3[g].technology::day;
			infile4>>q3[g].technology::job;
			infile4>>q3[g].technology::telephone;
			infile4>>q3[g].technology::award;
			infile4>>q3[g].technology::lost;
			infile4>>q3[g].technology::pay;
			infile4>>q3[g].technology::worktime;		
		}		
		while(q3[g].technology::age>0);
		infile4.close();
		q=q3;dd=g-1;
	}

	void close1()                                                //关闭文件
	{
		int x=0,o=0,u=0,g=0;
		ofstream outfile1("E://t1.txt");
	    if(!outfile1)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
		while(s3[x].salemanage::age>0)
		{
			outfile1<<s3[x].salemanage::num<<endl;
			outfile1<<s3[x].salemanage::name<<endl;
			outfile1<<s3[x].salemanage::sex<<endl;
			outfile1<<s3[x].salemanage::age<<endl;
			outfile1<<s3[x].salemanage::group<<endl;
			outfile1<<s3[x].salemanage::year<<endl;
			outfile1<<s3[x].salemanage::month<<endl;
			outfile1<<s3[x].salemanage::day<<endl;
			outfile1<<s3[x].salemanage::job<<endl;
			outfile1<<s3[x].salemanage::telephone<<endl;
			outfile1<<s3[x].salemanage::award<<endl;
			outfile1<<s3[x].salemanage::lost<<endl;
			outfile1<<s3[x].salemanage::pay<<endl;
			outfile1<<s3[x].salemanage::jibie<<endl;
			outfile1<<s3[x].salemanage::jintie<<endl;
			outfile1<<s3[x].salemanage::sale<<endl;
			x++;
		}
	    outfile1.close();
	    ofstream outfile2("E://t2.txt");
	    if(!outfile2)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	    	while(t3[o].techmanage::age>0)
		{
			outfile2<<t3[o].techmanage::num<<endl;
			outfile2<<t3[o].techmanage::name<<endl;
			outfile2<<t3[o].techmanage::sex<<endl;
			outfile2<<t3[o].techmanage::age<<endl;
			outfile2<<t3[o].techmanage::group<<endl;
			outfile2<<t3[o].techmanage::year<<endl;
			outfile2<<t3[o].techmanage::month<<endl;
			outfile2<<t3[o].techmanage::day<<endl;
			outfile2<<t3[o].techmanage::job<<endl;
			outfile2<<t3[o].techmanage::telephone<<endl;
			outfile2<<t3[o].techmanage::award<<endl;
			outfile2<<t3[o].techmanage::lost<<endl;
			outfile2<<t3[o].techmanage::pay<<endl;
			outfile2<<t3[o].techmanage::jibie<<endl;
			outfile2<<t3[o].techmanage::jintie<<endl;
			outfile2<<t3[o].techmanage::worktime<<endl;
			o++;
		}		
	    outfile2.close();
		ofstream outfile3("E://t3.txt");
	    if(!outfile3)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
	    while(p3[u].saler::age>0)
		{
			outfile3<<p3[u].saler::num<<endl;
			outfile3<<p3[u].saler::name<<endl;
			outfile3<<p3[u].saler::sex<<endl;
			outfile3<<p3[u].saler::age<<endl;
			outfile3<<p3[u].saler::group<<endl;
			outfile3<<p3[u].saler::year<<endl;
			outfile3<<p3[u].saler::month<<endl;
			outfile3<<p3[u].saler::day<<endl;
			outfile3<<p3[u].saler::job<<endl;
			outfile3<<p3[u].saler::telephone<<endl;
			outfile3<<p3[u].saler::award<<endl;
			outfile3<<p3[u].saler::lost<<endl;
			outfile3<<p3[u].saler::pay<<endl;
			outfile3<<p3[u].saler::sale<<endl;
			u++;
		}		
	    outfile3.close();
		ofstream outfile4("E://t4.txt");
	    if(!outfile4)
		{
			cerr<<"open error!"<<endl;
	        abort();
		}
		while(q3[g].technology::age>0)
		{
			outfile4<<q3[g].technology::num<<endl;
			outfile4<<q3[g].technology::name<<endl;
			outfile4<<q3[g].technology::sex<<endl;
			outfile4<<q3[g].technology::age<<endl;
			outfile4<<q3[g].technology::group<<endl;
			outfile4<<q3[g].technology::year<<endl;
			outfile4<<q3[g].technology::month<<endl;
			outfile4<<q3[g].technology::day<<endl;
			outfile4<<q3[g].technology::job<<endl;
			outfile4<<q3[g].technology::telephone<<endl;
			outfile4<<q3[g].technology::award<<endl;
			outfile4<<q3[g].technology::lost<<endl;
			outfile4<<q3[g].technology::pay<<endl;
			outfile4<<q3[g].technology::worktime<<endl;
			g++;
		}		
	    outfile4.close(); 
	}

	void count()                                                //计数函数
	{
		open1();
	    j1=0,j2=0,j3=0,j4=0;
		while(s->salemanage::age>0)
		{
			j1++;
			s++;
		}
		while(t->techmanage::age>0)
		{
			j2++;
			t++;
		}
		while(p->saler::age>0)
		{
			j3++;
			p++;
		}
		while(q->technology::age>0)
		{
			j4++;
			q++;
		}
		close1();
		
	}


	void look()                                                 //查询函数
	{
		int i;
		int m=0;
		nn=0;
		string b;
	    open1();	
		for(i=0;i<47;i++)  cout<<"*";cout<<endl;
		cout<<"*                   查询信息                  *"<<endl;
    	cout<<"*     1.按编号查询        2.按姓名查询        *"<<endl;
    	cout<<"*     3.按部门查询        4.按职务查询        *"<<endl;
		cout<<"*                 5.退出                      *"<<endl;
		for(i=0;i<47;i++) cout<<"*";cout<<endl;
		cout<<"              请输入相应编号:";
		cin>>nn;
		if(nn==1)
		{
			cout<<"请输入要查询的编号:";
			cin>>b; 
			
		while(s->salemanage::age>0)
			{
			if(s->salemanage::num==b) 
			{s->salemanage::display();j=m;break;}
			s++;m++;
			}
		while(t->techmanage::age>0)
			{
			if(t->techmanage::num==b)
			{t->techmanage::display();j=m-1;break;}
			t++;m++;
			}
		while(p->saler::age>0)
			{
			if(p->saler::num==b)
			{p->saler::display();j=m-2;break;}
			p++;m++;
			}
		while(q->technology::age>0)
			{
			if(q->technology::num==b)
			{q->technology::display();j=m-3;break;}
            q++;m++;
			}
		 if(s->salemanage::num!=b&&t->techmanage::num!=b&&p->saler::num!=b&&q->technology::num!=b)
		 {
			cout<<"没有这名员工!"<<endl;
		 }
		}
		 else if(nn==2)
		 {
			cout<<"请输入要查询的姓名:";
			cin>>b; 
			while(s->salemanage::age>0)
			{
				if(s->salemanage::name==b) 
				{s->salemanage::display();j=m;break;}
				s++;m++;
			}
			while(t->techmanage::age>0)
			{
			    if(t->techmanage::name==b)
				{t->techmanage::display();j=m;break;}
			    t++;m++;
			}
		    while(p->saler::age>0)
			{
			    if(p->saler::name==b)
				{p->saler::display();j=m;break;}
			    p++;m++;
			}
		    while(q->technology::age>0)
			{
			     if(q->technology::name==b)
				 {q->technology::display();j=m;break;}
                 q++;m++;
			}	 
		    if(s->salemanage::name!=b&&t->techmanage::name!=b&&p->saler::name!=b&&q->technology::name!=b)
				cout<<"没有这名员工!"<<endl;
		 }
		 else if(nn==3)
		 {
			cout<<"请输入要查询的部门:";
			cin>>b; 
			while(s->salemanage::age>0)
			{
				if(s->salemanage::group==b) 
				{s->salemanage::display();j=m;break;}
				s++;m++;
			}
			while(t->techmanage::age>0)
			{
			    if(t->techmanage::group==b)
				{t->techmanage::display();j=m;break;}
			     t++;m++;
			}
		    while(p->saler::age>0)
			{
			    if(p->saler::group==b)
				{p->saler::display();j=m;break;}
			    p++;m++;
			}
		    while(q->technology::age>0)
			{
			    if(q->technology::group==b)
				{q->technology::display();j=m;break;}
                q++;m++;
			}	
			if(s->salemanage::group!=b&&t->techmanage::group!=b&&p->saler::group!=b&&q->technology::group!=b) 
				cout<<"没有这名员工!"<<endl;
		 }		 
		 else if(nn==4)
		 {
			cout<<"请输入要查询的职务:";
			cin>>b; 
			while(s->salemanage::age>0)
			{
				if(s->salemanage::job==b)
				{s->salemanage::display();j=m;break;}
				s++;m++;
			}
			while(t->techmanage::age>0)
			{
			    if(t->techmanage::job==b)
				{t->techmanage::display();j=m;break;}
			     t++;m++;
			}
		    while(p->saler::age>0)
			{
			    if(p->saler::job==b)
				{p->saler::display();j=m;break;}
			    p++;m++;
			}
		    while(q->technology::age>0)
			{
			    if(q->technology::job==b)
				{q->technology::display();j=m;break;}
                q++;m++;
			}			
			if(s->salemanage::job!=b&&t->techmanage::job!=b&&p->saler::job!=b&&q->technology::job!=b)
				cout<<"没有这名员工!"<<endl;
		 }	
		 else if(nn==5) return;
		 close1();
	}


	
	void change()                                               //修改函数
	{
		int i,n,r;
		string a,b;
		for(i=0;i<47;i++) cout<<"*";cout<<endl;
		cout<<"*                                             *"<<endl;
    	cout<<"*     1.修改姓名          2.修改部门          *"<<endl;
    	cout<<"*     3.修改职务          4.修改联系电话      *"<<endl;
	    cout<<"*     5.修改奖金          6.修改扣发工资      *"<<endl;
		cout<<"*     7.修改基本工资      8.返回上级菜单      *"<<endl;
		for(i=0;i<47;i++) cout<<"*";cout<<endl;
		cout<<"                请输入相应编号:";
		cin>>n;
		if(n==8) return;
		cout<<"请查找要修改的人:"<<endl;		
		open1();
		look();
		if(nn==5)return;
		cout<<"确定要修改吗(是:Y/否:N):";
		cin>>b;
		if(b=="N")return;	
	   if(s->salemanage::age>0)
	   {
		if(n==1)
		{
			cout<<"输入新姓名:";
		    cin>>a;
		    s->salemanage::name=a;
			s->salemanage::display();
			s3[i].name=s->name;
		}
		if(n==2)
		{
			cout<<"输入新部门:";
		    cin>>a;
		    s->salemanage::group=a;
			s->salemanage::display();
		}
		if(n==3)
		{
			cout<<"输入新职务:";
		    cin>>a;
		    s->salemanage::job=a;
		    s->salemanage::display();
		}
		if(n==4)
		{
			cout<<"输入新联系电话:";
		    cin>>a;
		    s->salemanage::telephone=a;
			s->salemanage::display();
		}
		if(n==5)
		{
			cout<<"输入新奖金:";
		    cin>>r;
		    s->salemanage::award=r;
		    s->salemanage::display();
		}
		if(n==6)
		{
			cout<<"输入新扣发工资:";
		    cin>>r;
		    s->salemanage::lost=r;
		    s->salemanage::display();
		}
		if(n==7)
		{
			cout<<"输入新基本工资:";
		    cin>>r;
		    s->salemanage::pay=r;
		    s->salemanage::display();
		}
	   }


	   else if(t->techmanage::age>0)
	   {
		if(n==1)
		{
			cout<<"输入新姓名:";
		    cin>>a;
		    t->techmanage::name=a;
		    t->techmanage::display();
		}
		if(n==2)
		{
			cout<<"输入新部门:";
		    cin>>a;
		    t->techmanage::group=a;
			t->techmanage::display();
		}
		if(n==3)
		{
			cout<<"输入新职务:";
		    cin>>a;
		    t->techmanage::job=a;
		    t->techmanage::display();
		}
		if(n==4)
		{
			cout<<"输入新联系电话:";
		    cin>>a;
		    t->techmanage::telephone=a;
			t->techmanage::display();
		}
		if(n==5)
		{
			cout<<"输入新奖金:";
		    cin>>r;
		    t->techmanage::award=r;
		    t->techmanage::display();
		}
		if(n==6)
		{
			cout<<"输入新扣发工资:";
		    cin>>r;
		    t->techmanage::lost=r;
		    t->techmanage::display();
		}
		if(n==7)
		{
			cout<<"输入新基本工资:";
		    cin>>r;
		    t->techmanage::pay=r;
		    t->techmanage::display();
		}
	   }

	   else if(p->saler::age>0)
	   {
		if(n==1)
		{
			cout<<"输入新姓名:";
		    cin>>a;
		    p->saler::name=a;
		    p->saler::display();
		}
		if(n==2)
		{
			cout<<"输入新部门:";
		    cin>>a;
		    p->saler::group=a;
			p->saler::display();
		}
		if(n==3)
		{
			cout<<"输入新职务:";
		    cin>>a;
		    p->saler::job=a;
		    p->saler::display();
		}
		if(n==4)
		{
			cout<<"输入新联系电话:";
		    cin>>a;
		    p->saler::telephone=a;
			p->saler::display();
		}
		if(n==5)
		{
			cout<<"输入新奖金:";
		    cin>>r;
		    p->saler::award=r;
		    p->saler::display();
		}
		if(n==6)
		{
			cout<<"输入新扣发工资:";
		    cin>>r;
		    p->saler::lost=r;
		    p->saler::display();
		}
		if(n==7)
		{
			cout<<"输入新基本工资:";
		    cin>>r;
		    p->saler::pay=r;
		    p->saler::display();
		}
	   }

	   else if(q->technology::age>0)
	   {
		if(n==1)
		{
			cout<<"输入新姓名:";
		    cin>>a;
		    q->technology::name=a;
		    q->technology::display();
		}
		if(n==2)
		{
			cout<<"输入新部门:";
		    cin>>a;
		    q->technology::group=a;
			q->technology::display();
		}
		if(n==3)
		{
			cout<<"输入新职务:";
		    cin>>a;
		    q->technology::job=a;
		    q->technology::display();
		}
		if(n==4)
		{
			cout<<"输入新联系电话:";
		    cin>>a;
		    q->technology::telephone=a;
			q->technology::display();
		}
		if(n==5)
		{
			cout<<"输入新奖金:";
		    cin>>r;
		    q->technology::award=r;
		    q->technology::display();
		}
		if(n==6)
		{
			cout<<"输入新扣发工资:";
		    cin>>r;
		    q->technology::lost=r;
		    q->technology::display();
		}
		if(n==7)
		{
			cout<<"输入新基本工资:";
		    cin>>r;
		    q->technology::pay=r;
		    q->technology::display();
		}
       }
	   close1();	   
	}



    void shanchu()                                              //删除函数
	{
		string b;
		cout<<"请查找要删除的职工信息"<<endl;
		count();
		open1();
		look();
		if(nn==5)return;
		cout<<"确定要删除吗(是:Y/否:N):";
		cin>>b;
		if(b=="N")return;
		if(s->salemanage::age>0)
		{  
			for(int i=0,k=0;k<j;i++,k++)
				s3[k]=s3[i];
			for(i=j,k=j;k<j1;k++,i++)
				s3[k]=s3[i+1];
			close1();
		} 
		else if(t->techmanage::age>0)
		{   
			for(int i=0,k=0;k<j;i++,k++)
				t3[k]=t3[i];
			for(i=j,k=j;k<j2;k++,i++)
				t3[k]=t3[i+1];
		    close1();
		}
		else if(p->saler::age>0)
		{
			for(int i=0,k=0;k<j;i++,k++)
				p3[k]=p3[i];
			for(i=j,k=j;k<j3;k++,i++)
				p3[k]=p3[i+1];
			close1();
		}
		else if(q->technology::age>0)
		{
			for(int i=0,k=0;k<j;i++,k++)
				q3[k]=q3[i];
			for(i=j,k=j;k<j4;k++,i++)
				q3[k]=q3[i+1];
			close1();
		}
	}




	void add()                                                  //添加函数
	{
		int i,n; 		
		for(i=0;i<47;i++)  cout<<"*";cout<<endl;
		cout<<"*                   添加类型                  *"<<endl;
    	cout<<"*     1.销售经理          2.技术总监          *"<<endl;
    	cout<<"*     3.销售人员          4.技术人员          *"<<endl;
		cout<<"*                 5.退出                      *"<<endl;
		for(i=0;i<47;i++) cout<<"*";cout<<endl;
		cout<<"              请输入相应编号:";
		cin>>n;
		open1();
		if(n==1)
		{
			s3[aa+1].salemanage::set();
		}
		else if(n==2)
		{
			t3[bb+1].techmanage::set();   
		}
		else if(n==3)
		{
			p3[cc+1].saler::set();
		}
		else if(n==4)
		{
			q3[dd+1].technology::set();
		}
		else if(n==5) return;
		close1();
		cout<<"添加成功!"<<endl;   
	}




	void output()                                               //显示函数 
	{
		open1();
		w.person=0;
		while(s->salemanage::age>0)
		{
			s->salemanage::display();
			s++;
			w.person++;
		}
			   
		while(t->techmanage::age>0)
		{
			t->techmanage::display();
			t++;
			w.person++;
		}
	
		while(p->saler::age>0)
		{
			p->saler::display();
			p++;
            w.person++;
		}
		
		while(q->technology::age>0)
		{
			q->technology::display();
			q++;
			w.person++;
		}
		cout<<"所有员工的人数:"<<w.person<<endl;
		close1();
	} 

	void jisuan()                                               //计算函数
	{
		cout<<"请输入要计算的员工信息:"<<endl;
		open1();
		look();
		cout<<"该员工的工资为:";
		if(s->salemanage::age>0)
			cout<<s->salemanage::money()<<endl;
		else if(t->techmanage::age>0)
			cout<<t->techmanage::money()<<endl;
		else if(p->saler::age>0)
			cout<<p->saler::money()<<endl;
		else if(q->technology::age>0)
			cout<<q->technology::money()<<endl;
		close1();
	}
};



int main()
{
	manage a;
	int i,e;
	while(1)
	{
    for(i=0;i<47;i++)
	cout<<"*";cout<<endl;
	cout<<"*         欢迎使用本职工信息管理系统          *"<<endl;
	cout<<"*     1.修改职工信息      2.查询职工信息      *"<<endl;
	cout<<"*     3.删除职工信息      4.添加职工信息      *"<<endl;
	cout<<"*     5.显示所有职工信息  6.计算员工信息      *"<<endl;
	cout<<"*                 7.退出系统                  *"<<endl;
    for(i=0;i<47;i++)
	cout<<"*";cout<<endl;
	cout<<"               请输入相应编号:";
    cin>>e;
	if(e==1) a.change();
	if(e==2) a.look();
    if(e==3) a.shanchu();
	if(e==4) a.add();
	if(e==5) a.output();
	if(e==6) a.jisuan();
	if(e==7) exit(1); 
	}	
	return 0;
}
