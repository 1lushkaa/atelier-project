#include <iostream>
#include <string>
#include <vector>
#include <clocale>

// Структура заказа ателье
struct Order {
    int id;
    std::string client;
    std::string item;
    std::string deadline;
};

// Класс ателье
class Atelier {
private:
    std::vector<Order> orders;
    int nextId;

public:
    Atelier() : nextId(1) {}

    void addOrder(const std::string& client,
                  const std::string& item,
                  const std::string& deadline) {
        Order o;
        o.id = nextId++;
        o.client = client;
        o.item = item;
        o.deadline = deadline;
        orders.push_back(o);
        std::cout << "Заказ №" << o.id << " добавлен.\n";
    }

    void printAll() const {
        std::cout << "\n=== Список заказов ателье ===\n";
        if (orders.empty()) {
            std::cout << "Заказов нет.\n";
            return;
        }
        for (const auto& o : orders) {
            std::cout << "№" << o.id
                      << " | " << o.client
                      << " | " << o.item
                      << " | срок: " << o.deadline << "\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Atelier atelier;
    atelier.addOrder("Иванова А.П.", "Платье вечернее", "05.10.2026");
    atelier.addOrder("Петров С.С.",  "Костюм мужской",  "10.10.2026");
    atelier.printAll();

    return 0;
}
