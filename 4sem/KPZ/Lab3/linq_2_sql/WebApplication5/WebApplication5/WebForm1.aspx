<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication5.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:GridView ID="GridView1" runat="server"></asp:GridView>  

    </div>
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Чоловіки" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Працівники+Професії" />
        <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Жінки в IT" />
        <asp:GridView ID="GridView2" runat="server">
        </asp:GridView>
        <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="Додати" />
        <asp:Button ID="Button5" runat="server" OnClick="Button5_Click" Text="Видалити" />
    </form>
</body>
</html>
