
package simplex;

import simplex.source.*;
import simplex.gui.*;

/**
 * Точка входу в програму
 * @author Taras
 */
public class SimplexMethod {

    /**
     * Точка входу
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
       if(args.length == 0)
           //запуск графічного інтерфейсу 
           MainWindow.main(null);
       else if(args[0].toLowerCase().equals("con")) 
           // запуск з консолі
           Simplex.main(null);
       else
           System.err.println("Помилковий формат командноi строки !");
       
    }
    
}
