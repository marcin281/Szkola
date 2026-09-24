namespace Zadanie1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            groupBox1 = new GroupBox();
            groupBox2 = new GroupBox();
            textBox1 = new TextBox();
            textBox4 = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            comboBox1 = new ComboBox();
            label4 = new Label();
            textBox2 = new TextBox();
            checkBox1 = new CheckBox();
            checkBox2 = new CheckBox();
            checkBox3 = new CheckBox();
            button1 = new Button();
            button2 = new Button();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(comboBox1);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(textBox4);
            groupBox1.Controls.Add(textBox1);
            groupBox1.Location = new Point(26, 28);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(347, 265);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Dane pracownika";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(button2);
            groupBox2.Controls.Add(checkBox3);
            groupBox2.Controls.Add(checkBox2);
            groupBox2.Controls.Add(checkBox1);
            groupBox2.Controls.Add(textBox2);
            groupBox2.Controls.Add(label4);
            groupBox2.Location = new Point(422, 28);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(353, 265);
            groupBox2.TabIndex = 1;
            groupBox2.TabStop = false;
            groupBox2.Text = "Generowanie hasła";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(183, 63);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(119, 23);
            textBox1.TabIndex = 0;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(183, 124);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(119, 23);
            textBox4.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(42, 63);
            label1.Name = "label1";
            label1.Size = new Size(30, 15);
            label1.TabIndex = 3;
            label1.Text = "Imię";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(42, 124);
            label2.Name = "label2";
            label2.Size = new Size(57, 15);
            label2.TabIndex = 4;
            label2.Text = "Nazwisko";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(42, 189);
            label3.Name = "label3";
            label3.Size = new Size(67, 15);
            label3.TabIndex = 5;
            label3.Text = "Stanowisko";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "Kierownik", "Starszy programista", "Młodszy programista", "Tester" });
            comboBox1.Location = new Point(183, 189);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(119, 23);
            comboBox1.TabIndex = 6;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(61, 63);
            label4.Name = "label4";
            label4.Size = new Size(67, 15);
            label4.TabIndex = 7;
            label4.Text = "Ile znaków?";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(176, 63);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(119, 23);
            textBox2.TabIndex = 7;
            // 
            // checkBox1
            // 
            checkBox1.AutoSize = true;
            checkBox1.Checked = true;
            checkBox1.CheckState = CheckState.Checked;
            checkBox1.Location = new Point(50, 101);
            checkBox1.Name = "checkBox1";
            checkBox1.Size = new Size(122, 19);
            checkBox1.TabIndex = 8;
            checkBox1.Text = "małe i wielkie liery";
            checkBox1.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            checkBox2.AutoSize = true;
            checkBox2.Location = new Point(50, 128);
            checkBox2.Name = "checkBox2";
            checkBox2.Size = new Size(54, 19);
            checkBox2.TabIndex = 9;
            checkBox2.Text = "Cyfry";
            checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox3
            // 
            checkBox3.AutoSize = true;
            checkBox3.Location = new Point(50, 153);
            checkBox3.Name = "checkBox3";
            checkBox3.Size = new Size(107, 19);
            checkBox3.TabIndex = 10;
            checkBox3.Text = "Znaki specjalne";
            checkBox3.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            button1.BackColor = Color.SteelBlue;
            button1.ForeColor = SystemColors.Control;
            button1.Location = new Point(266, 415);
            button1.Name = "button1";
            button1.Size = new Size(266, 23);
            button1.TabIndex = 2;
            button1.Text = "Zatwierdź";
            button1.UseVisualStyleBackColor = false;
            // 
            // button2
            // 
            button2.BackColor = Color.SteelBlue;
            button2.ForeColor = SystemColors.Control;
            button2.Location = new Point(131, 224);
            button2.Name = "button2";
            button2.Size = new Size(116, 23);
            button2.TabIndex = 11;
            button2.Text = "Generuj hasło";
            button2.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.LightSteelBlue;
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Dodaj pracownika";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private ComboBox comboBox1;
        private Label label3;
        private Label label2;
        private Label label1;
        private TextBox textBox4;
        private TextBox textBox1;
        private GroupBox groupBox2;
        private CheckBox checkBox3;
        private CheckBox checkBox2;
        private CheckBox checkBox1;
        private TextBox textBox2;
        private Label label4;
        private Button button2;
        private Button button1;
    }
}
