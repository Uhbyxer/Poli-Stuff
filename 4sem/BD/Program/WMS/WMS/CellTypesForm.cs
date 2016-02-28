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
    public partial class CellTypesForm : Form
    {
        private WMSEntities context;
        public CellTypesForm()
        {
            InitializeComponent();
        }

        private void CellTypesForm_Load(object sender, EventArgs e)
        {
            context = new WMSEntities();
            var query = context.CellTypes.OrderBy(p => p.ID);
            cellTypesBindingSource.DataSource = query.ToList();

            dataGridViewTextBoxColumn1.ReadOnly = true;
        }

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.CellTypes.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (WMSEntities cont = new WMSEntities())
            {
                CellTypes t = new CellTypes { ID = 1 + LastID(), Name = textBox2.Text };
                cont.CellTypes.Add(t);
                cont.SaveChanges();
            }
            CellTypesForm_Load(null, null);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in cellTypesDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
                rows.Add((int)cellTypesDataGridView[0, RowIndex].Value);
            }


            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                    var query = from t in cont.CellTypes
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.CellTypes.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            CellTypesForm_Load(null, null);

        }

        private void cellTypesDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            context.SaveChanges();
        }
    }
}
