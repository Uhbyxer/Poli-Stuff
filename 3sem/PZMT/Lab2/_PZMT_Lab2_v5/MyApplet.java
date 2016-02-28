package org.me.hello;

import java.applet.*;
import java.awt.*;
import java.util.*;

public class MyApplet extends Applet {
    private int x, y; //поточні координати
    private int tokenIndex; //індекс поточного слова
    private String[] token; //масив слів
    private boolean started; //true - виводимо текст, false - пустий екран
    
    private Timer timer; //таймер
    private MyTask t; //завдання таймера
    
    @Override
    public void init() { //початкове заповнення властивостей аплета
        started = false;
        x = 20; y = 20;
        tokenIndex = -1;
        //розбиваємо стрічку на масив слів
        token = "Hello! This is my first Java-applet!".split(" ");
        
        //створюємо таймер
        timer = new Timer();
        t = new MyTask(this);
        //викликаємо кожних 200 мсек.
        timer.schedule(t, 0, 200);
    }
    
    @Override
    public void paint(Graphics g) {
        //задамо кольори фону та тексту 
        setBackground(Color.BLUE);
        g.setColor(Color.YELLOW);
        //текст не виводимо
        if(!started) return;
        //виводимо поточне слово у поточних координатах
        g.drawString(token[tokenIndex], x, y);
    }    
    
    @Override
    public boolean mouseDown(Event evt, int x, int y)  { 
    	//якщо подвійний клік
        if(evt.clickCount > 1) { 
            //дозволяємо виводити текст
            started = true;
            repaint();
            //якщо вивели останнє слово в реченні - починаємо з першого 
            if(++tokenIndex >= token.length) tokenIndex  = 0;
    	}
        return true;
    }
    
    @Override
    public boolean keyDown(Event evtObj, int key) {
        //натиснули клавішу DELETE
        if(key == Event.DELETE) {
            //зупинка таймера
            t.cancel();
            //переініціалізація властивостей аплета
            init();
            repaint();
        }
      return true;
   }  
   
   //переміщення тексту у вікні
   public void Move() {
       if(!started) return;
       /* збільшуємо координати, споочатку по осі Y,
        * а потім  - Х, з вказаним кроком та контролем границь
       */
       y += 10;
       if (y > 200) {
           y = 20;
           x += 15;
       }
       if (x > 200) x = 20;
       //перемальовуємо вікно
       repaint();
   } 
}

//клас завдання таймера
class MyTask extends TimerTask {
    //ссилка на наш аплет
    private MyApplet app;
    
    //конструктор
    public MyTask(MyApplet app) {
        super();
        this.app = app;
    }

    //при завершенні певного проміжку часу - перемалбовуємо текст аплета
    @Override
    public void run() {
        app.Move();
    }
}


