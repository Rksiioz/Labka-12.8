#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(const string& value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() : head(nullptr) {}

    Node* getHead() const {
        return head;
    }

    void push_back(const string& value) {
        if (!head) {
            head = new Node(value);
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    LinkedList split(int index) {
        LinkedList secondList;

        if (index < 0 || !head) {
            cout << "Invalid index or empty list!" << endl;
            return secondList;
        }

        Node* current = head;
        int count = 0;
        while (current && count < index - 1) {
            current = current->next;
            count++;
        }

        if (!current || !current->next) {
            cout << "Invalid index!" << endl;
            return secondList;
        }

        secondList.head = current->next;
        current->next = nullptr;

        return secondList;
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void push_front(const string& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
};

int main() {
    ifstream file("test.txt");

    if (!file.is_open()) {
        cout << "Error!" << endl;
        return 1;
    }

    LinkedList wordsList;

    string word;
    while (file >> word) {
        wordsList.push_back(word);
    }

    file.close();

    cout << "List from file:" << endl;
    wordsList.display();

    string searchWord;
    int index;
    cout << "Enter word: ";
    cin >> searchWord;
    cout << "Enter number of elem: ";
    cin >> index;

    LinkedList secondList = wordsList.split(index);

    cout << "First list:" << endl;
    wordsList.push_front(searchWord);
    wordsList.display();

    cout << "Second list:" << endl;
    secondList.push_back(searchWord);
    secondList.display();

    return 0;
}
