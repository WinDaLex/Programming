/*
 * UVaOJ 748
 * Exponentiation
 * by A Code Rabbit
 */

import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            BigDecimal r = cin.nextBigDecimal();
            int n = cin.nextInt();
            BigDecimal ans = r.pow(n).stripTrailingZeros();
            System.out.println(ans.toPlainString().replaceAll("^0", ""));
        }
    }
}
