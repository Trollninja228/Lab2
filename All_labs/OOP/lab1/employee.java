package Labs.All_labs.OOP.lab1;

public class employee {
    public int empID;
    public String name;
    public String ssn;
    public double salary;

    public employee(){
        empID=0;
        name="None";
        ssn="None";
        salary=0;
    }
    public void setEmpId(int n){
        empID=n;
    }
    public void setName(String n){
        name=n;
    }
    public void setSSN(String n){
        ssn=n;
    }
    public void setSalary(double n){
        salary=n;
    }
    public int getEmpID(){
        return empID;
    }
    public String getName(){
        return name;
    }
    public String getSSN(){
        return ssn;
    }
    public double getSalary(){
        return salary;
    }
    public static void main(String[] args){

    }
}

