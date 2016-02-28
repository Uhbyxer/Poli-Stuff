unit Unit3;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, Spin;

type
  TForm3 = class(TForm)
    GroupBox1: TGroupBox;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    Label1: TLabel;
    Label2: TLabel;
    Button1: TButton;
    Button2: TButton;
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form3: TForm3;

implementation

uses Unit1, Unit5;

{$R *.DFM}

procedure TForm3.Button2Click(Sender: TObject);
begin
  form3.Close;
end;

procedure TForm3.Button1Click(Sender: TObject);
begin
  form3.Visible:=False;
  image_create;
  form1.Image1.Height:=SpinEdit2.Value;
  form1.Image1.Width:=SpinEdit1.Value;
  center_image;
  clear_image;
  form1.Panel2.Caption:=inttostr(SpinEdit1.Value)+' X '+inttostr(SpinEdit2.Value);
end;

procedure TForm3.FormResize(Sender: TObject);
begin
  form3.Width:=310;
  form3.Height:=136;
end;

end.
