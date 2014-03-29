import java.awt.*;
import java.sql.*;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.table.DefaultTableModel;
class findError extends JInternalFrame implements ActionListener{
	String sql="select * from carerror";
	ResultSet rs;
    JTable car=new JTable();//创建一个空白的JTable
    JButton b0=new JButton("上一页");
    JButton b1=new JButton("下一页");
    JButton b2=new JButton("全部");
    JButton b3=new JButton("查询");
    JButton b8=new JButton("返回");
    JButton b7=new JButton("退出");
        
    JLabel l1=new JLabel("违章编号：");//文本框
    JTextField j1=new JTextField(8);
    JLabel l2=new JLabel("车牌号：");
    JTextField j2=new JTextField(8);
    JLabel l3=new JLabel("姓名：");//文本框
    JTextField j3=new JTextField(8);
    JLabel l4=new JLabel("身份证号：");//文本框
    JTextField j4=new JTextField(8);
    JLabel l5=new JLabel("联系电话：");
    JTextField j5=new JTextField(8);
    JLabel l6=new JLabel("日期：");
    JTextField j6=new JTextField(8);
    JLabel l7=new JLabel("原因：");//下拉菜单
    String face[]={"酒驾","超速","超载"};
    JComboBox j7=new JComboBox(face);
    JLabel l8=new JLabel("是否处理：");//下拉菜单
    String s[]={"是","否"};
    JComboBox j8=new JComboBox(s);
    JPanel p1=new JPanel();
    JPanel p2=new JPanel();
    JPanel p3=new JPanel();
    JPanel p4=new JPanel();
    static int num=0;
    findError()throws Exception{
        super("违章信息");
        bind();//数据邦定
        JScrollPane jd=new JScrollPane();
        jd.setPreferredSize(new Dimension(600,200));
        jd.setViewportView(car);//将JTable添加到滚动面板中
        p2.add(jd);
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        p1.add(b0);
        p1.add(b1);
        p3.add(b2);
        p3.add(b3);
        p3.add(b8);
        p3.add(b7);
        car.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//设置JTable是否可以自动调整大小
        car.addMouseListener(new MouseAdapter() {//添加单击JTable的事件处理
            public void mouseClicked(MouseEvent evt) 
            {
            	int i,j=0;
            	i=car.rowAtPoint(evt.getPoint());
            	String s[]=new String[8];
            	while(j<8)
            	{
            		s[j]=(String) car.getValueAt(i, j);
            		j++;
            	}
            	j1.setText(s[0]);
            	j2.setText(s[1]);
            	j3.setText(s[2]);
            	j4.setText(s[3]);
            	j5.setText(s[4]);
            	j6.setText(s[5]);
            	j7.setSelectedItem(s[6]);
            	j8.setSelectedItem(s[7]);     
            }
        });
        Container contentpane=getContentPane();
        contentpane.setLayout(new GridLayout(4,1));
        contentpane.add(p2);//将JTable添加到窗体中
        contentpane.add(p1);//将JTable添加到窗体中     
        p4.add(l1);
        p4.add(j1);
        p4.add(l2);
        p4.add(j2);
        
        p4.add(l3);
        p4.add(j3);
        p4.add(l4);
        p4.add(j4);
        p4.add(l5);
        p4.add(j5);
        
        p4.add(l6);
        p4.add(j6);
        p4.add(l7);
        p4.add(j7);
        p4.add(l8);
        p4.add(j8);
        j7.setEditable(true);//设置可以编辑
        j8.setEditable(true);
        j8.setPreferredSize(new Dimension(40,20));
        
        contentpane.add(p4);
        contentpane.add(p3);
        
        /*txtname.setText("%");
        jcbsex.setSelectedItem("%");
		born.setText("%");
		work.setText("%");
		jcbdegree.setSelectedItem("%");
		jcbface.setSelectedItem("%");*/
        
        setSize(650,600);
        setVisible(true);
    }
    
    String[][] allStudent(int numb)throws Exception
    {	
        DBTools db=new DBTools();
        rs=db.getResult(sql);//执行SQL语句
        String [][]student=new String[10][8];
        int i=0,j=0;
        while(rs.next()){//处理数据
        	if(i>=numb){
        		if(i<numb+10){
                  student[j][0]=rs.getString(1);
                  student[j][1]=rs.getString(2);
                  student[j][2]=rs.getString(3);
                  student[j][3]=rs.getString(4);
                  student[j][4]=rs.getString(5);
                  student[j][5]=rs.getString(6);
                  student[j][6]=rs.getString(7);
                  student[j][7]=rs.getString(8);
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
    	     String []s={"违章编号","车牌号","姓名","身份证号","联系电话","日期","原因","是否处理"};
    	     String [][]stu=allStudent(num);
             DefaultTableModel dtm=new DefaultTableModel(stu,s);//创建TableModel
             car.setModel(dtm);//设置TableModel
    	}
    
    
     
    public void actionPerformed(ActionEvent e)
    {
    	  JButton b=(JButton)e.getSource();
    	  DBTools db=new DBTools();
		 
		 
      try{
    	  if(b.equals(b0)){//上一页
    		    num=num-10;
    		    bind();
    		}
    	  if(b.equals(b1)){//下一页
    		    num=num+10;
    		    bind();
    		}
    	  if(b.equals(b2))//全部
    	  {
    		    sql="select * from carerror";
  		    	bind();
  		  }
    	  if(b.equals(b3))//查询
    	  {
    		  if(j1.getText().length()==0) j1.setText("%");
    		  if(j2.getText().length()==0) j2.setText("%");
    		  if(j3.getText().length()==0) j3.setText("%");
    		  if(j4.getText().length()==0) j4.setText("%");
    		  if(j5.getText().length()==0) j5.setText("%");
    		  if(j6.getText().length()==0) j6.setText("%");
    		  if(j7.getSelectedItem()==" ")j7.setSelectedItem("%");
    		  if(j8.getSelectedItem()==" ")j8.setSelectedItem("%");
    		  sql="select * from carerror where 违章编号 like '"+j1.getText()+"'and 车牌号 like '"+j2.getText()+"'and 姓名 like'"+j3.getText()+"'and 身份证号 like'"+j4.getText()+"' and 联系电话 like'"+j5.getText()+"' and 日期 like'"+j6.getText()+"' and 原因 like '"+j7.getSelectedItem()+"' and 是否处理 like '"+j8.getSelectedItem()+"'";    	
    		  bind(); 
    	  }  	 
    	  if(e.getSource()==b7)//退出
    	  {
    		  dispose();
    		  System.exit(0);
    	  }
    	  if(e.getSource()==b8)//返回
    	  {
    		  dispose();
    	  }
    	}
    	catch(Exception ex){}    	
    	}
}
