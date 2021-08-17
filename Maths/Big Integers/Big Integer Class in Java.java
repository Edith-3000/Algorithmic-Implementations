// ADDING 2 BIG INTEGERS

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void addBigIntegers(){
	    BigInteger b1 = new BigInteger("67987966545454485765463546354354465");
	    BigInteger b2 = new BigInteger("1654646654864645");
	    b1 = b1.add(b2);
	    
	    System.out.println(b1);
	}
	
	public static void main(String[] args) {
		addBigIntegers();
	}
}

/********************************************************************************************************/

// MULTIPLYING 2 BIG INTEGERS

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void multiplyBigIntegers(){
	    BigInteger b1 = new BigInteger("67987966545454485765463546354354465");
	    BigInteger b2 = new BigInteger("1654646654864645");
	    b1 = b1.multiply(b2);
	    
	    System.out.println(b1);
	}
	
	public static void main(String[] args) {
		multiplyBigIntegers();
	}
}

/********************************************************************************************************/

// COUNT TOTAL #BITS & #SET BITS IN BINARY REPRESENTATION

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void countBitsOfBigIntegers(){
	    BigInteger b1 = new BigInteger("67987966545454485765463546354354465");

	    System.out.println(b1);

	    // count total #bits in binary representation
	    System.out.println(b1.bitLength());
	    
	    // count total #set bits in binary representation
	    System.out.println(b1.bitCount());
	}
	
	public static void main(String[] args) {
		countBitsOfBigIntegers();
	}
}

/********************************************************************************************************/

// CONVERT Int TO BigInteger AND FINDING GCD

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void gcdOfBigIntegers(){
	    Scanner sc = new Scanner(System.in);
	    
	    int a = sc.nextInt();
	    int b = sc.nextInt();
	    
	    BigInteger aBig = BigInteger.valueOf(a);
	    BigInteger bBig = BigInteger.valueOf(b);
	    
	    System.out.println(aBig.gcd(bBig));
	}
	
	public static void main(String[] args) {
		gcdOfBigIntegers();
	}
}

/********************************************************************************************************/

// CONVERT GIVEN NUMBER IN GIVEN BASE SYSTEM TO DECIMAL SYSTEM

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void addBigIntegers(){
	    // intreprets the number in given base
	    BigInteger b = new BigInteger("1011", 2);
	    System.out.println(b);
    }
	
	public static void main(String[] args) {
		addBigIntegers();
	}
}

/********************************************************************************************************/

// CALCULATING POWER

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static void powerBigIntegers(){
	    BigInteger base = new BigInteger("154989464646878789");
	    int exp = 12; // the exponent can't be a BigInteger
	    
	    System.out.println(base.pow(exp));
    }
	
	public static void main(String[] args) {
		powerBigIntegers();
	}
}