import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user to input details for the person
        System.out.print("Enter the name of the person: ");
        String name = scanner.nextLine();
        System.out.print("Enter the age of the person: ");
        int age = scanner.nextInt();

        // Create a PersonWrapper object (which represents a C Person object)
        PersonWrapper person = new PersonWrapper(name, age);

        // Interact with the C object through the PersonWrapper class
        System.out.println("Created person: " + person.getName() + ", Age: " + person.getAge());

        // Modify the name and age
        person.setName("John Doe");
        person.setAge(30);
        System.out.println("Updated person: " + person.getName() + ", Age: " + person.getAge());

        // Clean up resources when done (finalize will be called automatically)
        scanner.close();
    }
}
