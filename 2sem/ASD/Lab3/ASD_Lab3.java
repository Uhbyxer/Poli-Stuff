package _asd_lab3;
import java.util.*;

/**
 * �/� � 3 
 * �������� �����
 * @author Taras
 */
public class _ASD_Lab3 {
        //�� ���������� ������ ����������
        static final boolean showIntermediateResults = true;
        
        //����� ������, ���� ������ ����������� ������� �������� ������
        //���� ����������, ������� � ����� ������ �� ����������
        static int[] keys;
        
        //���� ��������� ����������
        static void message(Object obj) {
            if(showIntermediateResults) System.out.print(obj);
        }
        
        //������� ����� (����� int[] a ������� ���� ������������)
        static int binarySearch(int[] a, int key) {
            int low = 0;
            int high = a.length - 1;
            
            while (low <= high) {
                int mid = (low + high) >>> 1; //���������� ������ �� 2
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
                    return mid; // ��������
                }
            }
            return -1;  // �� ��������
        }
                

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
                
                //�������� ���� � ����� ������
                temp = keys[i];
                keys[i] = keys[minValueIndex];
                keys[minValueIndex] = temp;
            }	
        }

        //�������� �� �������� ������ �������� ��������� �������
        static boolean checkResults(int[] arr, int pos, int value) {
            if(pos < 0) {
                for(int i = 0; i < arr.length; i++)
                    if(arr[i] == value) return false;
                return true;
            }
            else 
                return arr[pos] == value;
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
            
            //����� ������
            keys = new int[a.length];
            
            //b - ���� ������ �, ������� ��� �������� ����������
            int[] b = new int[a.length];
            
            //����������� ��������� ������ ����������� ������� �� 0 �� 99
            for(int i = 0; i < a.length; i++) {
                a[i] = rand.nextInt(100);
                //���������� ���� ������
                keys[i] = i;
                //������� a[i] � b[i]
                b[i] = a[i];
            }
            
            System.out.println("\nArray:\n" + Arrays.toString(a));
            
            //��������� ������� �����
            sort(a);
            
            message("\nArray after sort:\n" + Arrays.toString(a));
            
            System.out.print("\nValue: ");
            if(!sc.hasNextInt()) { 
               // ���� ���������� ��� �� ���� ����� �������� �������� �����������
               System.out.println("It's not integer value! Program terminate...");
               return;
            }
            // ������� ���� ����� � �������� �����
            int value = sc.nextInt();
            
            //������� ��� ������� ������
            c = Calendar.getInstance();
            long timeStart = c.getTimeInMillis();
            
            
            //������� ������
            int res = binarySearch(a, value);
            
            //������� ��� ���������� ������
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

