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
    public partial class WarehousesForm : Form
    {
        private WMSEntities context;
        public WarehousesForm()
        {
            InitializeComponent();
        }

        private void WarehousesForm_Load(object sender, EventArgs e)
        {

            context = new WMSEntities();
            var query  = context.Warehouses.OrderBy(p => p.ID);
            warehousesBindingSource.DataSource = query.ToList();

            dataGridViewTextBoxColumn1.ReadOnly = true;
        }

        private void warehousesBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            context.SaveChanges();
        }

        private void warehousesBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }

        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {

        }

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Warehouses.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }


        //додавання
        private void button1_Click(object sender, EventArgs e)
        {
            using (WMSEntities cont = new WMSEntities())
            {
                Warehouses t = new Warehouses { ID = 1 + LastID(), Name = textBox2.Text };
                cont.Warehouses.Add(t);
                cont.SaveChanges();
            }
            WarehousesForm_Load(null, null);
        }

        private void warehousesDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            context.SaveChanges();
        }

        //видалення
        private void button2_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in warehousesDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell) row).RowIndex;
                rows.Add((int)warehousesDataGridView[0, RowIndex].Value);
            }
            

            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                 var query = from t in cont.Warehouses
                     where t.ID == row
                     select t;
                 if (query.Count() > 0)
                 {
                     var t = query.ToList().First();
                     cont.Warehouses.Remove(t);
                     cont.SaveChanges();
                 }
                }   
            }

            WarehousesForm_Load(null, null);
        }
    }
}
