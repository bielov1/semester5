package blockchain.basic;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import com.google.gson.Gson;
import com.google.gson.JsonSyntaxException;

import spark.Spark;

public class Controller {
	public static void main2(String[] args) {
		
		Spark.port(4568);	
		Blockchain blockchain = new Blockchain();
		Gson gson = new Gson();
		
		// Для створення нової транзакції в блоці
		Spark.post("/transactions/new", (req, res) -> {
			try {
			//Створюємо об'єкт транзакції за отриманими даними з запиту
				Transaction transaction = gson.fromJson(req.body(), Transaction.class);
				//Додаємо нову транзакцію
				int index = blockchain.newTransactionBOD(transaction.getSenderBOD(), 
														 transaction.getRecipientBOD(), 
														 transaction.getAmountBOD());
				//Якщо помилок не відбулося, то відправляємо відповідь 
				res.status(201);
				return "Transaction will be added to Block " + index;
			} catch(JsonSyntaxException e) {
				//Якщо запит має неправильну структуру - повертаємо помилку
				res.status(400);
				return "Invalid JSON";
			}
		});
				
		
		// Щоб вказати серверу, що потрібно майнити новий блок
		Spark.get("/mine", (req, res) -> {
			//Отримаємо станній блок у блокчейні
			Block lastBlock = blockchain.lastBlockBOD();
			
			//Отримаємо останнє підтвердження роботи
			int lastProof = lastBlock.getProofBOD();
			
			//Отримаємо нове підтвердження роботи
			int proofOfWork = blockchain.proofOfWorkBOD(lastProof);
			
			//створюємо нову транзакцію
			blockchain.newTransactionBOD("0", UUID.randomUUID().toString().replace("-", ""), 1);
			
			//Отримуємо останній хеш у блокчейні
			String lastHash = Blockchain.hashBOD(lastBlock);
			
			//Створюємо новий блок
			Block newBlock = blockchain.newBlockBOD(proofOfWork, lastHash);
			
			//Створюємо рядок, що є відображенням нового блока
			String json = gson.toJson(newBlock);
			
			//Ставимо статус відповіді 200
			res.status(200);
			
			//Відправляємо відомості про новий блок
			return json;
		});
		
		
		// Для повернення всього блокчейну
		Spark.get("/chain", (req, res) -> {
//			Map<String, Object> response = new HashMap<>();
//			response.put("chain", blockchain.chainBOD);
//			response.put("length", blockchain.chainBOD.size());
//			
//			String json = gson.toJson(response);
//			res.status(202);
//			return json;
			
			res.type("application/json");
			return gson.toJson(blockchain.chainBOD).toString();
		});
	}
}
