public class StringF {

    private native String modifyString(String input);

    static {
        System.loadLibrary("stringf"); 
    }

    public static void main(String[] args) {
        StringF stringf = new StringF();
        
        String input = "Original_String";
        
        String result = stringf.modifyString(input);

        System.out.println("Modified String: " + result);
    }
}
