//Design a TCP iterative Client and Server application to reverse the given input sentence.
//server.c
import java.io.*;
import java.net.*;

public class TCPServer {
    public static final int MYPORT = 13153;

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(MYPORT)) {
            System.out.println("Server: I am waiting -- Start of Main Loop");
            while (true) {
                Socket connectionSocket = serverSocket.accept();
                InetAddress clientAddress = connectionSocket.getInetAddress();
                System.out.println("Connection from " + clientAddress.getHostAddress());
                readString(connectionSocket);
                connectionSocket.close();
                System.out.println("Finished Serving One Client");
            }
        } catch (IOException e) {
            System.err.println("Server Error: " + e.getMessage());
        }
    }

    public static void readString(Socket socket) {
        try {
            InputStream input = socket.getInputStream();
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = input.read(buffer)) != -1) {
                baos.write(buffer, 0, bytesRead);
            }

            String received = baos.toString("UTF-8");
            System.out.println("Server: Received   " + received);

            String reversed = new StringBuilder(received).reverse().toString();
            System.out.println("Reversed string is: " + reversed);
        } catch (IOException e) {
            System.err.println("Error reading string: " + e.getMessage());
        }
    }
}
//output
$ java TCPServer
Server: I am waiting -- Start of Main Loop
Connection from 127.0.0.1
Server: Received   Network Programming
Reversed string is: gnimmargorP krowteN
Finished Serving One Client
Server: I am waiting -- Start of Main Loop


//client.c
import java.io.*;
import java.net.*;

public class TCPClient {
    public static final int MAXBUFFER = 1024;

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Please specify server IP and Port number.");
            return;
        }

        String serverIP = args[0];
        int serverPort = Integer.parseInt(args[1]);

        try (Socket socket = new Socket(serverIP, serverPort)) {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter sentence (end input with #): ");
            StringBuilder text = new StringBuilder();
            int ch;
            while ((ch = reader.read()) != -1 && (char) ch != '#') {
                text.append((char) ch);
            }

            sendString(socket, text.toString());
        } catch (IOException e) {
            System.err.println("Cannot connect to server: " + e.getMessage());
        }
    }

    public static void sendString(Socket socket, String message) {
        try {
            OutputStream output = socket.getOutputStream();
            byte[] buffer = message.getBytes();
            int bytesWritten = 0;

            while (bytesWritten < buffer.length) {
                int written = Math.min(MAXBUFFER, buffer.length - bytesWritten);
                output.write(buffer, bytesWritten, written);
                bytesWritten += written;
            }

            System.out.println("String: \"" + message + "\" sent to server");
        } catch (IOException e) {
            System.err.println("Error sending string: " + e.getMessage());
        }
    }
}
//output
$ java TCPClient 127.0.0.1 13153
Enter sentence (end input with #): Network Programming#
String: "Network Programming" sent to server

