/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, RegularUser, BusinessUser
 * Date: 30/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>
#include <cmath>
#include <vector>

class User
{
private:
	std::string username, email, password;
	int hashCode;
	bool business;
public:
	User(std::string username, std::string email, std::string password, bool business) : username(username), email(email), hashCode(0), business(business)
	{
		this->password = hash(password);
	}
	std::string hash(std::string password)
	{
		for (int i = 0; i < password.length(); i++) {
        	hashCode += password[i] * pow(31, i);
    	}
    	return std::to_string(hashCode);
	}
	void verify(std::string username, std::string email, std::string password)
	{
		if (this->username == username && this->email == email && this->password == hash(password))
			std::cout << "Logged In Sucessfully" << std::endl;
		else
			std::cout << "Username or Password Or Email entered incorrectly" << std::endl;
	}
	void display() {std::cout << "UserName: " << username << std::endl;}
	bool getBusiness() {return this->business;}
};

class Post
{
private:
	int postId, likes, views;
	std::string content;
	std::vector<std::string> comments;
public:
	Post(int postId = 0, std::string content = "") : postId(postId), likes(0), views(0), content(content) {}
	void likePost() {this->likes++;}
	void addComments(std::string comment) {this->comments.push_back(comment);}
	void displayPostDetails() 
	{
		std::cout << "Post Id: " << this->postId << std::endl
		<< "Likes: " << this->likes << std::endl
		<< "Content: " << this->content << std::endl;
		for (int i = 0; i < comments.size(); ++i)
		{
			std::cout << comments[i] << std::endl;
		}
	}
	void promotePost(bool business)
	{
		if (business)
		{
			views *= 3;
			likes *= 2;
		}
		else std::cout << "Not A BusinessUser!!";
	}
	int getPostId() {return this->postId;}
	void displayLikes() {std::cout << "Likes: " << this->likes << std::endl;}
	void displayViews() {std::cout << "Views: " << this->views << std::endl;}
	void displayCommentsCount() {std::cout << "Comments: " << this->comments.size() << std::endl;}
};

class RegularUser : public User
{
private:
	int postCount, feedCount;
	static const int MAX_FEED_SIZE;
	Post posts[5];
	Post** feed;
public:
	RegularUser(std::string username, std::string email, std::string password) : postCount(0), feedCount(0), User(username, email, password, false) 
	{
		feed = new Post*[MAX_FEED_SIZE];
	}
	void addPost(Post& post)
	{
		if (postCount < 5)
		{
			posts[postCount] = post;
			postCount++;
		}
		else
			std::cout << "Cannot Add More Posts" << std::endl;
	}
	void addToFeed(Post* post)
	{
		if (feedCount < MAX_FEED_SIZE)
		{
			feed[feedCount] = post;
			feedCount++;
			std::cout << "Added Post To Feed\n";
		}
		else
			std::cout << "Feed Full. Cannot Add More\n";
	}
	void viewFeed(){
		for (int i = 0; i < feedCount; ++i)
		{
			feed[i]->displayPostDetails();
		}	
	}
};

const int RegularUser::MAX_FEED_SIZE = 10;

class BusinessUser : public User
{
private:
	int promotionCount, promotionLimit;
	std::vector<Post> posts;
public:
	BusinessUser(std::string username, std::string email, std::string password) : promotionCount(0), promotionLimit(10), User(username, email, password, true) {}

	void promote(int postId)
	{
		if (getBusiness() && promotionCount < promotionLimit)
		{
			for (int i = 0; i < posts.size(); ++i)
			{
				if (posts[i].getPostId() == postId)
				{
					posts[i].promotePost(getBusiness());
					promotionCount++;
					break;
				}
			}
		}
		else
			std::cout << "Cannot Promote More Than " << promotionLimit << " Posts" << std::endl;
	}

	void addPost(Post &post) {posts.push_back(post);}
	void display() 
	{
		for (int i = 0; i < posts.size(); ++i)
		{
			posts[i].displayPostDetails();
		}
	}
};

int main()
{
	std::cout << "Muhammed Owais 23K-0047" << std::endl;
	// Create instances of users
    RegularUser regularUser("John", "john@example.com", "password123");
    BusinessUser businessUser("Jane", "jane@example.com", "businesspwd");

    // Create some posts
    Post post1(1, "First post content");
    Post post2(2, "Second post content");
    Post post3(3, "Third post content");

    // Add posts to users
    regularUser.addPost(post1);
    regularUser.addPost(post2);
    businessUser.addPost(post3);

    // Regular user interacts with posts
    post1.likePost();
    post1.addComments("Nice post!");
    post2.likePost();
    post2.likePost();

    // Business user promotes a post
    businessUser.promote(3);

    // Add posts to regular user's feed
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);
    regularUser.addToFeed(&post3);

    // View regular user's feed
    std::cout << "Regular User's Feed:\n";
    regularUser.viewFeed();

    // View Business user's posts
    std::cout << "Busines User's Posts\n";
    businessUser.display();
}