package com.cloudius.example;

public class Main {

  public static void main(String [] args) {
    Main.run();
  }

  public static void run(){
    int i =0;
    while(true){
	try{
	  Thread.sleep(1000);
	  System.out.println(i++);
	} catch (Exception e) {
	  System.err.println(e);
	}
    }
  }
}
