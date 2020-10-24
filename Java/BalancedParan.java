import java.util.*;

public class BalancedParan {

    static boolean areParanthesisBalanced(String expr)//Function which takes in a string expression
            //then iterates through it and returns a boolean value depending on whether the expression is balanced or not
    {
        Deque<Character> stack = new ArrayDeque<Character>();

        for (int i = 0; i < expr.length(); i++) {
            char x = expr.charAt(i);

            if (x == '(' || x == '[' || x == '{') {
                stack.push(x);
                continue;
            }

            if (stack.isEmpty())
                return false;

            switch (x) {
                case ')':
                    stack.pop();
                    if (x == '{' || x == '[')
                        return false;
                    break;

                case '}':
                    stack.pop();
                    if (x == '(' || x == '[')
                        return false;
                    break;

                case ']':
                    stack.pop();
                    if (x == '(' || x == '{')
                        return false;
                    break;
            }
        }

        return (stack.isEmpty());
    }

    public static void main(String[] args)
    {
        String expr = "([{}])";//the epression which is to checked for paranthesis balancing
        if (areParanthesisBalanced(expr))
            System.out.println("Balanced ");
        else
            System.out.println("Not Balanced ");
    }
}