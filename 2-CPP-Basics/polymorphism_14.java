// Polymorphism

class Animal{
    void bark(){
        System.out.println("Superclass defined");
    }
}

class dog extends Animal{
    void bark(){
        System.out.println("Dog barks");
    }
}

class cat extends Animal{
    void bark(){
        System.out.println("Meow meow");
    }
}

public class polymorphism_14 {
    public static void main(String[] args) {
        Animal a1 = new Animal();
        a1.bark();
        
        Animal d1 = new dog();
        d1.bark();
        
        Animal c1 = new cat();
        c1.bark();
    }
}