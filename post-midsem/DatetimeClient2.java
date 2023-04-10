import java.net.*;
import java.io.*;

public class DatetimeClient2 {

    public static void main(String[] args) throws UnknownHostException,IOException {
        
        Socket cs= new Socket("LocalHost",5000);
        
        BufferedReader fromserver=new BufferedReader(new InputStreamReader(cs.getInputStream()));
        
        System.out.println(fromserver.readLine());
        fromserver.close();
        cs.close();
        
    }
}
