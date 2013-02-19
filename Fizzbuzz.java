/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fizzbuzz;

/**
 *
 * @author H-Town
 */
public class Fizzbuzz {

    /**
     * @param args the command line arguments
     */
    // If number is divisible by 3 print "fizz"
    // If number is divisible by 5 print "buzz"
    // If number is divisible by both print "fizzbuzz"
    public static void main(String[] args) 
    {
        for(int i=0; i <= 100; i++)
        {
            if (( i % 3 == 0) && (i % 5 == 0))
            {
                System.out.println("fizzbuzz");
            }
            else if ( i % 3 == 0)
            {
                System.out.println("fizz");
            }
            else if ( i % 5 == 0)
            {
                System.out.println("buzz");
            }
            
            else
            {
                System.out.println(i);
            }
        }
    }
}
