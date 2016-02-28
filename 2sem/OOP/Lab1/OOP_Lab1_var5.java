package _oop_lab1;
import java.util.Scanner;

/**
 * �/� � 1 (������ 5)
 * ��������� �����. ���������� �ᑺ���. ������ �� ������ �� ������
 * ����� ����� �ᑺ��. ��������� ������������ � �����������.
 * @author Taras
 */

//���� �������
class Matrix {
    //���������� �����
    public int m, n; //����� ������ �
    public int[][] a; 
    
    //����������� �����
    public Matrix(int m, int n) {
        //��������� ����� ������� � ���������� �����
        this.m = m;
        this.n = n;
        //�������� ����� ������� m �� n
        a = new int[m][n];
        
        // �������� ��������� ����� Scanner ��� ������� ����� � ������ 
        Scanner sc = new Scanner(System.in); 
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; ) {
                System.out.print("a[" + (i+1) + "][" + (j+1) + "]: ");
                // ������� ������, ���� � ������ ����� ������� ���� �����
                if(sc.hasNextInt()) { 
                    // ������� ���� ����� � �������� �������� � ������� ������
                    a[i][j] = sc.nextInt(); 
                    j++;
                }
                else {
                    /* ���� ���������� ��� �� ���� ����� �������� �������� ������������,
                     * ���� �� ���� �������� �������� ��������  
                     */
                    System.out.println("It's not integer value! Try again...");
                    sc.next();
                }
            }
    }
    
    //���������� �������� �������� ������� "������� ���������"
    public void bubbleSort() {
        //������ ��� �������� ������
        for(int j = 0; j < n; j++)
            //��� "bubble sort" 
            for(int k = m-2; k >= 0; k--)
                for(int i = 0; i <= k; i++)
                    if(a[i][j] > a[i+1][j]) {
                        int temp = a[i][j];
                        a[i][j] = a[i+1][j];
                        a[i+1][j] = temp;
                    }
    }
    
    //������ ����������� �-�� ����� �������
    public double f(int i){
        double f = 0;
        for(int j = 0; j < n; j++)
            f += a[i][j];
        
        //���������� ������� "������ �� ����"
        try {
            f /= n;
        } catch (ArithmeticException e) {
            f = 0;
        }    
        System.out.print("" + f + "\t");
        return f;
    }

    //������� ������� f(i) ��� ����� �������
    public double F() {
        double F = 1;
        System.out.println("\nf():");
        for(int i = 0; i < m; i++)
            F *= f(i);
        return F;
    }
}

//�������� ���� ������
public class _OOP_Lab1 {
    static final int  M = 4; //��������� ������� ������ �������
    static final int  N = 3; //��������� ������� �������� �������
    
    //��������� ������� ������� m �� n �� �����
    public static void show(int m, int n, int[][] a) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                System.out.print("" + a[i][j] + "\t");
            System.out.println();    
        }
    }
    
    public static void main(String[] args) {
        //����������� ����� �������
        Matrix m = new Matrix(M, N);
        System.out.println("\nBefore sorting:");
        //�������� ������� �� ����������
        show(M, N, m.a);
        //���������
        m.bubbleSort();
        System.out.println("\nAfter sorting:");
        //... � ���� ���������� 
        show(M, N, m.a);
        //��������� F()
        System.out.println("\n\nF() = " + m.F());
    }
}