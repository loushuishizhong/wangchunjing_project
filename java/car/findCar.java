import java.awt.*;
import java.sql.*;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.table.DefaultTableModel;
class findCar extends JInternalFrame implements ActionListener{
	
	ResultSet rs1;
    DBTools db=new DBTools();
    static Connection con = null;
    
    JTable car=new JTable();//����һ���հ׵�JTable
    JScrollPane jd=new JScrollPane();
    JButton b0=new JButton("��һҳ");
    JButton b1=new JButton("��һҳ");
    JButton b2=new JButton("ȫ��");
    JButton b3=new JButton("��ѯ");
    JButton b7=new JButton("�˳�");
    JButton b8=new JButton("����");
    JButton b9=new JButton("����");
        
    JLabel l0=new JLabel("������Ϣ");
    JLabel l1=new JLabel("����");
	JLabel l2=new JLabel("�Ա�");
	JLabel l3=new JLabel("����");
	JLabel l4=new JLabel("���֤��");
	JLabel l5=new JLabel("סַ");
	JLabel l6=new JLabel("��ϵ��ʽ");
	JLabel l7=new JLabel("������Ϣ");
	JLabel l8=new JLabel("���ƺ�");
	JLabel l9=new JLabel("��ɫ");
	JLabel l10=new JLabel("����");
	JLabel l11=new JLabel("Ʒ��");

	
	JTextField jTextField1=new JTextField(8);
	String sex[]={" ","��","Ů"};
    JComboBox jcbsex=new JComboBox(sex);
    JTextField jTextField3=new JTextField(2);
    JTextField jTextField4=new JTextField(12);
    JTextField jTextField5=new JTextField(8);
    JTextField jTextField6=new JTextField(8);
    JTextField jTextField7=new JTextField(6);
	JTextField jTextField8=new JTextField(6);
	String type[]={" ","�γ�","����","�ͳ�","���⳵","������"};
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
        //super("Ա����Ϣ");
        bind();//���ݰ
       
        
       
        car.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//����JTable�Ƿ�����Զ�������С
        
        contentpane.setLayout(new GridLayout(4,1));
        
        jd.setPreferredSize(new Dimension(750,200));
        jd.setViewportView(car);
        p0.add(jd);//��JTable��ӵ����������
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
    	jcbsex.setEditable(true);//����jcbsex���Ա༭
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
    	
    	
    	setTitle("������Ϣ��ѯϵͳ");
    	setSize(800,800);
		setVisible(true);
        
        car.addMouseListener(new MouseAdapter() {//��ӵ���JTable���¼�����
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
       
        while(rs1.next()){//��������
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
    		 String []s={"����","�Ա�","����","���֤��","סַ","��ϵ�绰","���ƺ�","��ɫ","����","Ʒ��"};
    	     String [][]stu=allStudent(num);
             DefaultTableModel dtm=new DefaultTableModel(stu,s);//����TableModel
             car.setModel(dtm);//����TableModel
    	}
    
    
     
    public void actionPerformed(ActionEvent e)
    {
    	  JButton b=(JButton)e.getSource();
  
      try{
    	  if(b.equals(b0)){//��һҳ
    		    num=num-10;
    		    bind();
    		}
    	  if(b.equals(b1)){//��һҳ
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
    	  if(b.equals(b2))//ȫ��
    	  {
    		    sql="select * from carinfo";
  		    	bind();
  		  }
    	  if(b.equals(b3))//��ѯ
    	  {
    		  if(!findInfo1())
    		  {
    			  JOptionPane.showMessageDialog(null, "�ó�����¼�����ڣ�");
    		  }else 
    		  {
    			  bind(); 
    			  JOptionPane.showMessageDialog(null, "��ѯ�ɹ���");
    		  }
    		 
    	  }
   
    	  if(b.equals(b7))//�˳�
    	  {
    		  dispose();
    		  System.exit(0);
    	  }
    	  if(b.equals(b9))//����
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
    	sql="select * from carinfo where ���� like'" +jTextField1.getText()+ "'and �Ա� like'" + jcbsex.getSelectedItem() + "'and ���� like'" + jTextField3.getText() + "'and ���֤�� like '" + jTextField4.getText() + "'and סַ like '" + jTextField5.getText() + "'and ��ϵ�绰 like '" + jTextField6.getText() + "'and ���ƺ� like '" + jTextField7.getText() + "'and ��ɫ like '" + jTextField8.getText() + "'and ���� like '" + jcbtype.getSelectedItem() + "'and Ʒ�� like '" + jTextField10.getText() + "' ";
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
