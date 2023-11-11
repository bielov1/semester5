package blockchain.basic;

public class Transaction {
	private String senderBOD;
	private String recipientBOD;
	private int amountBOD;
	
	public Transaction(String sender, String recipient, int amount) {
		this.senderBOD = sender;
		this.recipientBOD = recipient;
		this.amountBOD = amount;
	}
	
	
	public String getSenderBOD() {
		return senderBOD;
	}
	
	public String getRecipientBOD() {
		return recipientBOD;
	}
	
	public int getAmountBOD() {
		return amountBOD;
	}
}
