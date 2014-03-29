import java.awt.*;
import java.sql.*;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.table.DefaultTableModel;
class check extends JInternalFrame implements ActionListener{
	String sql="select * from car_check";
    JTable car=new JTable();//创建一个空白的JTable
    JButton b0=new JButton("上一页");
    JButton b1=new JButton("下一页");
    JButton b2=new JButton("全部");
    JButton b3=new JButton("查询");
    JButton b4=new JButton("添加");
    JButton b5=new JButton("删除");
    JButton b6=new JButton("修改");  
    JButton b7=new JButton("退出");
    JButton b8=new JButton("返回");
    JButton b9=new JButton("重置");
    
    JLabel l1=new JLabel("             车检号：");//文本框
    JTextField j1=new JTextField(8);
    JLabel l2=new JLabel("                          车牌号：");
    JTextField j2=new JTextField(8);
    JLabel l3=new JLabel("                          车检单位：");//文本框
    JTextField j3=new JTextField(8);
    JLabel l4=new JLabel("             车检人姓名：");//文本框
    JTextField j4=new JTextField(8);
    JLabel l5=new JLabel("                      车检日期：");
    JTextField j5=new JTextField(8);
    JLabel l6=new JLabel("                      车检费用：");
    JTextField j6=new JTextField(8);
    
    JPanel p1=new JPanel();
    JPanel p2=new JPanel();
    JPanel p3=new JPanel();
    JPanel p4=new JPanel();
    static int num=0;
    check()throws Exception{
        super("年检信息");
        bind();//数据邦定
        JScrollPane jd=new JScrollPane();
        jd.setPreferredSize(new Dimension(450,200));
        jd.setViewportView(car);//将JTable添加到滚动面板中
        p2.add(jd);
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        p3.add(b9);
        p1.add(b0);
        p1.add(b1);
        p3.add(b2);
        p3.add(b3);
        p3.add(b4);
        p3.add(b5);
        p3.add(b6);
        p3.add(b8);
        p3.add(b7);
        car.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//设置JTable是否可以自动调整大小
        car.addMouseListener(new MouseAdapter() {//添加单击JTable的事件处理
            public void mouseClicked(MouseEvent evt) 
            {
            	int i,j=0;
            	i=car.rowAtPoint(evt.getPoint());
            	String s[]=new String[6];
            	while(j<6)
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
       
        
        contentpane.add(p4);
        contentpane.add(p3);
        
        setSize(650,600);
        setVisible(true);
    }
    
    String[][] allStudent(int numb)throws Exception
    {	
        DBTools db=new DBTools();
        ResultSet rs=db.getResult(sql);//执行SQL语句
        String [][]student=new String[10][6];
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
    	     String []s={"车检号","车牌号","车检单位","车检人姓名","车检日期","车检费用"};
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
    	  if(b.equals(b9)) //重置
    	  {
    		  j1.setText("");   
    		  j2.setText("");     
              j3.setText("");
              j4.setText("");
              j5.setText("");
              j6.setText("");
    	  }
    	  
    	  if(b.equals(b2))//全部
    	  {
    		    sql="select * from car_check";
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
    		  sql="select * from car_check where 车检号 like '"+j1.getText()+"'and 车牌号 like '"+j2.getText()+"'and 车检单位 like'"+j3.getText()+"'and 车检人姓名 like'"+j4.getText()+"' and 车检日期 like'"+j5.getText()+"' and 车检费用 like'"+j6.getText()+"'";    	
    		  bind(); 
    	  }
    	  if(b.equals(b4))//添加
    	  {   		   
    		    String sq3="insert into car_check values('"+j1.getText()+"' ,'" + j2.getText() + "','" + j3.getText() + "','" + j4.getText() + "','" + j5.getText() + "','"+j6.getText()+"')";
    		    String  sq1 = "select * from car_check where 车检号='" + j1.getText() + "'";
    		    String  sq2 = "select * from car_info where 车牌号='" + j2.getText() + "'";
    		    ResultSet rs1= db.getResult(sq1);
    		    ResultSet rs2= db.getResult(sq2);
    		    if(rs1.next())
    		    {
    		    	JOptionPane.showMessageDialog(null, "已有此编号！");   		    
    		    }else if(!rs2.next())
    		    {
    		    	JOptionPane.showMessageDialog(null, "不存在此车辆！");   		    
    		    }else if(j1.getText().length()==0)
    		    {
    		    	JOptionPane.showMessageDialog(null, "请输入车检号！");
    		    }else if(j2.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "请输入车牌号！");
        		}else if(j3.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "请输入车检单位！");
        		}else if(j4.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "请输入车检人姓名！");
        		}else if(j5.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "请输入车检日期！");
        		}				
    		    else if(db.updateResult(sq3)!=0){
    		    	bind(); 
					JOptionPane.showMessageDialog(null, "添加成功！");
				 }
      			else{
      				JOptionPane.showMessageDialog(null, "添加失败！");
      			}
      			
    	 }	  
    	  if(b.equals(b5))//删除
    	  {
    		  String sq3="delete from car_check where 车检号='"+j1.getText()+"'";
    		  if(db.updateResult(sq3)!=0)
    		  {
    			  bind();
    			  JOptionPane.showMessageDialog(null, "删除成功！");  
    		  }
    		  else JOptionPane.showMessageDialog(null, "删除失败！");
    	  }	  
    	  if(b.equals(b6))//修改
    	  {
    		  String sq3="update car_check set 车检号 ='"+j1.getText()+"', 车牌号 ='"+j2.getText()+"' ,车检单位 ='"+j3.getText()+"' ,车检人姓名 ='"+j4.getText()+"' ,车检日期 ='"+j5.getText()+"',车检费用 ='"+j6.getText()+"' where 车检号='"+j1.getText()+"'";
    		  if(db.updateResult(sq3)!=0)
    		  { 
    			  bind();
    			  JOptionPane.showMessageDialog(null, "修改成功！");
    		  }
    		  else JOptionPane.showMessageDialog(null, "修改失败！");
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
