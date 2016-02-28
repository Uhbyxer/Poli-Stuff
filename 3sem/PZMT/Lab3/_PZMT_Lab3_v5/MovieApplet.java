
package org.me.movie;

import java.applet.Applet;
import java.awt.*;
import java.util.Calendar;
import java.util.Random;

//������� ���� �����
enum direction {HORIZONTAL, VERTICAL, DIAGONAL};

public class MovieApplet extends Applet {
    //������� ������
    private int countThreads = 0;
    private Random rand;
    
    @Override
    public void init() {
        rand = new Random(Calendar.getInstance().getTimeInMillis()); 
        
        setBackground(Color.YELLOW);
        //��������� ��� ������
        new Movie(50, 20, 0xff5555, direction.DIAGONAL, 50).start(); 
	new Movie(30, 70, 0x5555ff, direction.VERTICAL, 100).start();
    }
    
    @Override
    public boolean mouseDown(Event evt, int x, int y) { 
        //��� ������� ������ ���� ��������� ����� ����
        new Movie(x, y, 
                  rand.nextInt(0xffffff), 
                  direction.values()[rand.nextInt(direction.values().length)] ,
                  50 + countThreads * 10).start();
        return true;
    }    
    class Movie extends Thread {
        //������ ���������� ������
        private int lastX,lastY;
	//������ ���������� ������
        private int x,y;
	//��� �������� ������ �� �����
        private int pause;
	//�������� ���� �� ������
        private direction dir;
	//����
        private Color col;
	
        Movie(int xStart, int yStart, int col, direction dir, int pause) {
            countThreads++;
            //���������� �������� ��������
            this.col = new Color(col);		
            this.pause = pause;
            this.dir = dir;				
            x = xStart; y = yStart; 
            lastX = x; lastY = y;
	}
	
        @Override
	public void run() {
            while(true) {      
                //�����'������� ���� ����������
                lastX = x; lastY = y;
                
                //� ��������� �� ������� ������� ������
                //����������
                switch(dir) {
                    case DIAGONAL: x += 10; y += 10; break;  
                    case VERTICAL: y += 10; break;
                    default: x += 10;
                }
                //���� ������ �� ������ �������
                if(x > 1000) x = 20;
                if(y > 500) y = 20;
		//�������
                mypaint();
		try { 
                    //�������� ����������
                    Movie.sleep(pause); 
                }
		catch (InterruptedException e){}
		}
	}
	
	public void mypaint() {		
            Graphics g = getGraphics();	
            if(g == null) return;
            
            //����������� "�����" ���������� �������� ����
            g.setColor(Color.YELLOW);
            g.drawOval(lastX, lastY, 20, 20);

            //������� "����" ����������
            g.setColor(col);
            g.drawOval(x, y, 20, 20);
	}
    }    
}
