#include <iostream>
#include <string>

using namespace std;

template<class T>
class NodeType {
public:
	T info;
	NodeType<T> * link;
};

template<class T>
class Queue{
	NodeType<T> * queueFront;
	NodeType<T> * queueRear;
	int count;

public:
	Queue(){
		queueFront = NULL;
		queueRear = NULL;
		count = 0;
	}

	~Queue(){
		NodeType<T> * current = queueFront;

		while (current != NULL){
			current = current->link;
			delete queueFront;
			queueFront = current;
		}
		
		queueRear = NULL;
		count = 0;
	}

	void addQueue(T elem){
		if (queueFront != NULL){
			NodeType<T> * newNode = new NodeType<T>;
			newNode->link = NULL;
			newNode->info = elem;
			queueRear->link = newNode;
			queueRear = newNode;

			count++;
		}
		else{
			NodeType<T> * newNode = new NodeType<T>;
			newNode->link = NULL;
			newNode->info = elem;
			queueFront = queueRear = newNode;
			count++;
		}
	}

	T deleteQueue(){
		if (queueFront != NULL){
			NodeType<T> * toBeDeleted = queueFront;
			queueFront = queueFront->link;
			T value = toBeDeleted->info;
			delete toBeDeleted;
			count--;

			return value;
		}
		else{
			cout << "The Queue is empty bro." << endl;
			abort();
		}
	}

	bool isEmpty(){
		return (count == 0);
	}

	int getSize(){
		return count;
	}
};

int main(){

	Queue<string> q2;
	string word;
	cout << "Input a sentence ending with space-period ( .) :" << endl;
	cin >> word;

	while ( word != "."){
		q2.addQueue(word);
		cin >> word;
	}

	cout << "Breaking down the sentence into ites words: " << endl;
	while (! q2.isEmpty()){
		cout << q2.deleteQueue() << endl;
	}

	cin >> word;
	
	return 0;
}