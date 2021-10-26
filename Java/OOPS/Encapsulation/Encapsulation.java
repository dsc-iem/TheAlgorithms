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
