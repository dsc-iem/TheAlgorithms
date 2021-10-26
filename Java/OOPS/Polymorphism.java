/*The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.*/

class Polymorphism{  
    public static void main(String args[]){  
        Bank b;  
        b=new SBI();  // Created an object of SBI
        System.out.println("SBI Rate of Interest: "+b.getRateOfInterest());  // The getRateOfInterest function of SBI class is called
        b=new ICICI();  
        System.out.println("ICICI Rate of Interest: "+b.getRateOfInterest());  // The getRateOfInterest function of ICICI class is called
        b=new AXIS();  
        System.out.println("AXIS Rate of Interest: "+b.getRateOfInterest());  // The getRateOfInterest function of AXIS class is called
    }  
}

class Bank{ 
    float getRateOfInterest(){return 0;}  
} 
 
class SBI extends Bank{  
    float getRateOfInterest(){return 8.4f;}  
}  

class ICICI extends Bank{  
    float getRateOfInterest(){return 7.3f;}  
}  

class AXIS extends Bank{  
    float getRateOfInterest(){return 9.7f;}  
}    

/*
    OUTPUT:
        SBI Rate of Interest: 8.4
        ICICI Rate of Interest: 7.3
        AXIS Rate of Interest: 9.7

*/
