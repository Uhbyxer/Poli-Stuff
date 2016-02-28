using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Windows.Forms;

namespace WebApplication5
{
    public partial class WebForm1 : System.Web.UI.Page
    {


        //всі працівники та відділи
        protected void Page_Load(object sender, EventArgs e)
        {
            SampleDataContext dbContext = new SampleDataContext();
            GridView1.DataSource =
                dbContext.Employees;
            GridView1.DataBind();

            GridView2.DataSource =
                dbContext.Departments;
            GridView2.DataBind();

        }

        //тільки чоловіки
        protected void Button1_Click(object sender, EventArgs e)
        {

            SampleDataContext dbContext = new SampleDataContext();
            GridView1.DataSource =
                from employee in dbContext.Employees
                where employee.Gender == "Male"
                orderby employee.Salary descending
                select employee;
            
            GridView1.DataBind();

        }

        //Працівнити та професії
        protected void Button2_Click(object sender, EventArgs e)
        {
            SampleDataContext dbContext = new SampleDataContext();
            GridView1.DataSource =
                from employee in dbContext.Employees
                join department in dbContext.Departments on employee.DepartmentId equals department.ID
                select new { employee.FirstName, employee.LastName,
                             department.Name,
                             department.Location
                };

            GridView1.DataBind();

        }

        //Жінки в IT
        protected void Button3_Click(object sender, EventArgs e)
        {

            SampleDataContext dbContext = new SampleDataContext();
            GridView1.DataSource =
                from employee in dbContext.Employees
                join department in dbContext.Departments on employee.DepartmentId equals department.ID
                where department.Name == "IT" && employee.Gender == "Female"
                select new
                {
                    employee.FirstName,
                    employee.LastName,
                    department.Name,
                    department.Location
                };

            GridView1.DataBind();
        }

        //Додати запис
        protected void Button4_Click(object sender, EventArgs e)
        {

            using (SampleDataContext dbContext = new SampleDataContext())
            {
                Departments dep = new Departments();
                dep.Location = "Ukraine";
                dep.Name = "Support";

                dbContext.Departments.InsertOnSubmit(dep);
                

                try
                {
                    dbContext.SubmitChanges();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }

            }
            GridView2.DataBind();

        }

        //Видалення
        protected void Button5_Click(object sender, EventArgs e)
        {

            SampleDataContext dbContext = new SampleDataContext();
            var deps = (
                from department in dbContext.Departments
                where department.Name == "Support"
                select department);


            
            if(deps.Count() == 0) return;
            var dep = deps.First();

            dbContext.Departments.DeleteOnSubmit(dep);

            try
            {
                dbContext.SubmitChanges();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            GridView2.DataBind();
            
        }
    }
}