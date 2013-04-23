package karel;

//Objects karel can pick up

import java.awt.*;
import java.net.*;
import javax.swing.*;

public class Gem extends Entity
{
    //constructor
    public Gem(int x,int y)
    {
        super(x,y);
    }
     private Image image;
    {
        URL loc = this.getClass().getResource("gem.png");
        ImageIcon iia = new ImageIcon(loc);
        image = iia.getImage();
        this.setImage(image);
    }
}
