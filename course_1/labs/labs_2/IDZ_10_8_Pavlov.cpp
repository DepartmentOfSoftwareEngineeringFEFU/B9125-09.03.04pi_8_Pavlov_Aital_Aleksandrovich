//#include <iostream>
//#include <iomanip>
//#include <ctime>
//using namespace std;
//
//
//struct Node {
//	double data;
//	Node* next;
//	Node* prev;
//};
//Node* createList(int n) {
//	Node* head = nullptr;
//	Node* tail = nullptr;
//
//	for (int i = 1; i <= n; i++) {
//		Node* newElem = new Node;
//		newElem->data = -1.0 + (double)rand() / RAND_MAX * 2.0;
//		newElem->next = nullptr;
//		newElem->prev = nullptr;
//
//		if (head == nullptr) {
//			head = newElem;
//			tail = newElem;
//		}
//		else {
//			tail->next = newElem;
//			newElem->prev = tail;
//			tail = newElem;
//		}
//	}
//	return head;
//}
//void printList(Node* head) {
//	
//	if (head == nullptr) {
//		cout << "Список пустой" << endl;
//		return;
//	}
//	
//	if (head->next == nullptr) {
//		cout << "От головы к хвосту: " << fixed << setw(2) << setprecision(2) << head->data << endl;
//		cout << "От хвоста к голове: " << fixed << setw(2) << setprecision(2) << head->data << endl;
//		return;
//	}
//
//	Node* p = head;
//	cout << "От головы к хвосту: ";
//	while (p != nullptr) {
//		cout << fixed << setw(2) << setprecision(2) << p->data;
//		if (p->next != nullptr) {
//			cout << " => ";
//		}
//		p = p->next;
//	}
//	cout << endl;
//
//	p = head;
//	cout << "От хвоста к голове: ";
//	while (p->next != nullptr) {
//		p = p->next;
//	}
//	while (p != nullptr) {
//		cout << fixed << setw(2) << setprecision(2) << p->data;
//		if (p->prev != nullptr) {
//			cout << " => ";
//		}
//		p = p->prev;
//	}
//	cout << endl;
//	
//}
//void deleteList(Node*& head) {
//	
//	while (head != nullptr) {
//		Node* p = head;
//		head = head->next;
//		delete p;
//	}
//	head = nullptr;
//}
//void insertElement(Node*& head, int pos, double val) {
//
//	Node* newElem = new Node;
//	newElem->data = val;
//	newElem->next = nullptr;
//	newElem->prev = nullptr;
//	//Вставка в начало
//	if (pos == 1 || head == nullptr) {
//		newElem->next = head;
//		if (head != nullptr) {
//			head->prev = newElem;
//		}
//		head = newElem;
//		return;
//	}
//	//Вставка в нужную позицию
//	Node* p = head;
//	int i = 1;
//	while (p->next != nullptr && i < pos - 1) {
//		p = p->next;
//		i++;
//	}
//	newElem->next = p->next;
//	newElem->prev = p;
//	if (p->next != nullptr) {
//		p->next->prev = newElem;
//	}
//	p->next = newElem;
//
//}
//void deleteElement(Node*& head, int pos) {
//	if (head == nullptr) {
//		cout << "Список пуст" << endl;
//		return;
//	}
//	Node* p = head;
//	//Удаление начала
//	if (pos == 1) {
//		head = head->next;
//		if (head != nullptr) {
//			head->prev = nullptr;
//		}
//		delete p;
//		return;
//	}
//	//Удаление дргуих элементов
//	int i = 1;
//	while (p->next != nullptr && i < pos) {
//		p = p->next;
//		i++;
//	}
//	if (p == nullptr) {
//		cout << "Элемента с таким номером нет" << endl;
//		return;
//	}
//	if (p->prev != nullptr) {
//		p->prev->next = p->next;
//	}
//	if (p->next != nullptr) {
//		p->next->prev = p->prev;
//	}
//	delete p;
//
//}
//void rebuild(Node*& head) {
//	if (head == nullptr) {
//		return;
//	}
//	Node* p = head;
//	while (p != nullptr) {
//		Node* next = p->next;
//		if (p->data < 0 && p != head) {
//			if (p->prev != nullptr) {
//				p->prev->next = p->next;
//			}
//			if (p->next != nullptr) {
//				p->next->prev = p->prev;
//			}
//			p->next = head;
//			p->prev = nullptr;
//			head->prev = p;
//			head = p;
//		}
//		p = next;
//	}
//
//}
//void menu() {
//	cout << "Меню: " << endl;
//	cout << "1)Создать список" << endl;
//	cout << "2)Вывести список" << endl;
//	cout << "3)Удаление всего списка" << endl;
//	cout << "4)Вставка одного элемента" << endl;
//	cout << "5)Удаление одного элмента" << endl;
//	cout << "6)Переставить с отрицательных до положительных" << endl;
//	cout << "0)Выход" << endl;
//	cout << "Выбор: ";
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int choice;
//	int n;
//	Node* myList = nullptr;
//	int pos;
//	double val;
//	do {
//		cout << endl;
//		menu();
//		cin >> choice;
//		switch (choice) {
//
//		case 1: {
//			cout << "Введите n: ";
//			cin >> n;
//			if (n > 0 && n<=100) {
//				deleteList(myList);
//				myList = createList(n);
//				break;
//			}
//			else if (n > 100) {
//				cout << "Нельзя" << endl;
//				break;
//			}
//			else if (n == 0) {
//				cout << "Введите n>=2!" << endl;
//				break;
//			}
//			else {
//				cout << "Введите n>=2!" << endl;
//				break;
//			}
//			
//		}
//
//		case 2: {
//			printList(myList);
//			break;
//		}
//
//		case 3: {
//			deleteList(myList);
//			cout << "Список удален" << endl;
//			break;
//		}
//			  
//		case 4: {
//			cout << "Введите позицию: " << endl;
//			cin >> pos;
//			if (cin.fail() || pos <= 0) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Введите больше 0!" << endl;
//				break;
//			}
//
//			cout << "Введите значение: " << endl;
//			cin >> val;
//
//			insertElement(myList, pos, val);
//			printList(myList);
//			break;
//		}
//
//		case 5: {
//			cout << "Введите позицию для удаления: " << endl;
//			cin >> pos;
//			if (cin.fail() || pos <= 0) {
//				cin.clear();
//				cin.ignore(1000, '\n');
//				cout << "Введите больше 0!" << endl;
//				break;
//			}
//
//			deleteElement(myList, pos);
//			printList(myList);
//			break;
//		}
//
//		case 6: {
//			rebuild(myList);
//			printList(myList);
//			break;
//		}
//
//		default: {
//			cout << "Выберите из меню" << endl;
//			break;
//		}
//
//		}
//	} while (choice != 0);
//	
//	return 0;
//}