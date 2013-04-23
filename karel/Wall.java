package karel;
import java.awt.Image;
import java.net.URL;
import javax.swing.ImageIcon;
//Objects karel cannot move to
public class Wall extends Entity
{
    //constructor
    public Wall(int x,int y)
    {
        super(x,y);
        
    }
   private Image image;
    {
        URL loc = this.getClass().getResource("wall.png");
        ImageIcon iia = new ImageIcon(loc);
        image = iia.getImage();
        this.setImage(image);
    }
}