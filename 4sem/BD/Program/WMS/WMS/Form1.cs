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
    public partial class Form1 : Form
    {
        private WMSEntities context;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            context = new WMSEntities();
            var query = context.Clients.OrderBy(p => p.ID);
            clientsBindingSource.DataSource = query.ToList();

            dataGridViewTextBoxColumn1.ReadOnly = true;
        }

        private void clientsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            context.SaveChanges();
        }

        private void usersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            UsersForm form = new UsersForm();
            form.Show();
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void warehousesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WarehousesForm form = new WarehousesForm();
            form.Show();
        }


        //збереження змін при виході з комірки
        private void clientsDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            context.SaveChanges();
        }

        //отримання останнього ID таблмці
        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Clients.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

        //додавання нового рядка
        private void button1_Click(object sender, EventArgs e)
        {
            using (WMSEntities cont = new WMSEntities())
            {
                Clients t = new Clients() { ID = 1 + LastID(), Name = textBox2.Text, Code = textBox1.Text};
                cont.Clients.Add(t);
                cont.SaveChanges();
            }
            Form1_Load(null, null);
        }

        //видалення рядка
        private void button2_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in clientsDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
                rows.Add((int)clientsDataGridView[0, RowIndex].Value);
            }


            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                    var query = from t in cont.Clients
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.Clients.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            Form1_Load(null, null);
        }

        private void regionsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            RegionsForm form = new RegionsForm();
            form.Show();
        }

        private void productsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ProductsForm form = new ProductsForm();
            form.Show();
        }

        private void cellTypesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CellTypesForm form = new CellTypesForm();
            form.Show();
        }

        private void cellsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CellForms form = new CellForms();
            form.Show();
        }

        private void clientsDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
