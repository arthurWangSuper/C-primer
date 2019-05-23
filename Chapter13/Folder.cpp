#include <iostream>

#include "Message.h"
#include "Folder.h"

using std::ostream;

void Folder::addMsg(Message *msg){
	messages.insert(msg);
}

void Folder::remMsg(Message *msg){
	messages.erase(msg);
}

Folder::~Folder(){
}

ostream& print_messages(ostream &out, const Folder &f){
	if(f.messages.empty()){
		out<<f.name<<" is empty";
	}else{
		cout<<f.name<<" has: "
		for(auto m:f.messages)
		{
			cout<<M->content<<", ";
		}
		cout<<"\b\b";
	}
	return out;
}
