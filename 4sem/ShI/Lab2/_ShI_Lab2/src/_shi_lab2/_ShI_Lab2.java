/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package _shi_lab2;
import _shi_lab2.forms.*;
import _shi_lab2.source.*;

/**
 *
 * @author Taras
 */
public class _ShI_Lab2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        //створюємо список хворіб
        ListOfDiseases list = new ListOfDiseases();
        list.add(new Disease("Кір", Disease.VIRUS, 0, 20, 1, 10, 2, 10, 6, 30, 14, 30));
        list.add(new Disease("Грип", Disease.VIRUS, 0, 20, 1, 10, 2, 10, 12, 30, 13, 30));
        list.add(new Disease("Запалення легень", Disease.VIRUS, 0, 20, 2, 20, 5, 30, 12, 15, 13, 15));
        list.add(new Disease("Ангіна", Disease.VIRUS, 0, 20, 3, 20, 4, 30, 12, 15, 13, 15));
        
        list.add(new Disease("Скарлатина", Disease.INFECT, 0, 15, 3, 15, 4, 10, 6, 30, 7, 30));
        list.add(new Disease("Свинка", Disease.INFECT, 0, 30, 4, 30, 8, 40));
        list.add(new Disease("Дизентерія", Disease.INFECT, 0, 20, 9, 40, 10, 40));
        list.add(new Disease("Гепатит", Disease.INFECT, 9, 40, 11, 60));
        
        
        //запуск граф. інтерфейсу
        MainWindow.main(list);
    }
    
    
}
