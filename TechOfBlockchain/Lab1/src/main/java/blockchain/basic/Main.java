package blockchain.basic;

//import java.nio.charset.StandardCharsets;

import com.google.common.base.Charsets;
import com.google.common.hash.Hashing;

public class Main {
	public static void main(String[] args) {
		Blockchain MyBlockchain = new Blockchain();
		//int x = 5;
		//int y = 0;
		//int d = x * y;
		
		//System.out.println(MyBlockchain.proofOfWork(x*d));
//		while(!Hashing.sha256().hashString(Integer.toString(d), Charsets.UTF_8).toString().endsWith("22112003")) {
//			y++;
//			d = x * y;
//		}
//		System.out.println("The solution is y = " + y);
		
		//System.out.println("The solution for proof  = " + MyBlockchain.proofOfWorkBOD(x));
		//System.out.println(Hashing.sha256().hashString(Integer.toString((104 * x)), Charsets.UTF_8).toString());
		
		int count = 0;
		System.out.println("hash for " 
				   + MyBlockchain.lastBlockBOD().getIndexBOD()
				   + " block: "
				   + Blockchain.hashBOD(MyBlockchain.lastBlockBOD()));
		do {
			MyBlockchain.newBlockBOD(1, MyBlockchain.lastBlockBOD().getPreviousHashBOD());
			System.out.println("hash for " 
					   + MyBlockchain.lastBlockBOD().getIndexBOD()
					   + " block: "
					   + Blockchain.hashBOD(MyBlockchain.lastBlockBOD()));
	
			count++;
			
		} while (count < 4);
		
		// Підтвердження доказу
		int x = 0x22112003;
		int myProof = MyBlockchain.proofOfWorkBOD(x);
		System.out.println();
		System.out.println("The solution for proof = " + myProof);
		System.out.println(Hashing.sha256().hashString(Integer.toString(x) + Integer.toString(myProof), 
													   Charsets.UTF_8).toString());
		
	}
}
