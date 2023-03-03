package CheckPrime;

import java.util.Scanner;

public class Check {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int number = scanner.nextInt();

        if (number < 2) {
            System.out.println("The number is not prime.");
            scanner.close();
            return;
        }

        long startTime = System.currentTimeMillis();
        System.out.printf("The number is %sprime.\n", isPrime(number) ? " " : "not ");
        long endTime = System.currentTimeMillis();

        System.out.printf("Time: %d ms\n", endTime - startTime);

        scanner.close();
    }

    public static boolean isPrime(int number) {
        if (number == 2 || number == 3)
            return true;

        if (number < 2 || number % 2 == 0 || number % 3 == 0)
            return false;

        for (int i = 5; i <= Math.sqrt(number); i += 6)
            if (number % i == 0 || number % (i + 2) == 0)
                return false;

        return true;
    }
}
