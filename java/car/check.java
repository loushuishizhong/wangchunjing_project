import java.awt.*;
import java.sql.*;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.table.DefaultTableModel;
class check extends JInternalFrame implements ActionListener{
	String sql="select * from car_check";
    JTable car=new JTable();//����һ���հ׵�JTable
    JButton b0=new JButton("��һҳ");
    JButton b1=new JButton("��һҳ");
    JButton b2=new JButton("ȫ��");
    JButton b3=new JButton("��ѯ");
    JButton b4=new JButton("���");
    JButton b5=new JButton("ɾ��");
    JButton b6=new JButton("�޸�");  
    JButton b7=new JButton("�˳�");
    JButton b8=new JButton("����");
    JButton b9=new JButton("����");
    
    JLabel l1=new JLabel("             ����ţ�");//�ı���
    JTextField j1=new JTextField(8);
    JLabel l2=new JLabel("                          ���ƺţ�");
    JTextField j2=new JTextField(8);
    JLabel l3=new JLabel("                          ���쵥λ��");//�ı���
    JTextField j3=new JTextField(8);
    JLabel l4=new JLabel("             ������������");//�ı���
    JTextField j4=new JTextField(8);
    JLabel l5=new JLabel("                      �������ڣ�");
    JTextField j5=new JTextField(8);
    JLabel l6=new JLabel("                      ������ã�");
    JTextField j6=new JTextField(8);
    
    JPanel p1=new JPanel();
    JPanel p2=new JPanel();
    JPanel p3=new JPanel();
    JPanel p4=new JPanel();
    static int num=0;
    check()throws Exception{
        super("�����Ϣ");
        bind();//���ݰ
        JScrollPane jd=new JScrollPane();
        jd.setPreferredSize(new Dimension(450,200));
        jd.setViewportView(car);//��JTable��ӵ����������
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
        car.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//����JTable�Ƿ�����Զ�������С
        car.addMouseListener(new MouseAdapter() {//��ӵ���JTable���¼�����
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
        contentpane.add(p2);//��JTable��ӵ�������
        contentpane.add(p1);//��JTable��ӵ�������     
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
        ResultSet rs=db.getResult(sql);//ִ��SQL���
        String [][]student=new String[10][6];
        int i=0,j=0;
        while(rs.next()){//��������
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
    	     String []s={"�����","���ƺ�","���쵥λ","����������","��������","�������"};
    	     String [][]stu=allStudent(num);
             DefaultTableModel dtm=new DefaultTableModel(stu,s);//����TableModel
             car.setModel(dtm);//����TableModel
    	}
    
    
     
    public void actionPerformed(ActionEvent e)
    {
    	  JButton b=(JButton)e.getSource();
    	  DBTools db=new DBTools();
		 
		 
      try{
    	  if(b.equals(b0)){//��һҳ
    		    num=num-10;
    		    bind();
    		}
    	  if(b.equals(b1)){//��һҳ
    		    num=num+10;
    		    bind();
    		}
    	  if(b.equals(b9)) //����
    	  {
    		  j1.setText("");   
    		  j2.setText("");     
              j3.setText("");
              j4.setText("");
              j5.setText("");
              j6.setText("");
    	  }
    	  
    	  if(b.equals(b2))//ȫ��
    	  {
    		    sql="select * from car_check";
  		    	bind();
  		  }
    	  if(b.equals(b3))//��ѯ
    	  {
    		  if(j1.getText().length()==0) j1.setText("%");
    		  if(j2.getText().length()==0) j2.setText("%");
    		  if(j3.getText().length()==0) j3.setText("%");
    		  if(j4.getText().length()==0) j4.setText("%");
    		  if(j5.getText().length()==0) j5.setText("%");
    		  if(j6.getText().length()==0) j6.setText("%");
    		  sql="select * from car_check where ����� like '"+j1.getText()+"'and ���ƺ� like '"+j2.getText()+"'and ���쵥λ like'"+j3.getText()+"'and ���������� like'"+j4.getText()+"' and �������� like'"+j5.getText()+"' and ������� like'"+j6.getText()+"'";    	
    		  bind(); 
    	  }
    	  if(b.equals(b4))//���
    	  {   		   
    		    String sq3="insert into car_check values('"+j1.getText()+"' ,'" + j2.getText() + "','" + j3.getText() + "','" + j4.getText() + "','" + j5.getText() + "','"+j6.getText()+"')";
    		    String  sq1 = "select * from car_check where �����='" + j1.getText() + "'";
    		    String  sq2 = "select * from car_info where ���ƺ�='" + j2.getText() + "'";
    		    ResultSet rs1= db.getResult(sq1);
    		    ResultSet rs2= db.getResult(sq2);
    		    if(rs1.next())
    		    {
    		    	JOptionPane.showMessageDialog(null, "���д˱�ţ�");   		    
    		    }else if(!rs2.next())
    		    {
    		    	JOptionPane.showMessageDialog(null, "�����ڴ˳�����");   		    
    		    }else if(j1.getText().length()==0)
    		    {
    		    	JOptionPane.showMessageDialog(null, "�����복��ţ�");
    		    }else if(j2.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "�����복�ƺţ�");
        		}else if(j3.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "�����복�쵥λ��");
        		}else if(j4.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "�����복����������");
        		}else if(j5.getText().length()==0)
    		    {
        		    JOptionPane.showMessageDialog(null, "�����복�����ڣ�");
        		}				
    		    else if(db.updateResult(sq3)!=0){
    		    	bind(); 
					JOptionPane.showMessageDialog(null, "��ӳɹ���");
				 }
      			else{
      				JOptionPane.showMessageDialog(null, "���ʧ�ܣ�");
      			}
      			
    	 }	  
    	  if(b.equals(b5))//ɾ��
    	  {
    		  String sq3="delete from car_check where �����='"+j1.getText()+"'";
    		  if(db.updateResult(sq3)!=0)
    		  {
    			  bind();
    			  JOptionPane.showMessageDialog(null, "ɾ���ɹ���");  
    		  }
    		  else JOptionPane.showMessageDialog(null, "ɾ��ʧ�ܣ�");
    	  }	  
    	  if(b.equals(b6))//�޸�
    	  {
    		  String sq3="update car_check set ����� ='"+j1.getText()+"', ���ƺ� ='"+j2.getText()+"' ,���쵥λ ='"+j3.getText()+"' ,���������� ='"+j4.getText()+"' ,�������� ='"+j5.getText()+"',������� ='"+j6.getText()+"' where �����='"+j1.getText()+"'";
    		  if(db.updateResult(sq3)!=0)
    		  { 
    			  bind();
    			  JOptionPane.showMessageDialog(null, "�޸ĳɹ���");
    		  }
    		  else JOptionPane.showMessageDialog(null, "�޸�ʧ�ܣ�");
    	  }
    	  if(e.getSource()==b7)//�˳�
    	  {
    		  dispose();
    		  System.exit(0);
    	  }
    	  if(e.getSource()==b8)//����
    	  {
    		  dispose();
    	  }
    	}
    	catch(Exception ex){}    	
    	}
}
