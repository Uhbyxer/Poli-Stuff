unit Unit5;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls;

type
  TForm5 = class(TForm)
    Image1: TImage;
    Button1: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form5: TForm5;

implementation

{$R *.DFM}

procedure TForm5.FormCreate(Sender: TObject);
var
 i,j:integer;
 LogF: TLogFont;
 OldStyle:TBrushStyle;
begin
  Randomize;
  for i:=0 to form5.image1.Width do
   for j:=0 to form5.image1.Height do
     form5.image1.Canvas.Pixels[i,j]:=RGB(round(random(255)/(i+1)),round(random(255)/(j+1)),round(random(255)/(i+1)*(j+1)));

  OldStyle:=form5.Image1.Canvas.Brush.Style;
  Form5.image1.canvas.Font.Name:='Arial';
  form5.Image1.Canvas.Font.Size:=8;
  form5.Image1.Canvas.Font.Color:=claqua;
  GetObject(form5.image1.canvas.Font.Handle, SizeOf(LogF), Addr(LogF));
  LogF.lfEscapement := LogF.lfEscapement+1;
  form5.image1.canvas.Font.Handle := CreateFontIndirect(LogF);
  form5.Image1.Canvas.Brush.Style:=bsClear;
  form5.image1.Canvas.TextOut(5, 50, '< Демонстрационная программа по фрастальным кривым >');
  form5.image1.Canvas.TextOut(5, 80, '< Разработанна студентом ПГУ Рыжовым Сергеем Алексеевичем >');
  form5.image1.Canvas.TextOut(5, 110, '< Версия 2.1 > < Россия > < Пенза > < 2001 - 2002 гг.>');
  form5.Image1.Canvas.Brush.Style:=OldStyle;
end;

procedure TForm5.Button1Click(Sender: TObject);
begin
 close;
end;

procedure TForm5.FormResize(Sender: TObject);
begin
  form5.Width:=366;
  form5.Height:=254;
end;

end.
 