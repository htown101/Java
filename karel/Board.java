/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package karel;
import java.awt.*;
import java.util.*;
import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import javax.swing.JPanel;

public class Board extends JPanel
{
    private final int OFFSET = 30;
    private final int SPACE = 20;
    private final int LEFT_COLLISION = 1;
    private final int RIGHT_COLLISION = 2;
    private final int TOP_COLLISION = 3;
    private final int BOTTOM_COLLISION = 4;

    private ArrayList areas = new ArrayList();
    private int w = 0;
    private int h = 0;
    private ArrayList walls = new ArrayList();//walls in world
    private ArrayList gems = new ArrayList(); //gems in world
   // private boolean isRunning = true; //game ending bool
    Wall home = new Wall(0,0); // home space
    Player player; //object for karel
    
    public static String level =
              "####################\n"
            + "#        $         #\n"
            + "#       $#$        #\n"
            + "#      $###$       #\n"
            + "#     $#####$      #\n"
            + "#    $#######$     #\n"
            + "#   $#########$    #\n"
            + "#  $###########$   #\n"
            + "#^ #############$ .#\n"
            + "####################\n";
    
    public int getBoardWidth() 
    {
        return this.w;
    }

    public int getBoardHeight() 
    {
        return this.h;
    }

    public void initWorld()
    {
        Wall wall;
        Gem gem;
     
        int x = 30;
        int y = 30; 
        
         for (int i = 0; i < level.length(); i++)
        {
            //Grab the item in string at i
            char item = level.charAt(i); 

            //Adjust X,Y value based on what character is at i
            //and create an item in the array list if needed
            if (item == '\n')
            {
                y += 1;
                x = 0;
            }
            else if (item == '#')
            {
                wall = new Wall(x,y);
                walls.add(wall);
                x += 1;
            }
            else if (item == '^')
            {
                player = new Player(x,y);
                x += 1;
            }
            else if (item == '$')
            {
                gem = new Gem(x,y);
                gems.add(gem);
                x += 1;
            }
            else if (item == '.')
            {
                home.SetX(x);
                home.SetY(y);
                x += 1;
            }
            else if (item == ' ')
            {
                x += 1;
            }
        }
    
    }
    public void buildWorld(Graphics g) 
    {
        g.setColor(new Color(250, 240, 170));
        g.fillRect(0, 0, this.getWidth(), this.getHeight());
        ArrayList world = new ArrayList();
        world.addAll(walls);
        world.addAll(areas);
        world.addAll(gems);
        world.add(player);
        for (int i = 0; i < world.size(); i++) 
        {
            Entity item = (Player) world.get(i);
            if ((item instanceof Player) || (item instanceof Wall))
            {
                 g.drawImage(item.getImage(), item.GetX() + 2, item.GetY() + 2, this);
            } 
            else 
            {
                g.drawImage(item.getImage(), item.GetX(), item.GetY(), this);
            }
        }
    }

    @Override
    public void paint(Graphics g) 
    {
        super.paint(g);
        buildWorld(g);
    }
}


