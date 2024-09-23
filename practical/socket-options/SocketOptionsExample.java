
import java.io.*;
import java.net.*;

public class SocketOptionsExample {

    public static void main(String[] args) {
        try {
            // Create a server socket bound to port 8080
            ServerSocket serverSocket = new ServerSocket(8080);

            // Accept incoming client connection
            Socket clientSocket = serverSocket.accept();

            // Set socket options
            clientSocket.setKeepAlive(true);  // SO_KEEPALIVE
            clientSocket.setSoLinger(true, 5);  // SO_LINGER (linger for 5 seconds)
            clientSocket.setSendBufferSize(4096);  // SO_SNDBUF (send buffer size)
            clientSocket.setReceiveBufferSize(4096);  // SO_RCVBUF (receive buffer size)
            clientSocket.setTcpNoDelay(true);  // TCP_NODELAY

            // Get and print socket option values
            System.out.println("SO_KEEPALIVE: " + clientSocket.getKeepAlive());
            System.out.println("SO_LINGER: " + clientSocket.getSoLinger());
            System.out.println("SO_SNDBUF: " + clientSocket.getSendBufferSize());
            System.out.println("SO_RCVBUF: " + clientSocket.getReceiveBufferSize());
            System.out.println("TCP_NODELAY: " + clientSocket.getTcpNoDelay());

            // Handle client communication
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                out.println(inputLine);
            }

            // Close the client socket and server socket
            clientSocket.close();
            serverSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
