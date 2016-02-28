/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package _shi_lab2.source;

/**
 *
 * @author Taras
 */
public class Symptoms {
    private static int count;
    private final int id = count++;
    private final String name;
    
    @Override
    public String toString() {
        return name;
    }
    
    public int getID() {
        return id;
    }

    public Symptoms(String name) {
        this.name = name;
    }
    
}
