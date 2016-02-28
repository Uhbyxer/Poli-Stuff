/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.grynchuk.source;

import java.util.*;
import java.util.*;

/**
 *
 * @author Taras
 */
public class Test {
    private final String name;
    private int answer = 0;
    
    public void setAnswer(int answer) {
        this.answer = answer;
    }
    
    @Override
    public String toString() {
        return name + "Варіант: " + answer + ". Бали: " + getResult();
    }
    
    private final HashMap<Integer,Integer> variants;
    
    public int getResult() {
        return variants.getOrDefault(answer, 0);
    }
    
    public Test(String name, int ... vars) {
        this.name = name;
        variants = new HashMap<>();
        int n = 0;
        for(int i: vars) 
            variants.put(n++, i);
    }
    
    public static String stringAnswer(int sum) {
        if (sum >= 8 && sum <= 13) return " Від 8 до 13 балів.\n Ваша поведінка залежить передусім від тих, хто вас оточує.\n Ви легко занепадаєте духом, легко вибухаєте, неохоче робите те, що вам не до вподоби.\n На вас справляє сильний вплив оточення, мікроклімат у колективі.\n Отже, ви не є господарем своїх рішень.\n Ви надто емоційні, і ваші вчинки залежать здебільшого від вашого настрою";
        if (sum >= 14 && sum <= 20) return " Від 14 до 20 балів.\n Хоча й пливете за течією, але намагаєтесь знайти свій стиль.\n Здатні до критичного аналізу.\n Коли здоровий глузд підказує, що ваша позиція хибна, ви цілком спроможні від неї відмовитись.";
        if (sum >= 21 && sum <= 27) return " Від 21 до 27 балів .\n Вважаєте себе непогрішимим. І все ж, підпадаєте під сторонній вплив.\n Шукаєте золоту середину між власними переконаннями й тими вимогами, які ставить життя.\n Допомагає те, що ви інстинктивно обираєте правильний шлях.";
        if (sum >= 28 && sum <= 34) return  " Від 28 до 34 балів\n Вам нелегко відмовитись від своїх принципів.\n Що більше хтось намагається на вас тиснути, то сильніший опір ви чините.\n Однак за впертістю приховується не стільки впевненість, скільки страх пошитися в дурні.";
        return "Від 35 до 40 балів.\n Якщо вже щось спаде вам на думку, то ніхто вас не переконає у протилежному.\n Попри все йдете до своєї мети.\n Але той , хто вас добре знає, може вміло та непомітно скеровувати ваші вчинки.\n Тож чи не варто проявляти менше впертості і більше кмітливості?. ";        
        
    } 
    
}
