import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class RandGen {
	public static long a = (long)Math.pow(4, 5);
	public static long c = 2;
	public static long m = (long)Math.pow(2, 12) - 1;
	public static long x = 8;	
	
	public static long getRand() {
	    x = (long)(a * x + c) % m;
	    return x;
	}

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Count: ");
        if(!sc.hasNextInt()) { 
           // Якщо користувач ввів не ціле число виводимо відповідне повідомлення
           System.out.println("It's not integer value! Program terminate...");
           return;
        }		
		int count = sc.nextInt();
		List<Long> list = new ArrayList<Long>();
		
		int r = 0;
		
		for(int i = 0; i < count; i++) {
		    list.add(getRand());   
			System.out.println(list.get(i));
			if(i > 0 && r == 0 && list.get(i) == list.get(0)) r = i;
		}   
		saveToTextFile(list, "d:\\Numbers.txt");
		if(r==0) System.out.println("repeated numbers not found");
		else System.out.println("repeated number on position = " + r);
	}
	
    public static void saveToTextFile(List<Long> list, String fileName) {
        try {
            PrintWriter out = new PrintWriter(new File(fileName));
            try {
                for(Long l: list)
                    out.println(l.toString());
            } finally {
                out.close();
            }
        } catch(IOException ex) {
            throw new RuntimeException("Error saving file !");
        }
        System.out.println("\nSaved to file:\n" + fileName);
    }

    
}
