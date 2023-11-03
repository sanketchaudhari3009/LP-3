#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(MinHeapNode *root, string str) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare {
    bool operator()(MinHeapNode *a, MinHeapNode *b) {
        return (a->freq > b->freq);
    }
};

bool isNumber(const string &s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void HuffmanCode() {
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    string input;
    char character;
    int frequency;

    do {
        cout << "Enter a character: ";
        cin >> input;

        if (input.length() == 1 && isalpha(input[0])) {
            character = input[0];
            break;
        } else {
            cout << "Please enter a valid character." << endl;
        }
    } while (true);

    do {
        cout << "Enter the frequency for character " << character << ": ";
        cin >> input;

        if (isNumber(input)) {
            frequency = stoi(input);
            break;
        } else {
            cout << "Please enter a number as frequency." << endl;
        }
    } while (true);

    minHeap.push(new MinHeapNode(character, frequency));

    while (true) {
    char choice;
    cout << "Do you want to add another character? (Y/N): ";
    cin >> choice;

    if (toupper(choice) == 'N') {
        break;
    } else if (toupper(choice) == 'Y') {
        do {
            cout << "Enter a character: ";
            cin >> input;

            if (input.length() == 1 && isalpha(input[0])) {
                character = input[0];
                break;
            } else {
                cout << "Please enter a valid character." << endl;
            }
        } while (true);

        do {
            cout << "Enter the frequency for character " << character << ": ";
            cin >> input;

            if (isNumber(input)) {
                frequency = stoi(input);
                break;
            } else {
                cout << "Please enter a number as frequency." << endl;
            }
        } while (true);

        minHeap.push(new MinHeapNode(character, frequency));
    } else {
        cout << "Invalid input. Please enter either 'Y' or 'N'." << endl;
    }
}


    while (minHeap.size() != 1) {
        MinHeapNode *left = minHeap.top();
        minHeap.pop();
        MinHeapNode *right = minHeap.top();
        minHeap.pop();
        MinHeapNode *temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    cout << "Huffman Codes:" << endl;
    printCodes(minHeap.top(), "");
}

int main() {
    HuffmanCode();
    return 0;
}
