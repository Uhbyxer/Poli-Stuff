unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Menus, ExtCtrls, ComCtrls, ExtDlgs;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    F0: TMenuItem;
    V0: TMenuItem;
    P0: TMenuItem;
    PO0: TMenuItem;
    F1: TMenuItem;
    F2: TMenuItem;
    N9: TMenuItem;
    F4: TMenuItem;
    F5: TMenuItem;
    N11: TMenuItem;
    P2: TMenuItem;
    V1: TMenuItem;
    V2: TMenuItem;
    V3: TMenuItem;
    V4: TMenuItem;
    V5: TMenuItem;
    V6: TMenuItem;
    V7: TMenuItem;
    V8: TMenuItem;
    V9: TMenuItem;
    V10: TMenuItem;
    V11: TMenuItem;
    V12: TMenuItem;
    V13: TMenuItem;
    N15: TMenuItem;
    V14: TMenuItem;
    PO1: TMenuItem;
    N18: TMenuItem;
    PO2: TMenuItem;
    F6: TMenuItem;
    F3: TMenuItem;
    ScrollBox1: TScrollBox;
    Image1: TImage;
    Panel1: TPanel;
    ProgressBar1: TProgressBar;
    Panel2: TPanel;
    Panel3: TPanel;
    SaveDialog1: TSaveDialog;
    SavePictureDialog1: TSavePictureDialog;
    OpenDialog1: TOpenDialog;
    procedure F1Click(Sender: TObject);
    procedure F2Click(Sender: TObject);
    procedure F3Click(Sender: TObject);
    procedure F4Click(Sender: TObject);
    procedure F5Click(Sender: TObject);
    procedure F6Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure V2Click(Sender: TObject);
    procedure V1Click(Sender: TObject);
    procedure V3Click(Sender: TObject);
    procedure V4Click(Sender: TObject);
    procedure V5Click(Sender: TObject);
    procedure V6Click(Sender: TObject);
    procedure V7Click(Sender: TObject);
    procedure V8Click(Sender: TObject);
    procedure V9Click(Sender: TObject);
    procedure V10Click(Sender: TObject);
    procedure V11Click(Sender: TObject);
    procedure V12Click(Sender: TObject);
    procedure V13Click(Sender: TObject);
    procedure V14Click(Sender: TObject);
    procedure PO1Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure P2Click(Sender: TObject);
    procedure PO2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  Parametr1,parametr2,parametr3:integer;
  fon_uk:integer;
  uk_red,uk_blue,uk_green:integer;
  uk_iz_fon:boolean;
  procedure image_create;
  procedure center_image;
  procedure clear_image;
  procedure image_1(uk:boolean);
  procedure image_2(uk:boolean);
  procedure image_3(uk:boolean);
  procedure image_4(uk:boolean);

implementation

uses Unit2, Unit3, Unit5, Unit4;

{$R *.DFM}

procedure image_1(uk:boolean);
Var
  i,j,cx,cy,Value,i1,j1:integer;
begin
  fon_uk:=1;
Value:=5000;
 if uk then
  begin
   cx:= form1.Image1.Width div 2;
   cy:= form1.Image1.Height div 2;
   i1:=form1.Image1.Width-1;
   j1:=form1.Image1.Height-1;
  end
   else
  begin
   cx:= form4.Image1.Width div 2;
   cy:= form4.Image1.Height div 2;
   i1:=form4.Image1.Width-1;
   j1:=form4.Image1.Height-1;
  end;
for i:=0 to i1 do
  for j:=0 to j1 do
   if uk then
    SetPixel(form1.Image1.Canvas.Handle,i,j,
             trunc(Value
                   * sqrt(sqr(i-cx) + sqr(j-cy))
                   * (form1.Image1.Height - j)
                  )
            )
      else
       form4.image1.Canvas.Pixels[i,j]:=trunc(Value
                   * sqrt(sqr(i-cx) + sqr(j-cy))
                   * (form4.Image1.Height - j)
                  );
end;

procedure image_2(uk:boolean);
Var
  i,j,cx,cy,Value,i1,j1:integer;
