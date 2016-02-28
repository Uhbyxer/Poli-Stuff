package _oop_lab1;
import java.util.Scanner;

/**
 * Л/р № 1 (варіант 5)
 * Створення класів. Оголошення об‘єктів. Доступ до змінних та методів
 * класів через об‘єкт. Реалізація конструкторів з параметрами.
 * @author Taras
 */

//клас Матриці
class Matrix {
    //властивості класу
    public int m, n; //розмір масиву а
    public int[][] a; 
    
    //конструктор класу
    public Matrix(int m, int n) {
        //збережемо розмір матриці у властивості класу
        this.m = m;
        this.n = n;
        //створимо масив розміром m на n
        a = new int[m][n];
        
        // створимо екземпляр класу Scanner для читання чисел з консолі 
        Scanner sc = new Scanner(System.in); 
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; ) {
                System.out.print("a[" + (i+1) + "][" + (j+1) + "]: ");
                // повертає істину, якщо з потоку можна зчитати ціле число
                if(sc.hasNextInt()) { 
                    // зчитуємо ціле число і зберігаємо значення в елемент масиву
                    a[i][j] = sc.nextInt(); 
                    j++;
                }
                else {
                    /* Якщо користувач ввів не ціле число виводимо відповідне попередження,
                     * поки не буде введенно коректне значення  
                     */
                    System.out.println("It's not integer value! Try again...");
                    sc.next();
                }
            }
    }
    
    //сортування елементів стовбців матриці "методом бульбашки"
    public void bubbleSort() {
        //перебір всіх стовбців масиву
        for(int j = 0; j < n; j++)
            //сам "bubble sort" 
            for(int k = m-2; k >= 0; k--)
                for(int i = 0; i <= k; i++)
                    if(a[i][j] > a[i+1][j]) {
                        int temp = a[i][j];
                        a[i][j] = a[i+1][j];
                        a[i+1][j] = temp;
                    }
    }
    
    //середнє арифметичне і-го рядка матриці
    public double f(int i){
        double f = 0;
        for(int j = 0; j < n; j++)
            f += a[i][j];
        
        //перехопимо помилку "ділення на нуль"
        try {
            f /= n;
        } catch (ArithmeticException e) {
            f = 0;
        }    
        System.out.print("" + f + "\t");
        return f;
    }

    //добуток значень f(i) всіх рядків матриці
    public double F() {
        double F = 1;
        System.out.println("\nf():");
        for(int i = 0; i < m; i++)
            F *= f(i);
        return F;
    }
}

//головний клас пакету
public class _OOP_Lab1 {
    static final int  M = 4; //константа кількості стрічок матриці
    static final int  N = 3; //константа кількості стовбців матриці
    
    //виведення матриці розміром m на n на екран
    public static void show(int m, int n, int[][] a) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                System.out.print("" + a[i][j] + "\t");
            System.out.println();    
        }
    }
    
    public static void main(String[] args) {
        //ініціалізація класу матриці
        Matrix m = new Matrix(M, N);
        System.out.println("\nBefore sorting:");
        //покажемо матрицю до сортування
        show(M, N, m.a);
        //відсортуємо
        m.bubbleSort();
        System.out.println("\nAfter sorting:");
        //... і після сортування 
        show(M, N, m.a);
        //обчислимо F()
        System.out.println("\n\nF() = " + m.F());
    }
}