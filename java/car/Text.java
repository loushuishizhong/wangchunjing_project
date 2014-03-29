import java.awt.event.*;
import javax.swing.*;
public class Text extends JFrame implements ActionListener 
{
     JMenuBar jMenuBar1 = new JMenuBar();
     JMenu jMenu1 = new JMenu("车辆信息查询");
     JMenuItem jMenuItem1 = new JMenuItem();
     JSeparator jSeparator1 = new JSeparator();
     JMenuItem jMenuItem2 = new JMenuItem();
     JMenuItem jMenuItem3 = new JMenuItem();
     public Text()
        {
        jMenuItem1.setText("查询基本信息");
        jMenuItem1.addActionListener(this);
        jMenu1.add(jMenuItem1);
     
		jMenu1.add(jSeparator1);
        jMenuItem2.setText("查询违章信息");
        jMenuItem2.addActionListener(this);;
        jMenu1.add(jMenuItem2);
        jMenuItem3.setText("查询年检信息");
        jMenuItem3.addActionListener(this);;
        jMenu1.add(jMenuItem3);
        jMenuBar1.add(jMenu1);
        
        setJMenuBar(jMenuBar1);
        
        setTitle("车辆信息咨询系统");
        setSize(800,800);
		setVisible(true);
        }
        
    public void actionPerformed(ActionEvent e)
	{		
    	if(e.getSource()==jMenuItem1)
			{	
				try {
					this.add(new findCar());
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
			else if(e.getSource()==jMenuItem2)
			{	
				try {
					this.add(new findError());
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
			else if(e.getSource()==jMenuItem3)
			{	
				try {
					this.add(new findcheck());
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
	}
 }

        
