package com.example.money;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.NumberFormat;
import java.util.Locale;

public class moneyFrame extends JFrame implements
 ItemListener, KeyListener, MouseListener {
	 JComboBox<String> combo = new JComboBox<>();
	 JLabel fromCurrencySymbol = new JLabel(" ");
	 JTextField textField = new JTextField(5);
	 JLabel resultLabel = new JLabel(" ");
	 NumberFormat currencyUS = NumberFormat.getCurrencyInstance(Locale.US);
	 NumberFormat currencyUK = NumberFormat.getCurrencyInstance(Locale.UK);
	 
	 public moneyFrame() {
		 setLayout(new FlowLayout(FlowLayout.LEFT));
		 combo.addItem("US to UK");
		 combo.addItem("UK to US");
		 add(combo);
		 add(fromCurrencySymbol);
		 textField.setText("0.00");
		 add(textField);
		 add(resultLabel);
		 combo.addItemListener(this);
		 textField.addKeyListener(this);
		 resultLabel.addMouseListener(this);
		 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 setSize(500, 100);
		 setVisible(true);
	 }
	 
	 void setResultText() {
		 String fromCurrency = "";
		 String amountString = "";
		 double dollarToPound = 0.74;
		 
		 try {
			 double amount = Double.parseDouble(textField.getText());
			 if (combo.getSelectedItem().equals("US to UK")) {
				 amountString = " = " + currencyUK.format(amount * dollarToPound);
				 fromCurrency = "$";
			 }
			 
			 if (combo.getSelectedItem().equals("UK to US")) {
				 amountString = " = " + currencyUS.format(amount / dollarToPound);
				 fromCurrency = "\u00A3";
			 }
		 }
		 catch (NumberFormatException e) {
			 amountString = "Bad value " + e.getMessage();
		 }
		 
		 fromCurrencySymbol.setText(fromCurrency);
		 resultLabel.setText(amountString);
	 }
	 
	 @Override
	 
	 public void itemStateChanged(ItemEvent i) {
		 setResultText();
	 }
	 
	 @Override
	 
	 public void keyReleased(KeyEvent k) {
		 setResultText();
		 
	}
	
	@Override
	public void keyPressed(KeyEvent k) {
		
	}
	
	@Override
	public void keyTyped(KeyEvent k) {
		
	}
	
	@Override
	public void mouseEntered(MouseEvent m) {
		resultLabel.setForeground(Color.red);
	}
	@Override
	public void mouseExited(MouseEvent m) {
		resultLabel.setForeground(Color.black);
	}
	
	@Override
	public void mouseClicked(MouseEvent m) {
		
	}
	
	@Override
	public void mousePressed(MouseEvent m) {
		
	}
	
	@Override
	public void mouseReleased(MouseEvent m) {
		
	}
 }