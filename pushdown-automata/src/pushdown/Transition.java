/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pushdown;

/**
 *
 * @author wellington
 */
public class Transition {
    private Integer from;
    private Character symbol;
    private Character fromStack;
    private String toStack;
    private Integer to;

    public Transition(Integer from, Character symbol, Character fromStack, String toStack, Integer to) {
        this.from = from;
        this.symbol = symbol;
        this.fromStack = fromStack;
        this.toStack = toStack;
        this.to = to;
    }

    public Transition() {
    }

    public Integer getFrom() {
        return from;
    }

    public void setFrom(Integer from) {
        this.from = from;
    }

    public Character getSymbol() {
        return symbol;
    }

    public void setSymbol(Character symbol) {
        this.symbol = symbol;
    }

    public Character getFromStack() {
        return fromStack;
    }

    public void setFromStack(Character fromStack) {
        this.fromStack = fromStack;
    }

    public String getToStack() {
        return toStack;
    }

    public void setToStack(String toStack) {
        this.toStack = toStack;
    }

    public Integer getTo() {
        return to;
    }

    public void setTo(Integer to) {
        this.to = to;
    }
    
    
}
