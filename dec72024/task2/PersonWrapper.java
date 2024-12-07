public class PersonWrapper {
    static {
        // Load the native library that contains the C functions
        System.loadLibrary("person"); // Name of the C library (person.so or person.dll)
    }

    // Native methods corresponding to C functions
    private native long createPerson(String name, int age);
    private native void setName(long personPtr, String name);
    private native String getName(long personPtr);
    private native void setAge(long personPtr, int age);
    private native int getAge(long personPtr);
    private native void freePerson(long personPtr);

    // Instance variable to store the C object pointer
    private long personPtr;

    // Constructor to create the C object
    public PersonWrapper(String name, int age) {
        this.personPtr = createPerson(name, age);
    }

    // Methods to interact with the C object
    public void setName(String name) {
        setName(personPtr, name);
    }

    public String getName() {
        return getName(personPtr);
    }

    public void setAge(int age) {
        setAge(personPtr, age);
    }

    public int getAge() {
        return getAge(personPtr);
    }

    // Destructor to free the C object
    @Override
    protected void finalize() throws Throwable {
        freePerson(personPtr);
        super.finalize();
    }
}
