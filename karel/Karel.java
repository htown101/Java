package karel;

import javax.swing.*;
     
 public final class Karel extends JFrame 
 {
    private final int OFFSET = 30;

    public Karel() 
    {
        InitUI();
    }

    public void InitUI() 
    {
        Board board = new Board();
        add(board);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(board.getBoardWidth() + OFFSET,
        board.getBoardHeight() + 2*OFFSET);
        setLocationRelativeTo(null);
        setTitle("Karel");
        
    }
    public static void main(String[] args) 
    {
        Karel karel = new Karel();
        karel.setVisible(true);
    }
}