package _asd_lab3;
import java.util.*;

/**
 * Л/р № 3 
 * Бінарний пошук
 * @author Taras
 */
public class _ASD_Lab3 {
        //чи показувати проміжні результати
        static final boolean showIntermediateResults = true;
        
        //масив ключів, який зберігає розташуваня індексів вхідного масиву
        //після сортування, відносно ж цього масиву до сортування
        static int[] keys;
        
        //вивід покрокової інформації
        static void message(Object obj) {
            if(showIntermediateResults) System.out.print(obj);
        }
        
        //бінарний пошук (масив int[] a повинен бути відсортований)
        static int binarySearch(int[] a, int key) {
            int low = 0;
            int high = a.length - 1;
            
            while (low <= high) {
                int mid = (low + high) >>> 1; //порозрядне ділення на 2
                int midVal = a[mid];
                message("\nm = a[" + mid + "] = " + midVal);
                
                if (midVal < key) {
                    message("\nm < " + key);
                    low = mid + 1;
                }
                else if (midVal > key) {
                    message("\nm > " + key);
                    high = mid - 1;
                }
                else {
                    message("\nm == " + key);
                    return mid; // знайдено
                }
            }
            return -1;  // не знайдено
        }
                

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
                
                //записуємо зміни в масив ключів
                temp = keys[i];
                keys[i] = keys[minValueIndex];
                keys[minValueIndex] = temp;
            }	
        }

        //перевірка чи алгоритм пошуку повернув правильну позицію
        static boolean checkResults(int[] arr, int pos, int value) {
            if(pos < 0) {
                for(int i = 0; i < arr.length; i++)
                    if(arr[i] == value) return false;
                return true;
            }
            else 
                return arr[pos] == value;
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
            
            //масив ключів
            keys = new int[a.length];
            
            //b - копія масиву а, потрібно для перевірки результату
            int[] b = new int[a.length];
            
            //ініціалізація едлементів масиву випадковими числами від 0 до 99
            for(int i = 0; i < a.length; i++) {
                a[i] = rand.nextInt(100);
                //початковий стан ключів
                keys[i] = i;
                //копіюємо a[i] в b[i]
                b[i] = a[i];
            }
            
            System.out.println("\nArray:\n" + Arrays.toString(a));
            
            //відсортуємо вхідний масив
            sort(a);
            
            message("\nArray after sort:\n" + Arrays.toString(a));
            
            System.out.print("\nValue: ");
            if(!sc.hasNextInt()) { 
               // Якщо користувач ввів не ціле число виводимо відповідне повідомлення
               System.out.println("It's not integer value! Program terminate...");
               return;
            }
            // зчитуємо ціле число і виконуємо пошук
            int value = sc.nextInt();
            
            //засічемо час початку пошуку
            c = Calendar.getInstance();
            long timeStart = c.getTimeInMillis();
            
            
            //функція пошуку
            int res = binarySearch(a, value);
            
            //засічемо час завершення пошуку
            c = Calendar.getInstance();
            long timeStop = c.getTimeInMillis();
            
            int oldPos;
            if(res < 0) {
                oldPos = -1;
                System.out.println("\nValue not found."); 
            }
            else {    
                oldPos = keys[res];
                System.out.println("\nPosition: " + keys[res]);
            }    
            System.out.println("The result is " + checkResults(b, oldPos, value) + 
                    ". Time elapsed: " + (timeStop - timeStart) + " msec.");
        }
}

