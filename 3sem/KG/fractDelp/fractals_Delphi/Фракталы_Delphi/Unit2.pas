unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, Spin,math;
const vr=1000;
type
  TForm2 = class(TForm)
    GroupBox1: TGroupBox;
    ComboBox1: TComboBox;
    Label5: TLabel;
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    SpinEdit3: TSpinEdit;
    Button3: TButton;
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ComboBox1Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  uk,par1,par2,par3:integer;
  global_uk:integer;

  procedure ris3(ss:integer;k1:integer;k2:integer);
  procedure ris4(ss:integer;v:integer);
  procedure ris1(RR1:integer;RR:integer;k1:integer);

implementation

uses Unit4, Unit1, Unit5, Unit3;

{$R *.DFM}

function par_step(parametr:real;stepen:real):real;
begin
if parametr=0 then parametr:=0.0000001;
if parametr<0 then parametr:=abs(parametr);
 Result:=exp(stepen*ln(parametr));
end;

procedure ris3(ss:integer;k1:integer;k2:integer);
var
 red,green,blue,xx,yy,i,x,y,r1:integer;
 r,fi,qx,qy:real;
begin
 form1.F3.Enabled:=True;
 form1.F5.Enabled:=True;
 form1.P2.Enabled:=True;
 global_uk:=2;
 Parametr1:=ss;
 Parametr2:=k1;
 Parametr3:=k2;
 form1.Image1.Repaint;
 form1.SetFocus;
 randomize;
 x:=0;
 y:=0;
 xx:=form1.Image1.Width;
 yy:=form1.Image1.Height;
 form1.ProgressBar1.Max:=yy;
  for i:=1 to k2 do
   begin
    if uk=3 then
     begin
       r1:=random(60);
       r:=k1*random(r1)*76*i;
     end
      else
       r:=k1;
    fi:=pi/xx*2+0.001;
      while (y <= yy) do
       begin
         while (x <= xx) do
          begin
           if uk=1 then
            begin
             qx:=r*(sin(fi*x*y/500)-0.5*sin(1.95*fi*y));
             qy:=r*(sin(fi*y*x/500)-1.5*sin(1.85*fi*x));
            end
             else
            begin
             qy:=r*(sin(fi*x*y/500)-0.5*sin(1.95*fi*y));
             qx:=r*(sin(fi*y*x/500)-1.5*sin(1.85*fi*x));
            end;
            red:=round(abs(qx)) mod 255;
            green:=round(abs(qx+qy)) mod 255;
            blue:=round(abs(qx)) mod 255;
            form1.Image1.Canvas.Brush.Color:=RGB(red,green,blue);
              if ss>1 then
                form1.Image1.Canvas.Rectangle(x,y,x-ss,y-ss);
              if ss=1 then
                form1.Image1.Canvas.Pixels[x,y]:=RGB(red,green,blue);
           x:=x+ss;
          end;
        x:=1;
        y:=y+ss;
        form1.ProgressBar1.Position:=y;
      end;
   end;
 form1.ProgressBar1.Position:=0;
end;

procedure ris4(ss:integer;v:integer);
var
 red,green,blue,xx,yy,i,r1,x,y,q,k,r2:integer;
 xc,yc:array[1..vr] of integer;
 r:array[1..vr] of real;
 j:real;
begin
 form1.F3.Enabled:=True;
 form1.F5.Enabled:=True;
 form1.P2.Enabled:=True;
 global_uk:=3;
 Parametr1:=ss;
 Parametr2:=v;
 form1.Image1.Repaint;
 form1.SetFocus;
 randomize;
 xx:=form1.Image1.Width;
 yy:=form1.Image1.Height;
 form1.ProgressBar1.Max:=xx;
  for i:=1 to v do
   begin
    r1:=random(790);
    r2:=random(545);
    xc[i]:=random(r1)+1;
    yc[i]:=random(r2)+1;
   end;
   x:=0;
   y:=0;
    while (x<=xx) do
     begin
      while (y<=yy) do
       begin
         for q:=1 to v do
          if uk=1 then
           r[q]:=par_step((sqr(xc[q]-x)+sqr(yc[q]-y)),0.5)
            else
             r[q]:=par_step((sqr(xc[q]-x)+sqr(yc[q]-y)),0.7);
          j:=r[1];
          for k:=2 to v do
             if j > r[k] then
               j:=r[k];
         red:=255-round(j);
         green:=255-round(j*1.3);
         blue:=255-round(j*1.1);
          if red<0 then red:=0;
          if green<0 then green:=0;
          if blue<0 then blue:=0;
         if ss>1 then
          begin
           form1.image1.Canvas.Brush.Color:=RGB(red,green,blue);
           form1.Image1.Canvas.Rectangle(x,y,x-ss,y-ss);
          end;
          if ss=1 then
           form1.Image1.Canvas.Pixels[x,y]:=RGB(red,green,blue);
        y:=y+ss;
       end;
        y:=1;
        x:=x+ss;
        form1.ProgressBar1.Position:=x;
     end;
 form1.ProgressBar1.Position:=0;
