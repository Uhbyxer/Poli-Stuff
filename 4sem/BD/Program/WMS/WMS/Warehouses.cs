//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан по шаблону.
//
//     Изменения, вносимые в этот файл вручную, могут привести к непредвиденной работе приложения.
//     Изменения, вносимые в этот файл вручную, будут перезаписаны при повторном создании кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace WMS
{
    using System;
    using System.Collections.Generic;
    
    public partial class Warehouses
    {
        public Warehouses()
        {
            this.Cells = new HashSet<Cells>();
        }
    
        public int ID { get; set; }
        public string Name { get; set; }
    
        public virtual ICollection<Cells> Cells { get; set; }
    }
}
