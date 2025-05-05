//Design a TCP iterative Client and Server application to reverse the given input sentence.
//server.c
import java.io.*;
import java.net.*;
public class ReverseServer {
    public static void main(String[] args) {
        int port = 5000;
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started. Listening on port " + port);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                String inputLine;
                while ((inputLine = in.readLine()) != null) {
                    if (inputLine.equalsIgnoreCase("exit")) {
                        System.out.println("Client requested termination.");
                        break;
                    }
                    String reversed = new StringBuilder(inputLine).reverse().toString();
                    out.println(reversed);
                }
                clientSocket.close();
                System.out.println("Client disconnected.\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//output
Server started. Listening on port 5000
Client connected: /127.0.0.1
Client requested termination.
Client disconnected.



//client.c
import java.io.*;
import java.net.*;
public class ReverseClient {
    public static void main(String[] args) {
        String serverAddress = "localhost";
        int port = 5000;
        try {
            Socket socket = new Socket(serverAddress, port);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println("Connected to server at " + serverAddress + ":" + port);            String input;
            while (true) {
                System.out.print("Enter a sentence (or type 'exit' to quit): ");
                input = userInput.readLine();
                out.println(input);
                if (input.equalsIgnoreCase("exit")) {
                    break;
                }
                String response = in.readLine();
                System.out.println("Reversed: " + response);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//output
Connected to server at localhost:5000
Enter a sentence (or type 'exit' to quit): hello world
Reversed: dlrow olleh
Enter a sentence (or type 'exit' to quit): Java is fun
Reversed: nuf si avaJ
Enter a sentence (or type 'exit' to quit): exit


