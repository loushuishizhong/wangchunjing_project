import java.awt.event.*;
import javax.swing.*;

import java.awt.*;
import java.io.IOException;
public class Text2 extends JFrame implements ActionListener 
{
     JMenuBar jMenuBar1 = new JMenuBar();
     JMenu jMenu2 = new JMenu("������Ϣ����");  
     JSeparator jSeparator1 = new JSeparator();
     JMenuItem jMenuItem3 = new JMenuItem();
     JMenuItem jMenuItem4 = new JMenuItem(); 
     JMenuItem jMenuItem5 = new JMenuItem("������Ϣ����"); 
     public Text2()
        {       
        jMenuItem3.setText("������Ϣ����");
        jMenuItem3.addActionListener(this);
        jMenu2.add(jMenuItem3);  
        jMenu2.add(jSeparator1);     
        jMenuItem4.setText("Υ����Ϣ����");
        jMenuItem4.addActionListener(this);
        jMenu2.add(jMenuItem4);
        jMenuItem5.addActionListener(this);
        jMenu2.add(jMenuItem5);
        jMenuBar1.add(jMenu2);
        
        setJMenuBar(jMenuBar1);
        
        setTitle("������Ϣ��ѯϵͳ");
        setSize(800,800);
		setVisible(true);
        }
        
    public void actionPerformed(ActionEvent e)
	{		
    	 if(e.getSource()==jMenuItem3)
		{	
			try {
					this.add(new index());
				} catch (Exception e1) {
					e1.printStackTrace();
				}
		}
         else if(e.getSource()==jMenuItem4)
		{	          	
           try {
				this.add(new weizhang());
				this.setVisible(true);
			} catch (Exception e1) {
				e1.printStackTrace();
			}
		}
         else if(e.getSource()==jMenuItem5)
 		{	          	
            try {
 				this.add(new check());
 				this.setVisible(true);
 			} catch (Exception e1) {
 				e1.printStackTrace();
 			}
 		}
	}
        
    public static void main(String args[]) 
    {       
            	Text2 t=new Text2();
    }
 }

        
