package karel;

import java.awt.*;
import java.net.*;
import javax.swing.*;

public class Area extends Entity 
{
    public Area(int x, int y) 
    {
        super(x, y);
        URL loc = this.getClass().getResource("area.png");
        ImageIcon iia = new ImageIcon(loc);
        Image image = iia.getImage();
        this.setImage(image);
    }
}