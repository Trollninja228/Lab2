package Labs.All_labs.OOP.lab1;

public class EmployeeTest {
    public static void main(String[] args){
        Employee emp=new Employee();
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
