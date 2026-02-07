#include<iostream>
#include <vector>
#include<string>
using namespace std;

class Book
{
    protected:
    int id;
    string book_title;
    bool issued;
    public:
    Book(string t,int id):id(id), book_title(t),issued(false){}
    void issueBook()
    {
        issued=true;
    }
    int getId()const {return id;};
    string getTitle()const {return book_title;}
    bool getIsIssued(){return issued;}
};
struct issuedBooksInfo
{
    string title;
    int id;
};
class User
{
    protected:
    string user_name;
    int userId1;
    vector<string> issuedBooks;
    vector<int> issueBookId;    
    vector<issuedBooksInfo> issueBooks;
    public:
    User(string name,int id) : user_name(name),userId1(id){}
    int userId()const {return userId1;}
    string userName()
    {
        return user_name;
    }
    void issued(string book,int id)
    {
        cout<<book<<" is issued by "<<user_name<<endl;
        issueBooks.push_back({book,id});
    }
    const vector<issuedBooksInfo>& getIssuedBooks()const {return issueBooks;}
};

class Library 
{
    vector<Book> books;
    vector<User> users;
    int nextBookId = 1;
    int nextUser=1;
    public:
    void add_books(const string& book)
    {

        for(auto &b : books)
        {
            if(b.getTitle()==book)
            {
                cout<<"Book already exis"<<endl;
                return ;
            }
        }
        books.emplace_back(book,nextBookId++);
        cout<<book<<" Added"<<endl;
    }
    void show_books()
    {
        for(auto &b : books)
        {
            cout<<b.getId()<<" ";
            cout<<b.getTitle()<<endl;
        }
    }
    void newUser(const string& user)
    {
        bool isuser=false;
        for(auto &u : users)
        {
            if(u.userName()==user)
            {
                isuser=true;
            }
        }
        if(!isuser)
        {
            users.emplace_back(user,nextUser++);
            cout<<user<<" created"<<endl;    
        }
        else{
            cout<<"User already exist"<<endl;
        }
    }
    void showUsers()
    {
        for(auto &u : users)
        {
            cout<<u.userName()<<endl;
        }
    }
    void issuedBook(const int& userId,const int& bookId)  
    {
        User* user=nullptr;
        Book* book=nullptr;

        for(auto &u : users)
        {
            if(u.userId()==userId)
            {
                user=&u;
                break ;
            }
        }

        if(!user)
        {
            cout<<"User does not exist"<<endl;
            return;
        }

        for(auto &b : books)
        {
            if(b.getId()==bookId)
            {
                if(b.getIsIssued()==true)
                {
                    cout<<"Book is issued";
                    return;
                }
                book=&b;
                break ;
            }
        }
        if(!book)
        {
            cout<<"book does not exist"<<endl;
            return;
        }
        
        user->issued(book->getTitle(),book->getId());
        book->issueBook();
    }
    void showTransations()
    {
        int ch;
        cout<<"1 for all user \n2 for specefic user"<<endl;
        cin>>ch;
        if(ch==1)
        {
            for(auto &b: users)
            {
            cout<<b.userName()<<":"<<endl<<"Books:-";

            for(const auto& u : b.getIssuedBooks())
            {
                cout<<"["<<u.id<<"] "<<u.title;
            }
            cout<<endl;
            }
        }
        else
        {
            User* user=nullptr;
            string username;
            cout<<"Enter the UserName:";
            cin>>username;
            for(auto &u: users)
            {
                if(u.userName()==username)
                {
                    user=&u;
                }
            }
            if(!user)
            {
                cout<<"user does not exist"<<endl;
                return;
            }
            cout<<user->userName()<<":"<<endl<<"Books:-";
            for(const auto& b : user->getIssuedBooks())
            {
                cout<<"["<<b.id<<"] "<<b.title;
            }
            cout<<endl;
        }
    }
};

int main()
{
    Library l1;
    int ch;
    string user,book;
    int bookId,userId;
    cout<<"1.New User"<<endl;
    cout<<"2.Show Books"<<endl;
    cout<<"3.Issue book"<<endl;
    cout<<"4.show Transastions"<<endl;
    cout<<"5.Add book"<<endl;
    cout<<"6.show users"<<endl;
    cout<<"7.Exit"<<endl;

    do{
        cout<<"Enter your choice:-"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1 :
                cout<<"Enter the userName:-";
                cin>>user;
                l1.newUser(user);
                break;
            case 2: l1.show_books();
                break;
            case 3 :
                cout<<"Enter the UserId and BookId:-";
                cin>>userId;
                cin>>bookId;
                l1.issuedBook(userId,bookId);
                break;
            case 4 : l1.showTransations();
            break;
            case 5:
                cout<<"Enter book name:-";
                cin>>book;
                l1.add_books(book);
                break;
            case 6:l1.showUsers();
            break;
            default:cout<<"Enter valid choice"<<endl;
        }

    }while(ch!=7);
    return 0;
}