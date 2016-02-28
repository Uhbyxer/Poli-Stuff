namespace WMS
{
    partial class AddEditCell
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.DepthText = new System.Windows.Forms.TextBox();
            this.AmountText = new System.Windows.Forms.TextBox();
            this.HeightText = new System.Windows.Forms.TextBox();
            this.NameText = new System.Windows.Forms.TextBox();
            this.WidthText = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.IDText = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.regionDataGridView = new System.Windows.Forms.DataGridView();
            this.clientsDataGridView = new System.Windows.Forms.DataGridView();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.warehoesesGridView = new System.Windows.Forms.DataGridView();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.StillageText = new System.Windows.Forms.TextBox();
            this.TierText = new System.Windows.Forms.TextBox();
            this.PositionText = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.SizeControlText = new System.Windows.Forms.TextBox();
            this.AmountControlText = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.regionDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.warehoesesGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // DepthText
            // 
            this.DepthText.Location = new System.Drawing.Point(221, 67);
            this.DepthText.Name = "DepthText";
            this.DepthText.Size = new System.Drawing.Size(96, 20);
            this.DepthText.TabIndex = 9;
            this.DepthText.Text = "0,0";
            this.DepthText.TextChanged += new System.EventHandler(this.DepthText_TextChanged);
            // 
            // AmountText
            // 
            this.AmountText.Location = new System.Drawing.Point(61, 67);
            this.AmountText.Name = "AmountText";
            this.AmountText.Size = new System.Drawing.Size(103, 20);
            this.AmountText.TabIndex = 10;
            this.AmountText.Text = "0,0";
            this.AmountText.TextChanged += new System.EventHandler(this.AmountText_TextChanged);
            // 
            // HeightText
            // 
            this.HeightText.Location = new System.Drawing.Point(221, 38);
            this.HeightText.Name = "HeightText";
            this.HeightText.Size = new System.Drawing.Size(96, 20);
            this.HeightText.TabIndex = 11;
            this.HeightText.Text = "0,0";
            this.HeightText.TextChanged += new System.EventHandler(this.HeightText_TextChanged);
            // 
            // NameText
            // 
            this.NameText.Location = new System.Drawing.Point(61, 38);
            this.NameText.Name = "NameText";
            this.NameText.Size = new System.Drawing.Size(103, 20);
            this.NameText.TabIndex = 12;
            this.NameText.TextChanged += new System.EventHandler(this.NameText_TextChanged);
            // 
            // WidthText
            // 
            this.WidthText.Location = new System.Drawing.Point(221, 9);
            this.WidthText.Name = "WidthText";
            this.WidthText.Size = new System.Drawing.Size(96, 20);
            this.WidthText.TabIndex = 13;
            this.WidthText.Text = "0,0";
            this.WidthText.TextChanged += new System.EventHandler(this.WidthText_TextChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(168, 74);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 13);
            this.label6.TabIndex = 3;
            this.label6.Text = "Depth";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // IDText
            // 
            this.IDText.Location = new System.Drawing.Point(61, 9);
            this.IDText.Name = "IDText";
            this.IDText.ReadOnly = true;
            this.IDText.Size = new System.Drawing.Size(103, 20);
            this.IDText.TabIndex = 14;
            this.IDText.TextChanged += new System.EventHandler(this.IDText_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(168, 41);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Height";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 74);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Amount";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(168, 12);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Width";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Name";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(18, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "ID";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // regionDataGridView
            // 
            this.regionDataGridView.AllowUserToAddRows = false;
            this.regionDataGridView.AllowUserToDeleteRows = false;
            this.regionDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.regionDataGridView.Location = new System.Drawing.Point(323, 114);
            this.regionDataGridView.MultiSelect = false;
            this.regionDataGridView.Name = "regionDataGridView";
            this.regionDataGridView.ReadOnly = true;
            this.regionDataGridView.Size = new System.Drawing.Size(321, 248);
            this.regionDataGridView.TabIndex = 17;
            this.regionDataGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.regionDataGridView_CellContentClick);
            // 
            // clientsDataGridView
            // 
            this.clientsDataGridView.AllowUserToAddRows = false;
            this.clientsDataGridView.AllowUserToDeleteRows = false;
            this.clientsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.clientsDataGridView.Location = new System.Drawing.Point(12, 114);
            this.clientsDataGridView.MultiSelect = false;
            this.clientsDataGridView.Name = "clientsDataGridView";
            this.clientsDataGridView.ReadOnly = true;
            this.clientsDataGridView.Size = new System.Drawing.Size(305, 248);
            this.clientsDataGridView.TabIndex = 18;
            this.clientsDataGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.clientsDataGridView_CellContentClick);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(320, 98);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 13);
            this.label8.TabIndex = 15;
            this.label8.Text = "Region";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(9, 98);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(31, 13);
            this.label7.TabIndex = 16;
            this.label7.Text = "Type";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(512, 459);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(132, 32);
            this.button1.TabIndex = 19;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 365);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(62, 13);
            this.label9.TabIndex = 16;
            this.label9.Text = "Warehouse";
            this.label9.Click += new System.EventHandler(this.label7_Click);
            // 
            // warehoesesGridView
            // 
            this.warehoesesGridView.AllowUserToAddRows = false;
            this.warehoesesGridView.AllowUserToDeleteRows = false;
            this.warehoesesGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.warehoesesGridView.Location = new System.Drawing.Point(12, 381);
            this.warehoesesGridView.MultiSelect = false;
            this.warehoesesGridView.Name = "warehoesesGridView";
            this.warehoesesGridView.ReadOnly = true;
            this.warehoesesGridView.Size = new System.Drawing.Size(632, 63);
            this.warehoesesGridView.TabIndex = 18;
            this.warehoesesGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.clientsDataGridView_CellContentClick);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(324, 12);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(41, 13);
            this.label10.TabIndex = 6;
            this.label10.Text = "Stillage";
            this.label10.Click += new System.EventHandler(this.label4_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(324, 41);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(25, 13);
            this.label11.TabIndex = 4;
            this.label11.Text = "Tier";
            this.label11.Click += new System.EventHandler(this.label5_Click);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(324, 74);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(44, 13);
            this.label12.TabIndex = 3;
            this.label12.Text = "Position";
            this.label12.Click += new System.EventHandler(this.label6_Click);
            // 
            // StillageText
            // 
            this.StillageText.Location = new System.Drawing.Point(377, 9);
            this.StillageText.Name = "StillageText";
            this.StillageText.Size = new System.Drawing.Size(96, 20);
            this.StillageText.TabIndex = 13;
            this.StillageText.Text = "0";
            this.StillageText.TextChanged += new System.EventHandler(this.WidthText_TextChanged);
            // 
            // TierText
            // 
            this.TierText.Location = new System.Drawing.Point(377, 38);
            this.TierText.Name = "TierText";
            this.TierText.Size = new System.Drawing.Size(96, 20);
            this.TierText.TabIndex = 11;
            this.TierText.Text = "0";
            this.TierText.TextChanged += new System.EventHandler(this.HeightText_TextChanged);
            // 
            // PositionText
            // 
            this.PositionText.Location = new System.Drawing.Point(377, 67);
            this.PositionText.Name = "PositionText";
            this.PositionText.Size = new System.Drawing.Size(96, 20);
            this.PositionText.TabIndex = 9;
            this.PositionText.Text = "0";
            this.PositionText.TextChanged += new System.EventHandler(this.DepthText_TextChanged);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(479, 12);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(62, 13);
            this.label13.TabIndex = 6;
            this.label13.Text = "Size control";
            this.label13.Click += new System.EventHandler(this.label4_Click);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(479, 41);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(78, 13);
            this.label14.TabIndex = 4;
            this.label14.Text = "Amount control";
            this.label14.Click += new System.EventHandler(this.label5_Click);
            // 
            // SizeControlText
            // 
            this.SizeControlText.Location = new System.Drawing.Point(579, 9);
            this.SizeControlText.Name = "SizeControlText";
            this.SizeControlText.Size = new System.Drawing.Size(65, 20);
            this.SizeControlText.TabIndex = 13;
            this.SizeControlText.Text = "0";
            this.SizeControlText.TextChanged += new System.EventHandler(this.WidthText_TextChanged);
            // 
            // AmountControlText
            // 
            this.AmountControlText.Location = new System.Drawing.Point(579, 38);
            this.AmountControlText.Name = "AmountControlText";
            this.AmountControlText.Size = new System.Drawing.Size(65, 20);
            this.AmountControlText.TabIndex = 11;
            this.AmountControlText.Text = "0";
            this.AmountControlText.TextChanged += new System.EventHandler(this.HeightText_TextChanged);
            // 
            // AddEditCell
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(656, 503);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.regionDataGridView);
            this.Controls.Add(this.warehoesesGridView);
            this.Controls.Add(this.clientsDataGridView);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.PositionText);
            this.Controls.Add(this.DepthText);
            this.Controls.Add(this.AmountText);
            this.Controls.Add(this.AmountControlText);
            this.Controls.Add(this.TierText);
            this.Controls.Add(this.HeightText);
            this.Controls.Add(this.NameText);
            this.Controls.Add(this.SizeControlText);
            this.Controls.Add(this.StillageText);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.WidthText);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.IDText);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "AddEditCell";
            this.Text = "Add / Edit Cell";
            this.Load += new System.EventHandler(this.AddEditCell_Load);
            ((System.ComponentModel.ISupportInitialize)(this.regionDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.warehoesesGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox DepthText;
        private System.Windows.Forms.TextBox AmountText;
        private System.Windows.Forms.TextBox HeightText;
        private System.Windows.Forms.TextBox NameText;
        private System.Windows.Forms.TextBox WidthText;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox IDText;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView regionDataGridView;
        private System.Windows.Forms.DataGridView clientsDataGridView;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.DataGridView warehoesesGridView;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox StillageText;
        private System.Windows.Forms.TextBox TierText;
        private System.Windows.Forms.TextBox PositionText;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox SizeControlText;
        private System.Windows.Forms.TextBox AmountControlText;
    }
}