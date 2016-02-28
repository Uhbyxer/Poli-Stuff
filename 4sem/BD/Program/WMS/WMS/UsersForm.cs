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
    public partial class UsersForm : Form
    {
        private WMSEntities context;
        public UsersForm()
        {
            InitializeComponent();
        }

        private void UsersForm_Load(object sender, EventArgs e)
        {

            context = new WMSEntities();
            var query = context.Users.OrderBy(p => p.ID);
            usersBindingSource.DataSource = query.ToList();

            dataGridViewTextBoxColumn1.ReadOnly = true;
        }

        private void usersBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            context.SaveChanges();
        }

        private void usersDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            context.SaveChanges();
        }

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Users.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

        private void button1_Click(object sender, EventArgs e)
        {

            using (WMSEntities cont = new WMSEntities())
            {
                Users t = new Users { ID = 1 + LastID(), Name = textBox2.Text };
                cont.Users.Add(t);
                cont.SaveChanges();
            }
            UsersForm_Load(null, null);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            HashSet<int> rows = new HashSet<int>();

            foreach (var row in usersDataGridView.SelectedCells)
            {
                int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
                rows.Add((int)usersDataGridView[0, RowIndex].Value);
            }


            foreach (int row in rows)
            {
                using (WMSEntities cont = new WMSEntities())
                {
                    var query = from t in cont.Users
                                where t.ID == row
                                select t;
                    if (query.Count() > 0)
                    {
                        var t = query.ToList().First();
                        cont.Users.Remove(t);
                        cont.SaveChanges();
                    }
                }
            }

            UsersForm_Load(null, null);
        }
    }
}
