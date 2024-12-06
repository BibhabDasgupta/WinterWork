import java.util.Scanner;

public class Print {

    private native float printValues(int intVal, float floatVal);

    static {
        System.loadLibrary("print"); 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int intVal = scanner.nextInt();

        System.out.print("Enter a float: ");
        float floatVal = scanner.nextFloat();

        float result=new Print().printValues(intVal, floatVal);

        // Print the result
        System.out.println("The sum of the integer and float is: " + result);
        scanner.close();
    }
}
