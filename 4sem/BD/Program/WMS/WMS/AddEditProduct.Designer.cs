namespace WMS
{
    partial class AddEditProduct
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
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.IDText = new System.Windows.Forms.TextBox();
            this.NameText = new System.Windows.Forms.TextBox();
            this.AmountText = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.WidthText = new System.Windows.Forms.TextBox();
            this.HeightText = new System.Windows.Forms.TextBox();
            this.DepthText = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.clientsDataGridView = new System.Windows.Forms.DataGridView();
            this.label8 = new System.Windows.Forms.Label();
            this.regionDataGridView = new System.Windows.Forms.DataGridView();
            this.clientsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.regionDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(515, 461);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(132, 32);
            this.button1.TabIndex = 0;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(18, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Name";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 83);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "Amount";
            // 
            // IDText
            // 
            this.IDText.Location = new System.Drawing.Point(65, 18);
            this.IDText.Name = "IDText";
            this.IDText.ReadOnly = true;
            this.IDText.Size = new System.Drawing.Size(167, 20);
            this.IDText.TabIndex = 2;
            // 
            // NameText
            // 
            this.NameText.Location = new System.Drawing.Point(65, 47);
            this.NameText.Name = "NameText";
            this.NameText.Size = new System.Drawing.Size(167, 20);
            this.NameText.TabIndex = 2;
            // 
            // AmountText
            // 
            this.AmountText.Location = new System.Drawing.Point(65, 76);
            this.AmountText.Name = "AmountText";
            this.AmountText.Size = new System.Drawing.Size(167, 20);
            this.AmountText.TabIndex = 2;
            this.AmountText.Text = "0,0";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(324, 21);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 1;
            this.label4.Text = "Width";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(324, 50);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "Height";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(324, 83);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 13);
            this.label6.TabIndex = 1;
            this.label6.Text = "Depth";
            // 
            // WidthText
            // 
            this.WidthText.Location = new System.Drawing.Point(377, 18);
            this.WidthText.Name = "WidthText";
            this.WidthText.Size = new System.Drawing.Size(167, 20);
            this.WidthText.TabIndex = 2;
            this.WidthText.Text = "0,0";
            // 
            // HeightText
            // 
            this.HeightText.Location = new System.Drawing.Point(377, 47);
            this.HeightText.Name = "HeightText";
            this.HeightText.Size = new System.Drawing.Size(167, 20);
            this.HeightText.TabIndex = 2;
            this.HeightText.Text = "0,0";
            // 
            // DepthText
            // 
            this.DepthText.Location = new System.Drawing.Point(377, 76);
            this.DepthText.Name = "DepthText";
            this.DepthText.Size = new System.Drawing.Size(167, 20);
            this.DepthText.TabIndex = 2;
            this.DepthText.Text = "0,0";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 112);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(33, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "Client";
            // 
            // clientsDataGridView
            // 
            this.clientsDataGridView.AllowUserToAddRows = false;
            this.clientsDataGridView.AllowUserToDeleteRows = false;
            this.clientsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.clientsDataGridView.Location = new System.Drawing.Point(15, 128);
            this.clientsDataGridView.MultiSelect = false;
            this.clientsDataGridView.Name = "clientsDataGridView";
            this.clientsDataGridView.ReadOnly = true;
            this.clientsDataGridView.Size = new System.Drawing.Size(305, 318);
            this.clientsDataGridView.TabIndex = 3;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(323, 112);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 13);
            this.label8.TabIndex = 1;
            this.label8.Text = "Region";
            // 
            // regionDataGridView
            // 
            this.regionDataGridView.AllowUserToAddRows = false;
            this.regionDataGridView.AllowUserToDeleteRows = false;
            this.regionDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.regionDataGridView.Location = new System.Drawing.Point(326, 128);
            this.regionDataGridView.MultiSelect = false;
            this.regionDataGridView.Name = "regionDataGridView";
            this.regionDataGridView.ReadOnly = true;
            this.regionDataGridView.Size = new System.Drawing.Size(321, 318);
            this.regionDataGridView.TabIndex = 3;
            // 
            // clientsBindingSource
            // 
            this.clientsBindingSource.DataSource = typeof(WMS.Clients);
            // 
            // AddEditProduct
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(667, 513);
            this.Controls.Add(this.regionDataGridView);
            this.Controls.Add(this.clientsDataGridView);
            this.Controls.Add(this.DepthText);
            this.Controls.Add(this.AmountText);
            this.Controls.Add(this.HeightText);
            this.Controls.Add(this.NameText);
            this.Controls.Add(this.WidthText);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.IDText);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Name = "AddEditProduct";
            this.Text = "Add / Edit Product";
            this.Load += new System.EventHandler(this.AddEditProduct_Load);
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.regionDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox IDText;
        private System.Windows.Forms.TextBox NameText;
        private System.Windows.Forms.TextBox AmountText;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox WidthText;
        private System.Windows.Forms.TextBox HeightText;
        private System.Windows.Forms.TextBox DepthText;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.BindingSource clientsBindingSource;
        private System.Windows.Forms.DataGridView clientsDataGridView;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.DataGridView regionDataGridView;
    }
}