import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            // Ask the user to select the library and functionality
            System.out.println("Select the library and functionality:");
            System.out.println("1. HelloWorld (sayHello)");
            System.out.println("2. StringF (modifyString)");
            System.out.println("3. Exit");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    // Load HelloWorld library and call sayHello
                    LibraryLoader.loadLibrary("HelloWorld");
                    HelloWorld helloWorld = new HelloWorld();
                    helloWorld.sayHello();
                    break;

                case 2:
                    // Load StringF library and call modifyString
                    LibraryLoader.loadLibrary("StringF");
                    System.out.print("Enter a string to modify: ");
                    String input = scanner.nextLine();
                    StringF stringF = new StringF();
                    String modifiedString = stringF.modifyString(input);
                    System.out.println("Modified string: " + modifiedString);
                    break;

                case 3:
                    // Exit the program
                    System.out.println("Exiting program...");
                    scanner.close();  // Close the scanner
                    return;  // Exit the loop and terminate the program

                default:
                    System.out.println("Invalid choice! Please select a valid option.");
            }
        }
    }
}
