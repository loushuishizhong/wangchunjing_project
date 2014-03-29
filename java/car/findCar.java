import java.awt.*;
import java.sql.*;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.table.DefaultTableModel;
class findCar extends JInternalFrame implements ActionListener{
	
	ResultSet rs1;
    DBTools db=new DBTools();
    static Connection con = null;
    
    JTable car=new JTable();//创建一个空白的JTable
    JScrollPane jd=new JScrollPane();
    JButton b0=new JButton("上一页");
    JButton b1=new JButton("下一页");
    JButton b2=new JButton("全部");
    JButton b3=new JButton("查询");
    JButton b7=new JButton("退出");
    JButton b8=new JButton("重置");
    JButton b9=new JButton("返回");
        
    JLabel l0=new JLabel("车主信息");
    JLabel l1=new JLabel("姓名");
	JLabel l2=new JLabel("性别");
	JLabel l3=new JLabel("年龄");
	JLabel l4=new JLabel("身份证号");
	JLabel l5=new JLabel("住址");
	JLabel l6=new JLabel("联系方式");
	JLabel l7=new JLabel("车辆信息");
	JLabel l8=new JLabel("车牌号");
	JLabel l9=new JLabel("颜色");
	JLabel l10=new JLabel("类型");
	JLabel l11=new JLabel("品牌");

	
	JTextField jTextField1=new JTextField(8);
	String sex[]={" ","男","女"};
    JComboBox jcbsex=new JComboBox(sex);
    JTextField jTextField3=new JTextField(2);
    JTextField jTextField4=new JTextField(12);
    JTextField jTextField5=new JTextField(8);
    JTextField jTextField6=new JTextField(8);
    JTextField jTextField7=new JTextField(6);
	JTextField jTextField8=new JTextField(6);
	String type[]={" ","轿车","货车","客车","出租车","公交车"};
    JComboBox jcbtype=new JComboBox(type);
    JTextField jTextField10=new JTextField(8);
	
    Container contentpane=getContentPane();
    JPanel p0=new JPanel();
    JPanel p1=new JPanel();
    JPanel p2=new JPanel();
    JPanel p3=new JPanel();
    JPanel p4=new JPanel();
    JPanel p5=new JPanel();
    JPanel p6=new JPanel();
    JPanel p7=new JPanel();
    JPanel p8=new JPanel();
    JPanel p9=new JPanel();
    
	String sql="select * from carinfo";
    static int num=0;
    findCar()throws Exception{
        //super("员工信息");
        bind();//数据邦定
       
        
       
        car.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//设置JTable是否可以自动调整大小
        
        contentpane.setLayout(new GridLayout(4,1));
        
        jd.setPreferredSize(new Dimension(750,200));
        jd.setViewportView(car);
        p0.add(jd);//将JTable添加到滚动面板中
    	p1.add(b0);   	
    	p1.add(b1);
    	b0.addActionListener(this);
        b1.addActionListener(this);
        p7.add(p1);
        
        
        p2.add(l0);       
        p3.add(l1);
    	p3.add(jTextField1);
    	p3.add(l2);
    	p3.add(jcbsex);
    	jcbsex.setEditable(true);//设置jcbsex可以编辑
    	jcbsex.setPreferredSize(new Dimension(40,20));
    	
    	p3.add(l3);
    	p3.add(jTextField3);
    	p3.add(l4);
    	p3.add(jTextField4);
    	
    	p3.add(l5);
    	p3.add(jTextField5);
    	p3.add(l6);
    	p3.add(jTextField6);
    	
    	
    	p4.add(l7);   	
    	p5.add(l8);
    	p5.add(jTextField7);
    	p5.add(l9);
    	p5.add(jTextField8);
    	
    	p5.add(l10);
    	p5.add(jcbtype);
    	jcbtype.setEditable(true);
    	jcbtype.setPreferredSize(new Dimension(60, 20));
    	p5.add(l11);
    	p5.add(jTextField10);
    	
    	//p5.add(l12);
    	//p5.add(jTextField11);
    	p8.add(p2);
    	p8.add(p3);
    	p8.add(p4);
    	p8.add(p5);
    
    	p6.add(b8);
    	b8.addActionListener(this);
    	p6.add(b2);
    	b2.addActionListener(this);
    	p6.add(b3);
    	b3.addActionListener(this);
    	p6.add(b9);
    	b9.addActionListener(this);
    	p6.add(b7);
    	b7.addActionListener(this);
    	
    	p9.add(p6);
    	
    	
    	contentpane.add(p0);
    	contentpane.add(p7);
    	contentpane.add(p8); 	
    	contentpane.add(p9);
    	
    	
    	setTitle("车辆信息查询系统");
    	setSize(800,800);
		setVisible(true);
        
        car.addMouseListener(new MouseAdapter() {//添加单击JTable的事件处理
            public void mouseClicked(MouseEvent evt) 
            {
            	int i,j=0;
            	i=car.rowAtPoint(evt.getPoint());
            	String s[]=new String[10];
            	while(j<10)
            	{
            		s[j]=(String) car.getValueAt(i, j);
            		j++;
            	}
            	jTextField1.setText(s[0]);
            	jcbsex.setSelectedItem(s[1]);
            	jTextField3.setText(s[2]);
            	jTextField4.setText(s[3]);
            	jTextField5.setText(s[4]);
            	jTextField6.setText(s[5]);
            	jTextField7.setText(s[6]);
            	jTextField8.setText(s[7]);
            	jcbtype.setSelectedItem(s[8]);
            	jTextField10.setText(s[9]);
            	//jTextField11.setText(s[10]);
            }
        });
        
    }
    
