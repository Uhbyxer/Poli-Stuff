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
    public partial class RegionsForm : Form
    {
        private WMSEntities context;
        public RegionsForm()
        {
            InitializeComponent();
        }

        private void RegionsForm_Load(object sender, EventArgs e)
        {
            context = new WMSEntities();
            var query = context.Regions.OrderBy(p => p.ID);
            regionsBindingSource.DataSource = query.ToList();

            dataGridViewTextBoxColumn1.ReadOnly = true;
        }

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Regions.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

        private void regionsDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            context.SaveChanges();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (WMSEntities cont = new WMSEntities())
            {
                Regions t = new Regions() { ID = 1 + LastID(), Name = textBox2.Text};
                cont.Regions.Add(t);
                cont.SaveChanges();
            }
            RegionsForm_Load(null, null);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in regionsDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
                rows.Add((int)regionsDataGridView[0, RowIndex].Value);
            }


            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                    var query = from t in cont.Regions
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.Regions.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            RegionsForm_Load(null, null);
        }



    }
}
