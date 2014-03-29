import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.ResultSet;
import java.sql.SQLException;
public class login extends JFrame implements ActionListener
{
	static int a;
	DBTools db=new DBTools();
	JPanel p0=new JPanel();
	JPanel p1=new JPanel();
	JPanel p2=new JPanel();
	JPanel p3=new JPanel();
	
	JTextField j1=new JTextField(10);
	JPasswordField j2=new JPasswordField(10);
	
	JButton jbutton1=new JButton("登录");
	JButton jbutton2=new JButton("取消");
	JRadioButton jRadioButton1=new JRadioButton("管理员");
    JRadioButton jRadioButton2=new JRadioButton("游客");
	Container contentpane=getContentPane();
	public login()
	{
		setTitle("欢迎登录车辆信息查询系统");		
		p0.add(jRadioButton1);
		p0.add(jRadioButton2);
		p1.add(new JLabel("用户名"));
		p1.add(j1);		
		p1.hide();
		
		p2.add(new JLabel("密   码:"));
		p2.add(j2);		
		p2.hide();
		
		p3.add(jbutton1);
		p3.add(jbutton2);		
		p3.hide();		
		jbutton1.addActionListener(this);
		jbutton2.addActionListener(this);
		jRadioButton1.addActionListener(this);
		jRadioButton2.addActionListener(this);
		contentpane.setLayout(new GridLayout(4,1));
		
		contentpane.add(p1);
		contentpane.add(p2);
		contentpane.add(p0);
		contentpane.add(p3);
		setSize(240,180);
		setVisible(true);
		}
	public void actionPerformed(ActionEvent e)
	{		
		
    	if(jRadioButton2.isSelected())
    	{
    		try {
    			Text t=new Text();
			} catch (Exception e1) {
				e1.printStackTrace();
			}
    		dispose();
    	}
    	else if(jRadioButton1.isSelected())
    	{	
    		p1.setVisible(true);
    		p2.setVisible(true);
    		p3.setVisible(true);
    		ResultSet rs;
        	String sql="select * from car_user where 用户名='"+j1.getText()+"'and 密码='"+j2.getText()+"'";
    		if(e.getSource()==jbutton1)
    		{
    			rs=db.getResult(sql);
    		try {
				if(rs.next())
				{
					try {
						Text2 t=new Text2();
					} catch (Exception e1) {
						e1.printStackTrace();
					}
					dispose();
				}
				else 
				{
					JOptionPane.showMessageDialog(null, "请检查用户名和密码！");
				}
				} catch (HeadlessException e1) {
					e1.printStackTrace();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}   
    		}	
    		else if(e.getSource()==jbutton2)
    		{
    			System.exit(0);		
    		}
    	}
	}
	public static void main(String args[]) 
	{
		login l=new login();
	}
}

