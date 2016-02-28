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

//класифікатор симптомів (синглтон)
public class ListOfSympthoms extends ArrayList<Symptoms> {
    private static final ListOfSympthoms list;
    
    static {
        list =  new ListOfSympthoms();
        list.add(new Symptoms("Температура"));
        list.add(new Symptoms("Нежить"));
        list.add(new Symptoms("Кашель"));
        list.add(new Symptoms("Біль горла"));
        list.add(new Symptoms("Збільшення підчелюсних залоз"));
        list.add(new Symptoms("Віддих"));
        list.add(new Symptoms("Різна висипка"));
        list.add(new Symptoms("Тошнота рвота"));
        list.add(new Symptoms("Опухлість завушних залоз"));
        list.add(new Symptoms("Болі в животі"));
        list.add(new Symptoms("Розлади кишківника"));
        list.add(new Symptoms("Пожовтіння шкіри"));
        list.add(new Symptoms("Головний біль"));
        list.add(new Symptoms("Озноб"));
        list.add(new Symptoms("Світлобоязнь"));
    }
    
    private ListOfSympthoms() {}
    
    public static ListOfSympthoms getList() {
        return list;
    }
}

