#include<iostream>

using namespace std;

class Healthrecord{
	private:
		string date;
		string disease;
	public:
		Healthrecord(){ date =" "; disease = " "	;}
		Healthrecord(string date, string disease){
			this->date = date;
			this->disease = disease;
		}
		~Healthrecord(){}
		
		string getDisease() {
        	return disease;
    	}
   
    	string getDate(){
        	return date;
    	}
};
typedef Healthrecord* record;
class System{
	private:
		struct Node{
			Healthrecord record;
			Node* next;
		};
		typedef Node* list;
		list head;
	public:
		System(){head = nullptr;}
		~System(){}

// add one record
	void addRecord(Healthrecord &newrecord){
		// make a new record
		list newnode = new Node;
		newnode->record = newrecord;
		newnode->next = nullptr;
		
		// check if list is null or not
		if(head == nullptr){
			head = newnode; 
		}
		else{
			list temp = head;
			while( temp->next != nullptr){ // scan to the last element
				temp = temp -> next;
			}
			temp->next = newnode;
		}			
	}

// find by date
	Healthrecord* Findbydate(string &date){
		list temp = head;
		while( temp != nullptr){
			if( temp-> record.getDate() == date){
				return &(temp->record);
			}
			temp = temp -> next;
		}
		
		return nullptr;
	}
// find by disease
	Healthrecord* Findbydisease(string &disease){
		list temp = head;
		while( temp != nullptr){
			if( temp-> record.getDisease() == disease){
				return &(temp->record);
			}
			temp = temp -> next;
		}
		
		return nullptr;
	}
		
		
};

int main(){
	System system;
	
	//record
	Healthrecord record1("1/1/1", "a");
	Healthrecord record2("2/1/1", "b");
	Healthrecord record3("3/1/1", "c");
	
	//add to system
	system.addRecord(record1);
	system.addRecord(record2);
	system.addRecord(record3);
	
	// find by da
    string searchDate = "1/1/1";
    record foundRecordDate = system.Findbydate(searchDate);
    if (foundRecordDate != nullptr) {
        cout << "Found record on date " << searchDate << ": " << foundRecordDate->getDate()
             << " " << foundRecordDate->getDisease() << endl;
    } else {
        cout << "No record found on date " << searchDate << endl;
    }

    // find by di
    string searchDisease = "b";
    record foundRecordDisease = system.Findbydisease(searchDisease);
    if (foundRecordDisease != nullptr) {
        cout << "Found record with disease " << searchDisease << ": " << foundRecordDisease->getDate()
             << " " << foundRecordDisease->getDisease() << endl;
    } else {
        cout << "No record found with disease " << searchDisease << endl;
    }
	return 0;
}