import java.util.HashSet;

public class LibraryLoader {
    // A set to keep track of loaded libraries
    private static final HashSet<String> loadedLibraries = new HashSet<>();

    // Synchronized method to load the library
    public static synchronized void loadLibrary(String libraryName) {
        if (!loadedLibraries.contains(libraryName)) {
            System.loadLibrary(libraryName); // Load the library
            loadedLibraries.add(libraryName); // Add to the set
            System.out.println("Library " + libraryName + " loaded successfully.");
        } else {
            System.out.println("Library " + libraryName + " is already loaded.");
        }
    }

    // Synchronized method to load a library using an absolute path
    public static synchronized void loadLibraryFromPath(String path) {
        if (!loadedLibraries.contains(path)) {
            System.load(path); // Load the library from the specified path
            loadedLibraries.add(path); // Add to the set
            System.out.println("Library at " + path + " loaded successfully.");
        } else {
            System.out.println("Library at " + path + " is already loaded.");
        }
    }
}
