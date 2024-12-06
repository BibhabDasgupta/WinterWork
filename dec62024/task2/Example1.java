// Example.java
public class Example1 {
    private String message;

    // Constructor
    public Example1(String message) {
        this.message = message;
    }

    // Getter for the message field
    public String getMessage() {
        return message;
    }

    // Native method that creates an Example object in C and returns it
    public native Example1 createObjectInC();

    static {
        System.loadLibrary("example1"); // Load the shared library (libexample.so)
    }

    public static void main(String[] args) {
        Example1 example = new Example1("Initial Message from Java");
        Example1 newExample = example.createObjectInC(); // Call native method

        // Print the message from the new Example object created in C
        System.out.println("Message from C-created object: " + newExample.getMessage());
    }
}
