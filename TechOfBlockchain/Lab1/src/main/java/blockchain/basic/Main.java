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
		
		for(int i = 0 ; i < 4; ++i) {
			MyBlockchain.newBlockBOD(1, MyBlockchain.chainBOD.get(i).getPreviousHashBOD());
		}
		
		for(int j = 0; j < 5; ++j) {
			System.out.println("hash for " 
							   + MyBlockchain.chainBOD.get(j).getIndexBOD()
							   + " block: "
							   + Blockchain.hashBOD(MyBlockchain.chainBOD.get(j)));
		}
		
		// Підтвердження доказу
		int x = 2003;
		int myProof = MyBlockchain.proofOfWorkBOD(x);
		System.out.println();
		System.out.println("The solution for proof = " + myProof);
		System.out.println(Hashing.sha256().hashString(Integer.toString(x) + Integer.toString(myProof), 
													   Charsets.UTF_8).toString());
	}
}
