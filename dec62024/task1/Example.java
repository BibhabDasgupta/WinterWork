public class Example {
    // Define a field
    public String message = "Hello from Java!";


     public void printMessage() {
        System.out.println("Message from Java: " + message);
    }

    // Native method declaration
    public native void printMessage(Example obj);

    // Load the native library
    static {
        System.loadLibrary("example"); // Load the shared library (libexample.so)
    }

    public static void main(String[] args) {
        Example example = new Example();
        example.printMessage(example); // Pass the object to the native method
    }
}
