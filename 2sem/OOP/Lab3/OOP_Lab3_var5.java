/**
 * �/� � 3 (������ 5)
 * �����������. ��������� �� ������������ �������� �����.
 * @author Taras
 */

package lab3_oop;
import java.util.*;

/* -----------------------------------------------------------------------------
 * ���� ˳������� �����������㳿 - �������� �-��� ������������ ���*���
 * ��� ����� ���������������, � ��������� �� ���� ������
 * �� �� ���������. 
 * ���� �� ���� ���� ��������� � ����������� "�� ������", ���������� �� ���
 * ������� ������ (Singleton) 
 */
class ElectricityCounter {
    public static ElectricityCounter value() {
        return ec;
    }
    
    //��������� ���������
    public void add(double kilowatts, double hours) {
        kilowattHours += kilowatts * hours;
    }
    //�������� �������� ����
    public double indicate() {
        return kilowattHours;
    }
    private double kilowattHours = 0;
    //��������� �����������, �������� ����������� ����� ����� ��������� ������
    private ElectricityCounter() {} 
    private static ElectricityCounter ec = new ElectricityCounter();
}

/* -----------------------------------------------------------------------------
 * ���� ����� - ������� � ����� ������� ���������� ��������
 */
class Engine { 
    //���������
    public double power;
    //�����������
    public Engine(double power) {
        this.power = power;
    }
    //������
    public void start() {
        System.out.println("Start engine...");
    }
    //���������� ������
    public void stop() {
        System.out.print("Stop engine.");
    }
}

/* -----------------------------------------------------------------------------
 * ����������� ���� ��������� �������� - ����������� ��� ��� �����
 */
abstract class Appliance {
    //����-��������������
    protected String type; //���
    private String manufacturer; //��������
    private String model; //������
    private Engine eng; //�����

    //�����������
    public Appliance(double power, String type, String manufacturer, String model) {
        eng = new Engine(power);
        this.type = type;
        this.manufacturer = manufacturer;
        this.model = model;
    }
    //�������������� ������������ ������ Object.toString() - �������������
    //��� ��������� �� ����� ����� ��'���� � ���� ����������������
    @Override
    public String toString() {
        return type + ": " + manufacturer + " " + model + " / " + eng.power + " kWt"; 
    }
    //������ ��������
    public void start() {
        eng.start();
    } 
    //��������� ��������
    public void stop(double hours) {
        eng.stop();
        System.out.println(" Time of work: " + hours + " hours.");
        ElectricityCounter.value().add(eng.power, hours);
    }
    //����������� (����������) �����. ����������� ��� ������� ���� 
    //���������� �������� ��-������
    abstract void work();
}

/* -----------------------------------------------------------------------------
 * ���� ������ ������� - ������� �� ��������� ��������
 * ��������������� ��� ���������� ���������� ������������ �����
 */
abstract class ServiceEquipment  extends Appliance {
    //�����������
    public ServiceEquipment(double power, String type, String manufacturer, String model) {
        //������ ������������ ������������ �����
        super(power, type, manufacturer, model);
    }
    //"������� ������� ���� ������"
    //����������� (����������) �����, ��� ������� ����������� ����
    //������� ������, ����������� ���� ��������� ����� ������
    abstract void CleanItself();
}

/* -----------------------------------------------------------------------------
 * ���� ������������(�����������) ������ - ������� �� ��������� ��������
 * ��������������� ��� ���������� ���������� ������������ �����
 */
abstract class InformationalTechnics extends Appliance {
    //����� �����
    private int volumeLevel;
    
    //�����������
    public InformationalTechnics(double power, String type, String manufacturer, String model) {
        //������ ������������ ������������ �����
        super(power, type, manufacturer, model);
        //��������� �������� ���� �����
        volumeLevel = 10;
    }
    //������������ ���� �����
    public void setVolumeLevel(int volumeLevel) {
        this.volumeLevel = volumeLevel;
    }
}

/* -----------------------------------------------------------------------------
 * ���� ������� ������ - ������� �� �������� �������
 */
class WashingMachine extends ServiceEquipment {
    //������� ���� � �����
    private int waterTankCapacity;

    //�����������
    public WashingMachine(double power, String manufacturer, String model, int waterTankCapacity) {
        //������ ������������ ������������ �����
        super(power, "Washing machine", manufacturer, model);
        this.waterTankCapacity = waterTankCapacity;
    }
    //�� ������������ ������������� ����� ������ �� ������� ����
    @Override
    public String toString() {
        return super.toString() + " / " + waterTankCapacity + " Liters"; 
    }
    //������
    public void wash() {
        System.out.println("Washing...");
    }
    //������������
    public void squeeze() {
        System.out.println("Squeezing...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        wash();
        squeeze();
    }
    //��������� ����������� ������ ����� �������� �������
    @Override
    public void CleanItself() {
        //������� ���� � �����
        System.out.println("Cleaning water from the tank.");
    }
}
 
/* -----------------------------------------------------------------------------
 * ���� ������� - ������� �� �������� �������
 */
class VacuumCleaner extends ServiceEquipment{
    //������� ������
    private int cordLength;
    
