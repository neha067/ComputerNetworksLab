import java.net.*;
import java.io.*;
import java.util.Date;
public class DatetimeServer2 {
    public static void main(String[] args)throws IOException {
    
        ServerSocket ss= new ServerSocket(5000);
        System.out.println("waiting for connection....");
        Socket cs=ss.accept();
        
        Date d=new Date();
        String s="Current Date & Time on Server is:"+d;
        
        PrintWriter toclient=new PrintWriter(cs.getOutputStream(),true);
        toclient.print(s);
        
        toclient.close();
        cs.close();
        ss.close();
   
    }
}
/* instructions to run...
==> compile both programs in different terminals
==> first run server, then client
*/
 
