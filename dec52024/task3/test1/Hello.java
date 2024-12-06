public class Hello {
    static {
        System.load("/home/bibhab/Pingyy/test1ext/libhello.so"); // Load the C library (hello.so)
    }

    private native void sayHello();

    public static void main(String[] args) {
        new Hello().sayHello();
    }
}
