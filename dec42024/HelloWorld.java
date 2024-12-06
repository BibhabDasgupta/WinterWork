public class HelloWorld {
    static {
        System.loadLibrary("hello"); // Load the C library (hello.so)
    }

    private native void sayHello();

    public static void main(String[] args) {
        new HelloWorld().sayHello();
    }
}
