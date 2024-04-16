#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
	ContactNode(string name = "NONAME", string number = "NONUM", ContactNode* nextNode = nullptr);
	string GetName();
	string GetPhoneNumber();
	void InsertAfter(ContactNode*& nodeLoc);
	ContactNode* GetNext();
	void PrintContactNode();

private:
	string contactName;
	string contactPhoneNumber;
	ContactNode* nextNodePtr;
};

ContactNode::ContactNode(string name, string number, ContactNode* nextNode) {
	this->contactName = name;
	this->contactPhoneNumber = number;
	this->nextNodePtr = nextNode;
}

string ContactNode::GetName() {
	return this->contactName;
}

string ContactNode::GetPhoneNumber() {
	return this->contactPhoneNumber;
}

ContactNode* ContactNode::GetNext() {
	return this->nextNodePtr;
}

void ContactNode::InsertAfter(ContactNode* &nodeLoc) {
	ContactNode* tempNode = nullptr;
	tempNode = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tempNode;
}

void ContactNode::PrintContactNode() {
	cout << "Name: " << this->contactName << endl;
	cout << "Phone number: " << this->contactPhoneNumber << endl;
}

int main() {
	ContactNode* headNode = nullptr;
	ContactNode* currNode = nullptr;

	headNode = new ContactNode();

	while (hasNext()) {}

	return 0;
}