package blockchain.basic;

import java.util.List;

public class Block {
	
	private int indexBOD;
	private long timestampBOD;
	private List<Transaction> transactionsBOD;
	private int proofBOD;
	private String previousHashBOD;
	
	public Block(int index, int proof, String previousHash,
			List<Transaction> transactions) {
		this.indexBOD = index;
		this.proofBOD = proof;
		this.previousHashBOD = previousHash;
		this.transactionsBOD = transactions;
		this.timestampBOD = System.currentTimeMillis();
	}
	
	public int getIndexBOD() {
		return indexBOD;
	}
	
	public long getTimestampBOD() {
		return timestampBOD;
	}
	
	public List<Transaction> getTransactionsBOD(){
		return transactionsBOD;
	}
	
	public int getProofBOD() {
		return proofBOD;
	}
	
	public String getPreviousHashBOD() {
		return previousHashBOD;
	}	
}
