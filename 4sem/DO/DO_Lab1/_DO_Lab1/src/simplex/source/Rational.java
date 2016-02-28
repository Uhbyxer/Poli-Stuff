
package simplex.source;

/**
 * <b>Клас для роботи з раціональними числоми у вигляді дробів</b>
 */

public class Rational implements Comparable<Rational> {
    
    /**
     * <i>Нуль у вигляды дробу</i>
     * @see ONE
     * @see POSITIVE_INFINITY
     */
    public static final Rational ZERO = new Rational(0, 1);
    
    /**
     * <i>Одиниця у вигляды дробу</i>
     */
    public static final Rational ONE = new Rational(1, 1);
    
    /**
     * <i>Додатня нескінченність у вигляды дробу</i>
     */
    public static final Rational POSITIVE_INFINITY = new Rational(1, 0);

    private int num;   // чисельник
    private int den;   // знаменник

    /** <i>Конструктор створення дробу з чисельником та знаменником</i>
     * @param numerator  чисельник
     * @param denominator  значенник
    */
    public Rational(int numerator, int denominator) {
        // скорочення дробу
        int g = gcd(numerator, denominator);
        num = numerator   / g;
        den = denominator / g;
        // перенесення мінуса в чисельник
        if (den < 0) { den = -den; num = -num; }
    }
    
    /** <i>Конструктор створення дробу тільки за чисельником</i>
     * @param numerator  чисельник
    */    
    public Rational(int numerator) {
        this(numerator, 1);
    }

    /**
     * @return Чисельник 
     */
    public int numerator()   { return num; }
    
    /**
     * @return Знаменник 
     */
    public int denominator() { return den; }

    /**
     * <i>Переведення дробу в Double</i>
     * @return Десяткове представлення дробу
     */
    public double toDouble() {
        return (double) num / den;
    }

    /**
     * @return Представлення у вигляды строки 
     */
    @Override
    public String toString() { 
        if (den == 1) return num + "";
        else          return num + "/" + den;
    }
    
    /**
     * @param b інший дріб
     * @return -1, 0, +1  
     */
    @Override
    public int compareTo(Rational b) {
        Rational a = this;
        int lhs = a.num * b.den;
        int rhs = a.den * b.num;
        if (lhs < rhs) return -1;
        if (lhs > rhs) return +1;
        return 0;
    }

    /**
     * Чи даний дріб є рівний <b>y</b>
     * @param y інший дріб
     * @return true/false
     */
    @Override
    public boolean equals(Object y) {
        if (y == null) return false;
        if (y.getClass() != this.getClass()) return false;
        Rational b = (Rational) y;
        return compareTo(b) == 0;
    }

    /**
     * Пов'язано з перевизначенням equals
     * @see equals
     * @return Хеш-код дробу 
     */
    @Override
    public int hashCode() {
        return this.toString().hashCode();
    }

    /**
     * Створює новий дріб: (r.num + s.num) / (r.den + s.den)
     * @param r Чисельник
     * @param s Знаменник
     * @return Результуючий дріб
     */
    public static Rational mediant(Rational r, Rational s) {
        return new Rational(r.num + s.num, r.den + s.den);
    }
    
    /**
     * Найбільший спільний дільник
     * @param m перше число
     * @param n друге число
     * @return Найбільший спільний дільник двох чисел 
     */
    public static int gcd(int m, int n) {
        if (m < 0) m = -m;
        if (n < 0) n = -n;
        if (0 == n) return m;
        else return gcd(n, m % n);
    }

    /**
     * Найменше спільне кратне
     * @param m перше число
     * @param n друге число
     * @return Найменше спільне кратне двох чисел
     */
    public static int lcm(int m, int n) {
        if (m < 0) m = -m;
        if (n < 0) n = -n;
        return m * (n / gcd(m, n));    
    }
    
    /**
     * добуток a * b
     * @param b інший дріб
     * @return добуток двох дробів 
     */
    public Rational times(Rational b) {
        Rational a = this;
        Rational c = new Rational(a.num, b.den);
        Rational d = new Rational(b.num, a.den);
        return new Rational(c.num * d.num, c.den * d.den);
    }

    /**
     * сума a + b
     * @param b інший дріб
     * @return сума двох дробів 
     */
    public Rational plus(Rational b) {
        Rational a = this;

        if (a.compareTo(ZERO) == 0) return b;
        if (b.compareTo(ZERO) == 0) return a;
        int f = gcd(a.num, b.num);
        int g = gcd(a.den, b.den);
        Rational s = new Rational((a.num / f) * (b.den / g) + (b.num / f) * (a.den / g),
                                  lcm(a.den, b.den));
        s.num *= f;
        return s;
    }

    /**
     * -Дріб
     * @return дріб з мінусом 
     */
    public Rational negate() {
        return new Rational(-num, den);
    }

    /**
     * a - b
     * @param b інший дріб
     * @return різниця
     */
    public Rational minus(Rational b) {
        Rational a = this;
        return a.plus(b.negate());
    }

    /**
     * Обертання дробу
     * @return обернений дріб 
     */
    public Rational reciprocal() { return new Rational(den, num);  }

    /**
     * a / b
     * @param b інший дріб
     * @return часка з ділення
     */
    public Rational divides(Rational b) {
        Rational a = this;
        return a.times(b.reciprocal());
    }


    /**
     * тестування
     * @param args командна строка 
     */
    public static void main(String[] args) {
        Rational x, y, z;

        // 1/2 + 1/3 = 5/6
        x = new Rational(1, 2);
        y = new Rational(1, 3);
        z = x.plus(y);
        System.out.println(z);

        // 8/9 + 1/9 = 1
        x = new Rational(8, 9);
        y = new Rational(1, 9);
        z = x.plus(y);
        System.out.println(z);

        // 1/200000000 + 1/300000000 = 1/120000000
        x = new Rational(1, 200000000);
        y = new Rational(1, 300000000);
        z = x.plus(y);
        System.out.println(z);

        // 1073741789/20 + 1073741789/30 = 1073741789/12
        x = new Rational(1073741789, 20);
        y = new Rational(1073741789, 30);
        z = x.plus(y);
        System.out.println(z);

        //  4/17 * 17/4 = 1
        x = new Rational(4, 17);
        y = new Rational(17, 4);
        z = x.times(y);
        System.out.println(z);

        // 3037141/3247033 * 3037547/3246599 = 841/961 
        x = new Rational(3037141, 3247033);
        y = new Rational(3037547, 3246599);
        z = x.times(y);
        System.out.println(z);

        // 1/6 - -4/-8 = -1/3
        x = new Rational( 1,  6);
        y = new Rational(-4, -8);
        z = x.minus(y);
        System.out.println(z);
    }

}