//
// Created by k on 18-12-29.
//
#ifdef _MESSAGE_
#define  _MESSAGE_

#include <set>
#include <string>


class Message{
    friend  class Folder;

    public:
        //folders 被隐式初始化为空集合
        explicit Message(const std::string &str=""):contents(str){ }
        //拷贝控制成员，用于管理指向本Message的指针
        Message(const Message& );
        Message& operator=(const Message& );
        ~Message();


        void save(Folder& );
        void remove(Folder& );


    private:
        std::string contents;
        std::set<Folder*> folders;

        //拷贝构造函数，拷贝赋值运算符和析构函数所使用的工具函数
        //将本Messages添加到指向参数的Folder中
        void add_to_Folders(const Message&);
        //
        void remove_from_Folders();
};
Message::Message(const Message& m):
    contents(m.contents),folders(m.folders){
        
	    add_to_Folders(m);
}

Message& operator=(const Message& rhs){
    //先把消息从对应的folders中删去
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
}

Message::~Message()
{
        remove_from_Folders();
}
void Message::save(Folder& f)
{
    //将Folder添加到Folder列表中
    folders.insert(&f);
    //将本Message添加到f的Message集合中
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    //从Folder列表中删除
    folders.erase(&f);
    //从Folder中删除消息
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for(auto& f:m.folders)
        f->addMsg(this);
}
void Message::remove_from_Folders()
{
    for(auto& f:folders)
        f->remMsg(this);
}

void swap(Message &lhs,Message &rhs)
{
    using std::swap;

     for(auto& f:lhs.folders)
        f->remMsg(this);
     for(auto& f:rhs.folders)
        f->remMsg(this);
     swap(lhs.contents,rhs.contents);
     swap(lhs.folders,rhs.folders);

     for(auto& f:lhs.folders)
        f->addMsg(this);
     for(auto& f:lhs.folders)
        f->addMsg(this);
}
#endif