end;

procedure ris1(RR1:integer;RR:integer;k1:integer);
var
 red,green,blue,xx,yy:integer;
 i,j,t,s,z,rr0,x,y,x1,y1,x2,y2,pp:real;
begin
 form1.F3.Enabled:=True;
 form1.F5.Enabled:=True;
 form1.P2.Enabled:=True;
 global_uk:=1;
 Parametr1:=RR1;
 Parametr2:=RR;
 Parametr3:=k1;
 form1.Image1.Repaint;
 form1.SetFocus;
 randomize;
 form1.ProgressBar1.Max:=360;
 xx:=round(form1.Image1.Width/2);
 yy:=round(form1.Image1.Height/2);
 i:=0;
 j:=0;
  while (i<=360) do
   begin
    while (j<=360) do
     begin
      t:=i*pi/180;
      s:=j*pi/180;
       case uk of
         1:RR0:=RR1;
         2:RR0:=RR1+k1*sqr(sin(2*t));
         3:RR0:=RR1;
         4:RR0:=RR1+k1*sqr(sin(7*t))+k1*par_step(sin(8*s),14)*par_step(sin(16*t),14);
         5:RR0:=RR1+k1*sqr(sin(2*t))+k1*par_step(sin(8*s),24)*par_step(sin(16*t),24);
       end;
      X:=RR*cos(t)+RR0*cos(s);
      Y:=RR0*sin(s);
       if uk = 1 then pp:=t
        else  pp:=2*t;
      z:=RR*sin(pp)+RR0*cos(s);
      X1:=X-z*cos(pi/3)*0.5;
      Y1:=Y-z*sin(pi/3)*0.5;
      red:=round(255*RR0/(RR1+60));
      green:=round(255*i/10) mod 255;
      blue:=round(0.1*i*j) mod 255;
      form1.image1.Canvas.MoveTo(round(X1+xx),round(Y1+yy));
      form1.image1.Canvas.Pen.Color:=RGB(red,green,blue);
       if i<>0 then
      form1.image1.Canvas.LineTo(round(X2+xx),round(Y2+yy));
      X2:=X1;
      Y2:=Y1;
      j:=j+2;
     end;
     j:=0;
     i:=i+0.5;
     form1.ProgressBar1.Position:=trunc(i);
   end;
 form1.ProgressBar1.Position:=0;
end;


procedure TForm2.Button2Click(Sender: TObject);
begin
  form2.Close;
end;

procedure TForm2.Button3Click(Sender: TObject);
begin
  form2.Visible:=false;
  form4.Visible:=true;
end;

procedure TForm2.Button1Click(Sender: TObject);
begin
  form2.Visible:=False;
  par1:=Spinedit1.Value;
  par2:=Spinedit2.Value;
  par3:=Spinedit3.Value;
  case Combobox1.Itemindex of
   0:begin uk:=1;form1.Panel3.Caption:='Тор';form1.Panel3.Repaint;ris1(par1,par2,par3);end;
   1:begin uk:=2;form1.Panel3.Caption:='Гантели';form1.Panel3.Repaint;ris1(par1,par2,par3);end;
   2:begin uk:=3;form1.Panel3.Caption:='Восьмёрка';form1.Panel3.Repaint;ris1(par1,par2,par3);end;
   3:begin uk:=4;form1.Panel3.Caption:='Гирлянда';form1.Panel3.Repaint;ris1(par1,par2,par3);end;
   4:begin uk:=5;form1.Panel3.Caption:='Гусеница';form1.Panel3.Repaint;ris1(par1,par2,par3);end;
   5:begin uk:=1;form1.Panel3.Caption:='Фантазия1';form1.Panel3.Repaint;ris3(par1,par3,1);end;
   6:begin uk:=2;form1.Panel3.Caption:='Фантазия2';form1.Panel3.Repaint;ris3(par1,par3,1);end;
   7:begin uk:=3;form1.Panel3.Caption:='Фантазия3';form1.Panel3.Repaint;ris3(par1,par3,par2);end;
   8:begin uk:=1;form1.Panel3.Caption:='Пена';form1.Panel3.Repaint;ris4(par3,par1);end;
   9:begin uk:=2;form1.Panel3.Caption:='Пузыри';form1.Panel3.Repaint;ris4(par3,par1);end;
  end;
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
     Combobox1.Itemindex:=0;
     label1.Caption:='Радиус малого круга-RR1 (1...1000)';
     label2.Caption:='Радиус большого круга-RR (1..1000)';
     label3.Caption:='Коэфф. искажения при-RR0 (1..1000)';
     Spinedit1.MaxValue:=1000;
     Spinedit1.MinValue:=1;
     Spinedit1.Value:=60;
     Spinedit2.MaxValue:=1000;
     Spinedit2.MinValue:=1;
     Spinedit2.Value:=240;
     Spinedit3.MaxValue:=1000;
     Spinedit3.MinValue:=1;
     Spinedit3.Value:=60;
     par1:=Spinedit1.Value;
     par2:=Spinedit2.Value;
     par3:=Spinedit3.Value;
