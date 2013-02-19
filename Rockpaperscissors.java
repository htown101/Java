/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rockpaperscissors;

/**
 *
 * @author Heather McMillen
 */
import java.util.Scanner;
import java.util.Random;
 
public class Rockpaperscissors 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Random generator = new Random(); 
        String answer;
        String selection;
        String choice;
        int GameCount =0;
        int Cwin =0, Pwin=0;
        String CompSelection;
        int compMove;
        CompSelection = "";
        Scanner in = new Scanner(System.in);
        Welcome();
        Rules();
        System.out.println("Would you like to play (y/n)? ");
        answer = in.next();
        while (answer.equals("y") || (answer.equals("Y")))
        {
            GameCount++;
            System.out.println("Please enter your choice (r,p,s): ");
            selection = in.next(); 
            
            System.out.println("The computer chose: ");
             compMove = generator.nextInt(3)+1;  
             switch(compMove)
            {
                case 1: CompSelection = "r"; break;
                case 2: CompSelection = "p"; break;
                case 3: CompSelection = "s"; break;
                default: System.out.println("Invalid selection. ");
            }
            System.out.println(CompSelection);
            
            choice = DetermineWinner(selection,CompSelection);
            if ( choice.matches("Player1"))
            {
                Pwin++;
            }
            else if (choice.matches("Computer"))
            {
                Cwin++; 
            }
            
            System.out.print("The score is: ");
            System.out.print("Player 1: ");
            System.out.println(Pwin);
            System.out.print("Computer: ");
            System.out.println(Cwin);
            System.out.print("Total games played: ");
            System.out.println(GameCount);
            System.out.println("Would you like to play? ");
            answer = in.next();    
        }
     }
public static void Welcome()
{
    System.out.println("Welcome to Rock,Paper,Scissors!!!");
    System.out.println();
}

public static void Rules()
{
    System.out.println("Player 1 chooses r-rock, p-paper, s-scissors, q-quit");
    System.out.println("Rock beats scissors, paper beats rock, and scissors cuts paper.");
}
// Method to Determine who won. 
// Parameters: User input and computer input Strings
// Returns: String - either Player 1 or Computer
public static String DetermineWinner(String selection, String CompSelection)
{ 
    if (selection.equals("r") && CompSelection.equals("p")|| selection.equals("p")&& CompSelection.equals("r") )
    {
        System.out.println("Paper covers Rock. ");
        if(CompSelection.equals("p"))
        {
            System.out.println("Computer wins.");
            return "Computer";
        }
        else
        {
            System.out.println("Player 1 wins.");
            return "Player 1";
        }
    }
    else if (selection.equals("r") && CompSelection.equals("s")|| selection.equals("s")&& CompSelection.equals("r"))
    {
        System.out.println("Rock beats Scissors.");
        if(CompSelection.equals("r"))
        {
            System.out.println("Computer wins.");
            return "Computer";
        }
        else
        {
            System.out.println("Player 1 wins.");
            return "Player 1";
        }
    }
    else if (selection.equals("p") && CompSelection.equals("s")|| selection.equals("s")&& CompSelection.equals("p"))
    {
        System.out.println("Scissors cuts Paper.");
        if(CompSelection.equals("s"))
        {
            System.out.println("Computer wins.");
            return "Computer";
        }
        else
        {
            System.out.println("Player 1 wins.");
            return "Player1";
        }
    }
    else if (selection.equals(selection) == CompSelection.equals(CompSelection))
    {
        System.out.println("It's a tie.");
        return "Tie";
    }
    return "";
}
}