package _asd_lab2;
import java.util.*;

/**
 * �/� � 2
 * ����� ���������� �������
 * @author Taras
 */
public class _ASD_Lab2 {
        //�� ���������� ������ ����������
        static final boolean showIntermediateResults = true;

        //������� ����������
	static void sort(int arr[]) {
            for (int i = 0; i < arr.length; i++) {
                // �������� ��������� ������� ��
                // ������� ������� [i; a.length);
                // �������� ���� ������ ����� i
                int minValueIndex = i;

                // ���������� ��������, �� ���������� �� �������
                for (int j = i + 1; j < arr.length; j++) {
                    // ���� ������� � ������� j ������
                    // �������� � ������� minValueIndex, ��
                    // ��������� �������� �������� �������
                    if (arr[j] < arr[minValueIndex]) {
                        minValueIndex = j;
                    }
                }

                // ̳����� �������� ������� � ���������
                int temp = arr[i];
                arr[i] = arr[minValueIndex];
                arr[minValueIndex] = temp;
                
                //�������� �������� ���������, ���� �� �������
                if(showIntermediateResults) show(arr);
            }	
        }
        
        //���� ������������ ������ �� ����� 
        static void show(int[] arr) {
            for(int i = 0; i < arr.length; i++)
                System.out.print("" + arr[i] + " ");
            System.out.println();
        }
        
        //�������� �� ����� ������������ � ������� ��������� ������� ��������
        static boolean checkResults(int[] arr) {
            for(int i = 1; i < arr.length; i++)
                if(arr[i] < arr[i-1]) return false;
            return true;
        }
        
        //������� ������� ��������
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.print("Array size: ");
            if(!sc.hasNextInt()) { 
               // ���� ���������� ��� �� ���� ����� �������� �������� �����������
               System.out.println("It's not integer value! Program terminate...");
               return;
            }
            // ������� ���� ����� � ��������� �����
            int[] a = new int[sc.nextInt()];
            Calendar c = Calendar.getInstance(); 
            Random rand = new Random(c.getTimeInMillis());
            
            //����������� ��������� ������ ����������� ������� �� 0 �� 99
            for(int i = 0; i < a.length; i++)
                a[i] = rand.nextInt(100);
            
            System.out.println("\nBefore sorting:");
            show(a);
            
            //������� ��� ������� ����������
            c = Calendar.getInstance();
            long timeStart = c.getTimeInMillis();
            
            //������� ���������� (����������)
            sort(a);
            
            //������� ��� ���������� ����������
            c = Calendar.getInstance();
            long timeStop = c.getTimeInMillis();
            
            System.out.println("\nAfter sorting:");
            show(a);
            System.out.println("\nThe result is " + checkResults(a) + 
                    ". Time elapsed: " + (timeStop - timeStart) + " msec.");
        }
}