begin
 fon_uk:=2;
Value:=11111;
 if uk then
  begin
   cx:= form1.Image1.Width div 2;
   cy:= form1.Image1.Height div 2;
   i1:=form1.Image1.Width-1;
   j1:=form1.Image1.Height-1;
  end
   else
  begin
   cx:= form4.Image1.Width div 2;
   cy:= form4.Image1.Height div 2;
   i1:=form4.Image1.Width-1;
   j1:=form4.Image1.Height-1;
  end;
for i:=0 to i1 do
  for j:=0 to j1 do
   if uk then
    SetPixel(form1.Image1.Canvas.Handle,i,j,
             trunc(Value
                   * sqrt(sqr(i-cx) + sqr(j-cy))
                  )
            )
      else
       form4.image1.Canvas.Pixels[i,j]:=trunc(Value
                   * sqrt(sqr(i-cx) + sqr(j-cy))
                  );
end;

procedure image_3(uk:boolean);
var
 i1,j1:integer;
begin
 fon_uk:=3;
 if uk then
  begin
   for i1:=0 to form1.Image1.Width do
     for j1:=1 to form1.Image1.Height do
       SetPixel(form1.Image1.Canvas.Handle,i1,j1,round(i1/j1)*clWhite);
  end
   else
  begin
   for i1:=0 to form4.Image1.Width do
     for j1:=1 to form4.Image1.Height do
       form4.Image1.Canvas.Pixels[i1,j1]:=round(i1/j1)*clWhite;
  end;
end;

procedure image_4(uk:boolean);
var
 i,j: integer;
 c1,c2: integer;
begin
 fon_uk:=4;
 if uk then
  begin
   c1 := form1.Image1.Width div 2;
   c2 := form1.Image1.Height div 2;
    for i := 0 to form1.Image1.Width do
     for j := 0 to form1.Image1.Height do
      SetPixel(form1.Image1.Canvas.Handle,i,j, round(sin(i-c1)*i+cos(j-c2)*j));
   end
    else
  begin
   c1 := form4.Image1.Width div 2;
   c2 := form4.Image1.Height div 2;
    for i := 0 to form4.Image1.Width do
     for j := 0 to form4.Image1.Height do
     form4.Image1.Canvas.Pixels[i,j]:=round(sin(i-c1)*i+cos(j-c2)*j);
   end;
end;

procedure clear_image;
begin
  form1.image1.Canvas.Brush.Color:=clBtnFace;
  form1.image1.Canvas.Rectangle(1,1,form1.Image1.Width,form1.Image1.Height);
end;

procedure TForm1.F1Click(Sender: TObject);
var
 f:Textfile;
begin
  // Открытие фрактала
    OpenDialog1.DefaultExt:='frc';
 if OpenDialog1.Execute then
   begin
      AssignFile(f,OpenDialog1.FileName);
      Reset(f);
      Readln(f,global_uk);
       if global_uk=3 then
        begin
         Readln(f,Parametr1);
         Readln(f,Parametr2);
        end
         else
        begin
         Readln(f,Parametr1);
         Readln(f,Parametr2);
         Readln(f,Parametr3);
        end;
       readln(f,fon_uk);
       if fon_uk=0 then
         begin
          readln(f,uk_red);
          readln(f,uk_green);
          readln(f,uk_blue);
         end;
      CloseFile(f);
     clear_image;
     if fon_uk=0 then
      begin
       form1.image1.Canvas.Brush.Color:=RGB(uk_red,uk_green,uk_blue);
       form1.image1.Canvas.Rectangle(1,1,form1.Image1.Width,form1.Image1.Height);
      end
       else
         if fon_uk=1 then
          image_1(True)
           else
            if fon_uk=2 then
              image_2(True)
                else
                 if fon_uk=3 then
                   image_3(True)
                     else
                      image_4(True);
          if global_uk=1 then
           ris1(parametr1,parametr2,parametr3);
          if global_uk=2 then
           ris3(parametr1,parametr2,parametr3);
          if global_uk=3 then
           ris4(parametr1,parametr2);
  end;         
