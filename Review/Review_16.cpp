# include <iostream>
# include <stack>
# include <queue>

class Book
{
    private:
    std::string Name;
    std::string Author;
    int IdNum;

    public:
    static int num;
    Book();
    Book(std::string name, std::string author, int idnum);
    ~Book();
    friend std::ostream &operator<< (std::ostream &out, const Book &book);
    friend bool operator== (const Book &book1, const Book &book2);
};

int Book::num = 0;

Book::Book()
{
    Name = "N/A";
    Author = "N/A";
    IdNum = NULL;

    num++;
}

Book::Book(std::string name, std::string author, int idnum):Name(name), Author(author), IdNum(idnum)
{
    num++;
}

Book::~Book()
{
    num--;
}

std::ostream &operator<< (std::ostream &out, const Book &book)
{
    out << '\n';
    out << "the book information" << '\n';
    out << "Name: " << book.Name << '\n';
    out << "Author:" << book.Author << '\n';
    out << "IdNum:" << book.IdNum << '\n';
    out << '\n';

    return out;
}

bool operator== (const Book &book1, const Book &book2)
{
    return ((book1.IdNum)==(book2.IdNum));
}

int main()
{
    Book *books = new Book[10];
    *(books+0) = Book("A", "A", 1);
    *(books+1) = Book("B", "B", 2);
    *(books+2) = Book("C", "C", 3);
    *(books+3) = Book("D", "D", 4);
    *(books+4) = Book("E", "E", 5);

    // std::cout << "the num of book is " << Book::num << '\n';

    // auto p = books;

    // while(p != (books+10))
    // {
    //     std::cout << *(p++);
    // }

    std::stack<Book> BookLib_stack;
    std::queue<Book> BookLib_queue;
    auto p = books;
    while(p != (books+10))
    {
        BookLib_stack.push(*p);
        BookLib_queue.push(*p);
        p++;
    }

    std::cout << "the num of book is " << Book::num << '\n';

    std::cout << "the stack lib is " << '\n';

    while(!BookLib_stack.empty())
    {
        std::cout << BookLib_stack.top();
        BookLib_stack.pop();
    }

    std::cout << "the queue lib is " << '\n';

    while(!BookLib_queue.empty())
    {
        std::cout << BookLib_queue.front();
        BookLib_queue.pop();
    }

    if(*books == Book("A", "A", 1))
    {
        std::cout << "yes!" << '\n';
    }
    else
    {
        std::cout << "no!" << '\n';
    }

    return 0;
}

