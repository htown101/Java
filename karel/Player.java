package karel;

//Player class used to control karel the robot

import java.awt.*;
import java.net.*;
import javax.swing.*;

public class Player extends Entity
{
    char direction; //karels icon ^ > < v
    
    //Constructor - set Karel north
    public Player(int x,int y)
    {
        super(x,y);
        this.direction = '^';
        
        URL loc = this.getClass().getResource("Link.thunmbnail.png");
        ImageIcon iia = new ImageIcon(loc);
        Image image = iia.getImage();
        this.setImage(image);
        
        
    }
    
    //updates karels position
    public void move(int x, int y) 
    {
        int newX = this.GetX() + x;
        int newY = this.GetY() + y;
        this.SetX(newX);
        this.SetY(newY);
    }
    
    //moves karel to previous position to avoid collision
    public void moveBack(int x, int y) 
    {
        int newX = this.GetX() + x;
        int newY = this.GetY() + y;
        this.SetX(newX);
        this.SetY(newY);
    }
    
    public char GetDirection()
    {
        return this.direction;
    }
    
    public void SetDirection(char newDirection)
    {
        this.direction = newDirection;
    }
}
