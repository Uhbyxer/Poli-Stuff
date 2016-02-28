
package org.me.movie;

import java.applet.Applet;
import java.awt.*;
import java.util.Calendar;
import java.util.Random;

//нарямки руху фігур
enum direction {HORIZONTAL, VERTICAL, DIAGONAL};

public class MovieApplet extends Applet {
    //кількість потоків
    private int countThreads = 0;
    private Random rand;
    
    @Override
    public void init() {
        rand = new Random(Calendar.getInstance().getTimeInMillis()); 
        
        setBackground(Color.YELLOW);
        //створюємо два потоки
        new Movie(50, 20, 0xff5555, direction.DIAGONAL, 50).start(); 
	new Movie(30, 70, 0x5555ff, direction.VERTICAL, 100).start();
    }
    
    @Override
    public boolean mouseDown(Event evt, int x, int y) { 
        //при натиску клавіші миші створюємо новий потік
        new Movie(x, y, 
                  rand.nextInt(0xffffff), 
                  direction.values()[rand.nextInt(direction.values().length)] ,
                  50 + countThreads * 10).start();
        return true;
    }    
    class Movie extends Thread {
        //останні координати фігури
        private int lastX,lastY;
	//поточні координати фігури
        private int x,y;
	//час затримки фігури на екрані
        private int pause;
	//напрямок руху по екрану
        private direction dir;
	//колір
        private Color col;
	
        Movie(int xStart, int yStart, int col, direction dir, int pause) {
            countThreads++;
            //присвоюємо початкові значення
            this.col = new Color(col);		
            this.pause = pause;
            this.dir = dir;				
            x = xStart; y = yStart; 
            lastX = x; lastY = y;
	}
	
        @Override
	public void run() {
            while(true) {      
                //запам'ятовуємо старі координати
                lastX = x; lastY = y;
                
                //в залежності від напряму змінюємо поточні
                //координати
                switch(dir) {
                    case DIAGONAL: x += 10; y += 10; break;  
                    case VERTICAL: y += 10; break;
                    default: x += 10;
                }
                //якщо вийшли за видиму область
                if(x > 1000) x = 20;
                if(y > 500) y = 20;
		//малюємо
                mypaint();
		try { 
                    //затримка зображення
                    Movie.sleep(pause); 
                }
		catch (InterruptedException e){}
		}
	}
	
	public void mypaint() {		
            Graphics g = getGraphics();	
            if(g == null) return;
            
            //замальовуємо "старе" зображення кольором фону
            g.setColor(Color.YELLOW);
            g.drawOval(lastX, lastY, 20, 20);

            //малюємо "нове" зображення
            g.setColor(col);
            g.drawOval(x, y, 20, 20);
	}
    }    
}