end;

procedure TForm1.F2Click(Sender: TObject);
begin
 // Создание фрактала
  form2.Visible:=True;
end;

procedure TForm1.F3Click(Sender: TObject);
Var
 f:Textfile;

begin
  // Сохранить  фрактал
  SaveDialog1.DefaultExt:='frc';
  SaveDialog1.FileName:=Panel3.Caption;
    if SaveDialog1.Execute then
     begin
      AssignFile(f,SaveDialog1.FileName);
      Rewrite(f);
      writeln(f,global_uk);
       if global_uk=3 then
        begin
         writeln(f,parametr1);
         writeln(f,parametr2);
        end
         else
        begin
         writeln(f,parametr1);
         writeln(f,parametr2);
         writeln(f,parametr3);
        end;
       writeln(f,fon_uk);
       if fon_uk=0 then
         begin
          writeln(f,uk_red);
          writeln(f,uk_green);
          writeln(f,uk_blue);
         end;
      closeFile(f);
     end;
end;

procedure TForm1.F4Click(Sender: TObject);
begin
  // Очистить экран
  clear_image;
  panel3.Caption:='';
  form1.image1.Canvas.Brush.Color:=clBtnFace;
  form1.image1.Canvas.Rectangle(-1,-1,form1.Image1.Width+1,form1.Image1.Height+1);
  center_image;
  clear_image;
  F3.Enabled:=False;
  F5.Enabled:=False;
end;

procedure TForm1.F5Click(Sender: TObject);
begin
  // Сохранить картинку
  SavePictureDialog1.DefaultExt:='BMP';
  SavePictureDialog1.FileName:=Panel3.Caption+'1.BMP';
  if SavePictureDialog1.Execute then
   begin
     image1.Picture.SaveToFile(SavePictureDialog1.FileName);
   end;
end;

procedure TForm1.F6Click(Sender: TObject);
begin
  // Выход
  Close;
end;

procedure center_image;
var
 dlina_gor_i,dlina_ver_i:integer;
 center_gor,center_ver:integer;
 i_left,i_top:integer;
begin
  dlina_gor_i:=round(form1.Image1.Width/2);
  dlina_ver_i:=round(form1.Image1.Height/2);
  center_gor:=round(form1.ScrollBox1.Width/2);
  center_ver:=round(form1.ScrollBox1.Height/2);
  i_left:=center_gor-dlina_gor_i;
  i_top:=center_ver-dlina_ver_i;
  if i_left<0 then i_left:=0;
  if i_top<0 then i_top:=0;
  form1.Image1.Left:=i_left;
  form1.Image1.Top:=i_top;
end;

procedure delete_sim;
var
 temp_s1:string;
begin
 temp_s1:=form1.V1.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V1.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V2.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V2.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V3.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V3.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V4.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V4.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V5.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V5.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V6.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V6.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V7.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V7.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V8.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V8.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V9.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V9.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V10.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V10.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V11.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V11.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V12.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V12.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V13.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V13.Caption:=' '+temp_s1;
   end;
 temp_s1:=form1.V14.Caption;
 if copy(temp_s1,1,1)='*' then
   begin
    delete(temp_s1,1,1);
    form1.V14.Caption:=' '+temp_s1;
   end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
 temp_s:string;
begin
  Parametr1:= 60;
  Parametr2:= 240;
  Parametr3:= 60;
  clear_image;
  temp_s:=V1.Caption;
  delete(Temp_s,1,4);
  V1.Caption:='*   '+Temp_s;
  Image1.Width:=152;
  Image1.Height:=152;
  center_image;
  Panel2.Caption:='152 X 152';
  global_uk:=1;
  fon_uk:=0;
  uk_green:=0;
  uk_red:=0;
  uk_blue:=0;
  uk_iz_fon:=False;
  F3.Enabled:=False;
  F5.Enabled:=False;
  P2.Enabled:=False;
end;

