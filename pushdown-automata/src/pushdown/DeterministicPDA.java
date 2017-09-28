/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pushdown;

import java.util.Arrays;
import java.util.Stack;

/**
 *
 * @author wellington
 */
public class DeterministicPDA {

    private Stack<Character> stack;
    private Integer currentState;
    private InfoPDA info;

    public DeterministicPDA(InfoPDA info) {
        this.info = info;
    }

    public Boolean run(String tape) {
        currentState = info.getStartState();
        for (Character c : tape.toCharArray()) {
            Character s = stack.peek();
            Transition t = delta(currentState, c, s);
            if (t == null){
                return false;
            }
            stack.pop();
            currentState = t.getTo();
            String to = t.getToStack();
            for (int i = to.length()-1; i >=0; i--){
                stack.push(to.charAt(i));
            }
        }
        return info.getFinalStates().contains(currentState);
    }

    private Transition delta(Integer state, Character c, Character s) {
        for (Transition t : info.getTransitions()) {
            if (t.getFrom() == state && t.getSymbol() == c && t.getFromStack() == s) {
                return t;
            }
        }
        return null;
    }

}
