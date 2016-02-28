unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, ComCtrls;

type
  TForm1 = class(TForm)
    btn1: TButton;
    grp1: TGroupBox;
    paintbox1: TPaintBox;
    LE1: TLabeledEdit;
    StartX: TLabeledEdit;
    StartY: TLabeledEdit;
    stat1: TStatusBar;
    btn2: TButton;
    btn3: TButton;
    msec: TLabeledEdit;
    procedure btn1Click(Sender: TObject);
    procedure draw();
    procedure erase();
    procedure info();
    procedure FormCreate(Sender: TObject);
    procedure StartYExit(Sender: TObject);
    procedure StartXExit(Sender: TObject);
    procedure LE1Exit(Sender: TObject);
    procedure btn2Click(Sender: TObject);
    procedure btn3Click(Sender: TObject);
    procedure msecExit(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

const
  //����������� ������� ��������
  MAX_ITER = 100000;
 var
  //������ ��������� �����
  PixArrX, PixArrY: array[1..MAX_ITER] of Integer;
  //�������� ���� ��������� ��������
  PixIndex: Integer;
  //�-��� ��������, ��� �������� �� ���� ���
  iterations: Integer;

{$R *.dfm}

//����������� ������ � ����� � ����������� ������� �����,
//� ����� �������� �� �������� ���
function TextToInt(s: String; a,b,default: Integer): Integer;
var
  str: string;
  i: Integer;
begin
  for i:= 1 to Length(s) do
  begin
    if s[i] = ' ' then Continue;
    if s[i] in ['0'..'9'] then str := str + s[i]
    else
    begin
      ShowMessage('�������! �������� ���� �� � ���� ����� [' + IntToStr(a) + '..' +
      IntToStr(b) + ']');
      Result := default;
      Exit;
    end;
 end;
  if str = '' then
  begin
    Result := default;
    Exit;
  end;
  Result := StrToInt(str);
  //�������� �� �������� ���
  if (Result < a) or (Result > b) then Result := default;
end;

//��������� ���������� ��� �������� � ������-���
procedure Tform1.info();
begin
  stat1.SimpleText := '�������� ��������: ' + IntToStr(PixIndex) +
    ' / ' + IntToStr(MAX_ITER);
end;  

//��������� ��������
procedure Tform1.draw();
var
    t, x, y: real;
    p: real;//��������� ��������
    k: longint;
    mid_x, mid_y, radius: integer;
    cur_x, cur_y: Integer;
begin
    if PixIndex >= MAX_ITER then
    begin
      ShowMessage('��������� ����������� ���� �������� !');
      Exit;
    end;

    mid_x := StrToInt(StartX.Text);
    mid_y := StrToInt(StartY.Text);
    radius := trunc(0.1 * mid_y);
    randomize;
    x := 1.0;
    y := 0.0;

    //������� ������ ������� ��������
    for k := 1 to iterations do
    begin
        if PixIndex >= MAX_ITER then  Exit;

        p := random;
        t := x;
        if p <= 0.85 then  //�������� ������� ������� ������
        begin
            x := 0.84 * x -0.045  * y;
            y := 0.045  * t + 0.86   * y + 1.6;
        end
        else
        if p <= 0.92 then  //�������� ����� ������
        begin
            x := 0.25   * x - 0.26 * y;
            y := 0.23 * t + 0.25   * y + 1.6;

        end                //�������� ������� ������
        else if p <= 0.99 then
        begin
            x := -0.135   * x + 0.28 * y;
            y := 0.26 * t + 0.245 * y + 0.44;
        end
        else
        begin              //�������� ������
            x := 0.0;
            y := 0.16 * y ;
        end;

        cur_x := mid_x+round(radius*x);
        cur_y := mid_y-round(radius*y)+35;

        //�������� ������� ����� � �����
        Inc(PixIndex);
        PixArrX[PixIndex] := cur_x;
        PixArrY[PixIndex] := cur_y;

        //�������� ������ �� �����
        paintbox1.Canvas.Pixels[cur_x, cur_y] := clGreen;
        info();
        //�������� ����������
        Sleep(StrToInt(msec.Text));
    end
end;

//���������� �� ��������� �����, ��������������� ������
//�������� ����
procedure Tform1.erase();
var
  cur_x, cur_y, k: Integer;
begin
    if PixIndex <= 0 then
    begin
      ShowMessage('��������� ����� ���� �������� !');
      Exit;
    end;
    for k := iterations downto 1 do
    begin
      if PixIndex <= 0 then Exit;
      Dec(PixIndex);
      cur_x := PixArrX[PixIndex];
      cur_y := PixArrY[PixIndex];
      //������� ������ �������� ����
      paintbox1.Canvas.Pixels[cur_x, cur_y] := clBtnFace;
      info();
      //�������� ����������
      Sleep(StrToInt(msec.Text));
    end;

end;

procedure TForm1.btn1Click(Sender: TObject);
begin
  draw();
end;

//������� ���������
procedure TForm1.FormCreate(Sender: TObject);
begin
  PixIndex := 0;
  LE1.Text := '30000';
  msec.Text := '0';
  iterations := StrToInt(LE1.Text);

  StartX.Text := IntToStr(paintbox1.width div 2);
  StartY.Text := IntToStr(paintbox1.height - 100);
end;

//��������� ����������� ���� � ��������� �������
procedure TForm1.StartYExit(Sender: TObject);
begin
  StartY.Text := IntToStr(TextToInt(StartY.Text, 50, 350, paintbox1.height - 100));
end;

procedure TForm1.StartXExit(Sender: TObject);
begin
  StartX.Text := IntToStr(TextToInt(StartX.Text, 150, 650, paintbox1.width div 2));
end;

procedure TForm1.LE1Exit(Sender: TObject);
begin
  iterations := TextToInt(LE1.Text, 1, 50000, 1000);
  LE1.Text :=  IntToStr(iterations);
end;

procedure TForm1.msecExit(Sender: TObject);
begin
  msec.Text := IntToStr(TextToInt(msec.Text, 0, 20000 div StrToInt(LE1.Text), 0));
end;

procedure TForm1.btn2Click(Sender: TObject);
begin
  erase();
end;

//������� �����
procedure TForm1.btn3Click(Sender: TObject);
begin
  PixIndex := 0;
  //������� ����������� �������� ���� �� ��� ����� �����
  paintbox1.Canvas.Brush.Color := clBtnFace;
  paintbox1.Canvas.FillRect(paintbox1.Canvas.ClipRect);
  info();
end;

end.
