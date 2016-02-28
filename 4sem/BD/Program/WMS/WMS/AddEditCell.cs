using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Entity.Migrations;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WMS
{
    public partial class AddEditCell : Form
    {
        private WMSEntities context;
        private bool editMode;

        private int LastID()
        {
            int res = 0;
            using (WMSEntities cont = new WMSEntities())
            {
                var query = cont.Cells.OrderBy(p => p.ID);
                if (query.Count() > 0) res = query.ToList().Last().ID;
            }
            return res;
        }

        public AddEditCell()
        {
            editMode = false;
            InitializeComponent();
            IDText.Text = (1 + LastID()).ToString();

        }

        public AddEditCell(String ID)
        {
            editMode = true;
            InitializeComponent();
            IDText.Text = ID;

        }

        private void AddEditCell_Load(object sender, EventArgs e)
        {
            context = new WMSEntities();
            context.Configuration.LazyLoadingEnabled = false;
            //var query = context.Clients.OrderBy(p => p.ID);


            var query =
               from types in context.CellTypes
               select new
               {
                   types.ID,
                   types.Name,
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

            query =
                   from ware in context.Warehouses
                   select new
                   {
                       ware.ID,
                       ware.Name,
                   };

            warehoesesGridView.DataSource = query.ToList();

            if (editMode)
            {
                int nID = int.Parse(IDText.Text);

                using (WMSEntities cont = new WMSEntities())
                {
                    var q =
                        from cells in cont.Cells
                        where cells.ID == nID
                        select cells;

                    Cells first = q.ToList().First();
                    NameText.Text = first.Name;
                    AmountText.Text = first.Amount.ToString();
                    WidthText.Text = first.Width.ToString();
                    HeightText.Text = first.Height.ToString();
                    DepthText.Text = first.Depth.ToString();
                    StillageText.Text = first.Stillage.ToString();
                    TierText.Text = first.Tier.ToString();
                    PositionText.Text = first.Position.ToString();
                    SizeControlText.Text = first.SizeControl.ToString();
                    AmountControlText.Text = first.AmountControl.ToString();
                    


                    for (int i = 0; i < clientsDataGridView.RowCount; i++)
                    {
                        int nClientID = (int)clientsDataGridView[0, i].Value;
                        if (nClientID == first.TypeID)
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

                    for (int i = 0; i < warehoesesGridView.RowCount; i++)
                    {
                        int nWareID = (int)warehoesesGridView[0, i].Value;
                        if (nWareID == first.WarehouseID)
                        {
                            warehoesesGridView[0, i].Selected = true;

                            break;
                        }
                    }

                }
            }

        }

        private void clientsDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void AmountText_TextChanged(object sender, EventArgs e)
        {

        }

        private void DepthText_TextChanged(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void HeightText_TextChanged(object sender, EventArgs e)
        {

        }

        private void WidthText_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void IDText_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void regionDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void NameText_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
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

            if (StillageText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Stillage is empty !");
                return;
            }

            if (TierText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Tier is empty !");
                return;
            }
            if (PositionText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Position is empty !");
                return;
            }

            if (SizeControlText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Size control is empty !");
                return;
            }
            if (AmountControlText.Text.Trim().Length == 0)
            {
                MessageBox.Show("Amount control is empty !");
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

            int nStillage;
            if (!int.TryParse(StillageText.Text.Trim(), out nStillage))
            {
                MessageBox.Show("Stillage: bad format of number !");
                return;
            }

            int nTier;
            if (!int.TryParse(TierText.Text.Trim(), out nTier))
            {
                MessageBox.Show("Tier: bad format of number !");
                return;
            }

            int nPosition;
            if (!int.TryParse(PositionText.Text.Trim(), out nPosition))
            {
                MessageBox.Show("Position: bad format of number !");
                return;
            }
            int nSizeControl;
            if (!int.TryParse(SizeControlText.Text.Trim(), out nSizeControl))
            {
                MessageBox.Show("Size control: bad format of number !");
                return;
            }
            int nAmountControl;
            if (!int.TryParse(AmountControlText.Text.Trim(), out nAmountControl))
            {
                MessageBox.Show("Amount control: bad format of number !");
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
            if (warehoesesGridView.SelectedCells.Count == 0)
            {
                MessageBox.Show("Choose the Warehouse !");
                return;
            }

            var row = clientsDataGridView.SelectedCells[0];
            int RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int nTypeID = (int)clientsDataGridView[0, RowIndex].Value;

            row = regionDataGridView.SelectedCells[0];
            RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int nRegionID = (int)regionDataGridView[0, RowIndex].Value;

            row = warehoesesGridView.SelectedCells[0];
            RowIndex = ((System.Windows.Forms.DataGridViewTextBoxCell)row).RowIndex;
            int nWareID = (int)warehoesesGridView[0, RowIndex].Value;


            using (WMSEntities cont = new WMSEntities())
            {

                Cells t = new Cells
                {
                    ID = int.Parse(IDText.Text),
                    Name = NameText.Text.Trim(),
                    Amount = nAmount,
                    Width = nWidth,
                    Height = nHeight,
                    Depth = nDepth,

                    Stillage = nStillage,
                    Tier = nTier,
                    Position = nPosition,
                    SizeControl = nSizeControl,
                    AmountControl = nAmountControl,
                    
                    TypeID = nTypeID,
                    RegionID = nRegionID,
                    WarehouseID = nWareID
                };

                cont.Cells.AddOrUpdate(t);


                cont.SaveChanges();
            }


            DialogResult = DialogResult.OK;
            Close();
        }
    }
}
