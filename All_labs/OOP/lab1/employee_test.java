package Labs.All_labs.OOP.lab1;
import Labs.All_labs.OOP.lab1.employee;


public class employee_test {
    public static void main(String[] args){
        employee emp=new employee();
        emp.setEmpId(101);
        emp.setName("Jane Smith");
        emp.setSSN ("012-34-5678");
        emp.setSalary(120_345.27);
        
        System.out.println("id: "+emp.getEmpID());
        System.out.println("Name: "+emp.getName());
        System.out.println("SSN: "+emp.getSSN());
        System.out.println("Salary: "+emp.getSalary());
    }
}
