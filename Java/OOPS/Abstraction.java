/*
 * Data Abstraction is defined as the process of reducing the object
 * to its essence so that only the necessary characteristics are exposed to the users.
 * Abstraction defines an object in terms of its
 * properties (attributes), behavior (methods), and interfaces (means of communicating with other objects).
 */
class Abstraction{  
    public static void main(String args[]){  
        Bike obj = new Honda();  
        obj.run();  
        obj.changeGear();  
    }  
}

abstract class Bike{  // Hiding the functionality of running the Bike and changing it's gears.
    Bike(){System.out.println("Bike is created");}  

    abstract void run();  

    void changeGear(){System.out.println("Gear changed");}  
}  

class Honda extends Bike{  
    void run(){
        System.out.println("Running safely..");
    }  
}  
