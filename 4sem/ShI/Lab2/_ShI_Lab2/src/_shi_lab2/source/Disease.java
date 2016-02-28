/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package _shi_lab2.source;
import java.util.*;

/**
 *
 * @author Taras
 */
public class Disease {
    private final String name;
    public final Type type;
    public final HashMap<Symptoms, Integer> symptoms;
    
    public int getPoints(int pos) {
        return symptoms.getOrDefault(ListOfSympthoms.getList().get(pos), 0);
    }
            
    public Type getType() {
        return type;
    }
    
    @Override
    public String toString() {
        return name;
    }
    
    public Disease(String name, Type type, int ... symp) {
        this.name = name;
        this.type = type;
        
        symptoms = new HashMap<>(); int[] temp = new int[2]; int n = 0;
        for(int s: symp) {
            temp[n++] = s;
            if(n == 2) {
                symptoms.put(ListOfSympthoms.getList().get(temp[0]), temp[1]);
                n = 0;
            }
        }
    }
    
    public interface Type {
        @Override
        public String toString();
    }
    
    public static Type INFECT = new Type() {
        @Override
        public String toString() {
            return "Інфекційне захворювання";
        }
        
    };
    
    public static Type VIRUS = new Type() {
        @Override
        public String toString() {
            return "Вірусне захворювання";
        }
        
    };
    
    
}
