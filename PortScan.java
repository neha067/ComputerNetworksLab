import java.net.*;
public class PortScan{
    public static void main(String args[]) {
        int startport = 0;
        int endport = 0;
        startport = Integer.parseInt(args[0]);
        endport = Integer.parseInt(args[1]);
        for (int i = startport; i <= endport; i++) {
            try {
                Socket servSocket = new Socket("127.0.0.1",i);
                System.out.println("port in use:    "+i);
            } catch (Exception e) {
                System.out.println("Port not in use: " + i );
            }
        }
    }
}