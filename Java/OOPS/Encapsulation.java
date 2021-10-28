/*
 * Encapsulation in Java is a mechanism of wrapping the data (variables) and
 * code acting on the data (methods) together as a single unit.
 * In encapsulation, the variables of a class will be hidden from other classes,
 * and can be accessed only through the methods of their current class.
 */
public class Encapsulation {  
    public static void main(String[] args) {  
        Account acc=new Account();    
        acc.setAcc_no(70535504000L);  
        acc.setName("Om Sharma");  
        acc.setEmail("om0312sharma@gmail.com");  
        acc.setAmount(500000f);    
        System.out.println(acc.getAcc_no()+" "+acc.getName()+" "+acc.getEmail()+" "+acc.getAmount());  
    }  
} 

class Account {  
    private long acc_no;  
    private String name,email;  
    private float amount;  
    public long getAcc_no() {  
        return acc_no;  
    }  

    public void setAcc_no(long acc_no) {  
        this.acc_no = acc_no;  
    }  

    public String getName() {  
        return name;  
    }  

    public void setName(String name) {  
        this.name = name;  
    }  

    public String getEmail() {  
        return email;  
    }  

    public void setEmail(String email) {  
        this.email = email;  
    }  

    public float getAmount() {  
        return amount;  
    }  

    public void setAmount(float amount) {  
        this.amount = amount;  
    }  

} 
