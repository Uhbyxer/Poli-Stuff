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
    public partial class CellForms : Form
    {
        private WMSEntities context;
        public CellForms()
        {
            InitializeComponent();
        }

        private void CellForms_Load(object sender, EventArgs e)
        {
            context = new WMSEntities();
            context.Configuration.LazyLoadingEnabled = false;
            //var query = context.Clients.OrderBy(p => p.ID);

            var query =
                from cell in context.Cells
                join types in context.CellTypes on cell.TypeID equals types.ID
                join region in context.Regions on cell.RegionID equals region.ID
                join ware in context.Warehouses on cell.WarehouseID equals ware.ID
                select new
                {
                    cell.ID,
                    cell.Name,
                    cell.Width,
                    cell.Height,
                    cell.Depth,
                    cell.SizeControl,
                    cell.Amount,
                    cell.AmountControl,
                    cell.Stillage,
                    cell.Tier,
                    cell.Position,

                    TypeID = types.ID,
                    TypeName = types.Name,
                    RegionID = region.ID,
                    RegionName = region.Name,
                    WarehouseID = ware.ID,
                    WarehouseName = ware.Name,

                };

            productsDataGridView.DataSource = query.ToList();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AddEditCell f = new AddEditCell();
            var res = f.ShowDialog();
            if (res == DialogResult.OK) CellForms_Load(null, null);

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

            AddEditCell f = new AddEditCell(sID.ToString());
            var res = f.ShowDialog();
            if (res == DialogResult.OK) CellForms_Load(null, null);
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
                    var query = from t in cont.Cells
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.Cells.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            CellForms_Load(null, null);
        }
    }
}
