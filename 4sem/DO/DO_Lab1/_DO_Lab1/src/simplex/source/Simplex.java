package simplex.source;
import java.util.*;

/**
 * <b>Клас для обчислення симплекс методу</b>
 * @see Rational
 * @author Тарас Гринчук
 * @version 1.0
 */
public class Simplex {
    
  /**
   * Обчислення max c(x), при A*x менших(рівних) b, x - відмінні від нуля 
   * @param A матриця обмежень
   * @param b стовбець вільних членів
   * @param c стовбець коефіцієнтів функціі
   * @param x стовбець розв'язків
   * @return Максимальне значення функціі
   */  
  public static Rational simplex(Rational[][] A, Rational[] b, Rational[] c, Rational[] x) {
    int m = A.length;
    int n = A[0].length + 1;
    int[] index = new int[n + m];
    for (int i = 0; i < n + m; i++) {
      index[i] = i;
    }
    Rational[][] a = new Rational[m + 2][n + 1];
    for (Rational[] a1 : a) {
      Arrays.fill(a1, Rational.ZERO);
    }
    int L = m;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n - 1; j++) {
        a[i][j] = A[i][j].negate();
      }
      a[i][n - 1] = Rational.ONE;
      a[i][n] = b[i];
      if (a[L][n].compareTo(a[i][n]) > 0) {
        L = i;
      }
    }
    for (int j = 0; j < n - 1; j++) {
      a[m][j] = c[j];
    }
    a[m + 1][n - 1] = Rational.ONE.negate();
    for (int E = n - 1;;) {
      if (L < m) {
        int t = index[E];
        index[E] = index[L + n];
        index[L + n] = t;
        a[L][E] = a[L][E].reciprocal();
        for (int j = 0; j <= n; j++) {
          if (j != E) {
            a[L][j] = a[L][j].times(a[L][E].negate());
          }
        }
        for (int i = 0; i <= m + 1; i++) {
          if (i != L) {
            for (int j = 0; j <= n; j++) {
              if (j != E) {
                a[i][j] = a[i][j].plus(a[L][j].times(a[i][E]));
              }
            }
            a[i][E] = a[i][E].times(a[L][E]);
          }
        }
      }
      E = -1;
      for (int j = 0; j < n; j++) {
        if (E < 0 || index[E] > index[j]) {
          if (a[m + 1][j].toDouble() > 0 || a[m + 1][j].toDouble() == 0 && a[m][j].toDouble() > 0) {
            E = j;
          }
        }
      }
      if (E < 0) {
        break;
      }
      L = -1;
      for (int i = 0; i < m; i++) {
        if (a[i][E].toDouble() < 0) {
          Rational d;
          if (L < 0 || (d = a[L][n].divides(a[L][E]).minus(a[i][n].divides(a[i][E]))).toDouble() < 0 || d.toDouble() == 0
              && index[L + n] > index[i + n]) {
            L = i;
          }
        }
      }
      if (L < 0) {
        return Rational.POSITIVE_INFINITY;
      }
    }
    if (a[m + 1][n].toDouble() < 0) {
      return null;
    }
    if (x != null) {
      Arrays.fill(x, Rational.ZERO);
      for (int i = 0; i < m; i++)
        if (index[n + i] < n - 1)
          x[index[n + i]] = a[i][n];
    }
    return a[m][n];
  }

  /**
   * Приклад розв'язку
   * @param args командна строка
   */
  public static void main(String[] args) {
      
    System.out.println("================================== Варіант 4");  
    long[][] a;
    long[] b;
    long[] c;
    
    a = new long[][] { { 1, 1, 1, 1, -1, -1 }, { 0, 1, 1, -1, -1, -1 }, 
                { 0, 1, 0, 0, 0, -1 } };
    b = new long[] { 1, 1, 2 };
    c = new long[] { 1, 0, 1, 0, 0, 1 };    
    
    Rational[] x = new Rational[c.length];
    Rational res = simplex(cnv(a), cnv(b), cnv(c), x);
    System.out.println(Arrays.toString(x));

    System.out.println("Інші приклади:");  
    System.out.println("=============================================");  
    a = new long[][] { { 3, 4, -3 }, { 5, -4, -3 }, { 7, 4, 11 } };
    b = new long[] { 23, 10, 30 };
    c = new long[] { -1, 1, 2 };
    x = new Rational[c.length];
    res = simplex(cnv(a), cnv(b), cnv(c), x);
    System.out.println(new Rational(57, 8).equals(res));
    System.out.println(Arrays.toString(x));

    System.out.println("=============================================");  
    // нема допустимих рішень розв'язків (в розвязку присутні штучні змінні)
    a = new long[][] { { 4, -1 }, { 2, 1 }, { -5, 2 } };
    b = new long[] { 8, -10, 2 };
    c = new long[] { 1, 1 };
    res = simplex(cnv(a), cnv(b), cnv(c), null);
    System.out.println(null == res);

    
    System.out.println("============================================="); 
    //Останній рядок містить від'ємні елементи. Простір допустимих рішень необмежено. Рішення не існує.
    a = new long[][] { { -4, 1 }, { -2, -1 }, { -5, 2 } };
    b = new long[] { -8, -10, 2 };
    c = new long[] { 1, 1 };
    res = simplex(cnv(a), cnv(b), cnv(c), null);
    System.out.println(Rational.POSITIVE_INFINITY == res);

    System.out.println("=============================================");  
    // нема допустимих рішень
    a = new long[][] { { 1 }, { -1 } };
    b = new long[] { 1, -2 };
    c = new long[] { 0 };
    res = simplex(cnv(a), cnv(b), cnv(c), null);
    System.out.println(null == res);

    System.out.println("=============================================");  
    // безліч розв'язків
    a = new long[][] { { 1, 1 } };
    b = new long[] { 0 };
    c = new long[] { 1, 1 };
    x = new Rational[c.length];
    res = simplex(cnv(a), cnv(b), cnv(c), x);
    System.out.println(Arrays.toString(x));
  }
        
        
  //створення одновимірного масиву дробів
  public static Rational[] cnv(long[] a) {
    Rational[] res = new Rational[a.length];
    for (int i = 0; i < a.length; i++) {
      res[i] = new Rational((int) a[i]);
    }
    return res;
  }
  
  //створення двовимірного масиву дробів
  public static Rational[][] cnv(long[][] a) {
    Rational[][] res = new Rational[a.length][];
    for (int i = 0; i < a.length; i++) {
      res[i] = cnv(a[i]);
    }
    return res;
  }
}