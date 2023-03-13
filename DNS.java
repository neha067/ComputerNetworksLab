import java.net.*;
import java.util.*;

public class DNS {

    public static void main(String args[]) throws Exception {
        
        try
        {
            Scanner in = new Scanner(System.in);
            System.out.println("\nEnter Host Name:  ");
            String hname= in.nextLine();
            InetAddress address;
            address = InetAddress.getByName(hname);
            System.out.println("Host Name: " + address.getHostName());
            System.out.println("IP: " + address.getHostAddress());
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
