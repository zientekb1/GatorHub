#include <vector>
#include <string>
#include <Friends.h>


class manageFriends {
private:
  std::vector<Friend> friendsList;
public:
  void addFriend(std::string name, int age, std::string city) {
    Friend newFriend(name, age, city);
    friendsList.push_back(newFriend);
  }
  std::vector<Friend> getFriends() const {
    return friendsList;
  }
  std::vector<Friend> getFriendsInCity(std::string city) const {
    std::vector<Friend> friendsInCity;
    for (const Friend& friend : friendsList) {
      if (friend.getCity() == city) {
        friendsInCity.push_back(friend);
      }
    }
    return friendsInCity;
  }
  std::vector<Friend> getFriendsInRange(int minAge, int maxAge) const {
    std::vector<Friend> friendsInRange;
    for (const Friend& friend : friendsList) {
      int age = friend.getAge();
      if (age >= minAge && age <= maxAge) {
        friendsInRange.push_back(friend);
      }
    }
    return friendsInRange;
  }
};