end;

procedure TForm2.ComboBox1Click(Sender: TObject);
begin
  if     (Combobox1.Itemindex=8)
      or (Combobox1.Itemindex=9)then
   begin
     label2.Visible:=false;
     Spinedit2.Visible:=false;
     label3.Caption:='Размер зерна-SS (1..100)';
     label1.Caption:='Количество пузырей-V (1..1000)';
     Spinedit1.MaxValue:=1000;
     Spinedit1.MinValue:=1;
     Spinedit1.Value:=5;
     Spinedit3.MaxValue:=100;
     Spinedit3.MinValue:=1;
     Spinedit3.Value:=1;
     par3:=Spinedit3.Value;
     par1:=Spinedit1.Value;
   end;
  if   Combobox1.Itemindex=7 then
    begin
     label2.Visible:=true;
     spinedit2.Visible:=true;
     label1.Caption:='Размер зерна-SS (1..100)';
     label2.Caption:='Вариант-i (2..30)';
     label3.Caption:='Расцветка-r (1..600)';
     Spinedit1.MaxValue:=100;
     Spinedit1.MinValue:=1;
     Spinedit1.Value:=1;
     Spinedit2.MaxValue:=30;
     Spinedit2.MinValue:=2;
     Spinedit2.Value:=5;
     Spinedit3.MaxValue:=600;
     Spinedit3.MinValue:=1;
     Spinedit3.Value:=282;
     par3:=Spinedit3.Value;
     par2:=Spinedit2.Value;
     par1:=Spinedit1.Value;
    end;
  if     (Combobox1.Itemindex=0)
      or (Combobox1.Itemindex=1)
      or (Combobox1.Itemindex=2)
      or (Combobox1.Itemindex=3)
      or (Combobox1.Itemindex=4)then
   begin
     label2.Visible:=true;
     spinedit2.Visible:=true;
     label1.Caption:='Радиус малого круга-RR1 (1...1000)';
     label2.Caption:='Радиус большого круга-RR (1..1000)';
     label3.Caption:='Коэф. искажения при-RR0 (1..1000)';
     Spinedit1.MaxValue:=1000;
     Spinedit1.MinValue:=1;
     Spinedit1.Value:=60;
     Spinedit2.MaxValue:=1000;
     Spinedit2.MinValue:=1;
     Spinedit2.Value:=240;
     Spinedit3.MaxValue:=1000;
     Spinedit3.MinValue:=1;
     Spinedit3.Value:=60;
     par1:=Spinedit1.Value;
     par2:=Spinedit2.Value;
     par3:=Spinedit3.Value;
   end;
  if    (Combobox1.Itemindex=5)
     or (Combobox1.Itemindex=6)then
   begin
     label2.Visible:=false;
     spinedit2.Visible:=false;
     label1.Caption:='Размер зерна-SS (1..100)';
     label3.Caption:='Расцветка-r (1..600)';
     Spinedit1.MaxValue:=100;
     Spinedit1.MinValue:=1;
     Spinedit1.Value:=1;
     Spinedit3.MaxValue:=600;
     Spinedit3.MinValue:=1;
     Spinedit3.Value:=282;
     par3:=Spinedit3.Value;
     par1:=Spinedit1.Value;
   end;
end;

procedure TForm2.FormResize(Sender: TObject);
begin
  form2.Width:=496;
  form2.Height:=320;
end;

end.
