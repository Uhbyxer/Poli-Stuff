unit Unit4;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls;

type
  TForm4 = class(TForm)
    GroupBox1: TGroupBox;
    RadioButton1: TRadioButton;
    Image1: TImage;
    ScrollBar1: TScrollBar;
    ScrollBar2: TScrollBar;
    ScrollBar3: TScrollBar;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    RadioButton2: TRadioButton;
    ComboBox1: TComboBox;
    Button2: TButton;
    Button3: TButton;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    procedure Button3Click(Sender: TObject);
    procedure GroupBox1Click(Sender: TObject);
    procedure RadioButton2Click(Sender: TObject);
    procedure RadioButton1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ScrollBar1Change(Sender: TObject);
    procedure ScrollBar2Change(Sender: TObject);
    procedure ScrollBar3Change(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure ComboBox1Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form4: TForm4;

implementation

uses Unit1, Unit2;

{$R *.DFM}

procedure TForm4.Button3Click(Sender: TObject);
begin
  Close;
end;

procedure TForm4.GroupBox1Click(Sender: TObject);
begin
 ComboBox1.Enabled:=False;
end;

procedure TForm4.RadioButton2Click(Sender: TObject);
begin
 ComboBox1.Enabled:=true;
 ScrollBar1.Enabled:=false;
 ScrollBar2.Enabled:=false;
 ScrollBar3.Enabled:=false;
 image_1(False);
end;

procedure TForm4.RadioButton1Click(Sender: TObject);
begin
 ComboBox1.Enabled:=False;
 ScrollBar1.Enabled:=true;
 ScrollBar2.Enabled:=true;
 ScrollBar3.Enabled:=true;
end;

procedure TForm4.FormCreate(Sender: TObject);
begin
 RadioButton1.Checked:=true;
 ComboBox1.Enabled:=False;
 Label4.Caption:=inttostr(ScrollBar1.Position);
 Label5.Caption:=inttostr(ScrollBar2.Position);
 Label6.Caption:=inttostr(ScrollBar3.Position);
 image1.Canvas.Brush.Color:=RGB(ScrollBar1.Position,ScrollBar2.Position,ScrollBar3.Position);
 image1.Canvas.Rectangle(1,1,Image1.Width,Image1.Height);
 ComboBox1.ItemIndex:=0;
end;

procedure TForm4.ScrollBar1Change(Sender: TObject);
begin
  label4.Caption:=inttostr(scrollbar1.Position);
  image1.Canvas.Brush.Color:=RGB(ScrollBar1.Position,ScrollBar2.Position,ScrollBar3.Position);
  image1.Canvas.Rectangle(1,1,Image1.Width,Image1.Height);
  fon_uk:=0;
  uk_red:=ScrollBar1.Position;
  uk_green:=ScrollBar2.Position;
  uk_blue:=ScrollBar3.Position;
end;

procedure TForm4.ScrollBar2Change(Sender: TObject);
begin
  label5.Caption:=inttostr(scrollbar2.Position);
  image1.Canvas.Brush.Color:=RGB(ScrollBar1.Position,ScrollBar2.Position,ScrollBar3.Position);
  image1.Canvas.Rectangle(1,1,Image1.Width,Image1.Height);
  fon_uk:=0;
  uk_red:=ScrollBar1.Position;
  uk_green:=ScrollBar2.Position;
  uk_blue:=ScrollBar3.Position;
end;

procedure TForm4.ScrollBar3Change(Sender: TObject);
begin
  label6.Caption:=inttostr(scrollbar3.Position);
  image1.Canvas.Brush.Color:=RGB(ScrollBar1.Position,ScrollBar2.Position,ScrollBar3.Position);
  image1.Canvas.Rectangle(1,1,Image1.Width,image1.Height);
  fon_uk:=0;
  uk_red:=ScrollBar1.Position;
  uk_green:=ScrollBar2.Position;
  uk_blue:=ScrollBar3.Position;
end;

procedure TForm4.Button2Click(Sender: TObject);
begin
 if form4.RadioButton1.Checked then
   begin
     form1.image1.Canvas.Brush.Color:=RGB(ScrollBar1.Position,ScrollBar2.Position,ScrollBar3.Position);
     form1.image1.Canvas.Rectangle(1,1,form1.Image1.Width,form1.image1.Height);
   end
    else
     begin
      if form4.ComboBox1.ItemIndex=0 then
       image_1(True);
      if form4.ComboBox1.ItemIndex=1 then
       image_2(True);
      if form4.ComboBox1.ItemIndex=2 then
       image_3(True);
      if form4.ComboBox1.ItemIndex=3 then
       image_4(True);
     end;
   if   uk_iz_fon then
     begin
      if global_uk=1 then
        ris1(parametr1,parametr2,parametr3);
      if global_uk=2 then
        ris3(parametr1,parametr2,parametr3);
      if global_uk=3 then
        ris4(parametr1,parametr2);
     end
      else
       form2.Visible:=True;
  uk_iz_fon:=False;
  form4.Visible:=False;
end;

procedure TForm4.ComboBox1Click(Sender: TObject);
begin
  if form4.ComboBox1.ItemIndex=0 then
    image_1(False);
  if form4.ComboBox1.ItemIndex=1 then
    image_2(False);
  if form4.ComboBox1.ItemIndex=2 then
    image_3(False);
  if form4.ComboBox1.ItemIndex=3 then
    image_4(False);
end;

procedure TForm4.FormResize(Sender: TObject);
begin
  form4.Width:=473;
  form4.Height:=321;
end;

end.
