/*
 * Why use Java interface?

 *  There are mainly three reasons to use interface. They are given below.

 *  It is used to achieve abstraction.
 *  By interface, we can support the functionality of multiple inheritance.
 *  It can be used to achieve loose coupling.
 *
 * define once and implement anywhere and anytime
*/

interface drawable{
    void draw();
}

class circle implements drawable{
    public void draw(){
        System.out.println("Draw Circle");
    }
}

class rect implements drawable{
    public void draw(){
        System.out.println("Draw Rectangle");
    }
}

public class interface_12 {
    public static void main(String[] args) {
        drawable dr = new circle();
        drawable dr1 = new rect();
        
        dr.draw();
        dr1.draw();
    }
}
