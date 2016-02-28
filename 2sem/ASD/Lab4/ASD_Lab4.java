package _asd_lab4;
import java.util.*;

/**
 * Л/р № 4 Алгоритм прямого пошуку стрічки 
 * @author Taras
 */
public class _ASD_Lab4 {
        //чи показувати проміжні результати
        static final boolean showIntermediateResults = true;
        
        //вивід покрокової інформації
        static void message(Object obj) {
            if(showIntermediateResults) System.out.println(obj);
        }
        
        //пошук першого входження підстроки word в строці text
        //повертає позицію першого символа, що співпав, якщо
        //підстроку не знайдено - повертає -1
        static int substringSearch(char[] text, char[] word) {
            //якщо пусте слово та пустий текст - то позиція входження = 0
            //якщо пусте слово в не пустому тексті - то позиція входження = -1
            if(word.length == 0) return text.length == 0 ? 0 : -1;
            
            for(int i = 0; i < text.length; i++) {
                int n = 0;
                message("\ni = " + i);
                
                for(int j = 0; (j < word.length) && (i + j < text.length); j++) {
                    message("" + word[j] + " == " + text[i+j] + " --> " 
                            + (word[j] == text[i+j]));
                    
                    //якщо не співпав наступний символ - не продовжуємо
                    if(word[j] != text[i+j]) break;
                    n++;
                }
                
                //якщо всі символи слова співпали
                if(n == word.length) {
                    message("res = " + i);
                    return i;
                }
            }
            return -1;  // не знайдено
        }
        
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter text: ");
            String text = sc.nextLine();
            
            System.out.println("Enter word: ");
            String word = sc.nextLine();
            int pos = substringSearch(text.toCharArray(), word.toCharArray());
            if(pos < 0) 
                System.out.println("\nWord is not found in the text.");
            else 
                System.out.println("\nEntry position: " + pos);
        }
}
