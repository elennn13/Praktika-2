#include <iostream>
#include <vector>
#include <initializer_list>


template<typename K, typename V>
class Map {

private:
	struct Pair { // для хранения пар ключ-значение внутри динамич. массива data
		K first;  // ключ
		V second; // значение
	};
	std::vector<Pair> data;

public:
	// конструктор по умолчанию
	Map() = default;

	// конструтор копирования 
	Map(const Map& other) : data(other.data) {}

	// конструктор принимающий initializer_list
		 // создает объект мап передав ему ключ-значение ин лист. 
		 // для каждой пары вызывает setItem для добавления элемента 
		 // в коллекцию
	Map(std::initializer_list<std::pair<K, V>> list) {
		 // TODO
	}


	// деструктор
	~Map() = default;

	// метод setItem добавляет новую пару  ключей в коллекию.

	void setItem(const K& key, const V& value) {
		for (auto& pair : data) { // проверка ключей с таким же значением // TODO: не forEach
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		data.push_back({ key, value }); // если элемента с таким же ключом нет, добавляется
	}


	// оператор [] для доступа к элементу по ключу

	V& operator[](const K& key) {
		for (auto& pair : data) { // ищем элемент с заданным ключом
			if (pair.first == key) {
				return pair.second;
			}
		}
		setItem(key, V());
		return data.back().second;
	}

	// метод clear очищает удаляя всю коллекцию data
	void clear() {
		data.clear();
	}

	// метод size возвращает кол. элементов хранящихся в коллекции
	size_t size() const {
		return data.size();
	}

};

int main() {
	setlocale(LC_ALL, "ru");

	Map<std::string, int> myMap = { {"apple", 5}, {"banana", 3}, {"cherry", 10} };
	myMap.setItem("orange", 7);


	std::cout << "Size: " << myMap.size() << std::endl;
	std::cout << "value for key 'banana': " << myMap["banana"] << std::endl;
	myMap["banana"] = 5;

	myMap.clear();
	std::cout << "Size clear: " << myMap.size() << std::endl;
	return 0;
}
