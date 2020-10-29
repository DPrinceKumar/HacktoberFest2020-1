import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Stack;
import java.util.Arrays;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jannik.Richter
 */
public class Board {
    
    private class Coord {
        public int y;
        public int x;
        
        public Coord(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    private final int dim;     
    private final int[][] blocks; 
    
    /**
     * @description construct a board from an n-by-n array of blocks
     * (where blocks[i][j] = block in row i, column j)
     * @param blocks 
     */
    public Board(int[][] blocks)  {
        
        if(blocks == null) {
            throw new IllegalArgumentException();
        }
        
        // initialize Board
        this.dim = blocks[0].length;
        this.blocks = blocks.clone();
        
        getBlank();
    }         
    
    private Coord getBlank(){
        for(int i = 0; i < dim; i ++){
            for(int j = 0; j < dim; j++){
                if(blocks[i][j]==0){                    
                    return new Coord(i,j);
                }
            }
        }
        // if no blank space, basically not possible
        return null;
    }
    
    /**
     * @description board dimension n
     * @return 
     */                                 
    public int dimension() {
        return dim;
    }
    
    /**
     * @description number of blocks out of place
     * Quadratic array accesses
     * @return 
     */
    public int hamming() {
        
        int count = 0; // number of blocks out of place
        int index = 1; // position correct number allocation
        
        for(int i = 0; i < dim; i++) {
            for(int j = 0; j < dim; j++) {
                if(blocks[i][j] != index && blocks[i][j] != 0) { // do not compute if blank space
                    count++;
                }       
                
                index++;
            }
        }
        
        return count;
    }
    
    /**
     * @description sum of Manhattan distances between blocks and goal
     * Quadratic array accesses
     * @return 
     */
    public int manhattan() {
        
        int count = 0; // number of wrong positions        
      
        for(int i = 0; i < dim; i++) {
            for(int j = 0; j < dim; j++) {                
                if(blocks[i][j] != 0) { // if not empty
                    int adjusted = blocks[i][j] - 1; // adjust to allow for additional 1 to be in [0][0]
                    int x = adjusted % dim; // correct x position
                    int y =  (int) Math.floor(adjusted / dim); // correct y position
                    
                    count += Math.abs(y - i) + Math.abs(x - j);
                }              
            }
        }
        return count;
    }
    
    /**
     * @description is this board the goal board? 
     * Worst case quadratic array accesses 0(n^2)
     * @return 
     */
    public boolean isGoal() {
               
        for(int i = 0; i < dim; i++) {
            for(int j = 0; j < dim; j++) {                
                if(blocks[i][j] != 0) { // if not empty  
                   int loc = (i * dim) + j + 1; // correct location
                   if(blocks[i][j] != loc) {
                       return false;
                   }
                }              
            }
        }
        
        return true;
    }
    
    /**
     * @description a board that is obtained by exchanging any pair of blocks
     * @return 
     */
    public Board twin() {
        
        Board twin = new Board(blocks);
        Coord blank = getBlank();
        
        for(int y = 0; y < dim; y++) {            
            for(int x = 0; x < dim - 1; x++) {
                if((blank.y != y || blank.x != x) && (blank.y != y || blank.x != x + 1)) {                  
                    return new Board(exch(y, x, y, x + 1 ));
                }                 
            }
        }
        return twin;
    }
    
    private int[][] exch(int row, int col, int row1, int col1) {
        int[][] cpy = copy(blocks);
        int tmp = cpy[row][col];
        cpy[row][col] = cpy[row1][col1];
        cpy[row1][col1] = tmp;
        
        return cpy;
    }
    
    /**   
     * @description does this board equal y?
     * @param other
     * @return 
     */
    @Override
    public boolean equals(Object other) {
        if(other == this) return true;
        if(other == null) return false;
        if(other.getClass() != this.getClass()) return false;
        
        Board that = (Board) other;
        
        if(that.blocks.length != this.blocks.length) return false;
        if(that.blocks[0].length != this.blocks[0].length) return false;
        
        for(int i = 0; i < this.blocks.length; i++) {
            for(int j = 0; j < this.blocks[0].length; j++){
                if(this.blocks[i][j] != that.blocks[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private int[][] copy(int[][] a){
        int[][] b = new int[dim][dim];
        
        for(int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                b[i][j] = a[i][j];
            }
        }
        
        return b;
    }

    /**
     * @description all neighboring boards
     * @return 
     */
    public Iterable<Board> neighbors() {
        Stack<Board> boards = new Stack<>();
        Coord blank = getBlank();
        
        if(blank.x > 0) {         
            boards.push(new Board(exch(blank.y, blank.x, blank.y, blank.x - 1)));
        }
        
        if(blank.x < dim - 1) {
            boards.push(new Board(exch(blank.y, blank.x, blank.y, blank.x + 1)));
        }
        
        if(blank.y > 0) {
            boards.push(new Board(exch(blank.y, blank.x, blank.y - 1, blank.x)));
        }
        
        if(blank.y < dim - 1) {
            boards.push(new Board(exch(blank.y, blank.x, blank.y + 1, blank.x)));
        }
        
        return boards;
    }
    
    /**
     * @description string representation of this board (in the output format specified below)
     * @return 
     */
    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(dim).append("\n");
        for (int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                s.append(String.format("%2d ", blocks[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }

    /**
     * @description unit tests
     * @param args 
     */
    public static void main(String[] args) {
      
    }
}
