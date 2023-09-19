class Vehicle {
    void print(){
        System.out.println("Parent Function");
    }
}

public class functionOverriding_15 extends Vehicle {
    @Override
    void print(){
        System.out.println("Child Function");
    }
    public static void main(String[] args) {
        functionOverriding_15 newObj = new functionOverriding_15();
        newObj.print();
    }
}