#include <iostream>
#include <string>

struct Data {
	char data;
};

struct Stack {
	Data digit;
	Stack* next;
};

Stack* top = nullptr;

Stack* push(Data digit);
void pop();
void printStack();
void findElement(char element);
void correctString();

int main() {
	int startCommand = -1;
	do {
		std::cout << "enter \"0\" to exit" << std::endl;
		std::cout << "enter \"1\" to check PUSH COMMAND" << std::endl;
		std::cout << "enter \"2\" to check POP COMMAND" << std::endl;
		std::cout << "enter \"3\" to check FIND ELEMENT COMMAND" << std::endl;
		std::cout << "enter \"4\" to check CORRECT STRING COMMAND" << std::endl;

		std::cin >> startCommand; 

		switch (startCommand) {
		
		case 0: 
			break;

		case 1: {
			char pushNumber = ' ';
			do {
				printStack();
				std::cout << "enter the number(symbol) you want to add to the Stack (not 0): ";
				std::cin >> pushNumber;

				Data digit;
				digit.data = pushNumber;
				if (pushNumber != '0') push(digit);
			} while (pushNumber != '0');
			std::cout << "\n";
			break;
		}
		case 2: {
			pop();
			std::cout << "\n";
			break;
		}
		case 3:{
			char elementToSearch;
			std::cout << "Enter the number(symbol) you want to find: ";
			std::cin >> elementToSearch;

			findElement(elementToSearch);
			std::cout << "\n";
			break;
		}
		case 4:{
			top = nullptr;
			correctString();
			std::cout << "\n";
			break;
		}
		default:
			std::cout << "Unknown command!" << std::endl;
			std::cout << "\n";
			break;
		}
	} while (startCommand != 0);

	return 0;
}

Stack* push(Data digit) {
	Stack* ptr = new Stack;

	ptr->digit = digit;
	ptr->next = top;

	top = ptr;
	return ptr;
}

void pop() {
	if (top == nullptr) return;
	Stack* ptr = top->next;

	std::cout << "Digit " << top->digit.data << " was deleted" << std::endl;

	delete top;
	top = ptr;
}

void printStack() {
	Stack* current = top;

	while (current != nullptr) {
		std::cout << current->digit.data << " " << current << std::endl;
		current = current->next;
	}
}

void findElement(char element) {
	bool isFound = false;
	Stack* current = top;
	while (current != nullptr) {
		if (current->digit.data == element) {
			std::cout << current->digit.data << " " << current << std::endl;
			isFound = true;
			break;
		}
		current = current->next;
	}
	if (!isFound) std::cout << "this item is not on the stack" << std::endl;
}


void correctString() {
	char openingBrackets[3] = { '(', '[', '{' };
	char closingBrackets[3] = { ')', ']', '}' };

	std::cout << "Enter the Brackets string: ";
	std::string userString;
	std::cin >> userString; 

	bool isCorrect = true;

	for (int i = 0; i < userString.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (userString[i] == openingBrackets[j]) {
				Data symbol;
				symbol.data = openingBrackets[j];
				push(symbol);
			}

			else if (userString[i] == closingBrackets[j]) {
				if (top == nullptr) break;
				else {
					char topSymbol = top->digit.data;
					pop();
					if (topSymbol != openingBrackets[j]) isCorrect = false;
				}
			}
		}
	}

	if (isCorrect && (top == nullptr)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
}
