#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
  string Name;
  int SubscriberCount;
  list<string> PublishedVideoTitles;

protected:
  string OwnerName;
  int contentQuality;
public:
  YouTubeChannel(string name, string ownerName) {
    Name = name;
    OwnerName = ownerName;
    SubscriberCount = 0;
    contentQuality = 0;
  }
  void getInfo() {
    cout << "Name: " << Name << endl;
    cout << "OwnerName: " << OwnerName << endl;
    cout << "SubscriberCount: " << SubscriberCount << endl;
    cout << "Videos: " << endl;
    for(string videoTitle:PublishedVideoTitles) {
      cout << videoTitle << endl;
    }
  }
  void subscribe() {
    SubscriberCount++;
  }
  void unsubscribe() {
    if (SubscriberCount > 0)
      SubscriberCount--;
  }
  void publishVideo(string title) {
    PublishedVideoTitles.push_back(title);
  }
};

//Inheritance
class cookingYoutubeChannel:public YouTubeChannel {
public: 
  cookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name,ownerName) {}
void Practice() {
  cout << OwnerName << " practicing cooking, learning new recipes" << endl;
  contentQuality++;
}
};

class singerYoutubeChannel:public YouTubeChannel {
public: 
  singerYoutubeChannel(string name, string ownerName):YouTubeChannel(name,ownerName) {}
void Practice() {
  cout << OwnerName << " is taking singing class, learning new songs, learning how to dance..." << endl;
    contentQuality++;
}
};

int main() {
  cookingYoutubeChannel cookingYtChannel("Twice", "Twice");
  
  singerYoutubeChannel singerYtChannel("BTS", "BTS");
  
  cookingYtChannel.Practice();
  cout << endl;
  singerYtChannel.Practice();
}