using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WMS
{
    public partial class ProductsForm : Form
    {
        private WMSEntities context;
        public ProductsForm()
        {
            InitializeComponent();
        }

        private void ProductsForm_Load(object sender, EventArgs e)
        {

            context = new WMSEntities();
            context.Configuration.LazyLoadingEnabled = false;
            //var query = context.Clients.OrderBy(p => p.ID);

            var query =
                from product in context.Products
                join client in context.Clients on product.ClientID equals client.ID
                join region in context.Regions on product.RegionID equals region.ID
                select new
                {
                    product.ID,
                    product.Name,
                    product.Width,
                    product.Height,
                    product.Depth,
                    product.Amount,

                    ClientID = client.ID,
                    ClientName = client.Name, 
                    RegionID = region.ID,
                    RegionName = region.Name
                    
                };

            productsDataGridView.DataSource = query.ToList();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AddEditProduct f = new AddEditProduct();
            var res =  f.ShowDialog();
            if (res == DialogResult.OK) ProductsForm_Load(null, null);


        }

        private void button2_Click(object sender, EventArgs e)
        {

            if (productsDataGridView.SelectedCells.Count != 1)
            {
                MessageBox.Show("Choose the one row to edit !");
                return;
            }
            var row = productsDataGridView.SelectedCells[0];
            int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int sID = (int)productsDataGridView[0, RowIndex].Value;

            AddEditProduct f = new AddEditProduct(sID.ToString());
            var res = f.ShowDialog();
            if (res == DialogResult.OK) ProductsForm_Load(null, null);

        }

        private void button3_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in productsDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
                rows.Add((int)productsDataGridView[0, RowIndex].Value);
            }


            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                    var query = from t in cont.Products
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.Products.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            ProductsForm_Load(null, null);

        }
    }
}
