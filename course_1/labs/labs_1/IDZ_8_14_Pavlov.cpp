//#include <iostream>
//#include <set>
//#include <string>
//#include <fstream>
//using namespace std;
//
//const int MAX = 1000;
//
//struct LESSONS {
//	string date;
//	string subject;
//	string typeLesson;
//	unsigned int group;
//	string lastName;
//};
//bool isRussianName(const string& name) {
//	for (char c : name) {
//		if (!((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я'))) return false;
//	}
//	return true;
//}
//bool proverkaDate(const string& date) {
//	if (date.length() != 10) return false;
//	if (date[2] != '.' || date[5] != '.') return false;
//	
//	for (int i = 0; i < date.length(); i++) {
//		if (i == 2 || i == 5) continue;
//		if (!isdigit(date[i])) return false;
//	}
//	int day = stoi(date.substr(0, 2));
//	int month = stoi(date.substr(3, 2));
//	int year = stoi(date.substr(6, 4));
//
//	if (day < 1 || day>31) return false;
//	if (month < 1 || month>12) return false;
//	if (year < 1900 || year>2100) return false;
//	
//	return true;
//}
//bool proverkaSubject(const string& subject) {
//	if (subject.empty()) return false;
//
//	for (char c : subject) {
//		if (!((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я'))) return false;
//	}
//	return true;
//}
//bool proverkaTypeLesson(const string& typeLesson) {
//	return typeLesson == "ЛЕК" || typeLesson == "ПР" || typeLesson == "ЛАБ";
//}
//bool proverkaGroup(unsigned int group) {
//	if (group < 1 || group>1000) return false;
//	return true;
//}
//bool proverkaLastName(const string& name) {
//	if (!isRussianName(name)) return false;
//	return true;
//}
//
//
//int main() {
//	setlocale(LC_ALL, "Ru");
//
//	set<unsigned int> groups;
//	LESSONS lessons[MAX];
//	int countLesson = 0;
//	int countLecture = 0;
//	
//
//	//проверка файла
//	ifstream file("IDZ_8_14_Pavlov.txt");
//	if (!file.is_open()) {
//		cout << "Ошибка чтения файла!!!" << endl;
//		return 0;
//	}
//	if (file.peek() == EOF) {
//		cout << "Файл пустой" << endl;
//		return 0;
//	}
//
//	//проеврка входных данных из файла
//	while (countLesson<MAX){
//
//		LESSONS t;
//		bool okOrNot = true;
//
//		if (!(file >> t.date >> t.subject >> t.typeLesson >> t.group >> t.lastName)) {
//			break;
//		}
//
//		if (!proverkaDate(t.date)) {
//			cout << "Ошибка в дате: " << t.date << endl;
//			okOrNot = false;
//		}
//		if (!proverkaSubject(t.subject)) {
//			cout << "Ошибка в названии предмета: " << t.subject << endl;
//			okOrNot = false;
//		}
//		if (!proverkaTypeLesson(t.typeLesson)) {
//			cout << "Ошибка в типе занятия: " << t.typeLesson << endl;
//			okOrNot = false;
//		}
//		if (!proverkaGroup(t.group)) {
//			cout << "Ошибка в номере группы: " << t.group << endl;
//			okOrNot = false;
//		}
//		if (!proverkaLastName(t.lastName)) {
//			cout << "Ошибка в фамилии препода: " << t.lastName << endl;
//			okOrNot = false;
//		}
//		if (!okOrNot) return 0;
//		
//		lessons[countLesson++] = t;
//	}
//	file.close();
//
//	//Нахождение всех преподов, преподов которые ведут лекции
//	set<string> allTeachers;
//	set<string> lectureTeachers;
//
//	//тут у меня не видит русские буквы, поэтому я так сделал
//	string teacher = "Иванов";
//	cout << "Введите преподавателя: " << endl;
//	cout << "Иванов" << endl;
//
//	for (int i = 0; i < countLesson; i++) {
//		allTeachers.insert(lessons[i].lastName);
//		if (lessons[i].typeLesson == "ЛЕК") {
//			lectureTeachers.insert(lessons[i].lastName);
//		}
//	}
//	//проверка фамилии учителя
//	if (allTeachers.count(teacher) == 0) {
//		cout << "Такого преподавателя нет!" << endl;
//		return 0;
//	}
//	if (!isRussianName(teacher)) {
//		cout << "Фамилия должна содержать только русские буквы!" << endl;
//		return 0;
//	}
//
//	//Нахождение лекций прочитанных тем самым преподом 
//	for (int i = 0; i < countLesson; i++) {
//		if (lessons[i].typeLesson == "ЛЕК" && lessons[i].lastName == teacher) {
//			countLecture++;
//			groups.insert(lessons[i].group);
//		}
//	}
//
//	//Вывод результатов
//	cout << "-------Задание 1-------" << endl << "Общее количество лекций, прочитанных заданным преподавателем: " << endl
//		<< countLecture << endl << "Перечень групп - слушателей этих лекций: " << endl;
//	
//	for (unsigned int g : groups) {
//		cout << g << " ";
//	}
//	cout << endl;
//
//	//вывод результатов
//	cout << endl << "-------Задание 2-------" << endl 
//		 << "Фамилии преподавателей, которые ведут только ПР и ЛАБ: " << endl;
//	for (string t: allTeachers) {
//		if (lectureTeachers.count(t) == 0) {
//			cout << t << endl;
//		}
//	}
//
//	return 0;
//	}