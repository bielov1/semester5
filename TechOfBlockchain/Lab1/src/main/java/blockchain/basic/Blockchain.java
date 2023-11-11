package blockchain.basic;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.google.common.hash.Hashing;

public class Blockchain {
	List<Block> chainBOD = new ArrayList<>();
	List<Transaction> currentTransactionsBOD = new ArrayList<>();
	
	public Blockchain() {
		newBlockBOD(1, "BIELOV0000000000000000000000000000000000000000000000000022112003");
	}
	
	
	public Block newBlockBOD(int proof, String previousHash) {
		List<Transaction> transactions = this.currentTransactionsBOD.stream().collect(Collectors.toList());
		Block newBlock = new Block(this.chainBOD.size()+1, proof, previousHash, transactions);
		this.currentTransactionsBOD.clear();
		this.chainBOD.add(newBlock);
		return newBlock;
	}
	
	
	public int newTransactionBOD(String sender, String recipient, int amount) {
		this.currentTransactionsBOD.add(new Transaction(sender, recipient, amount));
		return this.chainBOD.size();
	}
	
	public static String hashBOD(Block block) {
		StringBuilder hashingInputBuilder = new StringBuilder();
		hashingInputBuilder
			.append(block.getIndexBOD())
			.append(block.getTimestampBOD())
			.append(block.getProofBOD())
			.append(block.getPreviousHashBOD());
		
		String hashingInput = hashingInputBuilder.toString();
		
		return Hashing.sha256().hashString(hashingInput, StandardCharsets.UTF_8).toString();
	}
	
	public Block lastBlockBOD() {
		return this.chainBOD.size() > 0? this.chainBOD.get(this.chainBOD.size() - 1) : null;
	}
	
	public int proofOfWorkBOD(int lastProofOfWork) {
		int proof = 0;
		while(!isProofValidBOD(lastProofOfWork, proof)) {
			proof++;
		}
		return proof;
	}
	
	private boolean isProofValidBOD(int lastProof, int proof) {
		String guessString = Integer.toString(lastProof) + Integer.toString(proof);
		String guessHash = Hashing.sha256().hashString(guessString, StandardCharsets.UTF_8).toString();
		return guessHash.endsWith("11");
	}
}
