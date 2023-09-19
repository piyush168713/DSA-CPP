// Inheritance

// extends is for extending a class

class Animal{
    void eat(){
        System.out.println("Superclass defined");
    }
}

class dog extends Animal{
    void bark(){
        System.out.println("Dog barks");
    }
}

class cat extends Animal{
    void run(){
        System.out.println("Meow meow");
    }
}

class inheritance_13 {
    public static void main(String[] args) {
        dog d1 = new dog();
        d1.bark();
        d1.eat();
        
        cat c1 = new cat();
        c1.run();
        c1.eat();
    }
}