    String[][] allStudent(int numb)throws Exception
    {	
    	
        rs1=db.getResult(sql);
        String [][]student=new String[10][10];
        int i=0,j=0;
       
        while(rs1.next()){//处理数据
        	if(i>=numb){
        		if(i<numb+10){
                  student[j][0]=rs1.getString(1);
                  student[j][1]=rs1.getString(2);
                  student[j][2]=rs1.getString(3);
                  student[j][3]=rs1.getString(4);
                  student[j][4]=rs1.getString(5);
                  student[j][5]=rs1.getString(6);
                  student[j][6]=rs1.getString(7);
                  student[j][7]=rs1.getString(8);
                  student[j][8]=rs1.getString(9);
                  student[j][9]=rs1.getString(10);
                  //student[j][10]=rs1.getString(11);
                  j++;
                  }
            else{  
            	return student;}
         }
        	i++;
        	}
        	return student;
    	}
    void bind()throws Exception
    	{
    		 String []s={"姓名","性别","年龄","身份证号","住址","联系电话","车牌号","颜色","类型","品牌"};
    	     String [][]stu=allStudent(num);
             DefaultTableModel dtm=new DefaultTableModel(stu,s);//创建TableModel
             car.setModel(dtm);//设置TableModel
    	}
    
    
     
    public void actionPerformed(ActionEvent e)
    {
    	  JButton b=(JButton)e.getSource();
  
      try{
    	  if(b.equals(b0)){//上一页
    		    num=num-10;
    		    bind();
    		}
    	  if(b.equals(b1)){//下一页
    		    num=num+10;
    		    bind();
    		}
    	  if(b.equals(b8))
    	  {
    		  jTextField1.setText("");        
              jTextField3.setText("");
              jTextField4.setText("");
              jTextField5.setText("");
              jTextField6.setText("");
              jTextField7.setText("");
              jTextField8.setText("");
              jTextField10.setText("");
              //jTextField11.setText("");
    	  }
    	  if(b.equals(b2))//全部
    	  {
    		    sql="select * from carinfo";
  		    	bind();
  		  }
    	  if(b.equals(b3))//查询
    	  {
    		  if(!findInfo1())
    		  {
    			  JOptionPane.showMessageDialog(null, "该车辆记录不存在！");
    		  }else 
    		  {
    			  bind(); 
    			  JOptionPane.showMessageDialog(null, "查询成功！");
    		  }
    		 
    	  }
   
    	  if(b.equals(b7))//退出
    	  {
    		  dispose();
    		  System.exit(0);
    	  }
    	  if(b.equals(b9))//返回
    	  {
    		  dispose();
    	  }
    	}
    	catch(Exception ex){}    	
    	}
    boolean findInfo1()
    {
    	ResultSet rs;
    	if(jTextField1.getText().length()==0) jTextField1.setText("%");
    	if(jTextField3.getText().length()==0) jTextField3.setText("%");
    	if(jcbsex.getSelectedItem()==" ")     jcbsex.setSelectedItem("%");
    	if(jTextField4.getText().length()==0) jTextField4.setText("%");
    	if(jTextField5.getText().length()==0) jTextField5.setText("%");
    	if(jTextField6.getText().length()==0) jTextField6.setText("%");
    	if(jTextField7.getText().length()==0) jTextField7.setText("%");
    	if(jTextField8.getText().length()==0) jTextField8.setText("%");
    	if(jcbtype.getSelectedItem()==" ")	  jcbtype.setSelectedItem("%");
    	if(jTextField10.getText().length()==0) jTextField10.setText("%");
    	sql="select * from carinfo where 姓名 like'" +jTextField1.getText()+ "'and 性别 like'" + jcbsex.getSelectedItem() + "'and 年龄 like'" + jTextField3.getText() + "'and 身份证号 like '" + jTextField4.getText() + "'and 住址 like '" + jTextField5.getText() + "'and 联系电话 like '" + jTextField6.getText() + "'and 车牌号 like '" + jTextField7.getText() + "'and 颜色 like '" + jTextField8.getText() + "'and 类型 like '" + jcbtype.getSelectedItem() + "'and 品牌 like '" + jTextField10.getText() + "' ";
    	rs=db.getResult(sql);
    	try {
			if(rs.next())
			{			
								
				return true;
			}
		} catch (HeadlessException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
    }
    
   /* boolean findInfo2()
    {	 	
    	String sql="select * from carinfo";
    	ResultSet rs;
    	rs=db.getResult(sql);
    	try {
			if(!rs.next())
			{			
				return false;
			}else{				
				return true;
			}
		} catch (HeadlessException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
    }*/
}
