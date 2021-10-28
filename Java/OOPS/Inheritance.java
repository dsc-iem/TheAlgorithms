/*
 * Inheritance in Java is a concept that acquires the properties from one class to other classes;
 * for example, the relationship between father and son.
 * In Java, a class can inherit attributes and methods from another class.
 * The class that inherits the properties is known as the sub-class or the child class.
 */
class one { // Parent class
    public void print_hello()
    {
        System.out.println("Hello!");
    }
}

class two extends one { // Child Class of one
    public void print_i_am() { System.out.print("I am "); }
}

class three extends two { // Child Class of two
    public void print_om()
    {
        System.out.println("Om");
    }
}

public class Inheritance {
    public static void main(String[] args)
    {
        three g = new three();
        g.print_hello();
        g.print_i_am();
        g.print_om();
    }
}
