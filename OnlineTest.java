/*Online Java Paper Test*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class OnlineTest extends JFrame implements ActionListener
{
	JLabel l;
	JRadioButton jb[]=new JRadioButton[5];
	JButton b1,b2;
	ButtonGroup bg;
	int count=0,current=0,x=1,y=1,now=0;
	int m[]=new int[10];	
	OnlineTest(String s)
	{
		super(s);
		l=new JLabel();
		add(l);
		bg=new ButtonGroup();
		for(int i=0;i<5;i++)
		{
			jb[i]=new JRadioButton();	
			add(jb[i]);
			bg.add(jb[i]);
		}
		b1=new JButton("Next");
		b2=new JButton("Bookmark");
		b1.addActionListener(this);
		b2.addActionListener(this);
		add(b1);add(b2);
		set();
		l.setBounds(30,40,450,20);
		jb[0].setBounds(50,80,100,20);
		jb[1].setBounds(50,110,100,20);
		jb[2].setBounds(50,140,100,20);
		jb[3].setBounds(50,170,100,20);
		b1.setBounds(100,240,100,30);
		b2.setBounds(270,240,100,30);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		setLocation(250,100);
		setVisible(true);
		setSize(600,350);
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			if(check())
				count=count+1;
			current++;
			set();	
			if(current==9)
			{
				b1.setEnabled(false);
				b2.setText("Result");
			}
		}
		if(e.getActionCommand().equals("Bookmark"))
		{
			JButton bk=new JButton("Bookmark"+x);
			bk.setBounds(480,20+30*x,100,30);
			add(bk);
			bk.addActionListener(this);
			m[x]=current;
			x++;
			current++;
			set();	
			if(current==9)
				b2.setText("Result");
			setVisible(false);
			setVisible(true);
		}
		for(int i=0,y=1;i<x;i++,y++)
		{
		if(e.getActionCommand().equals("Bookmark"+y))
		{
			if(check())
				count=count+1;
			now=current;
			current=m[y];
			set();
			((JButton)e.getSource()).setEnabled(false);
			current=now;
		}
		}
	
		if(e.getActionCommand().equals("Result"))
		{
			if(check())
				count=count+1;
			current++;
			//System.out.println("correct ans="+count);
			JOptionPane.showMessageDialog(this,"correct ans="+count);
			System.exit(0);
		}
	}
	void set()
	{
		jb[4].setSelected(true);
		if(current==0)
		{
			l.setText("Que1: Which type of inheritance is not supported in java");
			jb[0].setText("multiple");jb[1].setText("multilevel");jb[2].setText("hybrid");jb[3].setText("hierarchical");	
		}
		if(current==1)
		{
			l.setText("Que2: Instance of class is known as");
			jb[0].setText("class");jb[1].setText("object");jb[2].setText("recursion");jb[3].setText("datatype");
		}
		if(current==2)
		{
			l.setText("Que3: which of the following is NOT a non-acess modifier");
			jb[0].setText("static");jb[1].setText("final");jb[2].setText("public");jb[3].setText("abstract");
		}
		if(current==3)
		{
			l.setText("Que4: Which of the following is considered as the first truly object-oriented programming language");
			jb[0].setText("C");jb[1].setText("SmallTalk");jb[2].setText("C++");jb[3].setText("Simula");
		}
		if(current==4)
		{
			l.setText("Que5: Different behaviour of objects at different instances is known as");
			jb[0].setText("abstraction");jb[1].setText("inheritance");jb[2].setText("encapsulation");jb[3].setText("polymorphism");
		}
		if(current==5)
		{
			l.setText("Que6: Hiding our irrelevent data is known as");
			jb[0].setText("abstraction");jb[1].setText("encapsulatiion");jb[2].setText("inheritance");jb[3].setText("polymorphism");
		}
		if(current==6)
		{
			l.setText("Que7: Protecting of data is known as");
			jb[0].setText("inheritance");jb[1].setText("abstraction");jb[2].setText("encapsulation");jb[3].setText("polymorphism");
		}
		if(current==7)
		{
			l.setText("Que8:One property of object is acquiring to another property of object");
			jb[0].setText("abstraction");jb[1].setText("polymorphism");jb[2].setText("inheritance");jb[3].setText("encapsulation");		
		}
		if(current==8)
		{
			l.setText("Que9: What is known as the implementation of the service requested by the message");
			jb[0].setText("method");jb[1].setText("main");jb[2].setText("class");jb[3].setText("constructor");
		}
		if(current==9)
		{
			l.setText("Que10: What is known as a request for a service");
			jb[0].setText("typecasting");jb[1].setText("library");jb[2].setText("parsing");jb[3].setText("message");
		}
		l.setBounds(30,40,450,20);
		for(int i=0,j=0;i<=90;i+=30,j++)
			jb[j].setBounds(50,80+i,200,20);
	}
	boolean check()
	{
		if(current==0)
			return(jb[0].isSelected());
		if(current==1)
			return(jb[1].isSelected());
		if(current==2)
			return(jb[2].isSelected());
		if(current==3)
			return(jb[1].isSelected());
		if(current==4)
			return(jb[3].isSelected());
		if(current==5)
			return(jb[0].isSelected());
		if(current==6)
			return(jb[2].isSelected());
		if(current==7)
			return(jb[2].isSelected());
		if(current==8)
			return(jb[0].isSelected());
		if(current==9)
			return(jb[3].isSelected());
		return false;
	}
	public static void main(String s[])
	{
		new OnlineTest("Online Test Of Java");
	}


}
