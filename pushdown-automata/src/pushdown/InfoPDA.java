/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pushdown;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author wellington
 */
public class InfoPDA {
    private Integer startState;
    private List<Integer> finalStates;
    private List<Transition> transitions;

    public InfoPDA() {
        finalStates = new ArrayList<>();
        transitions = new ArrayList<>();
    }

    public Integer getStartState() {
        return startState;
    }

    public void setStartState(Integer startState) {
        this.startState = startState;
    }

    public List<Integer> getFinalStates() {
        return finalStates;
    }

    public List<Transition> getTransitions() {
        return transitions;
    }
    
    
}
