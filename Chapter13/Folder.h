#ifdef _FOLDER_
#define  _FOLDER_

#include <set>

class Folder{
    friend class Message;
    public:

    private:
        std::set<Message*> messages;
};

#endif