    //�����������
    public VacuumCleaner(double power, String manufacturer, String model, int cordLength) {
        //������ ������������ ������������ �����
        super(power, "Vacuum cleaner", manufacturer, model);
        this.cordLength = cordLength;
    }
    //�� ������������ ������������� ����� ������ �� ������� ������
    @Override
    public String toString() {
        return super.toString() + " / " + cordLength + " meters"; 
    }
    //����� "����������"
    public void clean() {
        System.out.println("Cleaning...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        clean();
    }
    //��������� ����������� ������ ����� �������� �������
    @Override
    public void CleanItself() {
        //�������� ���� � ������
        System.out.println("Cleaning garbage collector.");
    }
}

/* -----------------------------------------------------------------------------
 * ���� ���� - ������� �� ������������ ������ 
 */
class Radio extends InformationalTechnics {
    //������� �����
    private String frequencyRange;
 
    //�����������
    public Radio(double power, String manufacturer, String model, String frequencyRange) {
        //������ ������������ ������������ �����
        super(power, "Radio", manufacturer, model);
        this.frequencyRange = frequencyRange;
    }
    //�� ������������ ������������� ����� ������ �� ������� �����
    @Override
    public String toString() {
        return super.toString() + " / " + frequencyRange; 
    }
    //���������� ���������
    public void playRadio() {
        System.out.println("Playing radio...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        playRadio();
    }
}

/* -----------------------------------------------------------------------------
 * ���� �������� - ������� �� ������������ ������ 
 */
class TV extends InformationalTechnics {
    //������� ������� � ������
    private int diagonal;
    
    //�����������
    public TV(double power, String manufacturer, String model, int diagonal) {
        //������ ������������ ������������ �����
        super(power, "TV-set", manufacturer, model);
        this.diagonal = diagonal;
    }
    //�� ������������ ������������� ����� ������ �� ������� �������
    @Override
    public String toString() {
        return super.toString() + " / " + diagonal + " inch"; 
    }
    //�������� ���������
    public void playTV() {
        System.out.println("Playing TV channel...");
    }
    //���������
    public void displayTeleText() {
        System.out.println("Displaying teletext...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        playTV();
        displayTeleText();
    }
}

/* -----------------------------------------------------------------------------
 * ���� ��������� - ������� �� ����
 */
class TapeRecorder extends Radio {
    //������� ���������
    private int cassetteNumber;

    //�����������
    public TapeRecorder(double power, String manufacturer, String model,String frequencyRange, int cassetteNumber) {
        //������ ������������ ������������ �����
        super(power, manufacturer, model, frequencyRange);
        //������������ ��� �� ��������
        type = "Tape recorder";
        this.cassetteNumber = cassetteNumber;
    }
    //�� ������������ ������������� ����� ������ �� ������� ���������
    @Override
    public String toString() {
        return super.toString() + " / " + cassetteNumber + " tape(s)"; 
    }
    //���������� ����� �� �����
    public void playTapes() {
        System.out.println("Playing tapes...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        //�������� ��������� ����������� ����������
        super.work();
        playTapes();
    }
}

/* -----------------------------------------------------------------------------
 * ���� �������� ����� - ������� �� ���������
 */
class StereoSystem extends TapeRecorder {
    //������� ����� ��� �����
    private int cdNumber;

    //�����������
    public StereoSystem(double power, String manufacturer, String model, String frequencyRange, int cassetteNumber,
            int cdNumber) {
        //������ ������������ ������������ �����
        super(power, manufacturer, model, frequencyRange, cassetteNumber);
        //������������ ��� �� ��������
        type = "Stereo system";
        this.cdNumber = cdNumber;
    }
    //�� ������������ ������������� ����� ������ �� ������� �D-�����
    @Override
    public String toString() {
        return super.toString() + " / " + cdNumber + " cd's"; 
    }
    //���������� CD-���� 
    public void playCD() {
        System.out.println("Playing cd's...");
    }
    //��������� ����������� ������ ����� ��������� ��������
    @Override
    public void work() {
        //�������� ��������� ����������� ����������
        super.work();
        playCD();
    }
}

/* =============================================================================
 * �������� ���� ������ 
 */
public class Lab3_OOP {
    public static void main(String[] args) {
        
        //��������� ������ ��������� ��������
        Appliance[] app = {
            new WashingMachine(0.95, "Bosch", "WAB 20071 CE", 42),
            new VacuumCleaner(0.25, "Philips", "FC 9174", 9),
            new Radio(0.01, "LG", "SP820", "AM+FM"), 
            new TV(0.1, "Sony", "KDL-42W807", 42),
            new TapeRecorder(0.05, "Pioneer", "BDP-150", "FM", 2),
            new StereoSystem(0.12, "Sharp", "GX-M10HOR", "AM+FM", 1, 4)
        };
        
        //��������� ���������� ������� ��� �������� ���� ������ ��������
        Calendar c = Calendar.getInstance(); 
        Random rand = new Random(c.getTimeInMillis());
        
        //����� ������ ��������
        for(Appliance a : app) {
            System.out.println("================================================================");
            System.out.println(a);
            //�������� �������
            a.start();
            //���������� ���� ���������� ��������
            a.work();     
            //���������
            //���� ����������� ��������� �-�� ����� � ������ ����
            a.stop(rand.nextInt(24) + 1); 
            //���� ������� �������� �� ���� ��������, 
            //�������� ���� ���� ������
            if(a instanceof ServiceEquipment)
                ((ServiceEquipment) a).CleanItself();
            //�������� �������� ���� ���������� ��������� �����������㳿
            System.out.println("----------------------------------------------------------------");
            System.out.println("Electricity counter: " 
                    + ElectricityCounter.value().indicate() + " kWt*hrs");
       }
    }
}