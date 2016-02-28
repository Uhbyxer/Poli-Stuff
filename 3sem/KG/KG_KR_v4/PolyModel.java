/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package polymodel;


//Клас грань
/**
 *
 * @author Taras
 */
public class PolyModel {

    public Point[] points = {new Point(), new Point(), new Point(),
    new Point(), new Point(), new Point()};
   
    public Border[] borders = {new Border(4), new Border(4), new Border(4),
    new Border(3), new Border(3)};

    public PolyModel() {
        borders[0].pointID[0] = 0;
        borders[0].pointID[1] = 1;
        borders[0].pointID[2] = 2;
        borders[0].pointID[3] = 3;
        
        borders[1].pointID[0] = 0;
        borders[1].pointID[1] = 1;
        borders[1].pointID[2] = 4;
        borders[1].pointID[3] = 5;        

        borders[2].pointID[0] = 3;
        borders[2].pointID[1] = 2;
        borders[2].pointID[2] = 4;
        borders[2].pointID[3] = 5;        
        
        borders[3].pointID[0] = 0;
        borders[3].pointID[1] = 5;
        borders[3].pointID[2] = 3;
             
        borders[4].pointID[0] = 1;
        borders[4].pointID[1] = 4;
        borders[4].pointID[2] = 2;
        
        for(Border b: borders) System.out.println(b);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        new PolyModel();
    }
}

//Клас Вершина

//Клас Вершина
class Border {
    public static int count;
    public int id;
    
    public int numberOfPoints; //К-сть вершин
    public int[] pointID; //масив номерів вершин

    public Border(int numberOfPoints) {
        this.numberOfPoints = numberOfPoints;
        id = count++;
        pointID = new int[numberOfPoints];
    }

    @Override
    public String toString() {
        String res = "";
        
        for (int p: pointID) {
            if (res.length() != 0) res += ", ";
            res += p;
        }
        
        return "Границя № " + id + " = (" + res + ")"; 
    }
}  

//Клас Вершина
class Point {
    public static int count; 
    public int id;
    public int x, y, z;

    public Point() {
        id = count++;
    }
}
