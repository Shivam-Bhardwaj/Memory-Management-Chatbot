#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <memory>
#include <string>

// Helps to see what's going under the hood
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define TAG printf(">>>>> TAG: line (%d), function (%s), file (%s)\n\n", \
              __LINE__, __FUNCTION__, __FILENAME__);

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
  private:
  // data handles (owned)
  wxBitmap *_image; // avatar image

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

  public:
  // constructors / destructors
  ChatBot();                     // constructor WITHOUT memory allocation
  ChatBot(std::string filename); // constructor WITH memory allocation
  ~ChatBot();

  //// STUDENT CODE
  ////
  ChatBot(const ChatBot &source); // copy constructor
  ChatBot &operator=(const ChatBot &source); //copy assignment constructor
  ChatBot(ChatBot &&source); // move constructor
  ChatBot &operator=(ChatBot &&source); // move assignment constructor
  ////
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode *node);

  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }

  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }

  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */