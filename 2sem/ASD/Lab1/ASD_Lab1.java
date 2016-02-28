package _asd_lab2;
import java.util.*;

/**
 * Л/р № 2
 * Метод сортування вибором
 * @author Taras
 */
public class _ASD_Lab2 {
        //чи показувати проміжні результати
        static final boolean showIntermediateResults = true;

        //функція сортування
	static void sort(int arr[]) {
            for (int i = 0; i < arr.length; i++) {
                // Знайдемо мінімальний елемент на
                // проміжку індексів [i; a.length);
                // спочатку його індекс рівний i
                int minValueIndex = i;

                // Перебираємо елементи, що залишилися на проміжку
                for (int j = i + 1; j < arr.length; j++) {
                    // Якщо елемент в позиції j менший
                    // елемента в позиції minValueIndex, то
                    // необхідно обновити значення індекса
                    if (arr[j] < arr[minValueIndex]) {
                        minValueIndex = j;
                    }
                }

                // Міняємо поточний елемент з мінімальним
                int temp = arr[i];
                arr[i] = arr[minValueIndex];
                arr[minValueIndex] = temp;
                
                //виведемо проміжний результат, якщо це потрібно
                if(showIntermediateResults) show(arr);
            }	
        }
        
        //вивід одновимірного масиву на екран 
        static void show(int[] arr) {
            for(int i = 0; i < arr.length; i++)
                System.out.print("" + arr[i] + " ");
            System.out.println();
        }
        
        //перевірка чи масив відсортований у порядку зростяння значень елементів
        static boolean checkResults(int[] arr) {
            for(int i = 1; i < arr.length; i++)
                if(arr[i] < arr[i-1]) return false;
            return true;
        }
        
        //основна функція програми
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.print("Array size: ");
            if(!sc.hasNextInt()) { 
               // Якщо користувач ввів не ціле число виводимо відповідне повідомлення
               System.out.println("It's not integer value! Program terminate...");
               return;
            }
            // зчитуємо ціле число і створюємо масив
            int[] a = new int[sc.nextInt()];
            Calendar c = Calendar.getInstance(); 
            Random rand = new Random(c.getTimeInMillis());
            
            //ініціалізація едлементів масиву випадковими числами від 0 до 99
            for(int i = 0; i < a.length; i++)
                a[i] = rand.nextInt(100);
            
            System.out.println("\nBefore sorting:");
            show(a);
            
            //засічемо час початку сортування
            c = Calendar.getInstance();
            long timeStart = c.getTimeInMillis();
            
            //функція сортування (рекурсивна)
            sort(a);
            
            //засічемо час завершення сортування
            c = Calendar.getInstance();
            long timeStop = c.getTimeInMillis();
            
            System.out.println("\nAfter sorting:");
            show(a);
            System.out.println("\nThe result is " + checkResults(a) + 
                    ". Time elapsed: " + (timeStop - timeStart) + " msec.");
        }
}