procedure TForm1.V2Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V2.Caption;
  delete(Temp_s,1,4);
  V2.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=200;
  Image1.Height:=200;
  center_image;
  clear_image;
  Panel2.Caption:='200 X 200';
end;

procedure TForm1.V1Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V1.Caption;
  delete(Temp_s,1,4);
  V1.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=152;
  Image1.Height:=152;
  center_image;
  clear_image;
  Panel2.Caption:='152 X 152';
end;

procedure TForm1.V3Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V3.Caption;
  delete(Temp_s,1,4);
  V3.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=300;
  Image1.Height:=300;
  center_image;
  clear_image;
  Panel2.Caption:='300 X 300';
end;

procedure TForm1.V4Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V4.Caption;
  delete(Temp_s,1,4);
  V4.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=320;
  Image1.Height:=200;
  center_image;
  clear_image;
  Panel2.Caption:='320 X 200';
end;

procedure TForm1.V5Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V5.Caption;
  delete(Temp_s,1,4);
  V5.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=320;
  Image1.Height:=240;
  center_image;
  clear_image;
  Panel2.Caption:='320 X 240';
end;

procedure TForm1.V6Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V6.Caption;
  delete(Temp_s,1,4);
  V6.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=400;
  Image1.Height:=400;
  center_image;
  clear_image;
  Panel2.Caption:='400 X 400';
end;

procedure TForm1.V7Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V7.Caption;
  delete(Temp_s,1,4);
  V7.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=640;
  Image1.Height:=400;
  center_image;
  clear_image;
  Panel2.Caption:='640 X 400';
end;

procedure TForm1.V8Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V8.Caption;
  delete(Temp_s,1,4);
  V8.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=640;
  Image1.Height:=480;
  center_image;
  clear_image;
  Panel2.Caption:='640 X 480';
end;

procedure TForm1.V9Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V9.Caption;
  delete(Temp_s,1,4);
  V9.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=800;
  Image1.Height:=600;
  center_image;
  clear_image;
  Panel2.Caption:='800 X 600';
end;

procedure TForm1.V10Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V10.Caption;
  delete(Temp_s,1,4);
  V10.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=800;
  Image1.Height:=800;
  center_image;
  clear_image;
  Panel2.Caption:='800 X 800';
end;

procedure TForm1.V11Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V11.Caption;
  delete(Temp_s,1,4);
  V11.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=1024;
  Image1.Height:=768;
  center_image;
  clear_image;
  Panel2.Caption:='1024 X 768';
end;

procedure TForm1.V12Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V12.Caption;
  delete(Temp_s,1,4);
  V12.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=1024;
  Image1.Height:=1024;
  center_image;
  clear_image;
  Panel2.Caption:='1024 X 1024';
end;

procedure TForm1.V13Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V13.Caption;
  delete(Temp_s,1,4);
  V13.Caption:='*   '+Temp_s;
  clear_image;
  image_create;
  Image1.Width:=1600;
  Image1.Height:=1600;
  center_image;
  clear_image;
  Panel2.Caption:='1600 X 1600';
end;

procedure TForm1.V14Click(Sender: TObject);
var
 temp_s:string;
begin
  delete_sim;
  temp_s:=V14.Caption;
  delete(Temp_s,1,4);
  V14.Caption:='*   '+Temp_s;
  form3.visible:=True;
  form3.SpinEdit2.Value:=Image1.Height;
  form3.SpinEdit1.Value:=Image1.Width;
end;

procedure image_create;
begin
  form1.Image1.Free;
  form1.Image1:=Timage.Create(Form1);
  form1.Image1.Parent:=form1.ScrollBox1;
end;

procedure TForm1.PO1Click(Sender: TObject);
begin
  form5.Visible:=True;
end;

procedure TForm1.FormResize(Sender: TObject);
begin
  form1.Width:=640;
  form1.Height:=480;
end;

procedure TForm1.P2Click(Sender: TObject);
begin
  uk_iz_fon:=true;
  form4.Visible:=True;
end;

procedure TForm1.PO2Click(Sender: TObject);
begin
 winhelp(Form1.Handle,'Помощь.hlp',HELP_CONTEXT,1);
end;

end.
