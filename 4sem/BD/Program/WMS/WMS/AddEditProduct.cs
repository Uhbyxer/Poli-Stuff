using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Entity.Migrations;
using System.Drawing;//D:\Docs\_Politex\4sem\BD\Program\WMS\WMS\packages.config
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WMS
{
    public partial class AddEditProduct : Form
    {
        private WMSEntities context;
        private bool editMode;


        //конструктор - для нового товару
        public AddEditProduct()
        {
            editMode = false;
            InitializeComponent();
            IDText.Text = (1 + LastID()).ToString();
            
        }
        //конструктор - для редагування існуючого товару 
        public AddEditProduct(String ID)
        {
            editMode = true;
            InitializeComponent();
            IDText.Text = ID;

        }

        //кнопка "ОК"
        private void button1_Click(object sender, EventArgs e)
        {
            //перевірка кокектності заповнення
            if (NameText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Name is empty !");
                return;
            }

            if (AmountText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Amount is empty !");
                return;
            }

            if (WidthText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Width is empty !");
                return;
            }

            if (HeightText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Height is empty !");
                return;
            }

            if (DepthText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Depth is empty !");
                return;
            }

            decimal nAmount;
            if (!decimal.TryParse(AmountText.Text.Trim(), out nAmount))
            {
                MessageBox.Show("Amount: bad format of number !");
                return;
            }

            decimal nWidth;
            if (!decimal.TryParse(WidthText.Text.Trim(), out nWidth))
            {
                MessageBox.Show("Width: bad format of number !");
                return;
            }

            decimal nHeight;
            if (!decimal.TryParse(HeightText.Text.Trim(), out nHeight))
            {
                MessageBox.Show("Height: bad format of number !");
                return;
            }

            decimal nDepth;
            if (!decimal.TryParse(DepthText.Text.Trim(), out nDepth))
            {
                MessageBox.Show("Depth: bad format of number !");
                return;
            }

            if (clientsDataGridView.SelectedCells.Count == 0)
            {
                MessageBox.Show("Choose the Client !");
                return;
            }

            if (regionDataGridView.SelectedCells.Count == 0)
            {
                MessageBox.Show("Choose the Region !");
                return;
            }

            var row = clientsDataGridView.SelectedCells[0];
            int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int nClientID = (int)clientsDataGridView[0, RowIndex].Value;

            row = regionDataGridView.SelectedCells[0];
            RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int nRegionID = (int)regionDataGridView[0, RowIndex].Value;

            using (WMSEntities cont = new WMSEntities())
            {

                    Products t = new Products
                    {
                        ID = int.Parse(IDText.Text),
                        Name = NameText.Text.Trim(),
                        Amount = nAmount,
                        Width = nWidth,
                        Height = nHeight,
                        Depth = nDepth,
                        ClientID = nClientID,
                        RegionID = nRegionID,
                    };

                    cont.Products.AddOrUpdate(t);

                
                cont.SaveChanges();
            }


            DialogResult = DialogResult.OK;
            Close();
        }

        //при запуску форми - наповнення вмістом з БД
        private void AddEditProduct_Load(object sender, EventArgs e)
        {

            context = new WMSEntities();
            context.Configuration.LazyLoadingEnabled = false;
            //var query = context.Clients.OrderBy(p => p.ID);

  
                var query =
                   from client in context.Clients
                   select new
                   {
                       client.ID,
                       client.Name,
                   };
  
            clientsDataGridView.DataSource = query.ToList();

            query =
                   from region in context.Regions
                   select new
                   {
                       region.ID,
                       region.Name,
                   };

            regionDataGridView.DataSource = query.ToList();

            if (editMode)
            {
                int nID = int.Parse(IDText.Text);

                using (WMSEntities cont = new WMSEntities())
                {
                    var q =
                        from products in cont.Products
                        where products.ID == nID
                        select products;
                    Products first = q.ToList().First();
                    NameText.Text = first.Name;
                    AmountText.Text = first.Amount.ToString();
                    WidthText.Text = first.Width.ToString();
                    HeightText.Text = first.Height.ToString();
                    DepthText.Text = first.Depth.ToString();

                    for (int i = 0; i < clientsDataGridView.RowCount; i++)
                    {
                        int nClientID = (int)clientsDataGridView[0, i].Value;
                        if (nClientID == first.ClientID)
                        {
                            clientsDataGridView[0, i].Selected = true;

                            break;
                        }
                    }

                    for (int i = 0; i < regionDataGridView.RowCount; i++)
                    {
                        int nRegionID = (int)regionDataGridView[0, i].Value;
                        if (nRegionID == first.RegionID)
                        {
                            regionDataGridView[0, i].Selected = true;

                            break;
                        }
                    }

                }
            }


        }

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Products.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

    }
}
