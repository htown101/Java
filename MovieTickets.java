/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package movietickets;
import java.util.Scanner;
/**
 *
 * @author H-Town
 */
public class MovieTickets {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // Initialize 2-D array and fill with seat prices
        int [][] seats = new int[8][10];
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 10; j++)
            {
                seats[i][j] = 10;
            }
        }
        seats[3][0] = 10;
        seats[3][1] = 10;
        int i =3;
        for (int j=2; j < 8; j++)
        {
            seats[i][j] = 20;
        }
        seats[3][8] = 10;
        seats[3][9] = 10;
        i = 4;
        seats[i][0] = 10;
        seats[i][1] = 10;
        for (int j=2; j < 8; j++)
        {
            seats[i][j] = 20;
        }
        seats[i][8] = 10;
        seats[i][9] = 10;    
        i=5;
        seats[i][0] = 20;
        seats[i][1] = 20;
        seats[i][2] = 30;
        seats[i][3] = 30;
        seats[i][4] = 40;
        seats[i][5] = 40;
        seats[i][6] = 30;
        seats[i][7] = 30;
        seats[i][8] = 20;
        seats[i][9] = 20;
        i=6;
        seats[i][0] = 20;
        seats[i][1] = 30;
        seats[i][2] = 30;
        seats[i][3] = 40;
        seats[i][4] = 40;
        seats[i][5] = 50;
        seats[i][6] = 50;
        seats[i][7] = 30;
        seats[i][8] = 30;
        seats[i][9] = 20;
        i=7;
        seats[i][0] = 30;
        seats[i][1] = 40;
        seats[i][2] = 40;
        seats[i][3] = 50;
        seats[i][4] = 50;
        seats[i][5] = 50;
        seats[i][6] = 50;
        seats[i][7] = 50;
        seats[i][8] = 40;
        seats[i][9] = 30;
        
        // Print out numbers for rows and columns
        System.out.print("   ");
        for (i=1; i <=10; i++)
        {
            System.out.print(i);
            System.out.print("  ");
        }
        System.out.println();
        System.out.println();
        i=1;
        for (int f=0; f <8; f++)
        {   
            System.out.print(i);
            System.out.print("  ");
            for (int d=0; d <10; d++)
            {
                System.out.print(seats[f][d]);
                System.out.print(" ");
            }
            System.out.println();
            i++;
        }
        
        Scanner in = new Scanner(System.in);
        String answer;
        String useranswer;
        // User enters "seat" or "price"
        // Put in a while loop untill user enters q 
        System.out.print("Press any key to continue (q for quit): ");
        useranswer = in.next();
        while( !useranswer.equals("q") )
        {
            System.out.print("Please choose 'seat' or 'price': ");
            answer = in.next();

            if (answer.equals("seat"))
            {
                SeatNumber(seats);
            }
            else 
            {
                Price(seats);
            }

            // Print out results of new seating chart
            for (int f=0; f <8; f++)
            {
                for (int d=0; d <10; d++)
                {
                    System.out.print(seats[f][d]);
                    System.out.print(" ");
                }
                System.out.println();
            }
          System.out.print("Press any key to continue (q for quit): ");
          useranswer = in.next();
        }
       
    }
    // Takes the seating array
    // Only works for values of [0[0] - [4][2]
    public static void Price(int [][] seats)
    {
        int price;
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter the price (10-50): ");         // Ask user for price by increments of 10
        price = in.nextInt();
        for (int f=0; f <8; f++)
        {
            for (int d=0; d <10; d++)
            {
                if ( price == seats[f][d])
                {
                    System.out.print(seats[f][d]);
                    System.out.print(" ");
                }
                else
                {
                    System.out.print("**");
                    System.out.print(" ");
                }
            }
            System.out.println();
        }   
        SeatNumber(seats);              // Call the SeatsNumber method
    }
    
    // Takes the seating array
    // Only works for values of [0[0] - [4][2]
    public static void SeatNumber(int [][] seats)
    {
        String seatans;
        Scanner in = new Scanner(System.in);
        int row, col;
        System.out.println("Please enter the row (1-8): ");                 // Ask for user to input row and column numbers
        row = in.nextInt();                 
        row--;                                                              // Decrement row and column to match array numbers starting from 0
        System.out.println("Please enter the column(1-10): ")   ;
        col = in.nextInt();
        col--;
        for (int i=0; i < 8; i++)
        {
            for (int j=0; j < 10; j++)
            {
                if ( seats[i][j] == seats[row][col])
                {
                    System.out.print("You have chosen: ");
                    System.out.println(seats[row][col]);
                    if ( seats[row][col] != 0)                      // Determine if seat is avalible
                    {
                        System.out.println("This seat is availble.");
                        System.out.println("Would you like this seat (y/n)? ");
                        seatans = in.next();
                        if ( seatans.equals("y"))
                        {
                            System.out.println("Thank you for your purchase.");
                            seats[row][col] = 0; 
                        }
                        else if (seatans.equals("n"))
                        {
                            return;
                        }
                        else
                        {
                            System.out.println("This seat is unavailble. Please choose another.");
                        }   
                    } 
                }  
            }
        }
    }
}
