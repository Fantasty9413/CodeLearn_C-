# include <iostream>

# define ToString( x ) #x

struct Book
{
    std::string title;
    std::string author;
    std::string subject;
    int book_id;
};

std::ostream &operator << (std::ostream &output, const Book book)
{
    output << '\n';
    output << "Book Information" << '\n';
    output << "title:   " << book.title << '\n';
    output << "author:  " << book.author << '\n';
    output << "subject: " << book.subject << '\n';
    output << "book_id: " << book.book_id << '\n';
    output << '\n';
    return output;
}

int main()
{
    Book book;
    book.title = "Effictive C++";
    book.author = "Scott";
    book.subject = "Programme";
    book.book_id = 0;

    Book* books = new Book[10];
    Book* ptr = nullptr;

    for(int i=0; i<10; i++)
    {
        ptr = books + 1;
        *ptr = book;
        ptr->book_id = i;

        std::cout << "the " << i << "th" << " book's information is as follow: " << std::endl;
        std::cout << *ptr << std::endl;
    }

    return 0;
}