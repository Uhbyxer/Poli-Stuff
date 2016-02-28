package _asd_lab4;
import java.util.*;

/**
 * �/� � 4 �������� ������� ������ ������ 
 * @author Taras
 */
public class _ASD_Lab4 {
        //�� ���������� ������ ����������
        static final boolean showIntermediateResults = true;
        
        //���� ��������� ����������
        static void message(Object obj) {
            if(showIntermediateResults) System.out.println(obj);
        }
        
        //����� ������� ��������� �������� word � ������ text
        //������� ������� ������� �������, �� ������, ����
        //�������� �� �������� - ������� -1
        static int substringSearch(char[] text, char[] word) {
            //���� ����� ����� �� ������ ����� - �� ������� ��������� = 0
            //���� ����� ����� � �� ������� ����� - �� ������� ��������� = -1
            if(word.length == 0) return text.length == 0 ? 0 : -1;
            
            for(int i = 0; i < text.length; i++) {
                int n = 0;
                message("\ni = " + i);
                
                for(int j = 0; (j < word.length) && (i + j < text.length); j++) {
                    message("" + word[j] + " == " + text[i+j] + " --> " 
                            + (word[j] == text[i+j]));
                    
                    //���� �� ������ ��������� ������ - �� ����������
                    if(word[j] != text[i+j]) break;
                    n++;
                }
                
                //���� �� ������� ����� �������
                if(n == word.length) {
                    message("res = " + i);
                    return i;
                }
            }
            return -1;  // �� ��������
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
