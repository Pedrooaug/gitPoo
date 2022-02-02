#include <vector>
#include <memory>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

class Exception : public std:: exception {
    std:: string tweet;
    public:
        Exception(const std::string& tweet) : tweet(tweet) {}
        
        const char* what() const noexcept override {
            return tweet.c_str();
        }
};


class Tweet {
    std:: string nick;
    std:: string tweet;
    std:: set<std::string> likes;
    int id;

public:

    Tweet(int id, const std::string& nick, const std::string& tweet) : id(id), nick(nick), tweet(tweet) {}

    int getId() {
        return id;
    }

    void like (std::string& nick) {
        likes.insert(nick);
    }

    friend std::ostream& operator << (std::ostream& os, const Tweet& tweet) {
        os << tweet.id << ":" << tweet.nick << " (" << tweet.tweet << ")";
        
        if(!tweet.likes.empty()) {
            os << " [ ";
            
            for(auto& like : tweet.likes) {
                os << like << " ";
            }

            os << "]";

        }
        
        return os;
    }

};


class Inbox {
    std:: map<int, Tweet*> unread;
    std:: map <int, Tweet*> all_tweets;

public:
    
    Inbox() {}
    
    void unreaded(Tweet* tweet) {
        unread.insert(std::pair<int, Tweet*>(tweet->getId(), tweet));
    }

    void read(Tweet* tweet) {
        all_tweets.insert(std::pair<int,Tweet*>(tweet->getId(), tweet));
    }

    std::vector<Tweet*> getUnread() {
        std:: vector<Tweet*> unreaded;
        for(auto& tweet : unread) {
            unreaded.push_back(tweet.second);
            all_tweets.insert(std::pair<int, Tweet*>(tweet.first, tweet.second));
        }
        unread.clear();
        return unreaded;
    }


    std:: vector<Tweet*>getTweets() {
        std::vector<Tweet*>tweets;

        for(auto tweet : all_tweets) {
            tweets.push_back(tweet.second);
        }
        return tweets;
    }


    Tweet* getTweet(int id) {
        auto it = all_tweets.find(id);

        if(it == all_tweets.end()) {
            throw Exception("Tweet nao encontrado");
        }
        return it->second;
    }

    void tostring() {
        for(auto& tweet : this->getUnread()) {
            std:: cout << *tweet << "\n";
        }
        if(this->getUnread().empty()) {
            for(auto& tweet : this->getTweets()) {
                std:: cout << *tweet << "\n";
            }
        }

        std:: cout << "\n";
    }

};

class User {
std:: string nick;
Inbox inbox;
std::map<std:: string, User*> following;
std::map<std:: string, User*> followers;
public:

User(std:: string& nick) : nick(nick) {};

void follow(User* user) {
    if(following.find(user->nick) == following.end()) {
        following.insert(std::pair<std::string, User*>(user->nick, user));
        user->followers.insert(std::pair<std::string, User*>(nick, this));
    }
}

void unfollow(std::string nick) {
    auto it = following.find(this->nick);
    if(it == following.end()) {
        throw Exception("Voce nao segue o usuario ou o usuario nao foi encontrado");
    }
    auto teste = it->second->followers.find(this->nick);
    it->second->followers.erase(teste);
    following.erase(it);

}

void like (int id) {
    Tweet* tweet = inbox.getTweet(id);
    
    if(tweet == nullptr) {
        throw Exception("Tweet nao encontrado");
    }
    tweet->like(nick);
}

Inbox getInbox() {
    return inbox;
}

    void tweetar (Tweet* tweet) {
        inbox.unreaded(tweet);
        for(auto& seguidor : followers) {
            seguidor.second->getInbox().unreaded(tweet);
        }
    }

    void toString() {
        std:: cout << nick << "\n";
        std:: cout << " seguindo: [ ";
        for(auto& seguindo : following) {
            std:: cout << seguindo.first << " ";
        }
        std:: cout << "]\n";
    
        std:: cout << "seguidores: [ ";
        for(auto& seguidores : followers) {
            std:: cout << seguidores.first << " ";
        }
        std:: cout << "]\n";
    }

};

class Twt {
    std::map<std::string, std::shared_ptr<User>> users;
    std::map<int, std::shared_ptr<Tweet>> tweets;
    int id {0};

    Tweet* tweet(std::string nick, std::string conteudo) {
        Tweet* tweet = new Tweet(id, nick, conteudo);
        tweets.insert(std::pair<int, std::shared_ptr<Tweet>>(id, std::shared_ptr<Tweet>(tweet)));
        id++;
        return tweet;
    }
    
public:

    Twt() {}

    void addUser(std::string nick) {
        if(users.find(nick) != users.end()) {
            throw Exception("Esse nick ja e utilizado");
        }
        users.insert(std::pair<std::string, std:: shared_ptr<User>>(nick, std::shared_ptr<User>(new User(nick))));  
    }

User* getUser(std::string nick) {
    auto it = users.find(nick);
    if(it == users.end()) {
        throw Exception("Usuario nao existe ou nao foi encontrado");
    }
    return it->second.get();
}


void twittar(std::string nick, std:: string conteudo) {
    User* user = getUser(nick);
    Tweet* message = tweet(nick, conteudo);
    user->tweetar(message);
}

};









